#include "LocalFileService.h"
#include <QDebug>

// 私有实现类的定义
class LocalFileService::Lfs_impl
{
public:
    Lfs_impl() = default;
    ~Lfs_impl(){
        return;
    }
};

LocalFileService::LocalFileService() 
    : count(0)
    , impl_lfs(std::make_unique<Lfs_impl>())
{
}

LocalFileService::~LocalFileService()
{
    // 清理所有打开的文件
    QWriteLocker locker(&mapLock);
    for (auto it = opendFiles.begin(); it != opendFiles.end(); ++it) {
        if (it.value() && it.value()->file.isOpen()) {
            it.value()->file.close();
        }
    }
    opendFiles.clear();
}

bool LocalFileService::haveFile(fileID id) const
{
    QReadLocker locker(&mapLock);
    return opendFiles.contains(id);
}

fileID LocalFileService::openFile(const QString& path)
{
    if (path.isEmpty()) {
        return -1;
    }
    
    auto fileRes = std::make_shared<file_res>(path);
    if (!fileRes->file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Failed to open file:" << path;
        return -1;
    }
    
    QWriteLocker locker(&mapLock);
    fileID newId = generateNewId();
    opendFiles.insert(newId, fileRes);
    
    return newId;
}

bool LocalFileService::closeFile(fileID id)
{
    QWriteLocker locker(&mapLock);
    
    if (!opendFiles.contains(id)) {
        return false;
    }
    
    auto fileRes = opendFiles.value(id);
    if (fileRes && fileRes->file.isOpen()) {
        fileRes->file.close();
    }
    
    return opendFiles.remove(id) > 0;
}

QString LocalFileService::getFileContent(fileID id, QString charset)
{
    QReadLocker locker(&mapLock);
    
    if (!opendFiles.contains(id)) {
        return QString();
    }
    
    auto fileRes = opendFiles.value(id);
    if (!fileRes || !fileRes->file.isOpen()) {
        return QString();
    }
    
    QReadLocker fileLocker(&fileRes->lock);
    if (fileRes->file.seek(0)) {
        QByteArray data = fileRes->file.readAll();
        return QString::fromUtf8(data);
    }
    
    return QString();
}

bool LocalFileService::writeFile(fileID id, const QString& content)
{
    QReadLocker mapLocker(&mapLock);
    
    if (!opendFiles.contains(id)) {
        return false;
    }
    
    auto fileRes = opendFiles.value(id);
    if (!fileRes || !fileRes->file.isOpen()) {
        return false;
    }
    
    QWriteLocker fileLocker(&fileRes->lock);
    if (fileRes->file.resize(0) && fileRes->file.seek(0)) {
        qint64 written = fileRes->file.write(content.toUtf8());
        return written == content.toUtf8().size();
    }
    
    return false;
}

bool LocalFileService::delFile(fileID id)
{
    QString filePath;
    
    {
        QReadLocker locker(&mapLock);
        if (!opendFiles.contains(id)) {
            return false;
        }
        
        auto fileRes = opendFiles.value(id);
        filePath = fileRes->path;
        
        if (fileRes->file.isOpen()) {
            fileRes->file.close();
        }
    }
    
    // 移除映射关系
    {
        QWriteLocker locker(&mapLock);
        opendFiles.remove(id);
    }
    
    // 删除物理文件
    return QFile::remove(filePath);
}

fileID LocalFileService::generateNewId()
{
    return ++count;
}

bool LocalFileService::isValidFileId(fileID id) const
{
    return id > 0;
}

int LocalFileService::getOpenFileCount() const
{
    QReadLocker locker(&mapLock);
    return opendFiles.size();
}

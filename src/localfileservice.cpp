#include "LocalFileService.h"
#include "I_LocalFileService.h"
#include <QDebug>

#include <QReadLocker>
#include <qfileinfo.h>
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
    : impl_lfs(std::make_unique<Lfs_impl>())
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

fileID LocalFileService::creatFile(QString path, bool withOpen)
{
    return -1;
}


bool LocalFileService::haveFile(fileID id) const
{
    QReadLocker locker(&mapLock);
    return opendFiles.contains(id);
}

fileID LocalFileService::openFile(const QString& path)
{
    if (path.isEmpty()) {
        qWarning() << "Empty file path provided";
        return -1;
    }

    // 规范化路径并检查文件存在
    QFileInfo fileInfo(path);
    if (!fileInfo.exists() || !fileInfo.isFile()) {
        qWarning() << "File does not exist or is not a regular file:" << path;
        return -1;
    }

    QString canonicalPath = fileInfo.canonicalFilePath();
    if (canonicalPath.isEmpty()) {
        qWarning() << "Failed to get canonical path for:" << path;
        return -1;
    }

   {
    QReadLocker locker(&mapLock);
    for (auto it = opendFiles.constBegin(); it != opendFiles.constEnd(); ++it) {
        fileID id = it.key();
        auto res = it.value(); // 无需解引用，直接获取shared_ptr
        if (res->path == canonicalPath) {
            qWarning() << "File already opened:" << canonicalPath;
            return id;
        }
    }
    }

    // 创建文件资源
    auto fileRes = std::make_shared<file_res>(canonicalPath);

    // 尝试打开文件
    if (!fileRes->file.open(QIODevice::ReadWrite)) {  // 移除了Text模式
        qWarning() << "Failed to open file:" << canonicalPath
                   << "Error:" << fileRes->file.errorString();
        return -1;
    }

    // 获取新ID并插入映射
    QWriteLocker locker(&mapLock);
    fileID newId = generateNewId();
    if (newId < 0) {
        qWarning() << "Failed to generate valid file ID";
        return -1;  // 文件会自动关闭
    }

    opendFiles.insert(newId, fileRes);
    qDebug() << "File opened successfully:" << canonicalPath << "ID:" << newId;

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

    bool n = opendFiles.remove(id) > 0;
    return n;
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

    if (!fileRes->file.seek(0)) {
        return QString();
    }

    QByteArray data = fileRes->file.readAll();

    if (charset.isEmpty() || charset.compare("UTF-8", Qt::CaseInsensitive) == 0) {
        return QString::fromUtf8(data);
    }

    // 使用 QStringDecoder 替代 QTextCodec
    QStringDecoder decoder = QStringDecoder(charset.toLocal8Bit().constData());
    if (!decoder.isValid()) {
        return QString();
    }

    return decoder(data);
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

int LocalFileService::closeAll(){
    std::vector<fileID> files;
    {
        QReadLocker locker(&mapLock);
        for(auto it = opendFiles.begin();it!=opendFiles.end();it++){
            files.push_back(it.key());
        }
    }
    for(auto i :files){
        this->closeFile(i);
    }
    return files.size();

}

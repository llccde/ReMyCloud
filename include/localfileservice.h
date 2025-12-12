#ifndef LOCALFILESERVICE_H
#define LOCALFILESERVICE_H

#include "ILocalFileService.h"
#include <QFile>
#include <QReadWriteLock>
#include <memory>
#include<QMap>
class LocalFileService : public ILocalFileService
{
private:
    struct file_res 
    {
        QFile file;
        QString path;
        QReadWriteLock lock;
        explicit file_res(const QString& filePath) : file(filePath), path(filePath) {}
    };
    
    using file_ptr = std::shared_ptr<file_res>;
    
    // 私有实现
    class Lfs_impl;
    std::unique_ptr<Lfs_impl> impl_lfs;
    
    QMap<fileID, file_ptr> opendFiles;
    fileID count;
    mutable QReadWriteLock mapLock;  // 保护opendFiles的访问
    
public:
    explicit LocalFileService();
    virtual ~LocalFileService();
    
    // 实现接口方法
    virtual bool haveFile(fileID id) const override;
    virtual fileID openFile(const QString& path) override;
    virtual bool closeFile(fileID id) override;
    virtual QString getFileContent(fileID id,QString charset) override;
    virtual bool writeFile(fileID id, const QString& content) override;
    virtual bool delFile(fileID id) override;
    virtual int getOpenFileCount() const override;
    

    
private:
    // 辅助方法
    fileID generateNewId();
    bool isValidFileId(fileID id) const;
};

#endif // LOCALFILESERVICE_H

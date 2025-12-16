#ifndef LOCALFILESERVICE_H
#define LOCALFILESERVICE_H

#include "I_LocalFileService.h"
#include <QFile>
#include <QReadWriteLock>
#include <memory>
#include<QMap>
class LocalFileService : public I_LocalFileService
{
private:
    struct file_res 
    {
        QFile file;
        QString path;
        explicit file_res(const QString& filePath) : file(filePath), path(filePath) {}
    };
    
    using file_ptr = std::shared_ptr<file_res>;
    
    // 私有实现
    class Lfs_impl;
    std::unique_ptr<Lfs_impl> impl_lfs;
    int count = 0;
    QMap<fileID, file_ptr> opendFiles;
    mutable QReadWriteLock mapLock;  // 保护opendFiles的访问
    

    IDMaker idMaker;
public:
    explicit LocalFileService();
    virtual ~LocalFileService();
     
    // 实现接口方法
    fileID justGenerateID() override;
    bool creatFile(QString path) override;
    bool swapFile(fileID id1, fileID id2, bool file2CanBeNull = false) override;
    virtual bool haveFile(fileID id) const override;
    virtual fileID openFile(const QString& path) override;
    virtual bool closeFile(fileID id) override;
    virtual QString getFileContent(fileID id,QString charset) override;
    virtual bool writeFile(fileID id, const QString& content) override;
    virtual bool delFile(fileID id) override;
    virtual int getOpenFileCount() const override;
    virtual int closeAll()override;

    
private:
    // 辅助方法
    fileID generateNewId();
    bool isValidFileId(fileID id) const;
};



#endif // LOCALFILESERVICE_H

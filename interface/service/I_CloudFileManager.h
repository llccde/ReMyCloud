#ifndef __I_FILEMANAGER_H__
#define __I_FILEMANAGER_H__
#include "QString"
#include "QVector"
#include <memory>
#include <QString>
#include "I_CloudFileService.h"
struct historyItem{
    using historyID = int;
    historyID id;
    QString timestamp;
    QString description;
};
class FileEntity
{
    public:
        using cloudFileID = QString;

        FileEntity();
        ~FileEntity();
        QString fileName;
        QString description;
        cloudFileID fileIdentifier;
        QVector<historyItem> historyList;
};

// 云文件管理接口
//依赖于I_CloudFileService
//不能让I_CloudFileService依赖于它
class I_CloudFileManager
{

    std::weak_ptr<I_CloudFileService> localFileService;
    public:
    inline void setLocalFileService(std::shared_ptr<I_CloudFileService> service){
        localFileService = service;
    }
    virtual bool existOnServer(const FileEntity file) = 0;
    virtual QVector<FileEntity> getAllFilesFromServer() = 0;
    virtual bool uploadFileToServer(const FileEntity file,QString localPath) = 0;

};

#endif // __I_FILEMANAGER_H__
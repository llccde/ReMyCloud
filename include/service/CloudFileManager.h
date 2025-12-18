#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

#include "I_CloudFileManager.h"
class CloudFileManager : public I_CloudFileManager
{
    virtual bool existOnServer(const FileEntity file) override;
    virtual QVector<FileEntity> getAllFilesFromServer() override;
    virtual bool uploadFileToServer(const FileEntity file,QString localPath) override;
};
#endif // __FILEMANAGER_H__
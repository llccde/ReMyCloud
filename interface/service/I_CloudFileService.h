#ifndef __I_CLOUDLFILESERVICE_H__
#define __I_CLOUDLFILESERVICE_H__
#include "QString"
#include "QVector"
#include "QJsonObject"
#include <qjsonobject.h>
#include "CloudFileID.h"
#include "TypeOfCloudFileService.h"
class I_CloudFileService
{
    protected:
        QString serviceHost;
        int servicePort;
        
        const QString loginPath = "/login";

        const QString uploadPath = "/upload";
        const QString getAllFilesPath = "/allFiles";
        const QString downloadPath = "/download";
        const QString deleteFilePath = "/delete";
        const QString renameFilePath = "/rename";

        const QString setCurrentToHistory = "/setCurrentToHistory";


        const QString getAllHistoryOfFile = "/allHistory";
        const QString downloadHistoryFilePath = "/getHistoryFile";
public:
    virtual ~I_CloudFileService();
    virtual QJsonObject getAllFiles()=0;
    virtual LoginState login(const QString username,const QString password)=0;
    virtual bool uploadFile(const QString content,const QString CloudID )=0; 
    virtual QString getFileNameByCloudID(CloudFileID id);
};

#endif // __I_CLOUDLFILESERVICE_H__
#ifndef __I_CLOUDLFILESERVICE_H__
#define __I_CLOUDLFILESERVICE_H__
#include "QString"
#include "QVector"

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
};

#endif // __I_CLOUDLFILESERVICE_H__
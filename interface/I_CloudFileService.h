#ifndef __I_CLOUDLFILESERVICE_H__
#define __I_CLOUDLFILESERVICE_H__
#include "QString"
class I_CloudFileService
{
    const QString serviceHost = "127.0.0.1";
    const int servicePort = 1234;
    const QString loginPath = "/login";

    const QString uploadPath = "/upload";
    const QString getAllFilesPath = "/allFiles";
    const QString downloadPath = "/download";
    const QString deleteFilePath = "/delete";
    const QString renameFilePath = "/rename";

    const QString getAllHistoryOfFile = "/allHistory";
    const QString downloadHistoryFilePath = "/getHistoryFile";
    

public:
    I_CloudFileService();
    ~I_CloudFileService();
};

#endif // __I_CLOUDLFILESERVICE_H__
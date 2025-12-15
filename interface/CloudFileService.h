#ifndef __CLOUDLFILESERVICE_H__
#define __CLOUDLFILESERVICE_H__
#include "QString"
class CloudFileService
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
    CloudFileService();
    ~CloudFileService();
};

#endif // __CLOUDLFILESERVICE_H__
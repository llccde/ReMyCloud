#ifndef __CLOUDFILESERVICE_H__
#define __CLOUDFILESERVICE_H__

#include "I_CloudFileService.h"

class CloudFileService : public I_CloudFileService {
public:
    inline CloudFileService(const QString& host = "127.0.0.1", const int& port = 80) {
        serviceHost = host;
        servicePort = port;
    }

    ~CloudFileService() override;

    // Implement the pure virtual methods from I_CloudFileService
    QJsonObject getAllFiles() override;
    
    LoginState login(const QString username, const QString password) override;
    
    bool uploadFile(const QString content, const QString CloudID) override;
    
    QString getFileNameByCloudID(CloudFileID id) override;
};

#endif // __CLOUDFILESERVICE_H__
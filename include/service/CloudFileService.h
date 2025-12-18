#ifndef __CLOUDFILESERVICE_H__
#define __CLOUDFILESERVICE_H__
#include "I_CloudFileService.h"
class CloudFileService: public I_CloudFileService{
public:
    inline CloudFileService(const QString& host, const int& port){
        serviceHost = host;
        servicePort = port;
    };
    ~CloudFileService() override;
};
#endif // __CLOUDFILESERVICE_H__
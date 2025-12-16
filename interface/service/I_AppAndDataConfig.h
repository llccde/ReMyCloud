#ifndef __I_APPANDDATACONFIG_H__
#define __I_APPANDDATACONFIG_H__
#include "I_LocalFileService.h"
#include <memory>
// 应用程序和数据配置接口
//依赖于I_LocalFileService
class I_AppAndDataConfig
{
    struct config{

    }; 
    config appConfig;
    std::weak_ptr<I_LocalFileService> localFileService;
public:
    inline void setLocalFileService(std::shared_ptr<I_LocalFileService> service){
        localFileService = service;
    }
    virtual ~I_AppAndDataConfig() = default;
    
};
#endif // __I_APPANDDATACONFIG_H__
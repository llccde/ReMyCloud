#ifndef __I_APPCONFIGANDDATALOADER_H__
#define __I_APPCONFIGANDDATALOADER_H__
#include "memory"
#include "BaseService.h"
class DataConfig;

class I_DataConfigLoader:public BaeService 
{
protected:
    
public:
    virtual std::shared_ptr<DataConfig> loadConfig() = 0;
    ~I_DataConfigLoader() = default;
};

#endif // __I_APPCONFIGANDDATALOADER_H__
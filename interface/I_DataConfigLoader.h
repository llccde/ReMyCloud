#ifndef __I_APPCONFIGANDDATALOADER_H__
#define __I_APPCONFIGANDDATALOADER_H__
#include "memory"
class DataConfig;

class I_DataConfigLoader
{
public:
    virtual std::shared_ptr<DataConfig> loadConfig() = 0;
    virtual inline ~I_DataConfigLoader() = default;
};

#endif // __I_APPCONFIGANDDATALOADER_H__
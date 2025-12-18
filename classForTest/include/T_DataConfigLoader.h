#ifndef __T_DATACONFIGLOADER_H__
#define __T_DATACONFIGLOADER_H__
#include "I_DataConfigLoader.h"
#include <cstddef>
#include <memory>
class T_DataConfigLoader:public I_DataConfigLoader{
    private:
        bool hasLoad = false;
        std::shared_ptr<DataConfig> config = nullptr;
    public:
        std::shared_ptr<DataConfig> loadConfig() override;
    
};
#endif // __T_DATACONFIGLOADER_H__
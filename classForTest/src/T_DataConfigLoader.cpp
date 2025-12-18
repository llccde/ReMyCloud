#include "ConstAppConfig.h"
#include "T_DataConfigLoader.h"
std::shared_ptr<DataConfig> T_DataConfigLoader::loadConfig(){
    if (this->hasLoad) {
        return this->config;
    }
    else {
        QString path = ConstAppConfig::getConfigFilePath();
    }
}
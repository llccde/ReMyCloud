#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
#include "QString"
#include "memory"
#include <_mingw_stat64.h>
#include <memory>
class ConstAppConfig{
    protected:
        static std::shared_ptr<ConstAppConfig> appConfig;
    public:
        static inline std::shared_ptr<ConstAppConfig> getInstance(){
            return appConfig;
        }
        inline ConstAppConfig(){

        };
        const inline static QString getConfigFilePath(){
            return "E:/qt/ReMyCloud/config/appConfig.json";
        };

};
#endif // __APPCONFIG_H__
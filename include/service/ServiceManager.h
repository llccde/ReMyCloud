#ifndef __SERVICEMANAGER_H__
#define __SERVICEMANAGER_H__
#include"I_ServiceManager.h"
#include"Checkable.h"
class ServiceManager:public Checkable,public I_ServiceManager{
    public:
        inline void initializeServices() override{
            return;
        }
        inline bool checkOK() override{
            return localFileService != nullptr &&
                   cloudFileService != nullptr &&
                   fileMapping != nullptr &&
                   appAndDataConfig != nullptr &&
                   readmeToHtml != nullptr &&
                   readmeHighlight != nullptr;
        }
        inline ~ServiceManager(){}
};
#endif // __SERVICEMANAGER_H__
#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H
#include "I_LocalFileService.h"
#include "I_CloudFileService.h"
#include "I_CloudFileManager.h"
#include "I_FileMapping.h"
#include "I_AppAndDataConfig.h"
#include "I_ReadmeToHtml.h"
#include "I_ReadmeHighlight.h"
class ServiceManager{
public:
    std::shared_ptr<I_LocalFileService> localFileService = nullptr;
    std::shared_ptr<I_CloudFileService> cloudFileService = nullptr;
    std::shared_ptr<I_CloudFileManager> cloudFileManager = nullptr;
    std::shared_ptr<I_FileMapping> fileMapping = nullptr;
    std::shared_ptr<I_AppAndDataConfig> appAndDataConfig = nullptr;
    std::shared_ptr<I_ReadmeToHtml> readmeToHtml = nullptr;
    std::shared_ptr<I_ReadmeHighlight> readmeHighlight = nullptr;
    virtual void initializeServices();
    virtual ~ServiceManager();
};
#endif // SERVICEMANAGER_H

#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H
#include <memory>
class I_LocalFileService;
class I_CloudFileService;
class I_CloudFileManager;
class I_FileMapping;
class I_AppAndDataConfig;
class I_ReadmeToHtml;
class I_ReadmeHighlight;

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

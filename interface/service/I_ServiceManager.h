#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H
#include <memory>
#include <stdexcept>

class I_LocalFileService;
class I_CloudFileService;
class I_FileMapping;
class I_AppAndDataConfig;
class I_ReadmeToHtml;
class I_ReadmeHighlight;
class I_DataConfigLoader;
class I_ServiceManager{
protected:
    std::shared_ptr<I_LocalFileService> localFileService = nullptr;
    std::shared_ptr<I_CloudFileService> cloudFileService = nullptr;
    std::shared_ptr<I_FileMapping> fileMapping = nullptr;
    std::shared_ptr<I_AppAndDataConfig> appAndDataConfig = nullptr;
    std::shared_ptr<I_ReadmeToHtml> readmeToHtml = nullptr;
    std::shared_ptr<I_ReadmeHighlight> readmeHighlight = nullptr;
    std::shared_ptr<I_DataConfigLoader> dataConfigLoader = nullptr;


public:

    inline std::shared_ptr<I_LocalFileService> getLocalFileService() const {
        if (!localFileService) {
            throw std::runtime_error("LocalFileService is null");
        }
        return localFileService;
    }
    inline std::shared_ptr<I_CloudFileService> getCloudFileService() const {
        if (!cloudFileService) {
            throw std::runtime_error("CloudFileService is null");
        }
        return cloudFileService;
    }

    inline std::shared_ptr<I_FileMapping> getFileMapping() const {
        if (!fileMapping) {
            throw std::runtime_error("FileMapping is null");
        }
        return fileMapping;
    }

    inline std::shared_ptr<I_AppAndDataConfig> getAppAndDataConfig() const {
        if (!appAndDataConfig) {
            throw std::runtime_error("AppAndDataConfig is null");
        }
        return appAndDataConfig;
    }

    inline std::shared_ptr<I_ReadmeToHtml> getReadmeToHtml() const {
        if (!readmeToHtml) {
            throw std::runtime_error("ReadmeToHtml is null");
        }
        return readmeToHtml;
    }

    inline std::shared_ptr<I_ReadmeHighlight> getReadmeHighlight() const {
        if (!readmeHighlight) {
            throw std::runtime_error("ReadmeHighlight is null");
        }
        return readmeHighlight;
    }

    inline std::shared_ptr<I_DataConfigLoader> getDataConfigLoader() const {
        if (!dataConfigLoader) {
            throw std::runtime_error("DataConfigLoader is null");
        }
        return dataConfigLoader;
    }
    inline void setLocalFileService(std::shared_ptr<I_LocalFileService> service) {
        if (!service) {
            throw std::invalid_argument("LocalFileService cannot be null");
        }
        localFileService = service;
    }

    inline void setCloudFileService(std::shared_ptr<I_CloudFileService> service) {
        if (!service) {
            throw std::invalid_argument("CloudFileService cannot be null");
        }
        cloudFileService = service;
    }

    inline void setFileMapping(std::shared_ptr<I_FileMapping> service) {
        if (!service) {
            throw std::invalid_argument("FileMapping cannot be null");
        }
        fileMapping = service;
    }

    inline void setAppAndDataConfig(std::shared_ptr<I_AppAndDataConfig> service) {
        if (!service) {
            throw std::invalid_argument("AppAndDataConfig cannot be null");
        }
        appAndDataConfig = service;
    }

    inline void setReadmeToHtml(std::shared_ptr<I_ReadmeToHtml> service) {
        if (!service) {
            throw std::invalid_argument("ReadmeToHtml cannot be null");
        }
        readmeToHtml = service;
    }

    inline void setReadmeHighlight(std::shared_ptr<I_ReadmeHighlight> service) {
        if (!service) {
            throw std::invalid_argument("ReadmeHighlight cannot be null");
        }
        readmeHighlight = service;
    }

    inline void setDataConfigLoader(std::shared_ptr<I_DataConfigLoader> service) {
        if (!service) {
            throw std::invalid_argument("DataConfigLoader cannot be null");
        }
        dataConfigLoader = service;
    }

    virtual void initializeServices() = 0;

};
#endif // SERVICEMANAGER_H

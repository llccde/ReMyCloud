#ifndef __I_FILEMAPPING_H__
#define __I_FILEMAPPING_H__
#include <memory>
#include "QString"
#include "Checkable.h"
class I_LocalFileService;
class I_CloudFileManager;
class I_DataConfigLoader;
//文件映射接口
//负责管理与记录本地文件与云端文件的映射关系,以及提供安全的映射变更操作.
class RMCRelation{
public:
    QString theName;
    QString localPath;
    QString cloudPath;
    inline RMCRelation(const QString& local,const QString& cloud):localPath(local),cloudPath(cloud){}
    virtual ~RMCRelation()=default;
};
class I_FileMapping :public Checkable
{
protected:

    std::weak_ptr<I_LocalFileService> localFileService;
    std::weak_ptr<I_CloudFileManager> cloudFileManager;
    std::weak_ptr<I_DataConfigLoader> configLoader;
public:
    inline bool checkOK() override{
        auto localPtr = localFileService.lock();
        auto cloudPtr = cloudFileManager.lock();
        auto configPtr = configLoader.lock();
        return localPtr && cloudPtr && configPtr;
    }
    inline void setConfigLoader(std::shared_ptr<I_DataConfigLoader> loader){
        configLoader = loader;
    }
    inline void setLocalFileService(std::shared_ptr<I_LocalFileService> service){
        localFileService = service;
    }
    inline void setCloudFileManager(std::shared_ptr<I_CloudFileManager> manager){
        cloudFileManager = manager;
    }
    virtual void initMappingsFromConfig()=0;
    virtual ~I_FileMapping() = default;
};
#endif // __I_FILEMAPPING_H__
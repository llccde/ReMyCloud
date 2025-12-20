#ifndef __I_FILEMAPPING_H__
#define __I_FILEMAPPING_H__
#include <memory>
#include <qcontainerfwd.h>
#include "QString"
#include "Checkable.h"
#include "Qvector"
#include "CloudFileID.h"
#include "QWeakPointer"
#include "FileID.h"
class I_LocalFileService;
class I_DataConfigLoader;
class I_CloudFileService;

struct historyItem{
    using historyID = int;
    historyID id;
    QString timestamp;
    QString description;
};
//文件映射接口
//负责管理与记录本地文件与云端文件的映射关系,以及提供安全的映射变更操作.
class RMCRelation{
public:
    RMCFileID mainId;
    QString theName;
    
    bool inLocal;
    bool isLocalLatest;

    QString localPath;
    fileID localFileID;
    
    virtual ~RMCRelation()=default;
};
class I_FileMapping :public Checkable
{
protected:

    std::weak_ptr<I_LocalFileService> localFileService;
    std::weak_ptr<I_DataConfigLoader> configLoader;
public:
    inline bool checkOK() override{
        auto localPtr = localFileService.lock();
        auto configPtr = configLoader.lock();
        return localPtr && configPtr;
    }
    inline void setConfigLoader(std::shared_ptr<I_DataConfigLoader> loader){
        configLoader = loader;
    }
    inline void setLocalFileService(std::shared_ptr<I_LocalFileService> service){
        localFileService = service;
    }
    virtual void initMappingsFromConfig()=0;
    virtual ~I_FileMapping() = default;
    virtual QVector<RMCRelation> getAllFile();
    virtual RMCRelation getRMCFile(RMCFileID id);
    virtual RMCRelation newRMCFile();
};
#endif // __I_FILEMAPPING_H__
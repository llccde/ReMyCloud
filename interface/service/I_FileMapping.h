#ifndef __I_FILEMAPPING_H__
#define __I_FILEMAPPING_H__
#include "I_LocalFileService.h"
#include "I_CloudFileManager.h"
//负责管理与记录本地文件与云端文件的映射关系,以及提供安全的映射变更操作.
class I_FileMapping
{
    std::weak_ptr<I_LocalFileService> localFileService;
    std::weak_ptr<I_CloudFileManager> cloudFileManager;
public:
    inline void setLocalFileService(std::shared_ptr<I_LocalFileService> service){
        localFileService = service;
    }
    inline void setCloudFileManager(std::shared_ptr<I_CloudFileManager> manager){
        cloudFileManager = manager;
    }
    virtual ~I_FileMapping() = default;
};
#endif // __I_FILEMAPPING_H__
#ifndef __I_FILEMAPPING_H__
#define __I_FILEMAPPING_H__
#include <memory>
#include <qcontainerfwd.h>
#include "BaseService.h"
#include "QString"
#include "Checkable.h"
#include "Qvector"
#include "CloudFileID.h"
#include "QWeakPointer"
#include "FileID.h"
#include "RMCRelation.h"
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

class I_FileMapping :public BaeService
{
protected:

public:
    virtual void initMappingsFromConfig()=0;
    inline ~I_FileMapping(){};
    //select *
    virtual QVector<RMCRelation> getAllFileRMCRelation() = 0;
    // select by id
    virtual RMCRelation getRMCFile(RMCRuntimeFileID id) = 0;
    //select by localPath if exist in local
    virtual RMCRelation getRMCFileByLocalPath(QString path) = 0;
    //add new one
    virtual RMCRelation newRMCFile() = 0;
};
#endif // __I_FILEMAPPING_H__
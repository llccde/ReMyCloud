#ifndef __RMCRELATION_H__
#define __RMCRELATION_H__
#include "FileID.h"
#include "CloudFileID.h"
class RMCRelation{
public:
    RMCRuntimeFileID runtimeId = "";
    QString theName;
    
    bool inLocal;
    bool onlyLocal;
    bool isLocalLatest;
    CloudFileID cloudFileId;
    QString localPath;
    fileID localFileID;
    inline bool available(){
        return runtimeId.available();
    }
    inline ~RMCRelation()=default;
};
#endif // __RMCRELATION_H__
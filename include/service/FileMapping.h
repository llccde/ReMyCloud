#ifndef __FILEMAPPING_H__
#define __FILEMAPPING_H__
#include "CloudFileID.h"
#include "I_FileMapping.h"
#include "Qvector"
#include <qcontainerfwd.h>
#include <qreadwritelock.h>
#include "QReadWriteLock"
class FileMapping:public I_FileMapping{
    QReadWriteLock mapLock;
    QVector<RMCRelation> mappings;

    public:
    inline FileMapping(){};
    void initMappingsFromConfig() override;
    inline ~FileMapping(){};
    RMCRelation getRMCFile(RMCRuntimeFileID id) override;
    RMCRelation getRMCFileByLocalPath(QString path) override;
    RMCRelation newRMCFile() override;
    inline bool changeName(RMCRuntimeFileID id,QString newName){
        QWriteLocker L(&mapLock);
        for (int i=0;i!=mappings.size();i++) {
            if(mappings[i].runtimeId == id){
                mappings[i].theName = newName;
                return true;
            }
        }
        return false;
    };
    QVector<RMCRelation> getAllFileRMCRelation() override;
};
#endif // __FILEMAPPING_H__
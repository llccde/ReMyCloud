#ifndef __I_BACKEND_H__
#define __I_BACKEND_H__
#include "QWeakPointer"
#include "QSharedPointer"
#include <qarraydatapointer.h>
#include <qcontainerfwd.h>
#include <qobject.h>
#include "CloudFileID.h"
#include "MdHighLight.h"
#include "MdHTML.h"
class I_AsyncLuncher;
class I_ServiceManager;
class I_Backend{
protected:
    QSharedPointer<I_AsyncLuncher> asyncLuncher;
    QSharedPointer<I_ServiceManager> serviceManager;
    
public:
    virtual ~I_Backend() = default;
    inline void setAsyncLauncher(QSharedPointer<I_AsyncLuncher> al){
        this->asyncLuncher = al;
    };
    inline void setServiceManager(QSharedPointer<I_ServiceManager> sm){
        this->serviceManager = sm;
    }
    virtual void saveCloudFileFully(CloudFileID id) = 0;
    virtual void saveCloudOnlyLocal(CloudFileID id) = 0;
    virtual void writeCloudFile(CloudFileID id,QString content) = 0;
    virtual QString readCloudFileOnBuffer(CloudFileID id);
    virtual MdHighLight getCloudHighLight(CloudFileID id) = 0;
    virtual MdHtml getPreview(CloudFileID) = 0;
};

#endif // __I_BACKEND_H__
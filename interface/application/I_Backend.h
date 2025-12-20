#ifndef __I_BACKEND_H__
#define __I_BACKEND_H__
#include "QWeakPointer"
#include "QSharedPointer"
#include <memory>
#include <qarraydatapointer.h>
#include <qcontainerfwd.h>
#include <qobject.h>
#include <stdexcept>
#include "CloudFileID.h"
#include "MdHighLight.h"
#include "MdHTML.h"
#include "Checkable.h"
class I_AsyncLuncher;
class I_ServiceManager;
class I_Backend :public Checkable{
protected:
    std::shared_ptr<I_AsyncLuncher> asyncLuncher;
    std::shared_ptr<I_ServiceManager> serviceManager;

public:
    inline ~I_Backend() = default;




    virtual void saveCloudFileFully(RMCFileID id) = 0;
    virtual void saveCloudOnlyLocal(RMCFileID id) = 0;
    virtual void writeCloudFile(RMCFileID id,QString content) = 0;
    virtual QString readCloudFileOnBuffer(RMCFileID id) = 0;
    virtual MdHighLight getCloudHighLight(RMCFileID id) = 0;
    virtual MdHtml getPreview(RMCFileID) = 0;




    inline std::shared_ptr<I_AsyncLuncher> getAsyncLuncher() const {
        if (!asyncLuncher) {
            throw std::runtime_error("AsyncLuncher is null");
        }
        return asyncLuncher;
    }

    inline std::shared_ptr<I_ServiceManager> getServiceManager() const {
        if (!serviceManager) {
            throw std::runtime_error("ServiceManager is null");
        }
        return serviceManager;
    }
    inline void setAsyncLauncher(std::shared_ptr<I_AsyncLuncher> al) {
        if (!al) {
            throw std::invalid_argument("AsyncLuncher cannot be null");
        }
        this->asyncLuncher = al;
    };
    inline void setServiceManager(std::shared_ptr<I_ServiceManager> sm) {
        if (!sm) {
            throw std::invalid_argument("ServiceManager cannot be null");
        }
        this->serviceManager = sm;
    }

    inline bool checkOK() override{
        if(asyncLuncher&&serviceManager){
            return true;
        }else {
            error("backend not fully init");
            return false;
        }
    }
};

#endif // __I_BACKEND_H__
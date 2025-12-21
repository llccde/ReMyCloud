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
class I_ServiceManager;
class I_Backend :public Checkable{
protected:
    std::shared_ptr<I_ServiceManager> serviceManager = nullptr;

public:
    inline ~I_Backend() = default;




    virtual void saveCloudFileFully(RMCRuntimeFileID id) = 0;
    virtual void saveOnlyLocal(RMCRuntimeFileID id) = 0;
    virtual RMCRuntimeFileID loadFileFromLocal(QString path) = 0;
    virtual void writeCloudFileBuffer(RMCRuntimeFileID id,QString content) = 0;
    virtual QString readCloudFileOnBuffer(RMCRuntimeFileID id) = 0;
    virtual MdHighLight getCloudHighLight(RMCRuntimeFileID id) = 0;
    virtual MdHtml getPreview(RMCRuntimeFileID) = 0;



    inline std::shared_ptr<I_ServiceManager> getServiceManager() const {
        if (!serviceManager) {
            throw std::runtime_error("ServiceManager is null");
        }
        return serviceManager;
    }

    inline void setServiceManager(std::shared_ptr<I_ServiceManager> sm) {
        if (!sm) {
            throw std::invalid_argument("ServiceManager cannot be null");
        }
        this->serviceManager = sm;
    }

    inline bool checkOK() override{
        return serviceManager.get()!=nullptr;
    }
};

#endif // __I_BACKEND_H__
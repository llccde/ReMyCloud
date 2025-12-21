#include "Inject.h"
#include "LocalFileService.h"
#include "Singletons.h"
#include "Backend.h"
#include <memory>
#include <qobject.h>
#include "T_QmlAdapter.h"
#include "AsyncLauncher.h"
#include "ServiceManager.h"
#include "T_DataConfigLoader.h"
#include "FileMapping.h"
#include "AsyncLauncher.h"
void Inject::DoInject(){
    auto sit = this->singletons.lock();
    if(sit){
        sit->setBackend(QSharedPointer<Backend>(new Backend()));
        sit->setQmlAdapter(QSharedPointer<T_QmlAdapter>(new T_QmlAdapter()));
        sit->initDone();
    }
    auto backend = sit->getBackend();
    std::shared_ptr<ServiceManager> SM(new ServiceManager());
    std::shared_ptr<AsyncLauncher> AL(new AsyncLauncher()); 
    if(backend){
        backend->setServiceManager(SM);
    }
    backend->checkOK();
    SM->setLocalFileService(std::shared_ptr<I_LocalFileService>(new LocalFileService()));
    SM->setDataConfigLoader(std::shared_ptr<I_DataConfigLoader>(new T_DataConfigLoader()));
    SM->setFileMapping(std::shared_ptr<I_FileMapping>(new FileMapping()));
    SM->setAsyncLauncher(std::shared_ptr<I_AsyncLuncher>(new AsyncLauncher()));
    
    SM->getLocalFileService()->setServices(SM);
    SM->getFileMapping()->setServices(SM);
    SM->getDataConfigLoader()->setServices(SM);
}
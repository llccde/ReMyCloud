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
        backend->setAsyncLauncher(AL);
    }
    backend->checkOK();
    SM->setLocalFileService(std::shared_ptr<I_LocalFileService>(new LocalFileService()));
    SM->setDataConfigLoader(std::shared_ptr<I_DataConfigLoader>(new T_DataConfigLoader()));
    SM->getDataConfigLoader()->setServices(SM);
}
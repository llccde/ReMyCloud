#include "Inject.h"
#include "Singletons.h"
#include "Backend.h"
#include <memory>
#include <qobject.h>
#include "T_QmlAdapter.h"
void Inject::DoInject(){
    auto sit = this->singletons.lock();
    if(sit){
        sit->setBackend(QSharedPointer<Backend>(new Backend()));
        sit->setQmlAdapter(QSharedPointer<T_QmlAdapter>(new T_QmlAdapter()));
        sit->initDone();
    }
    
}
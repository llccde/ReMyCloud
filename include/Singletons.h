#ifndef __SINGLETONS_H__
#define __SINGLETONS_H__
#include <QtQml/qqml.h>
#include "QSharedPointer"
#include "QweakPointer"
#include "application/I_Inject.h"
#include <stdexcept>
class I_Backend;
class I_QmlAdapter;
class I_Inject;
class Singletons{
    friend class I_Inject;
    bool InjectDone = false;
protected:
    QSharedPointer<I_QmlAdapter> qmlAdapter;
    QSharedPointer<I_Backend> backend;
    static QSharedPointer<Singletons> instance;
    
public:
    static inline QSharedPointer<Singletons> Instance(){
        return instance;
    }
    void static init();
    Singletons();
    ~Singletons();
    
    inline QSharedPointer<I_Backend> getBackend(){
        if(backend.isNull()) {
            throw std::runtime_error("Backend pointer is null");
        }
        return backend;
    }
    inline QSharedPointer<I_QmlAdapter> getQmlAdapterInstance(){
        if(qmlAdapter.isNull()) {
            throw std::runtime_error("QmlAdapter pointer is null");
        }
        return qmlAdapter;
    }

    inline void setBackend(QSharedPointer<I_Backend> backendPtr) {
        if(InjectDone){
            throw std::runtime_error("cant set any singletons after init");
        }
        if(backendPtr.isNull()) {
            throw std::runtime_error("Cannot set null Backend pointer");
        }
        this->backend = backendPtr;
    }

    inline void setQmlAdapter(QSharedPointer<I_QmlAdapter> qmlAdapterPtr) {
        if(InjectDone){
            throw std::runtime_error("cant set any singletons after init");
        }
        if(qmlAdapterPtr.isNull()) {
            throw std::runtime_error("Cannot set null QmlAdapter pointer");
        }
        this->qmlAdapter = qmlAdapterPtr;
    }
    
    inline void initDone(){
        this->InjectDone = true;
    }


};
#endif // __SINGLETONS_H__
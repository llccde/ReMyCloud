#ifndef __SINGLETONS_H__
#define __SINGLETONS_H__
#include <QtQml/qqml.h>
#include <_mingw_stat64.h>
#include "QSharedPointer"
#include "QweakPointer"
class I_QmlAdapter;
class Singletons{
    QSharedPointer<I_QmlAdapter> qmlAdapter;
    static QSharedPointer<Singletons> instance;
    
public:
    static inline QSharedPointer<Singletons> Instance(){
        return instance;
    }
    void static init();
    Singletons();
    ~Singletons();
    inline QSharedPointer<I_QmlAdapter> getQmlAdapterInstance(){
        return qmlAdapter;
    }

};
#endif // __SINGLETONS_H__
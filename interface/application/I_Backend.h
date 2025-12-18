#ifndef __I_BACKEND_H__
#define __I_BACKEND_H__
#include "QWeakPointer"
#include "QSharedPointer"
#include <qarraydatapointer.h>
#include <qobject.h>
class I_AsyncLuncher;
class I_ServiceManager;
class I_Backend{
protected:
    QSharedPointer<I_AsyncLuncher> asyncLuncher;
    QSharedPointer<I_ServiceManager> serviceManager;
    
public:
    virtual ~I_Backend() = default;

};

#endif // __I_BACKEND_H__
#ifndef __I_BACKEND_H__
#define __I_BACKEND_H__
#include "I_AsyncLuncher.h"
#include "QWeakPointer"
#include "QSharedPointer"
#include <qarraydatapointer.h>
#include <qobject.h>
class UIData{
public:
    virtual ~UIData() = default;
    virtual void initialize();
};
class I_Backend{
protected:
    QSharedPointer<UIData> uiData;
    QArrayDataPointer<I_AsyncLuncher> asyncLuncher;
public:
    virtual ~I_Backend() = default;

};

#endif // __I_BACKEND_H__
#ifndef __I_BACEND_H__
#define __I_BACEND_H__
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
class I_Backend : QObject{
    Q_OBJECT
protected:
    QSharedPointer<UIData> uiData;
    QArrayDataPointer<I_AsyncLuncher> asyncLuncher;
public:
    virtual ~I_Backend() = default;

};

#endif // __I_BACEND_H__
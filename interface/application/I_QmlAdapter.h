#ifndef _I_QMLADAPTER_H
#define _I_QMLADAPTER_H
#include "qobject.h"
#include "QVector"
#include <qtmetamacros.h>
class I_QmlIAdapter:public QObject{
    public:
        Q_OBJECT
        Q_PROPERTY(QVector<QString> testList READ getTestList CONSTANT)
    public:
    virtual QVector<QString> getTestList() const = 0;
    I_QmlIAdapter();
    ~I_QmlIAdapter();
};
#endif // ADAPTER_H

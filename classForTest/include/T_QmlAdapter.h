#ifndef __T_QMLADAPTER_H__
#define __T_QMLADAPTER_H__
#include "I_QmlAdapter.h"
#include <qcontainerfwd.h>
#include <qobject.h>
#include <qtmetamacros.h>
class T_QmlAdapter:public I_QmlAdapter{
    Q_OBJECT
    QString hello = "Hello from T_QmlAdapter";
public:
    inline T_QmlAdapter(QObject* parent=nullptr):I_QmlAdapter(parent){};
    inline ~T_QmlAdapter() override{};

    inline QString getHello() override{
        return hello;
    }
    Q_INVOKABLE inline void setHello(const QString &hello) override{
        this->hello = hello;
        emit helloChanged();
    }
};

#endif // __T_QMLADAPTER_H__
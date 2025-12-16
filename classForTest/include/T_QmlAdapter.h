#ifndef __T_QMLADAPTER_H__
#define __T_QMLADAPTER_H__
#include "I_QmlAdapter.h"
class T_QmlAdapter:I_QmlIAdapter{

    Q_OBJECT
public:
    QVector<QString> getTestList() const override;
    T_QmlAdapter();
    ~T_QmlAdapter() override;
};

#endif // __T_QMLADAPTER_H__
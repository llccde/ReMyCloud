#ifndef _I_QMLADAPTER_H
#define _I_QMLADAPTER_H
#include "qobject.h"
#include "QVector"
#include "QString"
#include <csignal>
#include <qtmetamacros.h>
struct MappingFile{
    QString localPath;
    QString cloudPath;
};
class I_QmlAdapter:public QObject{
    public:
        Q_OBJECT
        Q_PROPERTY(QString hello READ getHello NOTIFY helloChanged)
    public:
        virtual QString getHello() = 0;
        Q_INVOKABLE virtual void setHello(const QString& hello) = 0;
            inline explicit I_QmlAdapter(QObject* parent=nullptr):QObject(parent){
        };

    inline ~I_QmlAdapter(){
        return;
    };
    signals:
        void helloChanged();
    public slots:
     
};
#endif // ADAPTER_H

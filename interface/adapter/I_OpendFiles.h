#ifndef __I_OPENDFILES_H__
#define __I_OPENDFILES_H__
#include "QAbstractListModel"
#include <qabstractitemmodel.h>
#include <qobject.h>
#include <qtmetamacros.h>
class I_OpendFiles:public QObject{
    Q_OBJECT
    public:
        Q_INVOKABLE virtual bool openFile(const QString& path)=0;
        Q_INVOKABLE virtual bool closeFile(const QString& path)=0;
        Q_INVOKABLE virtual bool isFileOpened(const QString& path)=0;
        Q_INVOKABLE virtual QStringList openFiles() const =0;
    public:
        inline explicit I_OpendFiles(QObject* parent=nullptr):QObject(parent){
        };
    inline ~I_OpendFiles(){
        return;
    };

};

#endif // __I_OPENDFILES_H__
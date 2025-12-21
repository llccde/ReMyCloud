#ifndef __CLOUDFILEID_H__
#define __CLOUDFILEID_H__
#include "ConstAppConfig.h"
#include "QString"
#include <qcontainerfwd.h>
#include <qdatetime.h>
#include <qmutex.h>
#include <qreadwritelock.h>
#include "QDateTime"
#include "QMutex"
#include "QReadWriteLock"
#include "QWriteLocker"
class RMCRuntimeFileID{
    
    static QString lastTime;
    static int countInSameTime;
    static QReadWriteLock lock;
    public:
    QString ID;
    inline static RMCRuntimeFileID unAvailable(){
        RMCRuntimeFileID id("");
        return id;
    }
    inline bool available(){
        return ID.length()>0;
    };
    inline QString toString(){
        return ID;
    };
    inline RMCRuntimeFileID(QString id){
        this->ID = id;
    }
    inline RMCRuntimeFileID(const char* id){
        this->ID = id;
    }
    inline bool operator==(const RMCRuntimeFileID& b){
        return this->ID==b.ID;
    }
    inline static RMCRuntimeFileID genNew(){
        QString id = "TimeAt"+QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch());
        QWriteLocker l(&RMCRuntimeFileID::lock);
        
        if(id == lastTime){
            countInSameTime++;
            id+=("-IndexOf"+QString::number(countInSameTime));   
        }
        else {
            countInSameTime=0;
        }
        return id;
    }
};
using CloudFileID = QString;
#endif // __CLOUDFILEID_H__

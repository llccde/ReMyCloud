#ifndef __BASESERVICE_H__
#define __BASESERVICE_H__
#include "I_ServiceManager.h"
#include <memory>
#include "Checkable.h"
#include "QString"
class I_ServiceManager;
class BaeService:public Checkable{
    protected:
    QString nullServiceManagerMessage = QString("base service has null serviceManager ptr");
    std::weak_ptr<I_ServiceManager> services;
    public:
    inline void setServices(std::shared_ptr<I_ServiceManager> services){
        if(services){
            this->services = services;
        }
    };

    inline bool checkOK() override{
        if(!services.lock()){
            error(nullServiceManagerMessage.toUtf8().constData());
            return 0;
        };
        return 1;
    };
};

#endif // __BASESERVICE_H__
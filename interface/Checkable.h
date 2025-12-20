#ifndef __CHECKABLE_H__
#define __CHECKABLE_H__
#include "stdexcpt.h"
#include <stdexcept>
#include <string>
class NotOkError:public std::runtime_error{
    public:
        inline NotOkError(const char* e):std::runtime_error(e){

        }
};
class Checkable{
public:
    virtual bool checkOK() =0;
    inline void error(const char* error){
        throw NotOkError(error);
        return;
    }; 
    virtual inline ~Checkable()=default;
};

#endif // __CHECKABLE_H__
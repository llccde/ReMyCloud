#ifndef __CHECKABLE_H__
#define __CHECKABLE_H__
class Checkable{
public:
    virtual bool checkOK()=0;
    virtual inline ~Checkable()=default;
};

#endif // __CHECKABLE_H__
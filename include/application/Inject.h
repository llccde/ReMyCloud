#ifndef __INJECT_H__
#define __INJECT_H__
#include "I_Inject.h"
class Inject:public I_Inject{
    public:
        void DoInject() override;
};

#endif // __INJECT_H__
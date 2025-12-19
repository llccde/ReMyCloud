#ifndef __I_INJECT_H__
#define __I_INJECT_H__

#include "QWeakPointer"
#include <qobject.h>
class Singletons;
class I_Inject{
    protected:
    QWeakPointer<Singletons> singletons;
    public:
        inline void setSingletons(QWeakPointer<Singletons> sit){
            this->singletons = sit;
        }
        virtual void DoInject() = 0;
};

#endif // __I_INJECT_H__
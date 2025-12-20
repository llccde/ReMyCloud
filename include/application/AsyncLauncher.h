#ifndef __ASYNCLAUNCHER_H__
#define __ASYNCLAUNCHER_H__
#include "I_AsyncLuncher.h"
class AsyncLauncher:public I_AsyncLuncher{
    public:
        inline void launchAsyncTask(const std::function<void ()> &task) override{

        };
};

#endif // __ASYNCLAUNCHER_H__
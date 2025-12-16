#ifndef __I_ASYNCLUNCHER_H__
#define __I_ASYNCLUNCHER_H__
// 异步任务启动器接口
// 负责管理和启动异步任务
#include <functional>
class I_AsyncLuncher
{
public:
    virtual void launchAsyncTask(const std::function<void()>& task) = 0;
    virtual ~I_AsyncLuncher() = default;
};

#endif // __I_ASYNCLUNCHER_H__
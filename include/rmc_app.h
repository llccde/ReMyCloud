#ifndef GLOBAL_H
#define GLOBAL_H
#include"memory"
#include"localFileService.h"
namespace rmc {
template<class T>
using ptr = std::shared_ptr<T>;

ptr<LocalFileService<int>> localFile = nullptr;



}

#endif // GLOBAL_H

#ifndef __FILEENTITYPROX_H__
#define __FILEENTITYPROX_H__
#include "I_CloudFileService.h"
#include "memory"
#include <memory>
class FileEntityProxFactory;
class FileEntityProx
{
    friend class FileEntityProxFactory;
    std::weak_ptr<I_CloudFileService> cloudService;
    public:
        FileEntityProx();
        ~FileEntityProx();
};
class FileEntityProxFactory{
    std::weak_ptr<I_CloudFileService> instance;
    public:
        inline FileEntityProxFactory( std::shared_ptr<I_CloudFileService> inst):instance(inst){
        };
        ~FileEntityProxFactory();
        inline FileEntityProx createFileEntityProx(){
            FileEntityProx prox;
            prox.cloudService = instance;
            return prox;
        };
};

#endif // __FILEENTITYPROX_H__
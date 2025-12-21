#include "FileMapping.h"
#include "CloudFileID.h"
#include "FileID.h"
#include "DataConfig.h"
#include "QDateTime"
#include "RMCRelation.h"
#include <qbytearrayview.h>
#include <qdatetime.h>
#include <qdebug.h>
#include "I_DataConfigLoader.h"
#include "I_ServiceManager.h"
#include "I_AsyncLuncher.h"
#include "CloudFileService.h"

static bool available(QString& str){
    return str.length()>0;
}
void FileMapping::initMappingsFromConfig(){
    auto localConfig = services.lock()->getDataConfigLoader()->loadConfig();
    if(localConfig){
        RMCRelation rela;
        //初始化ID,LocalFileID需要在实际访问的时候再初始化
        rela.runtimeId = RMCRuntimeFileID::genNew();
        rela.localFileID = fileID::unValid();
        for (auto i: localConfig->files) {
            //如果有存储在本地的话
            bool inLocal = available(i.localPath);
            bool inCloud = available(i.cloudId);
            if(inLocal){
                rela.localPath = i.localPath;
                rela.inLocal = true;
                //获取文件名
                if(i.localPath.contains("\\")){
                    rela.theName = i.localPath.split("\\").last();
                }else if(i.localPath.contains("/")){
                    rela.theName = i.localPath.split("/").last();
                }else {
                    rela.theName = i.localPath;
                }
            }else {
                //否则
                rela.inLocal = false;
                rela.onlyLocal = false;
            }
            //如果有云端的ID的话
            if(inCloud){
                rela.onlyLocal = false;
                rela.cloudFileId = i.cloudId;
                //为了获取文件名方便各种地方显示
                if(!rela.inLocal){
                    auto al = services.lock()->getAsyncLuncher();
                    al->launchAsyncTask([=](){
                        auto cfs = services.lock()->getCloudFileService();
                        auto name = cfs->getFileNameByCloudID("");
                        changeName(rela.runtimeId, name);
                    });
                }
            }else {
                rela.onlyLocal = inLocal;
            }
            //如果两次判断都为false,大概是配置文件的问题
            if(inLocal||inCloud){
                mappings.append(rela);
            }
            
        }
    }
}

QVector<RMCRelation> FileMapping::getAllFileRMCRelation(){
    return this->mappings;
}

RMCRelation FileMapping::getRMCFile(RMCRuntimeFileID id){
    for(auto i:mappings){
        if(i.runtimeId == id){
            return i;
        }
    }
    return  RMCRelation();
}

RMCRelation FileMapping::getRMCFileByLocalPath(QString path){
    for(auto i:mappings){
        if(i.localPath == path){
            return i;
        }
    }
    return  RMCRelation();
}

RMCRelation FileMapping::newRMCFile(){
    RMCRelation rela;
    rela.runtimeId = RMCRuntimeFileID::genNew();
    return rela;
}
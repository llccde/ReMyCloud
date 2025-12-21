#include "ConstAppConfig.h"
#include "T_DataConfigLoader.h"
#include "DataConfig.h"
#include "QJsonObject"
#include <qjsondocument.h>
#include <qjsonobject.h>
#include "QJsonDocument"
#include "QJsonArray"
#include "I_LocalFileService.h"

std::shared_ptr<DataConfig> T_DataConfigLoader::loadConfig(){
    if (this->hasLoad) {
        return this->config;
    }
    QString path = ConstAppConfig::getConfigFilePath();
    auto file = services.lock()->getLocalFileService()->openFile(path);
    QJsonObject json = QJsonDocument::fromJson(services.lock()->getLocalFileService()->getFileContent(file).toUtf8()).object() ;
    this->config = std::shared_ptr<DataConfig>(new DataConfig());

    RMCFile temp;
    if(json["RMCFiles"].isArray()){
        for (auto i : json["RMCFiles"].toArray()) {
            if(i.isObject()){
                auto io = i.toObject();
                if(io["localPath"].isString()){
                    temp.localPath = io["localPath"].toString();
                }else {
                    temp.localPath = "";
                }

                if(io["cloudId"].isString()){
                    temp.cloudId = io["cloudId"].toString();
                }else {
                    temp.cloudId = "";
                }
            }
            this->config->files.append(temp);
            
        }
    }


    config->rawS = services.lock()->getLocalFileService()->getFileContent(file);
    config->rawO = json;

    return  config;
}
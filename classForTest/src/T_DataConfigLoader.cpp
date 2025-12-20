#include "ConstAppConfig.h"
#include "T_DataConfigLoader.h"
#include "DataConfig.h"
#include "QJsonObject"
#include <qjsondocument.h>
#include <qjsonobject.h>
#include "QJsonDocument"
std::shared_ptr<DataConfig> T_DataConfigLoader::loadConfig(){
    if (this->hasLoad) {
        return this->config;
    }
    QString path = ConstAppConfig::getConfigFilePath();
    auto file = services.lock()->getLocalFileService()->openFile(path);
    QJsonObject json = QJsonDocument::fromJson(services.lock()->getLocalFileService()->getFileContent(file).toUtf8()).object() ;
    this->config = std::shared_ptr<DataConfig>(new DataConfig());
    config->rawS = services.lock()->getLocalFileService()->getFileContent(file);
    return  config;
}
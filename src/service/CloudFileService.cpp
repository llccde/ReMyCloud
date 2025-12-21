#include "../../include/service/CloudFileService.h"
#include <QJsonObject>
#include <QString>

CloudFileService::~CloudFileService() {
}

QJsonObject CloudFileService::getAllFiles() {
    
    return QJsonObject();
}

LoginState CloudFileService::login(const QString username, const QString password) {
    return pass;
}

bool CloudFileService::uploadFile(const QString content, const QString CloudID) {
    return false;
}

QString CloudFileService::getFileNameByCloudID(CloudFileID id) {
    return "exampleName"; 
}
#ifndef __CONFIGANDDATA_H__
#define __CONFIGANDDATA_H__
#include "QString"
#include "QVector"
#include "QJsonDocument"
#include <qcontainerfwd.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
struct RMCFile{
    QString localPath;
    QString cloudId;
};
using RMCFiles = QVector<RMCFile>;
struct DataConfig{
    QString dataDirectory;
    QString userConfigFile;
    QString localFileStorageDir;
    QString cloudServiceHost;
    int cloudServicePort;
    QString RMCRelationFile;
    QJsonDocument rawD;
    QString rawS;
    QJsonObject rawO;

    RMCFiles files;
};

#endif // __CONFIGANDDATA_H__
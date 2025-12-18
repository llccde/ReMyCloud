#ifndef __CONFIGANDDATA_H__
#define __CONFIGANDDATA_H__
#include "QString"
#include "QVector"
struct DataConfig{
    QString dataDirectory;
    
    QString userConfigFile;
    QString localFileStorageDir;
    
    QString cloudServiceHost;
    int cloudServicePort;

    QString RMCRelationFile;

    struct RMCRelationRaw{
        QString localPath;
        QString cloudPath;
        QString theName;
    };
    QVector<RMCRelationRaw> relations;
};
#endif // __CONFIGANDDATA_H__
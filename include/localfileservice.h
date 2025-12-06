#ifndef LOCALFILESERVICE_H
#define LOCALFILESERVICE_H
#include<QFile>
#include<QMap>
#include<QtCore>
#include<QReadWriteLock>
using fileID = long long;

struct file_res{
    QReadWriteLock lock;
    QFile file;
};

class LocalFileService
{

    using file = std::shared_ptr<file_res>;
    QMap<fileID,file> opendFiles = QMap<fileID,file>();

public:
    static fileID count;

    LocalFileService();
    fileID openFile(QString path);
    bool closeFile(fileID);
    QString getFileContent(fileID);
    bool haveFile();
    bool writeFile(fileID id,QString content);

};

fileID LocalFileService::count=0;
#endif // LOCALFILESERVICE_H

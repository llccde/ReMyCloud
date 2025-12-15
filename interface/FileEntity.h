#ifndef __FILEENTITY_H__
#define __FILEENTITY_H__
#include "QString"
#include "QVector"
class FileEntity
{

    public:
        using fileID = QString;
        using HistoryID = int;
        FileEntity();
        ~FileEntity();
        QString fileName;
        fileID fileIdentifier;
        QVector<HistoryID> historyList;
};
#endif // __FILEENTITY_H__
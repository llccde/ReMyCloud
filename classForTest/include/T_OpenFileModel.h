#ifndef __T_OPENFILEMODEL_H__
#define __T_OPENFILEMODEL_H__
#include "QAbstractListModel"
#include "I_OpendFiles.h"
class T_OpenFileModel :virtual public QAbstractListModel,virtual public I_OpendFiles{
    Q_OBJECT
    public:
        enum Roles {
            FilePathRole = Qt::UserRole + 1,
            FileNameRole
        };
        Q_ENUM(Roles)

        // QAbstractListModel overrides
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QHash<int, QByteArray> roleNames() const override;

        // I_OpendFiles interface (declare expected methods)
        bool openFile(const QString &path) override;
        bool closeFile(const QString &path) override;
        QStringList openFiles() const override;

    public slots:
        void appendFile(const QString &path);
        void removeFile(const QString &path);

    signals:
        void fileOpened(const QString &path);
        void fileClosed(const QString &path);

    private:
        QStringList m_files;


    public:
        T_OpenFileModel();
        ~T_OpenFileModel();
};
#endif // __T_OPENFILEMODEL_H__
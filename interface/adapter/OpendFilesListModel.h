

#include <QAbstractListModel>
#include <QStringList>
#include <QVector>
#include <QVariant>

class OpendFilesListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    // 构造函数
    explicit OpendFilesListModel(QObject *parent = nullptr);
    explicit OpendFilesListModel(const QStringList &strings, QObject *parent = nullptr);

    // 基础Model接口实现
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                       int role = Qt::DisplayRole) const override;

    // 编辑功能
    bool setData(const QModelIndex &index, const QVariant &value,
                int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    // 数据操作接口
    bool insertRows(int position, int rows, 
                   const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int position, int rows,
                   const QModelIndex &parent = QModelIndex()) override;

    // 自定义数据操作方法
    void setStringList(const QStringList &strings);
    QStringList stringList() const;
    
    // 添加数据项
    void append(const QString &item);
    void insert(int row, const QString &item);
    
    // 删除数据项
    void removeAt(int row);
    void clear();
    
    // 查找功能
    int find(const QString &text, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
    
    // 批量操作
    void appendList(const QStringList &items);
    
    // 获取数据项
    QString at(int index) const;

private:
    QStringList m_stringList;
};

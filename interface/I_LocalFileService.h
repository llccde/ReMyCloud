#ifndef I_LOCALFILESERVICE_H
#define I_LOCALFILESERVICE_H

#include <QString>

// 文件ID类型定义
using fileID = int;

/**
 * @brief 本地文件服务接口
 * 
 * 该接口定义了本地文件操作的基本功能，包括打开、关闭、读取、写入和删除文件等操作。
 */
class I_LocalFileService
{
public:
    virtual ~I_LocalFileService() = default;
    
    /**
     * @brief 检查文件是否已打开
     * @param id 文件ID
     * @return 如果文件存在且已打开则返回true，否则返回false
     */
    virtual bool haveFile(fileID id) const = 0;
    
    virtual fileID creatFile(QString path,bool withOpen) = 0;

    virtual bool renameFile(fileID id) = 0;
    /**
     * @brief 打开文件
     * @param path 文件路径
     * @return 成功打开返回文件ID，失败返回-1
     */
    virtual fileID openFile(const QString& path) = 0;
    
    /**
     * @brief 关闭文件
     * @param id 文件ID
     * @return 关闭成功返回true，失败返回false
     */
    virtual bool closeFile(fileID id) = 0;
    
    /**
     * @brief 获取文件内容
     * @param id 文件ID
     * @param charset 字符编码（如"UTF-8"、"GBK"等）
     * @return 文件内容字符串，读取失败返回空字符串
     */
    virtual QString getFileContent(fileID id, QString charset = "UTF-8") = 0;
    
    /**
     * @brief 写入内容到文件
     * @param id 文件ID
     * @param content 要写入的内容
     * @return 写入成功返回true，失败返回false
     */
    virtual bool writeFile(fileID id, const QString& content) = 0;
    
    /**
     * @brief 删除文件
     * @param id 文件ID
     * @return 删除成功返回true，失败返回false
     */
    virtual bool delFile(fileID id) = 0;
    
    /**
     * @brief 获取当前打开的文件数量
     * @return 打开的文件数量
     */
    virtual int getOpenFileCount() const = 0;

    virtual int closeAll() = 0;
};

#endif // ILOCALFILESERVICE_H

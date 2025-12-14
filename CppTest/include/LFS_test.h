#ifndef LFS_TEST_H
#define LFS_TEST_H

#include <QObject>
#include <QString>
#include <QTemporaryDir>
#include "ILocalFileService.h"
#include <QStringDecoder>
#include <QStringEncoder>
class LFS_test : public QObject
{
    Q_OBJECT
    ILocalFileService* fileService = nullptr;
public:
    LFS_test();
    ~LFS_test();
    void setImpl(ILocalFileService* impl);
private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();
    
    // 基础功能测试
    void testOpenFile();
    void testOpenNonExistentFile();
    void testOpenFileTwice();

    void testCloseFile();
    void testCloseNonExistentFile();

    void testHaveFile();

    // 文件内容操作测试
    void testGetFileContent();
    void testGetFileContentWithCharset();
    void testGetFileContentInvalidId();

    void testWriteFile();
    void testWriteFileInvalidId();
    void testWriteFileAppend();

    // 文件管理测试
    void testDeleteFile();
    void testDeleteOpenFile();
    void testDeleteNonExistentFile();

    // 统计功能测试
    void testGetOpenFileCount();
    void testMultipleFilesOperations();

    // 边界条件测试
    void testEmptyFileOperations();
    void testLargeFileOperations();
    void testSpecialCharactersInContent();

private:
    QTemporaryDir tempDir;
    QString testFilePath;
    QString utf8TestFilePath;
    QString gbkTestFilePath;

    void createTestFile(const QString& path, const QByteArray& content);
};


#endif // LFS_TEST_H

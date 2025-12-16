#include <QFile>
#include <QTextStream>
#include"LFS_test.h"
#include "I_LocalFileService.h"
#include <QDebug>
#include <QByteArray>
#include <QtTest/qtestcase.h>

void LFS_test::setImpl(I_LocalFileService* impl){
    this->fileService = impl;
}
LFS_test::LFS_test()
    : fileService(nullptr)
{
}

LFS_test::~LFS_test()
{
}

void LFS_test::initTestCase()
{
    // 创建测试用的文件服务实例


    // 创建临时目录用于测试
    QVERIFY(tempDir.isValid());

    // 创建测试文件路径
    testFilePath = tempDir.path() + "/test_file.txt";
    utf8TestFilePath = tempDir.path() + "/utf8_file.txt";
    gbkTestFilePath = tempDir.path() + "/gbk_file.txt";

    // 创建UTF-8编码的测试文件
    createTestFile(utf8TestFilePath, QString("UTF-8测试内容\n第二行内容\n第三行内容").toUtf8());

    // 创建GBK编码的测试文件

    QStringEncoder encoder("GBK");

    if (encoder.isValid()) {
        createTestFile(gbkTestFilePath, encoder.encode("GBK测试内容\n中文测试"));
    }
}

void LFS_test::cleanupTestCase()
{
    fileService->closeAll();

    fileService = nullptr;
}

void LFS_test::init()
{
    // 每个测试用例开始前，确保文件是关闭的
    QCOMPARE(fileService->getOpenFileCount(), 0);

    // 清理测试文件
    QFile::remove(testFilePath);
}

void LFS_test::cleanup()
{
    // 每个测试用例结束后，关闭所有打开的文件
    // 注意：实际的实现类应该会自动清理，这里我们只是确保状态
}

void LFS_test::createTestFile(const QString& path, const QByteArray& content)
{
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(content);
        file.close();
    }
}

// ================ 基础功能测试 ================

void LFS_test::testOpenFile()
{
    // 创建测试文件
    createTestFile(testFilePath, "Test content");

    // 测试打开文件
    fileID id = fileService->openFile(testFilePath);
    QVERIFY(id.isValid());
    QVERIFY(fileService->haveFile(id));
    QCOMPARE(fileService->getOpenFileCount(), 1);

    // 清理
    fileService->closeFile(id);
}

void LFS_test::testOpenNonExistentFile()
{
    QString nonExistentPath = tempDir.path() + "/non_existent.txt";
    fileID id = fileService->openFile(nonExistentPath);
    QVERIFY(id.isValid() == false);
    QCOMPARE(fileService->getOpenFileCount(), 0);
}

void LFS_test::testOpenFileTwice()
{
    createTestFile(testFilePath, "Test content");

    fileID id1 = fileService->openFile(testFilePath);
    QVERIFY(id1.isValid());

    // 第二次打开应该相同的的ID（或者根据实现可能返回-1）
    fileID id2 = fileService->openFile(testFilePath);



    if(id1==id2){
        QVERIFY(id1 == id2);
        fileService->closeFile(id2);
    }else {
        QVERIFY(id1==id2);
        fileService->closeFile(id1);
        fileService->closeFile(id2);
    }


}

void LFS_test::testCloseFile()
{
    createTestFile(testFilePath, "Test content");

    fileID id = fileService->openFile(testFilePath);
    QVERIFY(id.isValid());
    QCOMPARE(fileService->getOpenFileCount(), 1);

    bool result = fileService->closeFile(id);
    QVERIFY(result);
    QCOMPARE(fileService->getOpenFileCount(), 0);
    QVERIFY(!fileService->haveFile(id));
}

void LFS_test::testCloseNonExistentFile()
{
    bool result = fileService->closeFile(fileID::fromLongLong(999)); // 不存在的ID
    QVERIFY(!result);
}

void LFS_test::testHaveFile()
{
    createTestFile(testFilePath, "Test content");

    fileID id = fileService->openFile(testFilePath);
    QVERIFY(fileService->haveFile(id));

    fileService->closeFile(id);
    QVERIFY(!fileService->haveFile(id));
}

// ================ 文件内容操作测试 ================

void LFS_test::testGetFileContent()
{
    QString expectedContent = "Hello World!\nThis is a test file.";
    createTestFile(testFilePath, expectedContent.toUtf8());

    fileID id = fileService->openFile(testFilePath);
    QString content = fileService->getFileContent(id, "UTF-8");

    QCOMPARE(content, expectedContent);

    fileService->closeFile(id);
}

void LFS_test::testGetFileContentWithCharset()
{
    // 测试UTF-8编码
    fileID utf8Id = fileService->openFile(utf8TestFilePath);
    QString utf8Content = fileService->getFileContent(utf8Id, "UTF-8");
    QVERIFY(!utf8Content.isEmpty());
    QVERIFY(utf8Content.contains("测试内容"));
    fileService->closeFile(utf8Id);


    if (QFile::exists(gbkTestFilePath)) {
        fileID gbkId = fileService->openFile(gbkTestFilePath);
        QString gbkContent = fileService->getFileContent(gbkId, "GBK");
        QVERIFY(!gbkContent.isEmpty());
        QVERIFY(gbkContent.contains("测试"));
        fileService->closeFile(gbkId);
    }
}

void LFS_test::testGetFileContentInvalidId()
{
    QString content = fileService->getFileContent(fileID::fromLongLong(999), "UTF-8");
    QVERIFY(content.isEmpty());
}

void LFS_test::testWriteFile()
{
    QString originalContent = "Original content";
    createTestFile(testFilePath, originalContent.toUtf8());

    fileID id = fileService->openFile(testFilePath);

    QString newContent = "New written content";
    bool result = fileService->writeFile(id, newContent);
    QVERIFY(result);

    // 重新打开文件验证内容
    fileService->closeFile(id);
    id = fileService->openFile(testFilePath);
    QString writtenContent = fileService->getFileContent(id, "UTF-8");
    QCOMPARE(writtenContent, newContent);

    fileService->closeFile(id);
}

void LFS_test::testWriteFileInvalidId()
{
    bool result = fileService->writeFile(fileID::fromLongLong(999), "Test content");
    QVERIFY(!result);
}

void LFS_test::testWriteFileAppend()
{
    // 注意：根据接口定义，writeFile可能会覆盖原内容
    // 如果需要测试追加功能，需要查看具体实现

    QString initialContent = "Initial content\n";
    createTestFile(testFilePath, initialContent.toUtf8());

    fileID id = fileService->openFile(testFilePath);

    QString additionalContent = "Additional line";
    fileService->writeFile(id, additionalContent);

    fileService->closeFile(id);

    // 读取文件验证
    QFile file(testFilePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString content = QString::fromUtf8(file.readAll());
        // 根据实现，可能是覆盖或追加
        // QCOMPARE(content, additionalContent); // 如果是覆盖
        // 或者
        // QVERIFY(content.contains(additionalContent)); // 如果是追加
    }
}

// ================ 文件管理测试 ================

void LFS_test::testDeleteFile()
{
    createTestFile(testFilePath, "To be deleted");

    // 先打开文件
    fileID id = fileService->openFile(testFilePath);
    QVERIFY(id.isValid());

    // 关闭文件
    fileService->closeFile(id);

    // 删除文件
    bool result = fileService->delFile(id);

    // delFile应该返回false，因为文件已关闭
    QVERIFY(!result);

    // 验证文件是否还存在（根据具体实现）
    // QFile::exists(testFilePath) 可能为true或false
}

void LFS_test::testDeleteOpenFile()
{
    createTestFile(testFilePath, "Content");

    fileID id = fileService->openFile(testFilePath);
    QVERIFY(id.isValid());

    // 尝试删除打开的文件
    bool result = fileService->delFile(id);
    // 根据实现，可能成功或失败
    QVERIFY(result);
    fileService->closeFile(id);
}

void LFS_test::testDeleteNonExistentFile()
{
    bool result = fileService->delFile(fileID::fromLongLong(999)); // 不存在的ID
    QVERIFY(!result);
}

// ================ 统计功能测试 ================

void LFS_test::testGetOpenFileCount()
{
    QCOMPARE(fileService->getOpenFileCount(), 0);

    createTestFile(testFilePath, "Test");
    createTestFile(tempDir.path() + "/test2.txt", "Test2");

    fileID id1 = fileService->openFile(testFilePath);
    QCOMPARE(fileService->getOpenFileCount(), 1);

    fileID id2 = fileService->openFile(tempDir.path() + "/test2.txt");
    QCOMPARE(fileService->getOpenFileCount(), 2);

    fileService->closeFile(id1);
    QCOMPARE(fileService->getOpenFileCount(), 1);

    fileService->closeFile(id2);
    QCOMPARE(fileService->getOpenFileCount(), 0);
}

void LFS_test::testMultipleFilesOperations()
{
    QString file1Path = tempDir.path() + "/file1.txt";
    QString file2Path = tempDir.path() + "/file2.txt";

    createTestFile(file1Path, "File 1 content");
    createTestFile(file2Path, "File 2 content");

    fileID id1 = fileService->openFile(file1Path);
    fileID id2 = fileService->openFile(file2Path);

    QVERIFY(id1.isValid());
    QVERIFY(id2.isValid());
    QVERIFY(id1 != id2);
    QCOMPARE(fileService->getOpenFileCount(), 2);

    // 测试haveFile
    QVERIFY(fileService->haveFile(id1));
    QVERIFY(fileService->haveFile(id2));

    // 测试getFileContent
    QString content1 = fileService->getFileContent(id1, "UTF-8");
    QString content2 = fileService->getFileContent(id2, "UTF-8");
    QCOMPARE(content1, "File 1 content");
    QCOMPARE(content2, "File 2 content");

    // 测试writeFile
    fileService->writeFile(id1, "Updated content 1");
    fileService->writeFile(id2, "Updated content 2");

    // 重新读取验证
    content1 = fileService->getFileContent(id1, "UTF-8");
    content2 = fileService->getFileContent(id2, "UTF-8");
    QCOMPARE(content1, "Updated content 1");
    QCOMPARE(content2, "Updated content 2");

    // 清理
    fileService->closeFile(id1);
    fileService->closeFile(id2);
}

// ================ 边界条件测试 ================

void LFS_test::testEmptyFileOperations()
{
    createTestFile(testFilePath, "");

    fileID id = fileService->openFile(testFilePath);
    QVERIFY(id.isValid());

    QString content = fileService->getFileContent(id, "UTF-8");
    QVERIFY(content.isEmpty());

    // 写入空内容
    bool result = fileService->writeFile(id, "");
    QVERIFY(result);

    content = fileService->getFileContent(id, "UTF-8");
    QVERIFY(content.isEmpty());

    fileService->closeFile(id);
}

void LFS_test::testLargeFileOperations()
{
    // 创建一个大文件（例如1MB）
    QString largeContent;
    largeContent.reserve(1024 * 1024);
    for (int i = 0; i < 1024 * 1024 / 100; ++i) {
        largeContent += "This is a line of text for testing large files. ";
    }

    createTestFile(testFilePath, largeContent.toUtf8());

    fileID id = fileService->openFile(testFilePath);
    QVERIFY(id.isValid());

    QString content = fileService->getFileContent(id, "UTF-8");
    QVERIFY(!content.isEmpty());
    QCOMPARE(content.length(), largeContent.length());

    fileService->closeFile(id);
}

void LFS_test::testSpecialCharactersInContent()
{
    QString specialContent = "特殊字符测试:\n"
                             "中文测试\n"
                             "Emoji: 😀🎉\n"
                             "特殊符号: @#$%^&*()\n"
                             "换行测试\n第二行\n第三行";

    createTestFile(testFilePath, specialContent.toUtf8());

    fileID id = fileService->openFile(testFilePath);
    QString content = fileService->getFileContent(id, "UTF-8");

    QCOMPARE(content, specialContent);
    QVERIFY(content.contains("中文"));
    QVERIFY(content.contains("😀"));

    // 测试写入特殊字符
    QString newSpecialContent = "新内容: ©®™\n跨平台测试";
    fileService->writeFile(id, newSpecialContent);

    content = fileService->getFileContent(id, "UTF-8");
    QCOMPARE(content, newSpecialContent);

    fileService->closeFile(id);
}


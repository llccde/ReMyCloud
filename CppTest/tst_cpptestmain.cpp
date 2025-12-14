#include <QTest>
#include<Backend.h>
#include"LocalFileService.h"
#include"LFS_test.h"
#include"iostream"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    qDebug() << "Hello, Console!"; // 输出到控制台
    // 创建具体的文件服务实例
    LocalFileService service;

    // 创建测试类实例并设置服务
    LFS_test test;
    test.setImpl(&service);

    // 运行所有测试
    int result = QTest::qExec(&test, argc, argv);
    qDebug() << "Hello, Console!"; // 输出到控制台

    return result;
}


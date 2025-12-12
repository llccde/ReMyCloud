#include <QTest>
#include<Backend.h>
class LFS_test : public QObject
{
    Q_OBJECT

public:
    LFS_test();
    ~LFS_test();

private slots:
    void initTestCase();
    void init();
    void cleanupTestCase();
    void cleanup();
    void test_case1();
};

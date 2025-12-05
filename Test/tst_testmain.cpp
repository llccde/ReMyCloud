#include <QTest>

// add necessary includes here

class TestMain : public QObject
{
    Q_OBJECT

public:
    TestMain();
    ~TestMain();

private slots:
    void initTestCase();
    void init();
    void cleanupTestCase();
    void cleanup();
    void test_case1();
};

TestMain::TestMain() {}

TestMain::~TestMain() {}

void TestMain::initTestCase()
{
    // code to be executed before the first test function
}

void TestMain::init()
{
    // code to be executed before each test function
}

void TestMain::cleanupTestCase()
{
    // code to be executed after the last test function
}

void TestMain::cleanup()
{
    // code to be executed after each test function
}

void TestMain::test_case1() {}

QTEST_APPLESS_MAIN(TestMain)

#include "tst_testmain.moc"

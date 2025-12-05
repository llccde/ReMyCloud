#include <QTest>

// add necessary includes here

class CppTestMain : public QObject
{
    Q_OBJECT

public:
    CppTestMain();
    ~CppTestMain();

private slots:
    void initTestCase();
    void init();
    void cleanupTestCase();
    void cleanup();
    void test_case1();
};

CppTestMain::CppTestMain() {}

CppTestMain::~CppTestMain() {}

void CppTestMain::initTestCase()
{
    // code to be executed before the first test function
}

void CppTestMain::init()
{
    // code to be executed before each test function
}

void CppTestMain::cleanupTestCase()
{
    // code to be executed after the last test function
}

void CppTestMain::cleanup()
{
    // code to be executed after each test function
}

void CppTestMain::test_case1() {}

QTEST_APPLESS_MAIN(CppTestMain)

#include "tst_cpptestmain.moc"

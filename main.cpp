#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qlogging.h>
#include <qqmlapplicationengine.h>
#include <qreadwritelock.h>
#include "CloudFileID.h"
#include "I_QmlAdapter.h"
#include "Singletons.h"
#include "Inject.h"
#include "I_Backend.h"
#include "DataConfig.h"
#include "I_ServiceManager.h"
#include "I_DataConfigLoader.h"
#include "CloudFileID.h"
QReadWriteLock RMCRuntimeFileID::lock = QReadWriteLock();
QString RMCRuntimeFileID::lastTime = "";
int RMCRuntimeFileID::countInSameTime = 0;

void registerQmlTypes(){
    
}
void registerQmlSingletons(){
    qmlRegisterSingletonInstance<I_QmlAdapter>("RMC",1,0,
        "MainAdapter",
        Singletons::Instance()->getQmlAdapterInstance().data());
}
void initSingletons(){
    if(Singletons::Instance().isNull()){
        Singletons::init();
        qWarning() << "Singletons does not initialized.";
    }
}

int main(int argc, char *argv[])
{
    Singletons::init();
    Inject inject;
    
    inject.setSingletons(Singletons::Instance());
    inject.DoInject();
    qDebug()<<Singletons::Instance()->getBackend()->getServiceManager()->getDataConfigLoader()->loadConfig()->rawO["RMCFiles"][0]["localPath"].toString();


    registerQmlTypes();
    registerQmlSingletons();
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("ReMyCloud", "Main");

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qlogging.h>
#include <qqmlapplicationengine.h>
#include "I_QmlAdapter.h"
#include "Singletons.h"
#include "Inject.h"
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

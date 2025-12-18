#include "Singletons.h"
#include "I_QmlAdapter.h"
#include "T_QmlAdapter.h"
QSharedPointer<Singletons> Singletons::Singletons::instance = nullptr;
void Singletons::init(){
    Singletons::instance = QSharedPointer<Singletons>(new Singletons());
}
Singletons::Singletons(){
    qmlAdapter = QSharedPointer<I_QmlAdapter>(new T_QmlAdapter());
}

Singletons::~Singletons(){
}
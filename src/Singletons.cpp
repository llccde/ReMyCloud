#include "Singletons.h"
QSharedPointer<Singletons> Singletons::Singletons::instance = nullptr;
void Singletons::init(){
    Singletons::instance = QSharedPointer<Singletons>(new Singletons());
}
Singletons::Singletons(){
}
Singletons::~Singletons(){
}
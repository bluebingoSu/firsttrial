#include "object.h"
#include "observer.h"
#include <list>

Object::Object(string name){
    this->name=name;
}

void Object::notice(){
    cout << name << ":: notice!" << endl;
    for(Observer* o:observers) {
        o->receive();
    }
}

void Object::addObserver(Observer *o){
    observers.push_back(o);
}

void Object::delObserver(Observer *o){
    observers.remove(o);
}

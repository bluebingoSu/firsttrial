#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <list>
using namespace std;

class Observer;

class Object
{
public:
    Object(string name);
    void notice();
    void addObserver(Observer *o);
    void delObserver(Observer *o);

private:
    list<Observer *> observers;
    string name;
};

#endif // OBJECT_H

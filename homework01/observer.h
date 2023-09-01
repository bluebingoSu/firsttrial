#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
using namespace std;

class Observer
{
public:
    Observer(string name);
    void receive();
private:
    string name;
};

#endif // OBSERVER_H

#include "observer.h"
#include <iostream>
#include <string>
using namespace std;

Observer::Observer(string name)
{
    this->name=name;
}

void Observer::receive(){
    cout << name << ":: Message received." << endl;
}

#include <iostream>
#include "object.h"
#include "observer.h"
using namespace std;

int main()
{
    Object *teacher=new Object("tch");
    Observer *student1=new Observer("stu1");
    Observer *student2=new Observer("stu2");

    teacher->addObserver(student1);
    teacher->addObserver(student2);
    teacher->notice();
    return 0;
}

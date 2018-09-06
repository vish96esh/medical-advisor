#ifndef MANUFACTURER_H
#define MANUFACTURER_H
#include <cstring>
#include <iostream>
#include "computer.h"
//#include "medicine.h"
//#include "store.h"
using namespace std;

class medicine;
class store;

class manufacturer
{
    int id;
    string name;
    public:
        string no;
        string add;
        int med_no;
        medicine *m[100];
        manufacturer();
        int getid();
        void shift();
        string getname();
        void display();
        void addmed(medicine *m1);
        void set(int id1,string name1,string add1,string no1);
        void update();

        friend class user;
};

#endif // MANUFACTURER_H

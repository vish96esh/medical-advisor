#ifndef STORE_H
#define STORE_H
#include <cstring>
#include <iostream>
#include "computer.h"
//#include "medicine.h"
//#include "manufacturer.h"
using namespace std;

class medicine;
class manufacturer;

class store
{
    int id;
    string name;
    string location;
    public:
        string address;
        string no;
        medicine *m[100];
        int med_no;
        int quantity[100][2];
        float discount;
        store();
        int getid();
        string getname();
        string getLocation();
        void addstore(int);
        void shift();
        void addmed(medicine *m1);
        void set(int id1,string name1,string location1);
        int getQuantity(int id);
        void display();
        void showmed();
        int update();
        friend class user;
};

#endif // STORE_H

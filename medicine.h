#ifndef MEDICINE_H
#define MEDICINE_H
#include <iostream>
#include <cstring>
#include "computer.h"
//#include "manufacturer.h"
//#include "store.h"
using namespace std;

class manufacturer;
class store;
class disease;

class medicine
{
    private:
        int id;
        string name;
        float price;
    public:
        manufacturer *m;
        disease *d;
        int dd,mm,yy;
        store *s1[100];
        int s1_no;
        medicine();
        void display(int);
        float getprice();
        string getname();
        bool checkDate(int d,int m,int y);
        void set(int);
        void set(int id1,string name1,float price1,int dd1, int mm1, int yy1);
        void add_store(store *);
        void mset(manufacturer *);
        int getid();
        void update();

        friend class user;
};


#endif // MEDICINE_H

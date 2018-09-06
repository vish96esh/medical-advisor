#ifndef DISEASE_H
#define DISEASE_H
#include <iostream>
#include <cstring>
#include "medicine.h"

class medicine;

class disease
{
    public:
        int id;
        string name;
        medicine *m[10];
        int m_no;
        disease();
        void display();
        void addmed(medicine *m);
};

#endif // DISEASE_H

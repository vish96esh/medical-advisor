#ifndef CUSTOMER_H
#define CUSTOMER_H

//#include <user.h>
#include "computer.h"
#include "medicine.h"
#include "manufacturer.h"
#include "store.h"
#include "user.h"
#include "store_list.h"

class user;
class store;
class medicine;
class manufacturer;
class store_list;

class customer : public user,public computer
{
    medicine *cart[10];
    int *quant;
    int c_no;
    float total;
    public:
        //medicine **cart;
        customer();
        void welcome();
        void add_med_to_cart(medicine *m,int q);
        void choice1();
        void choice2();
        void choice3();
        void choice4();
        void checkout();
        void search_med();
        void shift(int pos);
        void show_cart();
        int show_alternative(medicine*);
};

#endif // CUSTOMER_H

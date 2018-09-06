#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "user.h"
#include "manufacturer.h"
#include "store.h"
#include "store_list.h"
#include "computer.h"

class computer;
class user;
class store;
class medicine;
class manufacturer;
class store_list;

class employee : public user, public computer
{
    public:
        void welcome();
        void shift(int pos,char ch);
        void del_man();
        void del_med();
        store_list* del_s(store_list *start1);
        void add_med();
        void add_man();
        void add_med_to_store();
        store_list *add_store(store_list *start1);
        store_list* rearrange(store_list *start1);
        store_list *update(store_list *start1);
        void update(char c);
};

#endif // EMPLOYEE_H

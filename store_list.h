#ifndef STORE_LIST_H
#define STORE_LIST_H
#include "store.h"

class store;

class store_list
{
     public:
        store s;
        store_list *next;
        store_list(int);
        store_list(store ptr);
};

#endif // STORE_LIST_H

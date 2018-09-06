#ifndef COMPUTER_H
#define COMPUTER_H
#include "medicine.h"
#include "manufacturer.h"
#include "store.h"
#include "user.h"
#include "store_list.h"
#include "disease.h"

class user;
class store;
class medicine;
class manufacturer;
class store_list;

class computer
{
        //private:
        //static int u_no;
        //int pos;
    public:
        static medicine med[1000];
        static manufacturer man[50];
        static disease dis[50];
        static store_list *start;
        static int med_no; //no of medicines
        static int man_no; //no of manufacturers
        static int s_no;
        static int d_no;
    //public:
        static user *u;
        //int exit=0;
        computer();
        friend class medicine;
        friend class manufacturer;
        friend class store;
        friend class user;

        void load();
        void save();
        int login(string);
        int signup();
        medicine *get_med_by_id(int id1);
        store *get_store_by_id(int id2);
        bool validID(int id1,int t);
        medicine *search_med_by_man(string man1);
        medicine *search_med_by_name(string name1);
        medicine *get_med();
        manufacturer *get_man_by_id(int id1);
        disease* get_disease_by_name(string);
        disease* get_disease_by_id(int);
};

#endif // COMPUTER_H

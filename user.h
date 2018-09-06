#ifndef USER_H
#define USER_H
#include <iostream>
#include <cstring>
using namespace std;

class user
{
    protected:
        string location;
        //string id;
        string pass;
        char type;  //customer or employee
        string name;
     public:
        string id;
        virtual void welcome();
        void new_user(string id1,string name1,string pass1,string location1,char type1);
        void display();
        void setid(string id1);
        void setname(string name1);
        void settype(char type1);
        void setpass(string pass1);
        void setlocation(string location1);
        string getid();
        string getpass();
        string getname();
        string getlocation();
        void update();
        char gettype();
};

#endif //USER_H

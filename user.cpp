#include "user.h"
#include <iostream>
#include <cstring>
using namespace std;

void user::welcome(){}

void user::new_user(string id1,string name1,string pass1,string location1,char type1)
{
    name=name1;
    pass=pass1;
    type=type1;
    id=id1;
    location=location1;
}

void user::display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Location: "<<location<<endl;
}

void user::setid(string id1)
{
    id=id1;
}

void user::setname(string name1)
{
    name=name1;
}

void user::settype(char type1)
{
    type=type1;
}

void user::setpass(string pass1)
{
    pass=pass1;
}

void user::setlocation(string location1)
{
    location=location1;
}

string user::getid()
{
    return id;
}

string user::getpass()
{
    return pass;
}

string user::getname()
{
    return name;
}

string user::getlocation()
{
    return location;
}

void user::update()
{
    int ch,ch1;
    string pass1;
    cout<<"1.Name\n2.Password(under maintainance)\n3.Location\n";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"Enter your new name: ";
            cin>>name;
            break;
                /*case 2:pas:
                    cout<<"Enter your old password: ";
                    cin>>pass1;
                    if(pass=pass1)
                    {
                        cout<<"Enter your new password: ";
                        cin>>pass;
                    }
                    else
                    {
                        cout<<"Password incorrect\nDo you want to enter again?<Y=1,N=0>\n";
                        cin>>ch1;
                        if(ch1==1)
                            goto pas;
                        else
                            return;
                    }
                    break;*/
        case 3:cout<<"Enter your new location: ";
            cin>>location;
            break;
    }
    cout<<"Do you want to update again?<Y=1,N=0>\n";
    cin>>ch;
    if(ch==1)
        update();
}

char user::gettype()
{
    return type;
}

int main()
{
    return 0;
}

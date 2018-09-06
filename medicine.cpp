#include "manufacturer.h"
#include "medicine.h"
#include "store.h"
#include "computer.h"
#include<iostream>
#include<cstring>
using namespace std;

class manufacturer;
class store;
class medicine;

manufacturer::manufacturer()
        {
            id=0;
            name="";
            add="";
            no="";
            med_no=0;
  //          *m=new medicine[10];
        }

        int manufacturer::getid()
        {
            return id;
        }

int store::getid()
{
    return id;
}

void manufacturer::display()
{
    int i,ch;
    cout<<"Manufacturer details: \n\n";
    cout<<"ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<add<<endl;
    cout<<"Ph No.: "<<no<<endl;
    cout<<"For details of medicines press 1\n";
    cin>>ch;
    if(ch==1)
    {
        for(i=0;i<med_no;i++)
            m[i]->display(1);
    }
}

medicine::medicine()
{
    id=0;
    name="";
    price=0.0;
    dd=0;mm=0;yy=0;
    s1_no=0;
  //  *s1=new store[100]
}

void medicine::display(int x)// x=1 if manufacturer details have already been shown
{
    int ch,ch1;
    cout<<"Details of the medicine = \n\n";
    cout<<"Medicine id= "<<id<<endl;
    cout<<"Name= "<<name<<endl;
    cout<<"Price= "<<price<<endl;
    cout<<"Expiry date= "<<dd<<"-"<<mm<<"-"<<yy<<endl;
    cout<<"For more details enter 1 else enter 0\n";
    cin>>ch;
    if(ch==1)
    {
        cout<<"1.Manufacturer details\n2.Composition\n3.Diseases it can cure\n";
        cin>>ch1;
        if(ch1==1&&x==0)
        {
            if(m==NULL)
            {
                cout<"manfacturer not available\n";
            }
            else
                m->display();
        }
        else if(ch1==1&&x==1)
            cout<<"manufacturer details already shown\n";
    }
}

float medicine::getprice()
{
    return price;
}

string medicine::getname()
{
    return name;
}

bool medicine::checkDate(int d,int m,int y)
{
    if (! (1<= m && m<=12) )
        return false;
    if (! (1<= d && d<=31) )
        return false;
    if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
        return false;
    if ( (d==30) && (m==2) )
        return false;
    if ( (m==2) && (d==29) && (y%4!=0) )
        return false;
    if ( (m==2) && (d==29) && (y%400==0) )
        return true;
    if ( (m==2) && (d==29) && (y%100==0) )
        return false;
    if ( (m==2) && (d==29) && (y%4==0)  )
        return true;
    return true;
}

void medicine::set()
{
    cout<<"Enter details of the medicine: \n";
    cout<<"ID: ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"price: ";
    cin>>price;
    date:
    cout<<"Expiry date (dd mm yyyy): ";
    cin>>dd>>mm>>yy;
    if(!checkDate(dd,mm,yy))
    {
        cout<<"Invalid date\n";
        goto date;
    }
}

void medicine::set(int id1,string name1,float price1,int dd1, int mm1, int yy1)
{
    id=id1;
    name=name1;
    price=price1;
    dd=dd1;
    mm=mm1;
    yy=yy1;
}

void medicine::add_store(store *s2)
{
    int i,flag=0;
    for(i=0;i<s1_no;i++)
    {
        if(s1[i]->getid()==s2->getid())
        {
            flag=1;
            break;
        }
    }
    if(!flag)
        s1[s1_no++]=s2;
}

void medicine::mset(manufacturer *m1)
{
    m=m1;
}

int medicine::getid()
{
    return id;
}

void medicine::update()
{
    int ch;
    cout<<"\n1.Name\n2.Price\n3.Expiry Date\n";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"\nEnter new name: ";
            cin>>name;
            break;
        case 2:cout<<"\nEnter new price: ";
            cin>>price;
            break;
        case 3:cout<<"\nEnter new expiry date(dd mm yyyy): ";
            cin>>dd>>mm>>yy;
            break;
    }
}

int main()
{
    return 0;
}

#include "medicine.h"
#include "store.h"
#include "manufacturer.h"
#include <iostream>
#include <cstring>
using namespace std;
//using namespce std;

class medicine;
class store;
class manufacturer;

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

        void manufacturer::shift()
        {
            int i,j;
            for(i=0;i<med_no;i++)
            {
                if(m[i]==NULL)
                {
                    if(i==med_no-1)
                        med_no--;
                    else
                    {
                        for(j=i;j<med_no;j++)
                        {
                            m[j]=m[j+1];
                            med_no--;
                        }
                    }
                }
            }
        }

        string manufacturer::getname()
        {
            return name;
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

        void manufacturer::addmed(medicine *m1)
        {
            m[med_no]=m1;
            med_no++;
        }

        void manufacturer::set(int id1,string name1,string add1,string no1)
        {
            id=id1;
            name=name1;
            add=add1;
            no=no1;
        }

        void manufacturer::update()
        {
            int ch;
            cout<<"\n1.Name\n2.Address\n3.Phone number\n";
            cin>>ch;
            switch(ch)
            {
                case 1:cout<<"\nEnter new name: ";
                    cin>>name;
                    break;
                case 2:cout<<"\nEnter new address: ";
                    cin>>add;
                    break;
                case 3:cout<<"\nEnter new phone no: ";
                    cin>>no;
                    break;
            }
        }

int main()
{
    return 0;
}

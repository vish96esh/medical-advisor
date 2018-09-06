#include "store.h"
#include "store_list.h"
#include <iostream>
#include <cstring>
#include "medicine.h"
#include "manufacturer.h"
using namespace std;

class medicine;
class manufacturer;
class store_list;
//class store;


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

int medicine::getid()
{
    return id;
}

string medicine::getname()
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

        store::store()
        {
            id=0;
            name="";
            location="";
            address="";
            no="";
            discount=0;
     //       *m=new medicine[1000];
            med_no=0;
        }

        int store::getid()
        {
            return id;
        }

        string store::getname()
        {
            return name;
        }

        string store::getLocation()
        {
            return location;
        }

        void store::addstore(int id1)
        {
            int ch;
            cout<<"Enter details of the store: \n\n";
            /*cout<<"ID: ";
            cin>>id1;
            if(validID(id1,3))
            {
                cout<<"Store already present. Please enter a valid ID\n";
                cout<"1.Input again\n2.Go back\n";
                cin>>ch;
                if(ch==1)
                    addstore();
                else
                    return;
            }*/
            id=id1;
            cout<<"Name: ";
            cin>>name;
            cout<<"Location: ";
            cin>>location;
            cout<<"Address: ";
            cin>>address;
            cout<<"Phone no.: ";
            cin>>no;
            cout<<"Enter the discount rate: ";
            cin>>discount;
            //cout<<"Do you want to add medicines?<Y=1,N=0>\n";
            //cin>>ch;
            //if(ch==1)
              //  addmed(id);
        }

        void store::set(int id1,string name1,string location1)
        {
            id=id1;
            name=name1;
            location=location1;
        }

        void store::shift()
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

        void store::addmed(medicine *m1)
        {
            m[med_no]=m1;
            quantity[med_no][0]=m1->getid();
            cout<<"Enter quantity of the medicine\n";
            cin>>quantity[med_no][1];
        }

        int store::getQuantity(int id)
        {
            for(int i=0;i<med_no;i++)
            {
                if(quantity[i][0]==id)
                    return quantity[i][1];
            }
            return -1;
        }

        void store::display()
        {
            cout<<"Details of the store are: \n\n";
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Location: "<<location<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Phone no.: "<<no<<endl;
            cout<<"Discount: "<<discount<<endl;
            cout<<"Do you want to view the mdecines available in the store?<Y=1,N=0>\n";
            int ch;
            cin>>ch;
            if(ch==1)
                showmed();
        }

        void store::showmed()
        {
            int j;
            for(int i=0;i<med_no;i++)
            {
                cout<<i+1<<")\n";
                m[i]->display(0);
                cout<<"\nQuantity left: ";
                for(j=0;j<med_no;j++)
                {
                    if(quantity[j][0]==m[i]->getid())
                        cout<<quantity[j][1];

                }
                cout<<endl<<endl;
            }
        }

        int store::update() //returns 1 if discount rate is changed
        {

            int ch,i,j,flag,ch1;
            cout<<"\n1.Name\n2.Location and Address\n3.Phone number\n4.Medicine quantity\n5.Discount\n";
            cin>>ch;
            switch(ch)
            {
                case 1:cout<<"\nEnter new name: ";
                    cin>>name;
                    break;
                case 2:cout<<"\nEnter new location: ";
                    cin>>location;
                    cout<<"\nEnter new address: ";
                    cin>>address;
                    break;
                case 3:cout<<"\nEnter new Phone number: ";
                    cin>>no;
                    break;
                case 4:medloop:
                    cout<<"\nEnter the ID of the medicine: ";
                    int med_id;
                    cin>>med_id;
                    for(i=0;i<med_no;i++)
                    {
                        if(m[i]->getid()==med_id)
                        {
                            cout<<"Enter the new quantity of "<<m[i]->getname()<<": ";
                            for(j=0;j<med_no;j++)
                            {
                                if(quantity[j][0]==m[i]->getid())
                                {
                                    cin>>quantity[j][1];
                                    break;
                                }
                            }
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<"\nMedicine not found. Do you want to enter id again?<Y=1,N=0>\n";
                        cin>>ch1;
                        if(ch1==1)
                            goto medloop;
                        else
                            return 0;
                    }
                    break;
                case 5:cout<<"Enter the new rate of discount: ";
                    cin>>discount;
                    return 1;
            }
            return 0;
        }

int main()
{
    return 1;
}

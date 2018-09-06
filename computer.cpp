#include "computer.h"
#include "medicine.h"
#include "manufacturer.h"
#include "store.h"
#include "user.h"
#include "customer.h"
#include "employee.h"
#include "store_list.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


class user;
class store;
class medicine;
class manufacturer;
class store_list;
class customer;
class employee;

user* computer::u=NULL;
//int computer::u_no=0;
medicine computer::med[1000]={};
manufacturer computer::man[50]={};
store_list* computer::start=NULL;
disease computer::dis[50]={};
int computer::d_no=0;
int computer::med_no=0;
int computer::man_no=0;
int computer::s_no=0;

computer::computer()
{
    //u=new user;
    pos=0;
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

medicine::medicine()
{
    id=0;
    name="";
    price=0.0;
    dd=0;mm=0;yy=0;
    s1_no=0;
  //  *s1=new store[100]
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

customer::customer()
        {
            *cart=new medicine[100];
            quant=new int[100];
            c_no=0;
            total=0;
        }

int store::getid()
        {
            return id;
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

        int manufacturer::getid()
        {
            return id;
        }

string medicine::getname()
{
    return name;
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

store_list::store_list(store ptr)
{
    s=ptr;
    next=NULL;
}

string user::getname()
{
    return name;
}

string user::getid()
{
    return id;
}

string user::getpass()
{
    return pass;
}

string user::getlocation()
{
    return location;
}

char user::gettype()
{
    return type;
}

void user::setlocation(string location1)
{
    location=location1;
}

void user::setid(string id1)
{
    id=id1;
}

void user::settype(char type1)
{
    type=type1;
}

void user::setname(string name1)
{
    name=name1;
}

void user::setpass(string pass1)
{
    pass=pass1;
}

int medicine::getid()
{
    return id;
}

void user::welcome(){}

void customer::welcome()
{
    cout<<"Welcome "<<name<<"!!\n";
    cout<<"1.Search\n2.Show cart\n3.Profile\n4.Exit\n";
    int ch,ch1;
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
        case 1:cout<<"1.Medicine\n2.Manufacturer\n3.Store\n4.Go back";
            cin>>ch1;
            switch(ch1)
            {
                case 1:search_med();
                    break;
                /*case 2:search_man();
                    break;
                case 3:search_store();
                    break;*/
                case 4:welcome();
                    return;
                    // break;
            }
            break;
        case 2:show_cart();
            break;
        case 3:display();
            break;
        case 4:return;
    }
    welcome();
}

void employee::welcome()
        {
            cout<<"Welcome Employee!!\n1.Add medicine\n2.Update medicine\n3.Delete medicine\n4.Add manufacturer\n5.Update manufacturer\n6.Delete manufacturer\n7.Add Store\n8.Update store\n9.Delete store\n10.Exit\n";
            int ch;
            cin>>ch;
            switch(ch)
            {
                case 1:add_med();
                    break;
                case 2:update('m');
                    break;
                case 3:del_med();
                    break;
                case 4:add_man();
                    break;
                case 5:update('M');
                    break;
                case 6:del_man();
                    break;
                case 7:start=add_store(start);
                    break;
                case 8:start=update(start);
                    break;
                case 9:start=del_s(start);
                    break;
                case 10:return;
            }
            welcome();
        }

void user::display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Location: "<<location<<endl;
}

void customer::search_med()
        {
            int q;
            medicine *m1=get_med();
            m1->display(0);
            cout<<"\n\n1.Add medicine to cart\n2.Show alternatives\n3.Search another medicine\n4.Go back\n";
            int ch,ch2;
            cin>>ch;
            switch(ch)
            {
                case 1:abc:
                    cout<<"Enter quantity: ";
                    cin>>q;
                    //if(checkQuantity(m1,q))
                        add_med_to_cart(m1,q);
                    /*else
                    {
                        cout<<"Not enough medicines left\nDo you want to enter quantity again <Y=1,N=0>\n";
                        cin>>ch2;
                        if(ch2==1)
                            goto abc;
                    }*/
                    cout<<endl<<endl<<"\n1.Search another medicines\n2.Checkout\n";
                    cin>>ch2;
                    if(ch2==1)
                        search_med();
                    else
                        checkout();
                    break;
                //case 2:show_alternatives(m1);
                  //  break;
                case 3:search_med();
                    break;
                case 4:return;
            }
        }

void customer::show_cart()
        {
            int i,ch;
            cout<<"SNO.\tname\tid\tprice\tquantity\ttotal\n";
            for(i=0;i<c_no;i++)
            {
                cout<<i+1<<".    "<<cart[i]->getname()<<"\t"<<cart[i]->getid()<<"\t"<<cart[i]->getprice()<<"\t"<<quant[i]<<"\t"<<cart[i]->getprice()*quant[i]<<endl;
                total+=cart[i]->getprice()*quant[i];
            }
            cout<<endl<<endl<<"Total Amount: "<<total<<endl<<endl;
            cout<<endl<<"1.Checkout\n2.Remove item\n3.clear all\n";
            cin>>ch;
            switch(ch)
            {
                case 1:checkout();
                    break;
                case 2:cout<<"\nEnter the id you want to delete\n";
                    if(c_no==0)
                    {
                        cout<<"Oops!! cart empty.\n";
                        break;
                    }
                    int id1;
                    cin>>id1;
                    for(i=0;i<c_no;i++)
                    {
                        if(cart[i]->getid()==id1)
                        {
                            cart=shift(cart,i);
                            break;
                        }
                    }
                    search_med();
                    break;
                case 3:*cart=new medicine[100];
                    quant=new int[100];
                    c_no=0;
                    total=0;
                    search_med();
                    break;
            }
        }

void employee::add_med()
        {
            int i,id1,flag=0;
            //med[med_no]=new medicine;
            med[med_no].set();
            cout<<"Enter manufacturer details: \n";
            cout<<"ID: ";
            cin>>id1;
            //checking if the manufacturer is an existing manufacturer by searching manufacturer list by its id
            for(i=0;i<man_no;i++)
            {
                if(man[i].getid()==id1)
                {
                    cout<<"\nManufacturer found\n\n";
                    man[i].display();
                    //med[med_no].mset(man[i].id,man[i].name,man[i].add,man[i].no);
                    //man[i].add_med(med[med_no].id,med[med_no].name,med[med_no].price,med[med_no].dd,med[med_no].mm,med[med_no].yy);
                    med[med_no].mset(&man[i]);
                    man[i].addmed(&med[med_no]);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                string name1,add1,no1;
                cout<<"\nManufacturer not found\nEnter the details of the manufacturer\n\n";
                //man[man_no]=new manufacturer;
                cout<<"Name: ";
                cin>>name1;
                cout<<"Address: ";
                cin>>add1;
                cout<<"Phone no: ";
                cin>>no1;
                man[man_no].set(id1,name1,add1,no1);
                //man[man_no].add_med(med[med_no].id,med[med_no].name,med[med_no].price,med[med_no].dd,med[med_no].mm,med[med_no].yy);
                man[man_no].addmed(&med[med_no]);
                med[med_no].mset(&man[man_no]);
                man_no++;
            }
            med_no++;
        }

store_list* employee::update(store_list *start1)
        {
            cout<<"\nEnter store id: ";
            int id1,flag=0;
            cin>>id1;
            store_list *ptr=start1;
            while(ptr!=NULL)
            {
                if(ptr->s.getid()==id1)
                {
                    int x=ptr->s.update();
                    if(x==1)
                        start1=rearrange(start1);
                    return start1;
                }
                ptr=ptr->next;
            }
            cout<<"\nStore not found. Do you want to enter id again?<Y=1,N=0>\n";
            int ch;
            cin>>ch;
            if(ch==1)
                start1=update(start1);
            else
                return start1;
        }

void employee::update(char c)
        {
            int i,id1,flag=0;
            switch(c)
            {
                case 'm':loop1:
                    cout<<"\nEnter the medicine id: ";
                    cin>>id1;
                    for(i=0;i<med_no;i++)
                    {
                        if(med[i].getid()==id1)
                        {
                            med[i].update();
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<"\nMedicine not found. Do you want to enter id again?<Y=1,N=0>\n";
                        int ch;
                        cin>>ch;
                        if(ch==1)
                            goto loop1;
                        else
                            return;
                    }
                    break;
                case 'M':loop2:
                    cout<<"\nEnter manufacturer id: ";
                    cin>>id1;
                    for(i=0;i<man_no;i++)
                    {
                        if(man[i].getid()==id1)
                        {
                            man[i].update();
                            flag=1;
                            break;
                        }
                    }
            if(flag==0)
            {
            cout<<"\nManufacturer not found. Do you want to enter id again?<Y=1,N=0>\nl";
            int ch;
            cin>>ch;
            if(ch==1)
                goto loop2;
            else
                return;
        }
        break;
    }
}

void employee::shift(int pos,char ch)
        {
            int i;
            /*switch(ch)
            {
                case 'm':x=med_no;
                    break;
                case 'M':x=man_no;
                    break;
                //case 's':x=s_no;
                  //  break;
            }*/
            switch(ch)
            {
                case 'm':for(i=pos;i<med_no;i++)
                    med[i]=med[i+1];
                    med_no--;
                    break;
                case 'M':for(i=pos;i<man_no;i++)
                    man[i]=man[i+1];
                    man_no--;
                    break;
                //case 's':s_no--;
                  //  break;
            }
           // return m;
        }

        void employee::del_man()
        {
            int id1,ch,i;
            cout<<"Enter the manufacturer ID: ";
            if(!validID(id1,2))
            {
                cout<<"Enter a valid id.\n1.Enter id again\n2.Exit\n";
                cin>>ch;
                if(ch==1)
                    del_man();
                else
                    return;
            }
            else
            {
                for(i=0;i<man_no;i++)
                {
                    if(man[i].getid()==id1)
                    {
                        shift(i,'M');
                        break;
                    }
                }
            }
        }

        void employee::del_med()
        {
            int id1,ch,i;
            cout<<"Enter the medicine ID: ";
            if(!validID(id1,1))
            {
                cout<<"Enter a valid id.\n1.Enter id again\n2.Exit\n";
                cin>>ch;
                if(ch==1)
                    del_med();
                else
                    return;
            }
            else
            {
                for(i=0;i<med_no;i++)
                {
                    if(med[i].getid()==id1)
                    {
                        delete(&med[i]);
                        shift(i,'m');
                        break;
                    }
                }
            }
        }

        store_list* employee::del_s(store_list *start1)
        {
            int id1,ch,i;
            cout<<"Enter the store ID: ";
            if(!validID(id1,3))
            {
                cout<<"Enter a valid id.\n1.Enter id again\n2.Exit\n";
                cin>>ch;
                if(ch==1)
                    start1=del_s(start1);
                else
                    return start1;
            }
            else
            {
                /*for(i=0;i<s_no;i++)
                {
                    if(s[i].id==id1)
                    {
                        free(s[i]);
                        s=shift(s,i);
                        break;
                    }
                }*/
                store_list *ptr=start1;
                if(ptr->s.getid()==id1)
                {
                    start1=start1->next;
                    s_no--;
                    return start1;
                }
                while(ptr->next!=NULL)
                {
                    if(ptr->next->s.getid()==id1)
                    {
                        ptr->next=ptr->next->next;
                        delete(ptr->next);
                        //s=shift(s,i);
                        s_no--;
                        break;
                    }
                    ptr=ptr->next;
                }
                return start1;
            }
        }

void employee::add_man()
        {
            int id1;
            string name1,add1,no1;
            cout<<"Enter the details of the manufaturer: \n\n";
            //man[man_no]=new manufacturer;
            cout<<"ID: ";
            cin>>id1;
            cout<<"Name: ";
            cin>>name1;
            cout<<"Address: ";
            cin>>add1;
            cout<<"Phone no: ";
            cin>>no1;
            man[man_no].set(id1,name1,add1,no1);
            man_no++;
        }

        void employee::add_med_to_store()
        {
            int id1,ch,ch1,id2;
            string name1,man1;
            medicine *m1;
            store *s1;
            cout<<"\nEnter your store ID\n";
            cin>>id2;
            if(!validID(id2,3))
            {
                cout<<"Store not found, do you want to add a new store? <Y=1,N=0>\n";
                cin>>ch1;
                if(ch1==1)
                    start=add_store(start);
                else
                    return;
            }
            //id1=get_med_id();
            //m1=get_med_by_id(id1);
            m1=get_med();
            /*for(i=0;i<s_no;i++)
            {
                if(s[i].id==id2)
                {
                    s[i].addmed(m1);
                    break;
                }
            }*/
            store_list *ptr=start;
            while(ptr!=NULL)
            {
                if(ptr->s.getid()==id2)
                {
                    s1=&(ptr->s);
                    ptr->s.addmed(m1);
                    break;
                }
                ptr=ptr->next;
            }
            //s1=get_store_by_id(id2);
            m1->add_store(s1);
        }

        store_list* employee::add_store(store_list *start1)
        {
            store_list *ptr,*temp,*temp1;
            ptr=new store_list();
            if(start1==NULL)
            {
               start1=ptr;
               s_no++;
            }
            else
            {
                if(ptr->s.discount>=start1->s.discount)
                {
                    ptr->next=start;
                    start1=ptr;
                    s_no++;
                    return start1;
                }
                temp=start1;
                temp1=temp->next;
                while(temp!=NULL)
                {
                    if(temp1==NULL)
                    {
                        temp->next=ptr;
                        s_no++;
                        break;
                    }
                    if(ptr->s.discount<temp->s.discount && ptr->s.discount>temp1->s.discount)
                    {
                        ptr->next=temp1;
                        temp->next=ptr;
                        s_no++;
                        break;
                    }
                    temp=temp->next;
                    temp1=temp->next;
                }
            }
            cout<<"\n\nDo you want to add medicines? <Y=1, N=0>\n";
            int ch;
            cin>>ch;
            if(ch==1)
                add_med_to_store();
            return start1;
        }

        store_list* employee::rearrange(store_list *start1)
        {
            store_list *temp,*ptr1,*ptr2,*nptr,*prev2,*prev1=NULL,*nprev;
            ptr1=start1;
            float big;
            int flag=0,ctr=0;
            while(ptr1!=NULL)
            {
                flag=0;
                ctr=0;
                big=ptr1->s.discount;
                prev2=ptr1;
                ptr2=ptr1->next;
                temp=ptr1->next;
                while(ptr2!=NULL)
                {
                    if(ptr2->s.discount>big)
                    {
                        nprev=prev2;
                        nptr=ptr2;
                        big=ptr2->s.discount;
                        ctr++;
                    }
                    prev2=prev2->next;
                    ptr2=ptr2->next;
                }
                if(ctr==0)
                {
                    prev1=ptr1;
                    ptr1=ptr1->next;
                    continue;
                }
                if(ptr1->next==nptr)
                    flag=1;
                ptr1->next=nptr->next;
                if(flag==1)
                    nptr->next=ptr1;
                else
                {
                    nptr->next=temp;
                    nprev->next=ptr1;
                }
                if(prev1==NULL)
                    start1=nptr;
                else
                    prev1->next=nptr;
                ptr1=nptr;
                prev1=ptr1;
                ptr1=ptr1->next;
            }
            return start1;
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

medicine** customer::shift(medicine *c1[100],int pos)
        {
            int i;
            for(i=pos;i<c_no-1;i++)
                c1[i]=c1[i+1];
            c_no--;
            return c1;
        }

void medicine::mset(manufacturer *m1)
{
    m=m1;
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

void store::addmed(medicine *m1)
        {
            m[med_no]=m1;
            quantity[med_no][0]=m1->getid();
            cout<<"Enter quantity of the medicine\n";
            cin>>quantity[med_no][1];
        }

string store::getLocation()
        {
            return location;
        }

store_list::store_list()
{
    s.addstore();
    next=NULL;
}

void store::addstore()
        {
            int ch;
            cout<<"Enter details of the store: \n\n";
            cout<<"ID: ";
            cin>>id;
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

int store::getQuantity(int id)
        {
            for(int i=0;i<med_no;i++)
            {
                if(quantity[i][0]==id)
                    return quantity[i][1];
            }
            return -1;
        }

string store::getname()
        {
            return name;
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

void customer::add_med_to_cart(medicine *m,int q)
{
    cart[c_no]=m;
    quant[c_no]=q;
    c_no++;
    total+=m->getprice()*q;
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

void customer::choice1()
{
    store_list *ptr;
    float amt1=0,amt[100],total1=0;
    int i,j,new_quant,ctr=0;
    for(i=0;i<c_no;i++)
    {
        new_quant=quant[i];
        ptr=start;
        ctr=0;
        cout<<i+1<<".    "<<cart[i]->getname()<<"\t"<<cart[i]->getid()<<"\n";
        while(ptr!=NULL&&new_quant!=0)
        {
            for(j=0;j<cart[i]->s1_no;j++)
            {
                if(cart[i]->s1[j]->getid()==ptr->s.getid()&&ptr->s.getQuantity(cart[i]->getid())!=0)
                {
                    cout<<++ctr<<".\nStore name= "<<ptr->s.getname()<<endl;
                    if(cart[i]->s1[j]->getQuantity(cart[i]->getid())<new_quant)
                    {
                        amt1+=((cart[i]->getprice())-(cart[i]->getprice())*(cart[i]->s1[j]->discount/100))*cart[i]->s1[j]->getQuantity(cart[i]->getid());
                        cout<<"Quantity= "<<cart[i]->s1[j]->getQuantity(cart[i]->getid())<<endl;
                        cout<<"Amount= "<<((cart[i]->getprice())-(cart[i]->getprice())*(cart[i]->s1[j]->discount/100))*cart[i]->s1[j]->getQuantity(cart[i]->getid())<<endl;
                        new_quant-=cart[i]->s1[j]->getQuantity(cart[i]->getid());
                        break;
                    }
                    amt1+=((cart[i]->getprice())-(cart[i]->getprice())*(cart[i]->s1[j]->discount/100))*new_quant;
                    cout<<"Quantity= "<<new_quant<<endl;
                    cout<<"Amount= "<<((cart[i]->getprice())-(cart[i]->getprice())*(cart[i]->s1[j]->discount/100))*new_quant<<endl;
                    new_quant=0;
                }
            }
            cout<<endl;
            ptr=ptr->next;
        }
        cout<<"Total amount for medicine "<<cart[i]->getname()<<"= "<<amt1<<endl;
        amt[i]=amt1;
        total1+=amt1;
        amt1=0;
        cout<<endl<<endl;
    }
    cout<<endl<<"Total amount = "<<total1<<endl;
    cout<<"Do you want to see store details?<Y=1.N=0>"<<endl;
    int ch,id1;
    cin>>ch;
    store *s1;
    if(ch==1)
    {
        choice:
        cout<<"Enter the store id: ";
        cin>>id1;
        if(validID(id1,3))
            s1=get_store_by_id(id1);
        else
        {
            int ch2;
            cout<<"Invalid id. Do you want see store details again?<Y=1,N=0>\n";
            cin>>ch2;
            if(ch2==1)
                goto choice;
            else
                return;
        }
        s1->display();
    }
}

        void customer::choice2()
        {
            store_list *ptr;
            float amt1=0,amt[100],total1=0;
            int i,j,new_quant,ctr=0;
            for(i=0;i<c_no;i++)
            {
                new_quant=quant[i];
                ptr=start;
                ctr=0;
                cout<<i+1<<".    "<<cart[i]->getname()<<"\t"<<cart[i]->getid()<<"\n";
                while(ptr!=NULL&&new_quant!=0)
                {
                    for(j=0;j<cart[i]->s1_no;j++)
                    {
                        if((cart[i]->s1[j]->getid()==ptr->s.getid())&&(cart[i]->s1[j]->getLocation()==location)&&ptr->s.getQuantity(cart[i]->getid())!=0)
                        {
                            cout<<++ctr<<".\nStore name= "<<ptr->s.getname()<<endl;
                            if(cart[i]->s1[j]->getQuantity(cart[i]->getid())<new_quant)
                            {
                                amt1+=((cart[i]->getprice())-(cart[i]->getprice())*(cart[i]->s1[j]->discount/100))*cart[i]->s1[j]->getQuantity(cart[i]->getid());
                                cout<<"Quantity= "<<cart[i]->s1[j]->getQuantity(cart[i]->getid())<<endl;
                                cout<<"Amount= "<<((cart[i]->getprice())-(cart[i]->getprice())*(cart[i]->s1[j]->discount/100))*cart[i]->s1[j]->getQuantity(cart[i]->getid())<<endl;
                                new_quant-=cart[i]->s1[j]->getQuantity(cart[i]->getid());
                                break;
                            }
                            amt1+=((cart[i]->getprice())-(cart[i]->getprice())*(cart[i]->s1[j]->discount/100))*new_quant;
                            cout<<"Quantity= "<<new_quant<<endl;
                            cout<<"Amount= "<<((cart[i]->getprice())-(cart[i]->getprice())*(cart[i]->s1[j]->discount/100))*new_quant<<endl;
                            new_quant=0;
                        }
                    }
                    cout<<endl;
                    ptr=ptr->next;
                }
                cout<<"Total amount for medicine "<<cart[i]->getname()<<"= "<<amt1<<endl;
                amt[i]=amt1;
                total1+=amt1;
                amt1=0;
                cout<<endl<<endl;
            }
            cout<<endl<<"Total amount = "<<total1<<endl;
            cout<<"Do you want to see store details?<Y=1.N=0>"<<endl;
            int ch,id1;
            cin>>ch;
            store *s1;
            if(ch==1)
            {
                choice:
                cout<<"Enter the store id: ";
                cin>>id1;
                if(validID(id1,3))
                    s1=get_store_by_id(id1);
                else
                {
                    int ch2;
                    cout<<"Invalid id. Do you want see store details again?<Y=1,N=0>\n";
                    cin>>ch2;
                    if(ch2==1)
                        goto choice;
                    else
                        return;
                }
                s1->display();
            }

        }

        void customer::choice3()
        {
            store_list *ptr=start;
            int i,j,flag=0,ctr=0;
            cout<<endl<<endl<<"stores: \n\n";
            while(ptr!=NULL)
            {
                ctr=0;
                for(i=0;i<c_no;i++)
                {
                    if(ptr->s.getQuantity(cart[i]->getid())==0)
                        continue;
                    for(j=0;j<ptr->s.med_no;j++)
                    {
                        if(ptr->s.m[j]->getid()==cart[i]->getid())
                        {
                            ctr++;
                            break;
                        }
                    }
                }
                if(ctr==c_no)
                {
                    ptr->s.display();
                    cout<<endl;
                    flag=1;
                }
                ptr=ptr->next;
            }
            if(flag==0)
                cout<<"sorry no such store found\n";

        }

        void customer::choice4()
        {
            store_list *ptr=start;
            int i,j,flag=0,ctr=0;
            cout<<endl<<endl<<"stores: \n\n";
            while(ptr!=NULL)
            {
                if(!(ptr->s.getLocation()==location))
                {
                    ptr=ptr->next;
                    continue;
                }
                ctr=0;
                for(i=0;i<c_no;i++)
                {
                    if(ptr->s.getQuantity(cart[i]->getid())==0)
                        continue;
                    for(j=0;j<ptr->s.med_no;j++)
                    {
                        if(ptr->s.m[j]->getid()==cart[i]->getid())
                        {
                            ctr++;
                            break;
                        }
                    }
                }
                if(ctr==c_no)
                {
                    ptr->s.display();
                    cout<<endl;
                    flag=1;
                }
                ptr=ptr->next;
            }
            if(flag==0)
            {
                cout<<"sorry no such store found in your locality. Do you want to search in other localities?<Y=1,N=0>\n";
                int ch;
                cin>>ch;
                if(ch==1)
                    choice4();
                else
                    return;
            }
        }

        void customer::checkout()
        {
            int i,ch,j;
            cout<<"1.Minimum bill amount\n2.Minimum amount at your locality\n3.All medicines in one store\n4.All medicines in a store in your locality\n";
            cin>>ch;
            switch(ch)
            {
                case 1:choice1();
                    break;
                case 2:choice2();
                    break;
                case 3:choice3();
                    break;
                case 4:choice4();
                    break;
            }
        }

float medicine::getprice()
{
    return price;
}

void computer::load()
{
    int i=0;//,j=0,id1;
    manufacturer obj1;
    medicine obj2;
    //string name1,add1,no1;
    float price1;
    ifstream i1,i2,i3;
    i1.open("manufacturer_db",ios::in|ios::binary);
    if(!i1)
        cout<<"Manufacturer list empty. Please enter some data\n";
    else
    {
        while(i1.read((char *)&obj1,sizeof(obj1)))
        {
            //man[i]=new manufacturer;
            man[i++]=obj1;
        }
        man_no=i;
    }
    i1.close();
    i2.open("medicine_db",ios::in|ios::binary);
    i=0;
    if(!i2)
        cout<<"medicine list empty. please enter some data\n";
    else
    {
        while(i2.read((char *)&obj2,sizeof(obj2)))
        {
            //med[i]=new medicine;
            med[i++]=obj2;
        }
        med_no=i;
    }
    i2.close();
    i3.open("store_db",ios::in|ios::binary);
    store obj3;
    if(!i3)
        cout<<"Store list empty. Please enter some data\n";
    else
    {
        store_list *ptr,*end=NULL;
        start=NULL;
        i=0;
        while(i3.read((char *)&obj3,sizeof(obj3)))
        {
            ptr=new store_list(obj3);
            if(start==NULL)
            {
                start=ptr;
                end=ptr;
            }
            else
            {
                end->next=ptr;
                end=ptr;
            }
            i++;
        }
        s_no=i;
    }
    i3.close();
}

        void computer::save()
        {
            ofstream o1,o2,o3;
            int i;
            o1.open("medicine_db",ios::app|ios::binary);
            for(i=0;i<med_no;i++)
            {
                o1.write((char *)&med[i],sizeof(medicine));
            }
            o1.close();
            o2.open("manufacturer_db",ios::app|ios::binary);
            for(i=0;i<man_no;i++)
            {
                o2.write((char *)&man[i],sizeof(manufacturer));
            }
            o2.close();
            o3.open("store_db",ios::app|ios::binary);
            store_list *ptr=start;
            while(ptr!=NULL)
            {
                o3.write((char *)&ptr->s,sizeof(store));
                ptr=ptr->next;
            }
            o3.close();
        }

int computer::login(string id1)
{
    string pass1;
    int ch;
    ifstream filein;
    filein.open("users",ios::in|ios::binary);
    if(!filein)
    {
        cout<<"File Empty.\n";
        return -1;
    }
    user obj;
    while (filein.read((char *)&obj,sizeof(obj)))
    {
        /*cout<<"loop\n";
        cout<<obj.getid()<<endl;*/
        if(obj.getid()==id1)
        {
            cout<<"Enter your password\n";
            cin>>pass1;
            if(obj.getpass()!=pass1)
                return 1;
            if(obj.gettype()=='c')
            {
                u=new customer;
                cout<<"Customer\n";
            }
            else
            {
                u=new employee;
                cout<<"Employee\n";
            }
            u->setname(obj.getname());
            u->settype(obj.gettype());
            u->setlocation(obj.getlocation());
            u->setid(obj.getid());
            u->setpass(obj.getpass());
            return 0;
        }
    }
    return 1;
}

        int computer::signup()
        {
            string name1,id1,pass1,location1;
            char type1;
            int ch;
            cout<<"Enter a username: ";
            cin>>id1;
            user obj;
            ifstream filein;
            filein.open("users",ios::in|ios::binary);
            if(!filein)
                cout<<"File Empty.\n";
            else
            {
                while(filein.read((char *)&obj,sizeof(obj)))
                {
                    cout<<obj.getid()
                    if(obj.getid()==id1)
                    {
                        cout<<"Username already in use\n";
                        return -1;
                    }
                }
            }
            filein.close();
            ofstream fileout;
            fileout.open("users",ios::app|ios::binary);
            if(!fileout)
            {
                cout<<"Error!\n";
                return -1;
            }
            else
            {
                //string name1,id1,pass1,location1;
                //char type1;
                user obj1;
                obj1.setid(id1);
                cout<<"Enter your name: ";
                cin>>name1;
                cout<<"Enter your password: ";
                cin>>pass1;
                cout<<"1.Customer\n2.Employee\n";
                int ch2;
                cin>>ch2;
                if(ch2==1)
                    type1='c';
                else
                    type1='e';
                cout<<"Enter your location\n";
                cin>>location1;
                obj1.setname(name1);
                obj1.setpass(pass1);
                obj1.settype(type1);
                obj1.setlocation(location1);
                fileout.write((char *)&obj1,sizeof(user));
                fileout.close();
                return 1;
                /*if(ch2==1)
                {
                    obj1.type='c';
                    u[u_no]=new customer;
                    u[u_no].new_user(id1,name1,pass1,type1);
                    u_no++;
                }

                else
                {
                    type1='e';


                        employee verification
                        use file handling

                    comment till here
                    u[u_no]=new employee;
                    u[u_no]=new_user(id1,name1,pass1,type1);
                    //add details to employee object from file correspondingly
                    u_no++;
                }*/
            }
        }

        medicine* computer::get_med_by_id(int id1)
        {
            int i;
            for(i=0;i<med_no;i++)
            {
                if(med[i].getid()==id1)
                    return &med[i];
            }
            return NULL;
        }

        store* computer::get_store_by_id(int id2)
        {
            store_list *ptr=start;
            while(ptr!=NULL)
            {
                if(ptr->s.getid()==id2)
                    return &ptr->s;
                ptr=ptr->next;
            }
            return NULL;
        }

        manufacturer* computer::get_man_by_id(int id1)
        {
            int i;
            for(i=0;i<man_no;i++)
            {
                if(man[i].getid()==id1)
                    return &man[i];
            }
            return NULL;
        }

        bool computer::validID(int id1,int t)
        {
            int i;
            if(t==1)
            {
                for(i=0;i<med_no;i++)
                {
                    if(med[i].getid()==id1)
                        return true;
                }
            }
            else if(t==2)
            {
                for(i=0;i<man_no;i++)
                {
                    if(man[i].getid()==id1)
                        return true;
                }
            }
            else
            {
                store_list *ptr=start;
                while(ptr!=NULL)
                {
                    if(ptr->s.getid()==id1)
                        return true;
                    ptr=ptr->next;
                }
            }
            return false;
        }

        medicine* computer::search_med_by_man(string man1)
        {
            int i,ctr=0,ch;
            for(i=0;i<man_no;i++)
            {
                if(man[i].getname()==man1)
                {
                    cout<<ctr+1<<".\n";
                    man[i].display();
                    cout<<endl;
                    ctr++;
                }
            }
            if(ctr==0)
                return NULL;
            else
            {
                check:
                cout<<"Enter the manufacturer id\n";
                int id1;
                cin>>id1;
                if(!validID(id1,2))
                {
                    cout<<"Invalid ID. Do you want to enter again? <Y=1,N=0>\n";
                    cin>>ch;
                    if(ch==1)
                        goto check;
                    else
                        return NULL;
                }
                return get_med_by_id(id1);
            }
        }

medicine* computer::search_med_by_name(string name1)
{
    int i,ctr=0,ch;
    for(i=0;i<med_no;i++)
    {
        if(med[i].getname()==name1)
        {
            med[i].display(0);
            cout<<endl;
            ctr++;
        }
    }
    if(ctr==0)
        return NULL;
    else
    {
        check:
        cout<<"Enter the medicine id\n";
        int id1;
        cin>>id1;
        if(!validID(id1,1))
        {
            cout<<"Invalid ID. Do you want to enter again? <Y=1,N=0>\n";
            cin>>ch;
            if(ch==1)
                goto check;
            else
                return NULL;
        }
        return get_med_by_id(id1);
    }
}

medicine* computer::get_med()
{
    int ch,ch1;
    medicine *m2;
    string man1,name1;
    cout<<"1.Add by name\n2.Add by manufacturer\n";
    cin>>ch;
    switch(ch)
    {
        case 1:medloop1:
            cout<<"\nEnter the name of the medicine: ";
            cin>>name1;
            m2=search_med_by_name(name1);
            if(m2==NULL)
            {
                cout<<"\nEnter a valid name\n1.Enter name again\n2.Search by another criteria\n";
                cin>>ch1;
                if(ch1==1)
                    goto medloop1;
                else
                    return get_med();
            }
            break;
        case 2:medloop3:
            cout<<"\n1.Enter the name of manufacturer\n";
            cin>>man1;
            m2=search_med_by_man(man1);
            if(m2==NULL)
            {
                cout<<"\nEnter a valid manufacturer name\n1.Enter manufacturer name again\n2.Search by another criteria\n";
                cin>>ch1;
                if(ch1==1)
                    goto medloop3;
                else
                    return get_med();
            }
            break;
        default:cout<<"Wrong input\n1.Search medicines again\n2.Do other operation\n";
            cin>>ch1;
            if(ch1==1)
                return get_med();
            else
                return NULL;
    }
    return m2;
}

int main()
{
    return 0;
}

#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"
#include "user.h"
#include "medicine.h"
#include "manufacturer.h"
#include "store.h"
#include "store_list.h"
#include "computer.h"
#include "customer.h"
#include "disease.h"
using namespace std;



class medicine;
class manufacturer;
class computer;
class store;
class user;
class employee;
class customer;
class store_list;
class disease;

user* computer::u=NULL;
//int computer::u_no=0;
medicine computer::med[1000]={};
manufacturer computer::man[50]={};
store_list* computer::start=NULL;
int computer::med_no=0;
int computer::man_no=0;
int computer::s_no=0;
disease computer::dis[50]={};
int computer::d_no=0;

computer::computer()
{
    //u=new user;
//    pos=0;
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

store_list::store_list(int id1)
{
    s.addstore(id1);
    next=NULL;
}

store_list::store_list(store ptr)
{
    s=ptr;
    next=NULL;
}

customer::customer()
        {
            //*cart=new medicine[100];
            //cout<<"test\n";
            quant=new int[100];
            c_no=0;
            total=0;
        }

disease::disease()
{
    id=0;
    name="";
    m_no=0;
}

void user::welcome(){}

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

char user::gettype()
{
    return type;
}

string user::getlocation()
{
    return location;
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

void user::setlocation(string location1)
{
    location=location1;
}

void user::setpass(string pass1)
{
    pass=pass1;
}

void user::display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Location: "<<location<<endl;
}

void computer::save()
{
    ofstream o1,o2,o3,o4;
    int i,j;
    o1.open("medicine_db",ios::binary);
    for(i=0;i<med_no;i++)
    {
        //cout<<"foo\n";
        o1<<med[i].getid()<<" "<<med[i].getname()<<" "<<med[i].getprice()<<" "<<med[i].dd<<" "<<med[i].mm<<" "<<med[i].yy<<" "<<med[i].m->getid()<<" "<<med[i].s1_no<<" "<<med[i].d->id<<" \n";
        for(j=0;j<med[i].s1_no;j++)
            o1<<med[i].s1[j]->getid()<<" \n";
    }
        //o1.write((char *)&med[i],sizeof(medicine));
    o1.close();
    o2.open("manufacturer_db",ios::binary);
    for(i=0;i<man_no;i++)
    {
    //            o2.write((char *)&man[i],sizeof(manufacturer));
        o2<<man[i].getid()<<" "<<man[i].getname()<<" "<<man[i].add<<" "<<man[i].no<<" "<<man[i].med_no<<" \n";
        for(j=0;j<man[i].med_no;j++)
            o2<<man[i].m[j]->getid()<<" \n";
    }
    o2.close();
    o3.open("store_db",ios::binary);
    store_list *ptr=start;
    while(ptr!=NULL)
    {
        //o3.write((char *)&ptr->s,sizeof(store));
        o3<<ptr->s.getid()<<" "<<ptr->s.getname()<<" "<<ptr->s.getLocation()<<" "<<ptr->s.address<<" "<<ptr->s.no<<" "<<ptr->s.discount<<" "<<ptr->s.med_no<<" \n";
        for(j=0;j<ptr->s.med_no;j++)
            o3<<ptr->s.quantity[j][0]<<" "<<ptr->s.quantity[j][1]<<" \n";
        ptr=ptr->next;
    }
    o3.close();
    o4.open("disease_db",ios::binary);
    for(i=0;i<d_no;i++)
    {
        o4<<dis[i].id<<" "<<dis[i].name<<" "<<dis[i].m_no<<" \n";
        for(j=0;j<dis[i].m_no;j++)
            o4<<dis[i].m[j]->getid()<<" \n";
    }
    o4.close();
}

void computer::load()
{
    int man_id_for_med[1000];
    int med_id_for_man[50][100];
    int s_id_for_med[1000][100];
    int d_id_for_med[1000];
    int med_id_for_dis[50][10];
    //int med_id_for_store[100][100];
    int id1,id2,mid,i=0,j;//,j=0,id1;
    //manufacturer obj1;
    //medicine obj2;
    string name1,add1,no1;
    float price1;
    ifstream i1,i2,i3,i4;
    i1.open("manufacturer_db",ios::in|ios::binary);
    if(!i1)
        cout<<"Manufacturer list empty. Please enter some data\n";
    else
    {
        i=0;
        int med_no1;
        //medicine *m1;
        //while(i1.read((char *)&obj1,sizeof(obj1)))
        while(i1>>id1>>name1>>add1>>no1>>med_no1)
        {
            man[i].set(id1,name1,add1,no1);
            man[i].med_no=med_no1;
            for(j=0;j<med_no1;j++)
            {
                i1>>id2;
                med_id_for_man[i][j]=id2;
                //m1=get_med_by_id(id2);
                //man[i].m[j]=m1;
            }
            //man[i]=new manufacturer;
            //man[i++]=obj1;
            i++;
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
        int dd1,mm1,yy1,s1_no1,did;
        //while(i2.read((char *)&obj2,sizeof(obj2)))
        while(i2>>id1>>name1>>price1>>dd1>>mm1>>yy1>>mid>>s1_no1>>did)
        {
            med[i].set(id1,name1,price1,dd1,mm1,yy1);
            med[i].s1_no=s1_no1;
            man_id_for_med[i]=mid;
            d_id_for_med[i]=did;
            //med[i]=new medicine;
            for(j=0;j<s1_no1;j++)
            {
                i2>>id2;
                s_id_for_med[i][j]=id2;
                //cout<<"s id for med "<<med[i].getname()<<" "<<s_id_for_med[i][j]<<endl;
            }
            i++;
        }
        med_no=i;
    }
    i2.close();
    i3.open("store_db",ios::in|ios::binary);
    store obj;
    if(!i3)
        cout<<"Store list empty. Please enter some data\n";
    else
    {
        store_list *ptr,*end=NULL;
        start=NULL;
        float discount1;
        i=0;
        //while(i3.read((char *)&obj3,sizeof(obj3)))
        string location1;
        int med_no1;
        while(i3>>id1>>name1>>location1>>add1>>no1>>discount1>>med_no1)
        {
            obj.set(id1,name1,location1);
            obj.address=add1;
            obj.no=no1;
            obj.med_no=med_no1;
            obj.discount=discount1;
            for(j=0;j<med_no1;j++)
                i3>>obj.quantity[j][0]>>obj.quantity[j][1];
            ptr=new store_list(obj);
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
    i4.open("disease_db",ios::in|ios::binary);
    if(!i4)
        cout<<"Disease list empty. Please enter some data\n";
    else
    {
        i=0;
        int m_no1;
        while(i4>>id1>>name1>>m_no1)
        {
            dis[i].id=id1;
            dis[i].name=name1;
            dis[i].m_no=m_no1;
            for(j=0;j<m_no1;j++)
                i4>>med_id_for_dis[i][j];
            i++;
        }
        d_no=i;
    }
    manufacturer *m1;
    store *s2;
    disease *d2;
    //cout<<"foo\n";
    for(i=0;i<med_no;i++)
    {
        m1=get_man_by_id(man_id_for_med[i]);
        d2=get_disease_by_id(d_id_for_med[i]);
        med[i].d=d2;
        med[i].mset(m1);
        for(j=0;j<med[i].s1_no;j++)
        {
            s2=get_store_by_id(s_id_for_med[i][j]);
            med[i].s1[j]=s2;
        }
       // med[i].display(0);
    }
    medicine *m2;
    for(i=0;i<man_no;i++)
    {
        for(j=0;j<man[i].med_no;j++)
        {
            m2=get_med_by_id(med_id_for_man[i][j]);
            man[i].m[j]=m2;
           // man[i].display();
        }
    }
    store_list *ptr=start;
    while(ptr!=NULL)
    {
        for(i=0;i<ptr->s.med_no;i++)
        {
           m2=get_med_by_id(ptr->s.quantity[i][0]);
           ptr->s.m[i]=m2;
           //ptr->s.display();
        }
        ptr=ptr->next;
    }
    for(i=0;i<d_no;i++)
    {
        for(j=0;j<dis[i].m_no;j++)
        {
            m2=get_med_by_id(med_id_for_dis[i][j]);
            dis[i].m[j]=m2;
        }
    }
}

int computer::login(string id1)
{
    string pass1;
    int ch;
    ifstream filein;
    filein.open("user_db",ios::in|ios::binary);
    if(!filein)
    {
        cout<<"File Empty.\n";
        return -1;
    }
    //user obj;
    string id2,pass2,name1,location1;
    char type1;
    while (filein>>id2>>name1>>pass1>>location1>>type1)
    {
        //cout<<"loop\n";
        //cout<<id2<<endl;
        if(id2==id1)
        {
            cout<<"Enter your password: ";
            cin>>pass2;
            if(pass2!=pass1)
                return 1;
            if(type1=='c')
            //{
                u=new customer;
                //u->*cart=new medicine[100];
            else
                u=new employee;
            u->setname(name1);
            u->settype(type1);
            u->setlocation(location1);
            u->setid(id2);
            u->setpass(pass2);
            //cout<<"Foobar\n";
            return 0;
        }
    }
    return 1;
}

int computer::signup()
{
    string name1,id1,pass1,location1,id2;
    char type1;
    int ch;
    cout<<"Enter a username: ";
    cin>>id1;
    //user obj;
    ifstream filein;
    filein.open("user_db",ios::in|ios::binary);
    if(!filein)
        cout<<"File Empty.\n";
    else
    {
        string test;
                //while(filein.read((char *)&obj,sizeof(obj)))
        while(filein>>id2>>name1>>pass1>>location1>>type1)
        {
                    //obj.display();
            //cout<<"loop\n";
            //test=obj.getid();
                    //cout<<test<<endl;
            if(id2==id1)
            {
                cout<<"Username already in use\n";
                return -1;
            }
        }
    }
    filein.close();
    ofstream fileout;
    fileout.open("user_db",ios::app|ios::binary);
    if(!fileout)
    {
        cout<<"Error!\n";
        return -1;
    }
    else
    {
        //string name1,id1,pass1,location1;
        //char type1;
        //user obj1;
        //obj1.setid(id1);
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
        /*obj1.setname(name1);
                obj1.setpass(pass1);
                obj1.settype(type1);
                obj1.setlocation(location1);
                fileout.write((char *)&obj1,sizeof(user));
                */
        fileout<<id1<<" "<<name1<<" "<<pass1<<" "<<location1<<" "<<type1<<" \n";//endl;
        fileout.close();
        return 1;
    }
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
    else if(t==3)
    {
        store_list *ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->s.getid()==id1)
                return true;
            ptr=ptr->next;
        }
    }
    else
    {
        for(i=0;i<d_no;i++)
        {
            if(dis[i].id==id1)
                return true;
        }
    }
    return false;
}

medicine* computer::get_med()
{
    int ch,ch1;
    medicine *m2;
    string man1,name1;
    cout<<"\n1.Search by medicine name\n2.Search by disease name\n";
    cin>>ch;
    switch(ch)
    {
        case 1:
        medloop1:
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
        case 2:cout<<"Enter the name of disease\n";
        string dname;
        cin>>dname;
        disease* d1=get_disease_by_name(dname);
        d1->display();
        loop2:
        cout<<"Enter the medicine id: ";
        int id1;
        cin>>id1;
        if(!validID(id1,1))
        {
            cout<<"Please enter a valid medicine id. Enter again!\n";
            goto loop2;
        }
        m2=get_med_by_id(id1);
        break;
    }
    return m2;

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

disease* computer::get_disease_by_name(string name1)
{
    int i;
    for(i=0;i<d_no;i++)
    {
        if(dis[i].name==name1)
            return &dis[i];
    }
    return NULL;
}

disease* computer::get_disease_by_id(int id1)
{
    int i;
    for(i=0;i<d_no;i++)
    {
        if(dis[i].id==id1)
            return &dis[i];
    }
    return NULL;
}

void customer::welcome()
{
    cout<<"Welcome "<<name<<"!!\n";
    cout<<"1.Search\n2.Show cart\n3.Profile\n4.Exit\n";
    int ch,ch1;
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
        case 1:search_med();
            break;
        case 2:show_cart();
            break;
        case 3:display();
            break;
        case 4:return;
    }
    welcome();
}

void customer::add_med_to_cart(medicine *m,int q)
{
    cart[c_no]=m;
    quant[c_no]=q;
    c_no++;
    total+=m->getprice()*q;
}

void customer::choice1()
{
    store_list *ptr;
    float amt1=0,amt[100],total1=0;
    int i,j,new_quant,ctr=0;
    int count=0;
    cout<<"SNO.  Name\tID\n";
    for(i=0;i<c_no;i++)
    {
        new_quant=quant[i];
        ptr=start;
        ctr=0;
        cout<<i+1<<".    "<<cart[i]->getname()<<"\t"<<cart[i]->getid()<<"\n";
        if(cart[i]->s1_no==0)
        {
            cout<<"Medicine currently not present in any store!\n";
            count++;
        }
        else
        {
            while(ptr!=NULL&&new_quant!=0)
            {
            //cout<<"foobar\n";
                for(j=0;j<cart[i]->s1_no;j++)
                {
                //cout<<"test\n";
                    if(cart[i]->s1[j]->getid()==ptr->s.getid()&&ptr->s.getQuantity(cart[i]->getid())!=0)
                    {
                        cout<<++ctr<<".\nStore name= "<<ptr->s.getname()<<"\nStore id= "<<ptr->s.getid()<<endl;
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
    }
    if(count==c_no)
        cout<<"Sorry, none of your medicines are available in our store!\n";
    else
    {
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
}

void customer::choice2()
{
    store_list *ptr;
    float amt1=0,amt[100],total1=0;
    int i,j,new_quant,ctr=0;
    int count=0;
    cout<<"SNO.  Name\tID\tPrice\tQuantity\tAmounnt\n";
    for(i=0;i<c_no;i++)
    {
        new_quant=quant[i];
        ptr=start;
        ctr=0;
        cout<<i+1<<".    "<<cart[i]->getname()<<"\t"<<cart[i]->getid()<<"\t"<<cart[i]->getprice()<<"\t"<<new_quant<<"\t"<<new_quant*cart[i]->getprice()<<endl;
        if(cart[i]->s1_no==0)
        {
            cout<<"Medicine currently not present in any store!\n";
            count++;
        }
        else
        {
            cout<<"\nStores available for medicine "<<cart[i]->getname()<<":\n\n";
            while(ptr!=NULL&&new_quant!=0)
            {
                for(j=0;j<cart[i]->s1_no;j++)
                {
                    if((cart[i]->s1[j]->getid()==ptr->s.getid())&&(cart[i]->s1[j]->getLocation()==location)&&ptr->s.getQuantity(cart[i]->getid())!=0)
                    {
                        cout<<++ctr<<". Store name= "<<ptr->s.getname()<<endl;
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
    }
    if(count==c_no)
        cout<<"Sorry, none of your medicines are available in our store!\n";
    else
    {
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

        int customer::show_alternative(medicine *m2)
        {
            int i;
            cout<<"ID\tName\n";
            for(i=0;i<m2->d->m_no;i++)
            {
                if(m2->getid()!=m2->d->m[i]->getid())
                    cout<<m2->d->m[i]->getid()<<"\t"<<m2->d->m[i]->getname()<<endl;
            }
            cout<<"\nEnter medicine id\n";
            int id1;
            input:
            cin>>id1;
            if(!validID(id1,1))
            {
                cout<<"Please enter a valid medicine id\n";
                goto input;
            }
            return id1;
        }

        void customer::search_med()
        {
            int q;
            medicine *m1=get_med();
            //m1->display(0);
            option:
            cout<<"\n\n1.Add medicine to cart\n2.Show alternatives\n3.Search another medicine\n4.Go back\n";
            int ch,ch2,id2;
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
                    cout<<endl<<endl<<"\n1.Search another medicines\n2.Checkout\n3.Go back\n";
                    cin>>ch2;
                    if(ch2==1)
                        search_med();
                    else if(ch2==2)
                        checkout();
                    else
                        return;
                    break;
                case 2:id2=show_alternative(m1);
                    m1=get_med_by_id(id2);
                    m1->display(0);
                    goto option;
                    break;
                case 3:search_med();
                    break;
                case 4:return;
            }
        }

        void customer::shift(int pos)
        {
            int i;
            for(i=pos;i<c_no-1;i++)
                cart[i]=cart[i+1];
            c_no--;
            //return c1;
        }

        void customer::show_cart()
        {
            int j,i,ch;
            total=0;
            cout<<"SNO.\tname\tid\tprice\tquantity\ttotal\n";
            for(i=0;i<c_no;i++)
            {
                cout<<i+1<<".    "<<cart[i]->getname()<<"\t"<<cart[i]->getid()<<"\t"<<cart[i]->getprice()<<"\t\t"<<quant[i]<<"\t"<<cart[i]->getprice()*quant[i]<<endl;
                //cout<<cart[i]->s1_no<<endl;
                for(j=0;j<cart[i]->s1_no;j++)
                    cout<<cart[i]->s1[j]->getname()<<endl;
                total+=cart[i]->getprice()*quant[i];
            }
            cout<<endl<<endl<<"Total Amount: "<<total<<endl<<endl;
            cout<<endl<<"1.Checkout\n2.Remove item\n3.clear all\n4.Go back\n";
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
                            shift(i);
                            break;
                        }
                    }
                    show_cart();
                    //search_med();
                    break;
                case 3:*cart=new medicine[100];
                    quant=new int[100];
                    c_no=0;
                    total=0;
                    search_med();
                    break;
                case 4:return;
            }
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
                case 8:cout<<"1.Add medicines\n2.Update information\n";
                    int ch1;
                    cin>>ch1;
                    if(ch1==1)
                        add_med_to_store();
                    else
                        start=update(start);
                    break;
                case 9:start=del_s(start);
                    break;
                case 10:return;
            }
            welcome();
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

        void employee::add_med()
        {
            int i,id1,flag=0;
            //med[med_no]=new medicine;
            cout<<"ID: ";
            //int id1;
            cin>>id1;
            if(validID(id1,1))
            {
                cout<<"Medicine already present. Please enter a valid ID\n";
                cout<"1.Input again\n2.Go back\n";
                int ch;
                cin>>ch;
                if(ch==1)
                    add_med();
                else
                    return;
            }
            med[med_no].set(id1);
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
            cout<<"Enter the name of disease it can cure:\n";
            string dname;
            cin>>dname;
            disease *d1=get_disease_by_name(dname);
            if(d1==NULL)
            {
                cout<<"Disease not found in database\nPlease enter information about the disease\n;";
                loop1:cout<<"ID: ";
                cin>>id1;
                if(validID(id1,4))
                {
                    cout<<"Disease already present. Please enter a valid ID\n";
                    cout<"1.Input again\n2.Go back\n";
                    int ch;
                    cin>>ch;
                    if(ch==1)
                        goto loop1;
                    else
                        return;
                }
                dis[d_no].id=id1;
                dis[d_no].name=dname;
                dis[d_no].m[dis[d_no].m_no++]=&med[med_no];
                med[med_no].d=&dis[d_no];
                d_no++;
            }
            else
            {
                d1->m[d1->m_no++]=&med[med_no];
                med[med_no].d=d1;
            }
            med_no++;
        }

        void employee::add_man()
        {
            int id1;
            string name1,add1,no1;
            cout<<"Enter the details of the manufaturer: \n\n";
            //man[man_no]=new manufacturer;
            cout<<"ID: ";
            cin>>id1;
            if(validID(id1,2))
            {
                cout<<"Manufacturer already present. Please enter a valid ID\n";
                cout<"1.Input again\n2.Go back\n";
                int ch;
                cin>>ch;
                if(ch==1)
                    add_man();
                else
                    return;
            }
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
            cout<<"Medicine added\n";
        }

        store_list* employee::add_store(store_list *start1)
        {
            store_list *ptr,*temp,*temp1;
            cout<<"Enter id: ";
            int id1;
            cin>>id1;
            if(validID(id1,3))
            {
                cout<<"Store already present. Please enter a valid ID\n";
                cout<"1.Input again\n2.Go back\n";
                int ch;
                cin>>ch;
                if(ch==1)
                    start1=add_store(start1);
                else
                    return start1;
            }
            ptr=new store_list(id1);
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
            /*cout<<"\n\nDo you want to add medicines? <Y=1, N=0>\n";
            int ch;
            cin>>ch;
            if(ch==1)
                add_med_to_store();*/
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

float medicine::getprice()
{
    return price;
}

string medicine::getname()
{
    return name;
}

int medicine::getid()
{
    return id;
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

void medicine::display(int x)// x=1 if manufacturer details have already been shown
{
    int ch,ch1;
    cout<<"Details of the medicine = \n\n";
    cout<<"Medicine id= "<<id<<endl;
    cout<<"Name= "<<name<<endl;
    cout<<"Price= "<<price<<endl;
    cout<<"Expiry date= "<<dd<<"-"<<mm<<"-"<<yy<<endl;
    cout<<"Manufacturer= "<<m->getname()<<endl;
    /*cout<<"For more details enter 1 else enter 0\n";
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
    }*/
}

void medicine::set(int id1)
{
    cout<<"Enter details of the medicine: \n";
    /*cout<<"ID: ";
    int id1;
    cin>>id1;

    if(validID(id1,1))
            {
                cout<<"Medicine already present. Please enter a valid ID\n";
                cout<"1.Input again\n2.Go back\n";
                int ch;
                cin>>ch;
                if(ch==1)
                    set();
                else
                    return;
            }*/
    id=id1;
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

void medicine::mset(manufacturer *m1)
{
    m=m1;
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

int store::getid()
        {
            return id;
        }

        string store::getname()
        {
            return name;
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

string store::getLocation()
        {
            return location;
        }

void store::set(int id1,string name1,string location1)
        {
            id=id1;
            name=name1;
            location=location1;
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

void store::addmed(medicine *m1)
        {
            m[med_no]=m1;
            quantity[med_no][0]=m1->getid();
            cout<<"Enter quantity of the medicine\n";
            cin>>quantity[med_no][1];
            med_no++;
        }

int store::update() //returns 1 if discount rate is changed
        {

            int ch,i,j,flag,ch1;
            cout<<"\n1.Name\n2.Location and Address\n3.Phone number\n4.Medicine quantity\n5.Discount\n6.Add medicine\n";
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

int manufacturer::getid()
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
            /*cout<<"For details of medicines press 1\n";
            cin>>ch;
            if(ch==1)
            {
                for(i=0;i<med_no;i++)
                    m[i]->display(1);
            }*/
        }

        void manufacturer::set(int id1,string name1,string add1,string no1)
        {
            id=id1;
            name=name1;
            add=add1;
            no=no1;
        }

void manufacturer::addmed(medicine *m1)
        {
            m[med_no]=m1;
            med_no++;
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

void disease::display()
{
    cout<<"ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Medicines that can cure this disease:\n";
    cout<<"Sno.  ID\tName\n";
    for(int i=0;i<m_no;i++)
    {
        cout<<i+1<<". "<<m[i]->getid()<<"\t"<<m[i]->getname()<<endl;
    }
}

void disease::addmed(medicine *m1)
{
    m[m_no++]=m1;
}

int main()
{
    try
    {
        computer c;
        c.load();
        cout<<"\t\t\tOOP Project\nBy:-\nVishesh Srivastava (14104022)\nSooraj Awasthi (14104029)\nHarsh Goyal (14104010)\nKinley Dorji (14014003)\n\n\n ";
        cout<<"\t\tWelcome to Medical Advisors\n";
        cout<<"1.Login\n2.Sign up\n3.Exit\n";
        int ch,x;
        cin>>ch;
        if(ch==1)
        {
            string id1;
            cout<<"Enter username: ";
            cin>>id1;
            x=c.login(id1);
            if(x==-1)
                return main();
            else if(x==1)
            {
                cout<<"Invalid username or password\n";
                return main();
            }
        }
        else if(ch==2)
        {
            x=c.signup();
            if(x==1)
                cout<<"You have succesfully registered\n";
            return main();
        }
        else if(ch==3)
            return 0;
        else
            throw "Wrong Input\n";
        c.u->welcome();
        c.save();
        return 0;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
}

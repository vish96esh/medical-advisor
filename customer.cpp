#include "customer.h"
#include "medicine.h"
#include "manufacturer.h"
#include "store.h"
#include "user.h"
#include "store_list.h"

class user;
class store;
class medicine;
class manufacturer;
class store_list;

user computer::*u=NULL;
//int computer::u_no=0;
medicine computer::med[1000]={};
manufacturer computer::man[50]={};
store_list* computer::start=NULL;
int computer::med_no=0;
int computer::man_no=0;
int computer::s_no=0;

customer::customer()
        {
            cout<<"test\n";
            *cart=new medicine[100];
            quant=new int[100];
            c_no=0;
            total=0;
        }

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
    cout<<"For details of medicines press 1\n";
    cin>>ch;
    if(ch==1)
    {
        for(i=0;i<med_no;i++)
            m[i]->display(1);
    }
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

int store::getid()
{
    return id;
}

int medicine::getid()
{
    return id;
}

string store::getLocation()
{
    return location;
}

string medicine::getname()
{
    return name;
}

void user::display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Location: "<<location<<endl;
}

void user::welcome(){}

float medicine::getprice()
{
    return price;
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

        medicine** customer::shift(medicine *c1[100],int pos)
        {
            int i;
            for(i=pos;i<c_no-1;i++)
                c1[i]=c1[i+1];
            c_no--;
            return c1;
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

int main()
{
    return 0;
}

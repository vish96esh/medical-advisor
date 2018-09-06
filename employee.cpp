#include "employee.h"
#include "user.h"
#include "medicine.h"
#include "manufacturer.h"
#include "store.h"
#include "store_list.h"
#include "computer.h"

class user;
class store;
class medicine;
class manufacturer;
class store_list;
class employee;

user computer::*u=NULL;
//int computer::u_no=0;
medicine computer::med[1000]={};
manufacturer computer::man[50]={};
store_list* computer::start=NULL;
int computer::med_no=0;
int computer::man_no=0;
int computer::s_no=0;

medicine::medicine()
{
    id=0;
    name="";
    price=0.0;
    dd=0;mm=0;yy=0;
    s1_no=0;
  //  *s1=new store[100]
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

string medicine::getname()
{
    return name;
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

void user::welcome(){}

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

string manufacturer::getname()
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

int manufacturer::getid()
{
    return id;
}

int medicine::getid()
{
    return id;
}

int store::getid()
{
    return id;
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

void store::addmed(medicine *m1)
{
    m[med_no]=m1;
    quantity[med_no][0]=m1->getid();
    cout<<"Enter quantity of the medicine\n";
    cin>>quantity[med_no][1];
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

store_list::store_list()
{
    s.addstore();
    next=NULL;
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
            cout<<"Enter id: ";
            int id1;
            cin>>id1;
            if(validID(id1,3))
            {
                cout<<"Store already present. Please enter a valid ID\n";
                cout<"1.Input again\n2.Go back\n";
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

int main()
{
    return 0;
}

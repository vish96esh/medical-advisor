#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class medicine;
class disease;

class medicine
{
    private:
        int id;
        string name;
        float price;
    public:
        disease *d;
        int dd,mm,yy;
        medicine();
        void display();
        float getprice();
        string getname();
        bool checkDate(int d,int m,int y);
        void set(int);
        void set(int id1,string name1,float price1,int dd1, int mm1, int yy1);
        int getid();
        void update();
};

class disease
{
    public:
        int id;
        string name;
        medicine *m;
        disease();
        void display();
};


medicine::medicine()
{
    id=0;
    name="";
    price=0.0;
    dd=0;mm=0;yy=0;
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

void medicine::display()
{
    int ch,ch1;
    cout<<"Details of the medicine = \n\n";
    cout<<"Medicine id= "<<id<<endl;
    cout<<"Name= "<<name<<endl;
    cout<<"Price= "<<price<<endl;
    cout<<"Expiry date= "<<dd<<"-"<<mm<<"-"<<yy<<endl;
}

void medicine::set(int id1)
{
    cout<<"Enter details of the medicine: \n";
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

disease::disease()
{
    id=0;
    name="";
    m_no=0;
}

void disease::display()
{
    cout<<"ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Medicines that can cure this disease is: "<<m->getname()<<endl;
}

int main()
{
    medicine m[10];
    int m_no=0;
    disease d[10];
    int dis_id_for_med[10];
    int med_id_for_dis[10];
    int d_no=0;
    string name1;
    ifstream i1,i2;
    int id1,did,dd1,mm1,yy1,mid;
    float price1;
    i1.open("medicine_db2",ios::in|ios::binary);
    if(!i1)
        cout<<"Medicine File empty. Please add medicine before doing any operation\n";
    else
    {
        while(i1>>id1>>name1>>price1>>dd1>>mm1>>yy1>>did)
        {
            m[m_no].set(id1,name1,price1,dd1,mm1,yy1);
            dis_id_for_med[m_no++]=did;
        }
    }
    i1.close();
    i2.open("disease_db2",ios::in|ios::binary)
    if(!i2)
        cout<<"Disease list empty. Plase aadd a disease before doing any operation\n";
    else
    {
        while(i2>>id1>>name1>>mid)
        {
            d[d_no].id=id1;
            d[d_no].name=name1;
            med_id_for_dis[d_no++]=mid;
        }
    }
    i2.close();
    int i;
    medicine *m1;
    disease *d1;
    for(i=0;i<d_no;i++)
    {
        for(j=0;j<m_no;j++)
        {
            if(m[j].getid()==med_id_for_dis[i])
            {
                m1=&m[j];
                break;
            }
        }
        d[i].m=m1;
    }
    for(i=0;i<m_no;i++)
    {
        for(j=0;j<d_no;j++)
        {
            if(d[j].id==dis_id_for_med[i])
            {
                d1=&d[j];
                break;
            }
        }
        m[i].d=d1;
    }
    int ch,ch1;
    int f,flag=0;
    string name1;
    start:
    cout<<"Welcome to Medical advisors\n1.Add medicine\n2.Update medicine\n3.Delete medicine\n4.Add disease\n5.Update disease\n6.Delete disease\n7.Search medicine by name\n8.Search medicine by disease\n";
    cin>>ch;
    switch(ch)
    {
        case 1:abc1:
        f=0;
        cout<<"\nEnter id: ";
        cin>>id1;
        for(i=0;i<m_no;i++)
        {
            if(m[i].getid()==id1)
            {
                cout<<"Medicine already present. Enter again\n";
                goto abc1;
            }
        }
        m[m_no].set(id1);
        xyz:
        cout<<"Enter disease name: ";
        cin>>name1;
        for(i=0;i<d_no;i++)
        {
            if(d[i].name==name1)
            {
                m[m_no].d=&d[i];
                d[i].m=&m[m_no];
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<"Disease not found\n1.It is a new disease\n2.Enter name again\n";
            cin>>ch1;
            if(ch1==1)
            {
                cout<<"\nEnter id: ";
                cin>>id1;
                for(i=0;i<d_no;i++)
                {
                    if(d[i].id==id1)
                    {
                        cout<<"Disease already present. Enter again\n";
                        goto abc4;
                    }
                }
                d[d_no].id=id1;
                cout<<"Enter name: ";
                cin>>name1;
                d[d_no].name=name1;
                d[d_no].m=&m[m_no];
                m[m_no].d=&d[d_no++];
            }
            else
                goto xyz;
            m_no++;
        }
        break;

        case 2:abc2:
        cout<<"\nEnter id: ";
        cin>>id1;
        for(i=0;i<m_no;i++)
        {
            if(m[i].getid()==id1)
            {
                m[i].update();
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"enter a valid ID\n";
            goto abc2;
        }
        break;

        case 3:abc3:
        cout<"\nEnter id: ";
        cin>>id1;
        for(i=0;i<m_no;i++)
        {
            if(m[i].getid()==id1)
            {
                flag=1;
                for(j=i;j<(m_no-1);j++)
                    m[j]=m[j+1];
                m_no--;
            }
        }
        if(flag==0)
        {
            cout<<"Enter a valid id\n";
            goto abc3;
        }
        break;

        case 4:abc4:
        cout<<"\nEnter id: ";
        cin>>id1;
        for(i=0;i<d_no;i++)
        {
            if(d[i].id==id1)
            {
                cout<<"Disease already present. Enter again\n";
                goto abc4;
            }
        }
        d[d_no].id=id1;
        cout<<"Enter name: ";
        cin>>name1;
        d[d_no++].name=name1;
        break;

        case 5:abc5:
        cout<<"\nEnter id: ";
        cin>>id1;
        for(i=0;i<d_no;i++)
        {
            if(d[i].id==id1)
            {
                cout<<"Enter new name: ";
                cin>>d[i].name;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"enter a valid ID\n";
            goto abc5;
        }
        break;

        case 6:abc6:
        cout<"\nEnter id: ";
        cin>>id1;
        for(i=0;i<d_no;i++)
        {
            if(d[i].id==id1)
            {
                flag=1;
                for(j=i;j<(d_no-1);j++)
                    d[j]=d[j+1];
                d_no--;
            }
        }
        if(flag==0)
        {
            cout<<"Enter a valid id\n";
            goto abc6;
        }
        break;

        case 7:abc7:cout<<"\nEnter the name of the medicine: ";
        cin>>name1;
        f=0;
        for(i=0;i<m_no;i++)
        {
            if(m[i].getname()==name1)
            {
                m[i].display();
                cout<<"Disease it cures: "<<m[i].d->name<<endl;
                f=1;
                break;
            }
        }
        if(f==0)
            cout<<"Name not found.\n"
        break;

        case 8:cout<<"\nEnter the name of the disease: ";
        cin>>name1;
        f=0;
        for(i=0;i<d_no;i++)
        {
            if(d[i].name==name1)
            {
                d[i].display();
                cout<<"Medicine that cures it: "<<d[i].m->getname()<<endl;
                f=1;
                break;
            }
        }
        if(f==0)
            cout<<"disease not found.\n";
        break;

        default:cout<<"Wrong input\n";
    }
    cout<"Do you want to input again?<Y1,N=0>\n";
    cin>>ch;
    if(ch==1)
        goto start;
    else
    {
        ofstream o1,o2;
        o1.open("medicine_db2",ios::binary);
        for(i=0;i<m_no;i++)
            o1<<m[i].getid()<<" "<<m[i].getname()<<" "<<m[i].getprice()<<" "<<m[i].dd<<" "<<m[i].mm<<" "<<m[i].yy<<" "<<
    }
}

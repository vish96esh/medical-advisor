#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class medicine
{
    public:
        string name;
        float price;
        int id;
        int dd,mm,yy;
        medicine()
        {
            name="";
            price=0;
            id=0;
            dd=mm=yy=0;
        }

        void display()
        {
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Date of expiry: "<<dd<<"-"<<mm<<"-"<<yy<<endl;
        }

        ~medicine(){}//cout<<"Object deleted\n";}
};

int main()
{
    medicine m[50];
    ifstream i2;
    int j,f,id1,dd1,mm1,yy1;
    string name,name1;
    float price1;
    i2.open("medicine_db1",ios::in|ios::binary);
    int i=0,flag=0;
    if(!i2)
    {
        cout<<"medicine list empty. please enter some data\n";
        flag=1;
        goto xyz;
    }
    else
    {
        while(i2>>id1>>name1>>price1>>dd1>>mm1>>yy1)
        {
            m[i].id=id1;
            m[i].name=name1;
            m[i].dd=dd1;
            m[i].mm=mm1;
            m[i].yy=yy1;
            m[i].price=price1;
            i++;
        }
    }
    cout<<"1.Add medicine\n2.Search medicine\n";
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:xyz:cout<<"ID: ";
            cin>>id1;
            //int j,f=0;
            for(j=0;j<i;j++)
            {
                if(m[j].id==id1)
                {
                    cout<<"ID already in use.Enter again\n";
                    f=1;
                    goto xyz;
                    break;
                }
            }
            if(f==0)
            {
                m[i].id=id1;
                cout<<"Name: ";
                cin>>m[i].name;
                cout<<"Price: ";
                cin>>m[i].price;
                cout<<"Date of expiry(dd mm yyyy): ";
                cin>>m[i].dd>>m[i].mm>>m[i].yy;
                i++;
            }
            break;
        case 2:cout<<"Enter name of a medicine: ";
            cin>>name1;
            int j;
            for(j=0;j<i;j++)
            {
                if(m[j].name==name1)
                {
                    m[j].display();
                    cout<<endl;
                }
            }
            break;
        default:cout<<"Wrong input\n";
    }
    i2.close();
    ofstream o1;
    o1.open("medicine_db1",ios::binary);
    for(j=0;j<i;j++)
        o1<<m[j].id<<" "<<m[j].name<<" "<<m[j].price<<" "<<m[j].dd<<" "<<m[j].mm<<" "<<m[j].yy<<" "<<endl;
    o1.close();
    cout<<"Do you want to do operations again?<Y=1,N=0>\n";
    int ch2;
    cin>>ch2;
    if(ch2==1)
            return main();
    else
        return 0;
}

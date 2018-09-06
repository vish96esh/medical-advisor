#include "store_list.h"
#include "store.h"

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

void store::addstore(int id1)
{
    int ch;
    cout<<"Enter details of the store: \n\n";
    //cout<<"ID: ";
    //cin>>id;
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

int main()
{
    return 1;
}

store_list::store_list()
{
    s.addstore();
    next=NULL;
}

store_list::store_list(store ptr)
{
    s=ptr;
    next=NULL;
}

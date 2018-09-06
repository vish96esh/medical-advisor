class user
{
    protected:
        string location;
        string pass;
        char type;  //customer or employee
        string name;
     public:
        string id;
        virtual void welcome();
        void new_user(string id1,string name1,string pass1,string location1,char type1);
        void display();
        void setid(string id1);
        void setname(string name1);
        void settype(char type1);
        void setpass(string pass1);
        void setlocation(string location1);
        string getid();
        string getpass();
        string getname();
        string getlocation();
        void update();
        char gettype();
};

class employee : public user, public computer
{
    public:
        void shift(int pos,char ch);
        void del_man();
        void del_med();
        store_list* del_s(store_list *start1);
        void add_med();
        void add_man();
        void add_med_to_store();
        store_list *add_store(store_list *start1);
        store_list* rearrange(store_list *start1);
        store_list *update(store_list *start1);
        void update(char c);
};

class customer : public user,public computer
{
    medicine *cart[10];
    int *quant;
    int c_no;
    float total;
    public:
        //medicine **cart;
        customer();
        void add_med_to_cart(medicine *m,int q);
        void choice1();
        void choice2();
        void choice3();
        void choice4();
        void checkout();
        void search_med();
        void shift(int pos);
        void show_cart();
        int show_alternative(medicine*);
};

class computer
{
    public:
        static medicine med[1000];
        static manufacturer man[50];
        static disease dis[50];
        static store_list *start;
        static int med_no; //no of medicines
        static int man_no; //no of manufacturers
        static int s_no;
        static int d_no;
        computer();
        void load();
        void save();
        int login(string);
        int signup();
        medicine *get_med_by_id(int id1);
        store *get_store_by_id(int id2);
        bool validID(int id1,int t);
        medicine *search_med_by_man(string man1);
        medicine *search_med_by_name(string name1);
        medicine *get_med();
        manufacturer *get_man_by_id(int id1);
        disease* get_disease_by_name(string);
        disease* get_disease_by_id(int);
};

class medicine
{
    private:
        int id;
        string name;
        float price;
    public:
        manufacturer *m;
        disease *d;
        int dd,mm,yy;
        store *s1[100];
        int s1_no;
        medicine();
        void display(int);
        float getprice();
        string getname();
        bool checkDate(int d,int m,int y);
        void set(int);
        void set(int id1,string name1,float price1,int dd1, int mm1, int yy1);
        void add_store(store *);
        void mset(manufacturer *);
        int getid();
        void update();
};



class disease
{
    public:
        int id;
        string name;
        medicine *m[10];
        int m_no;
        disease();
        void display();
        void addmed(medicine *m);
};

class manufacturer
{
    int id;
    string name;
    public:
        string no;
        string add;
        int med_no;
        medicine *m[100];
        manufacturer();
        int getid();
        void shift();
        string getname();
        void display();
        void addmed(medicine *m1);
        void set(int id1,string name1,string add1,string no1);
        void update();
};

class store
{
    int id;
    string name;
    string location;
    public:
        string address;
        string no;
        medicine *m[100];
        int med_no;
        int quantity[100][2];
        float discount;
        store();
        int getid();
        string getname();
        string getLocation();
        void addstore(int);
        void shift();
        void addmed(medicine *m1);
        void set(int id1,string name1,string location1);
        int getQuantity(int id);
        void display();
        void showmed();
        int update();
};


template <typename T>
T* del(T *arr,int id1,int x)
{
    int i,j,n;
    switch(x)
    {
        case 1:n=med_no;
        break;
        case 2:n=man_no;
        break;
        case 3:n=d_no;
        break;
    }
    for(i=0;i<n;i++)
    {
        if(arr[i].id==id1)
        {
            for(j=0;j<(n-1);j++)
                arr[j]=arr[j+1];
        }
    }
    return T;
}



}

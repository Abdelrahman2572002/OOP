//abdelrahman ramadan 20200284 s13
//ezz eldin ahmed saber 20200325 s13
//project about marketing selling
#include <iostream>
#include <string>
using namespace std;
//class item
class item
{
private:
    int id;
    string name;
    int quantity;
    double price;
public:
    //constructors
    static int counter;
    item()
    {
        id=0;
        name="none";
        quantity=0;
        price=0.0;
        counter++;
        id=counter;
    }
    item(string n,int q,double p)
    {
        name=n;
        quantity=q;
        price=p;
        counter++;
        this->id = counter;
    }

    item(item const &obj)
    {
        name=obj.name;
        quantity=obj.quantity;
        price=obj.price;
    }
    //setters to variables
    void setname(string na)
    {
        name=na;
    }
    void setquantity(int qu)
    {
        quantity=qu;
    }
    void setprice(double pr)
    {
        price=pr;
    }
    //getters to variables
    string getname()
    {
        return name;
    }
    int getquantity()
    {
        return quantity;
    }
    double getprice()
    {
        return price;
    }
    int getid()
    {
        return id;
    }
    //operators to item
    int operator==(item a)
    {
        return ((this->name == a.name));

    }
    void operator+=(item a)
    {
        (this -> quantity)+=a.quantity;

    }
    void operator-=(int Q)
    {
        (this -> quantity)-=Q;

    }

    friend istream&operator>>(istream& input,item& a)
    {
        input>>a.name>>a.quantity>>a.price;
        return input;
    }
    friend ostream&operator<<(ostream& output,item&a)
    {
        cout << "----------------\n";
        output << "name:" << a.name << endl <<
               "quantity:" << a.quantity << endl
               << "price:" << a.price << endl
               << "id:" << a.id << endl;
        cout << "----------------\n";
        return output;
    }
    friend class seller;



};
int item::counter=0;
//class seller
class seller
{
private:
    string name;
    string email;
    int maxitems;
    item* items;
public:
    //constructors
    seller()
    {
    };
    seller(string name, string email, int maxitems)
    {
        this->name = name;
        this->email = email;
        this->maxitems = maxitems;
        items = new item[maxitems];
        for (int i = 0; i < maxitems; i++)
        {
            items[i].quantity = 0;
        }

    };
    //function 1 to add item
    bool add_item(item a)
    {
        bool f;
        f=false;
        for (int i = 0; i < maxitems; i++)
        {

            if (items[i] == a)
            {

                items[i] += a;

                f = true;

                break;
            }
        }
        if (f == false)
        {

            for (int j = 0; j < maxitems; j++)
            {

                if (items[j].quantity == 0 && items[j].name == "none" && items[j].price == 0)
                {

                    items[j] = a;

                    f = true;

                    break;
                }

            }
        }
        return f;


    }
    //function 2 to sell item
    bool sell_item(string name2, int selledquantity)
    {
        bool f;
        f = false;
        for (int i = 0; i < maxitems; i++)
        {
            if (items[i].name == name2)
            {
                if (items[i].quantity >= selledquantity)
                {
                    items[i] -= selledquantity;
                    cout << "number of selled " << selledquantity << "of " << items[i].name << endl;
                    f = true;
                    break;
                }
                else
                {
                    cout << "there is " << items[i].quantity << " only for this item \n";

                }

            }
        }



        return f;
    }
    //function 3 to print item
    void print_item()
    {
        cout << "name of seller " << this->name << endl
             << "email of seller " << this->email << endl
             << "Has " << this->maxitems << " of items " << endl;
        cout << "\n \n \n";
        for (int j = 0; j < maxitems; j++)
        {
            if (items[j].quantity == 0)
            {
                continue;
            }
            cout << "number of item" << j + 1 << endl;
            cout << items[j];
            cout << "\n \n \n";
        }
    }
    //function 4 to find item
    item find_item(int ID)
    {
        int in;
        bool f = false;
        for (int j = 0; j < maxitems; j++)
        {
            if (items[j].id == ID)
            {
                f = true;
                in = j;

                break;
            }
        }

        if (f == true)
        {
            cout << items[in].name << "\n";
            return items[in];
        }



    }
//operators
    friend istream& operator>>(istream& input, seller& a)
    {
        input >> a.name >> a.email;
        return input;
    }



    friend ostream& operator<<(ostream& output, seller& i)
    {
        cout << "----------------\n";
        output << "name: " << i.name << endl <<
               "email: " << i.email << endl;
        cout << "----------------\n";
        return output;
    }


    void setitems(int index)
    {
        this->maxitems = index;
        items = new item[maxitems];
        for (int j = 0; j < maxitems; j++)
        {
            items[j].quantity = 0;
        }

        for (int j = 0; j < maxitems; j++)
        {
            if (items[j].quantity == 0)
            {
                item::counter--;
            }
        }

    }
    ~seller()
    {
        delete[]items;
    }


};



int main()
{
    seller s1;
    cout << "Please enter your name and email \n";
    cin >> s1;
    cout << "please enter your item capacity \n";
    int cap;
    cin >> cap;
    s1.setitems(cap);
    string option = "please press 1 to Print My Info \npress 2 to Add An Item \npress 3 to Sell An Item \npress 4 to Print Items";
    option += "\npress 5 to Find an Item by ID \npress 6 to exit\n________________________\n";
    while (true)
    {
        cout << option << "\n" << "please Choose from 1 to 6\n";

        int press;
        while (true)
        {
            cin >> press;
            if (press >= 1 && press <= 6)
            {
                break;
            }
            else
            {
                cout << "Invalid Choice ! please try again \n";
            }
        }

        if (press == 1)
        {
            cout << s1;
        }
        else if (press == 2)
        {
            cout << "name,quantity,price: ";
            item i1;
            cin >> i1;
            s1.add_item(i1);
        }
        else if (press == 3)
        {
            cout << "name,quantity: ";
            string n;
            int num;
            cin >> n >> num;
            s1.sell_item(n, num);
        }
        else if (press == 4)
        {
            s1.print_item();
        }
        else if (press == 5)
        {
            cout << "Input ID: ";
            int iD;
            cin >> iD;
            s1.find_item(iD);
        }
        else if (press == 6)
        {
            break;
        }
    }
    return 0;
}

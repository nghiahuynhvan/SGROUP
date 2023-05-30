#include"Client.h"
#include"Menu.h"
#include<iostream>
using namespace std;

class Order :public Client, public Menu
{
    private:
        string KBill;
        int Method;
        int Sum;
        int Count_Total = 0;
    public:
        Order(string = "Bill",int = 1,int = 0, string = "", string = "", string = "",string = "");
        ~Order();
        void OrderFood(Menu&);
        void TotalMoney();
        void Show();
        void Inputfile(ifstream&, Menu&);
        void Outputfile(ofstream&);
        const Order& operator=(const Order&);
        bool operator>(const Order&);
        bool operator==(const Order&);
        friend ostream& operator<<(ostream&,Order&);
};
#include<iostream>
#include<iomanip>
using namespace std;

class Client
{
    protected:
        string KClient;
        string NameClient;
        string Address;
        string PNumber;
    public:
        Client(string = "", string = "", string = "", string = "");
        ~Client();
        void Import();
        void Show();
};
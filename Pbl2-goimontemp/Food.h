#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;

typedef struct Unit UNIT;
class Food
{
    private:
        string KFood;
        string Name;
        string Unit;
        int Price;
        int Quantity;
    public:
        Food(string ="", string ="", string = "", int = 0, int = 0);
        ~Food();
        friend ostream& operator<<(ostream&, const Food&);
        friend istream& operator>>(istream&, Food&);
        bool operator>(const Food&);
        bool operator==(const Food&);
        const Food& operator=(const Food&);
        void InputFile(ifstream&);
        void OutputFile(ofstream&);
        friend class Menu;
        friend class Order;
};
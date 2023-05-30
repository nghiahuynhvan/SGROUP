#include"Food.h"
#include"LIST.h"

class Menu
{
    protected:
        List<Food> LF;
    public:
        Menu();
        ~Menu();
        void Add();
        void Show();
        void Del(string);
        void Update(string);
        void Inputfile(ifstream&, string);
        void Outputfile(ofstream&, string);
        friend ostream& operator<<(ostream&, const Menu&);
        friend istream& operator>>(istream&, Menu&);
        friend class Order;
};
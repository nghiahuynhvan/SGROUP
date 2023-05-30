#include<iostream>
#include"Order.h"
using namespace std;

class Order_Manager
{
    private:
        List<Order> LO;
    public:
        Order_Manager();
        Order_Manager(Menu&);
        ~Order_Manager();
        void Import(Menu&);
        void Export();
        void Sort();
        void Search();
        void Del();
};
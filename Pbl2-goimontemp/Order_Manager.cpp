#include"Order_Manager.h"
Order_Manager::Order_Manager()
{}
Order_Manager::Order_Manager(Menu& M)
{
    ifstream filein;
    filein.open("Order.txt",ios::in);
    while(!filein.eof())
    {
        Order O;
        O.Inputfile(filein,M);
        this->LO.addTail(this->LO.getNode(O));
    }
    filein.close();
}
Order_Manager::~Order_Manager()
{
    ofstream fileout;
    fileout.open("Order.txt",ios::out);
    for(struct node<Order> *k = this->LO.pHead ; k != NULL ; k = k->pNext)
    {
        k->data.Outputfile(fileout);
    }
    fileout.close();
}
void Order_Manager::Import(Menu& M)
{
    int select = 1;
    cout<<"Nhap thong tin don hang goi mon:\n";
    while (select != 2)
    {
        Order O;
        O.OrderFood(M);
        cout<<"Ban co muon tiep tuc:\n";
        cout<<"1. Co\n2. Khong\n";
        cout<<"Moi ban nhap lua chon: "; cin>>select;
        this->LO.addTail(this->LO.getNode(O));
    }
}
void Order_Manager::Export()
{
    this->LO.ShowLIST();
}
void Order_Manager::Sort()
{
    cout<<"Sap xep theo ma bill\n";
    this->LO.BSort();
}
void Order_Manager::Search()
{
    cout<<"Tim kiem theo ma bill\n";
    cout<<"Nhap ma bill can tim: ";
    string KB; fflush(stdin); getline(cin,KB);
    Order O(KB);
    for(struct node<Order> *k = this->LO.pHead ; k != NULL ; k = k->pNext)
    {
        if(k->data == O) cout<<k->data;
    }
}
void Order_Manager::Del()
{
    cout<<"Xoa theo ma bill\n";
    cout<<"Nhap ma bill can xoa: ";
    string KB; fflush(stdin); getline(cin,KB);
    Order O(KB);
    this->LO.deletePosition(this->LO.Search(O));
}
#include"Order.h"
static int Count_Bill = 0;
int Count_outfile = 0;
Order::Order(string KB,int M,int S,string KC, string NC, string A, string PN)
    :KBill(KB),Method(M),Sum(S),Client(KC,NC,A,PN)
{}
Order::~Order()
{}
void Order::OrderFood(Menu& M)
{
    Count_Bill++;
    this->KBill = "Bill" + to_string(Count_Bill);
    cout<<"Nhap phuong thuc goi mon:\n";
    cout<<"1. Goi off\n2. Goi on\n";
    cout<<"Moi ban nhap lua chon: "; cin>>this->Method;
    if(this->Method == 2)
    {
        this->Client::Import();
    }
    int select = 1;
    while (select == 1)
    {
        string KF;
        cout<<"Nhap ma mon can goi: "; fflush(stdin); getline(cin,KF);
        Food F(KF),Tg;
        M.LF.GetData(M.LF.Search(F),Tg);
        cout<<"Nhap so luong: "; cin>>Tg.Quantity;
        this->LF.addTail(this->LF.getNode(Tg));
        cout<<"Ban co muon tiep tuc goi mon:\n";
        cout<<"1. Co \n2. Khong\n";
        cout<<"Moi ban nhap lua chon: "; cin>>select;
    }
}
void Order::TotalMoney()
{
    for(struct node<Food> *k = this->LF.pHead; k != NULL ; k = k->pNext)
    {
        this->Sum += k->data.Price * k->data.Quantity;
    }
    this->Count_Total++;
}
void Order::Show()
{
    cout<<"Ma Bill: "<<this->KBill<<endl;
    if(this->Method == 2)
        this->Client::Show();
    cout<<setw(10)<<left<<"Ma mon"<<setw(20)<<left<<"Ten mon"<<setw(20)<<left<<"Don vi"<<setw(20)<<left<<"Gia tien (VND)"<<setw(10)<<right<<"So luong"<<endl;
    this->LF.ShowLIST();
    if(this->Count_Total == 0) this->TotalMoney();
    cout<<"Tong tien: "; cout<<this->Sum<<endl;
}
void Order::Inputfile(ifstream& filein, Menu& M)
{
    Count_Bill++;
    fflush(stdin); getline(filein,this->KBill,';');
    string Tg;
    fflush(stdin); getline(filein,Tg,';');
    this->Method = stoi(Tg);
    if(this->Method == 2)
    {
        fflush(stdin); getline(filein,this->KClient,';');
        fflush(stdin); getline(filein,this->NameClient,';');
        fflush(stdin); getline(filein,this->Address,';');
        fflush(stdin); getline(filein,this->PNumber,';');
    }
    int count;
    fflush(stdin); getline(filein,Tg,';');
    count = stoi(Tg);
    for(int i = 0 ; i < count ; i++)
    {
        string KF;
        fflush(stdin); getline(filein,KF,';');
        Food F(KF),TG;
        M.LF.GetData(M.LF.Search(F),TG);
        fflush(stdin); getline(filein,Tg,';');
        TG.Quantity = stoi(Tg);
        this->LF.addTail(this->LF.getNode(TG));
        if(i == count - 1)
        {
            string M;
            fflush(stdin); getline(filein,M);
        }
    }
}
void Order::Outputfile(ofstream& fileout)
{
    if(Count_outfile != 0) fileout<<endl;
    fileout<<this->KBill<<";"<<this->Method<<";";
    if(this->Method == 2)
    {
        fileout<<this->KClient<<";";
        fileout<<this->NameClient<<";"<<this->Address<<";"<<this->PNumber<<";";
    }
    fileout<<this->LF.Length()<<";";
    for(struct node<Food> *k = this->LF.pHead; k != NULL ; k = k->pNext)
    {
        fileout<<k->data.KFood<<";"<<k->data.Quantity<<";";
    }
    Count_outfile++;
}
bool Order::operator==(const Order& O)
{
    if(this->KBill == O.KBill)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Order::operator>(const Order& O)
{
    if(this->KBill > O.KBill)
    {
        return true;
    }
    else
    {
        return false;
    }
}
const Order& Order::operator=(const Order& O)
{
    struct node<Food> *p;
    while (this->LF.pHead != NULL)
    {
        p = this->LF.pHead;
        this->LF.pHead = this->LF.pHead->pNext;
        delete p;
    }
    this->KBill = O.KBill;
    this->Method = O.Method;
    this->KClient = O.KClient;
    this->NameClient = O.NameClient;
    this->PNumber = O.PNumber;
    this->Address = O.Address;
    for(struct node<Food> *k = O.LF.pHead; k != NULL ; k = k->pNext)
    {
        Food F = k->data;
        // F.KFood = k->data.KFood;
        // F.Name = k->data.Name;
        // F.Price = k->data.Price;
        // F.Unit = k->data.Unit;
        // F.Quantity = k->data.Quantity;
        this->LF.addTail(this->LF.getNode(F));
    }
    return *this;
}
ostream& operator<<(ostream& o,Order& Od)
{
    Od.Show();
    return o;
}
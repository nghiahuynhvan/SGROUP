#include"Order_Manager.h"
class Display
{
    private:
        int n;
    public:
        Display();
        ~Display();
        void ShowMenu();
        int Select();
        void Treatment();
};

Display::Display()
{}
Display::~Display()
{}
void Display::ShowMenu()
{
    cout << "=============================================================\n";
    cout << "1. Goi mon\n";
    cout << "2. Hien thi,xuat danh sach don hang goi mon\n";
    cout << "3. Sap xep danh sach don hang theo Ma don\n";
    cout << "4. Tim kiem don hang\n";
    cout << "5. Xoa 1 don hang\n";
    cout << "0. Thoat!!!\n";
    cout << "=============================================================\n";
}
int Display::Select()
{
    this->n = 0;
    cout << "Moi ban nhap lua chon: ";
    cin >> this->n;
    if (this->n >= 0)
        return this->n;
    else
        return Display::Select();
}
void Display::Treatment()
{
    int k, sel = 1;
    Menu M;
    ifstream filein;
    M.Inputfile(filein,"Menu");
    filein.close();
    Order_Manager OM(M);
    while (sel != 0)
    {
        this->ShowMenu();
        sel = this->Select();
        if (sel == 0)
            cout << "\t\t\t Da thoat!!!\n";
        if (sel == 1)
        {
            cout<<"\nGoi mon\n";
            M.Show();
            OM.Import(M);
        }
        if(sel == 2)
        {
            cout << "\nHien thi danh sach don hang goi mon\n";
            OM.Export();
        }
        if(sel == 3)
        {
            cout << "\nSap xep danh sach don hang theo Ma don\n";
            OM.Sort();
        }
        if(sel == 4)
        {
            cout << "\nTim kiem don hang\n";
            OM.Search();
        }
        if(sel == 5)
        {
            cout << "\nXoa 1 don hang\n";
            OM.Del();
        }
        if(sel > 6 || sel < 0)
            cout << "\nKhong hop le!!!\n";
    }
}
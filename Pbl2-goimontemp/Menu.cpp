#include"Menu.h"
Menu::Menu()
{

}
Menu::~Menu()
{

}
void Menu::Add()
{
    Food F;
    cin>>F;
    this->LF.addTail(this->LF.getNode(F));
}
void Menu::Del(string KF)
{
    Food F(KF);
    this->LF.deletePosition(LF.Search(F));
}
void Menu::Update(string KF)
{
    Food F(KF);
    cout<<"Sua ten mon: "; fflush(stdin); getline(cin,F.Name);
    cout<<"Sua don vi: "; fflush(stdin); getline(cin,F.Unit);
    cout<<"Sua gia tien: "; cin>>F.Price;
    this->LF.Update(this->LF.Search(F),F); 
}
void Menu::Show()
{
    cout<<setw(10)<<left<<"Ma mon"<<setw(20)<<left<<"Ten mon"<<setw(20)<<left<<"Don vi"<<setw(20)<<left<<"Gia tien (VND)"<<endl;
    this->LF.ShowLIST();
}
void Menu::Inputfile(ifstream& filein, string input)
{   
    filein.open(input + ".txt", ios::in);
    if(filein.eof() == true)
    {
        cout<<"Khong co du lieu trong file "<<input;
    }
    else
    {
        while (!filein.eof())
        {
            Food F;
            F.InputFile(filein);
            string M; getline(filein,M);
            this->LF.addTail(this->LF.getNode(F));
        }
    }
    filein.close();
}
void Menu::Outputfile(ofstream& fileout, string output)
{
    fileout.open(output + ".txt", ios::out);
    for(struct node<Food> *k = this->LF.pHead ; k != NULL ; k = k->pNext )
        k->data.OutputFile(fileout);
    fileout.close();
}
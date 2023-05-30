#include"Client.h"
Client::Client(string KC, string NC, string A, string PN)
{
    this->KClient = KC;
    this->NameClient = NC;
    this->Address = A;
    this->PNumber = PN;
}
Client::~Client()
{}
void Client::Import()
{
    cout<<"Nhap ma khach hang: "; fflush(stdin); getline(cin,this->KClient);
    cout<<"Nhap ten khach hang: "; fflush(stdin); getline(cin,this->NameClient);
    cout<<"Nhap dia chi cua khach hang: ";
    fflush(stdin); getline(cin,this->Address);
    cout<<"Nhap so dien thoai cua khach hang: ";
    fflush(stdin); getline(cin,this->PNumber); 
}
void Client::Show()
{
    cout<<"Ma khach hang: "<<this->KClient<<endl;
    cout<<"Ten khach hang: "<<this->NameClient<<endl;
    cout<<"Dia chi cua khach hang: "<<this->Address<<endl;
    cout<<"So dien thoai cua khach hang: "<<this->PNumber<<endl;
}
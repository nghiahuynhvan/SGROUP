#include"Food.h"
static int Check = 0;
Food::Food(string KF, string N, string U, int P, int Q)
{
    this->KFood = KF;
    this->Name = N;
    this->Unit = U;
    this->Price = P;
    this->Quantity = Q;
}
Food::~Food()
{

}
ostream& operator<<(ostream& o, const Food& F)
{
    if(F.Quantity==0)
        o<<setw(10)<<left<<F.KFood<<setw(20)<<left<<F.Name<<setw(20)<<left<<F.Unit<<setw(20)<<left<<F.Price<<endl;
    else 
        o<<setw(10)<<left<<F.KFood<<setw(20)<<left<<F.Name<<setw(20)<<left<<F.Unit<<setw(20)<<left<<F.Price<<setw(10)<<right<<F.Quantity<<endl;
    return o;
}
istream& operator>>(istream& i, Food& F)
{
    cout<<"Nhap Ma mon: "; fflush(stdin); getline(cin,F.KFood);
    cout<<"Nhap Ten mon: "; fflush(stdin); getline(cin,F.Name);
    cout<<"Nhap Don vi tinh: "; fflush(stdin); getline(cin,F.Unit);
    cout<<"Nhap Gia tien: "; i>>F.Price;
    return i;
}
bool Food::operator>(const Food& F)
{
    if(this->KFood > F.KFood)
        return true;
    else
        return false;
}
const Food& Food::operator=(const Food& F)
{
    this->KFood = F.KFood;
    this->Name = F.Name;
    this->Unit = F.Unit;
    this->Price = F.Price;
    this->Quantity = F.Quantity;
    return *this;
}
bool Food::operator==(const Food& F)
{
    if(this->KFood == F.KFood)
        return true;
    else
        return false;
}
void Food::InputFile(ifstream& filein)
{
    getline(filein,this->KFood,';');
    getline(filein,this->Name,';');
    getline(filein,this->Unit,';');
    filein>>this->Price;
}
void Food::OutputFile(ofstream& fileout)
{
    if(Check != 0) fileout<<endl;
    fileout<<this->KFood<<";";
    fileout<<this->Name<<";";
    fileout<<this->Unit<<";";
    fileout<<this->Price;
    Check++;
}
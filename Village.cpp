#include "Vilage.h"

Vilage::Vilage()
{
    _buildings = 0;
}

Vilage::Vilage(string country, string name, int pop, int buildings) : Place(country, name, pop)
{
    CheckPop(buildings);
    _buildings = buildings;
}

int Vilage::GetInt() const
{
    return _buildings;
}

void Vilage::SetInt(const int buildings)
{
    CheckPop(buildings);
    _buildings = buildings;
}

void Vilage::Print()
{
    cout << typeid(*this).name() << endl;
    cout << " Країна: " << _country<<endl;
    cout << " Назва: " << _name << endl;
    cout << " Населення: " << _pop << endl;
    cout << " К-сть будинків: " << _buildings << endl;
}

Vilage* Vilage::Clone()
{
    Vilage* copied = new Vilage(_country, _name, _pop, _buildings);
  
    return copied;
}

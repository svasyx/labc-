#include "City.h"

City::City()
{
    _routs = 0;
}

City::City(string country, string name, int pop, int routs) : Place(country, name, pop)
{
    CheckPop(routs);
    _routs = routs;
}

int City::GetInt() const
{
    return _routs;
}

void City::SetInt(const int routs)
{
    CheckPop(routs);
    _routs = routs;
}

void City::Print()
{
    cout << typeid(*this).name() << endl;
    cout << " Країна: " << _country << endl;
    cout << " Назва: " << _name << endl;
    cout << " Населення: " << _pop << endl;
    cout << " К-сть автобусних маршрутів: " << _routs << endl;
}

City* City::Clone()
{
    City* copied = new City(_country, _name, _pop, _routs);

    return copied;
}


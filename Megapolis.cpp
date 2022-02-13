#include "Megapolis.h"

Megapolis::Megapolis()
{
    _aglomeration_count = 0;
}

Megapolis::Megapolis(string country, string name, int pop, int aglomeration_count) : Place(country, name, pop)
{
    CheckPop(aglomeration_count);
    _aglomeration_count = aglomeration_count;
}

int Megapolis::GetInt() const
{
    return _aglomeration_count;
}

void Megapolis::SetInt(const int aglomeration_count)
{
    CheckPop(aglomeration_count);
    _aglomeration_count = aglomeration_count;
}

void Megapolis::Print()
{
   cout << typeid(*this).name() << endl;
    cout << " Країна: " << _country << endl;
    cout << " Назва: " << _name << endl;
    cout << " Населення: " << _pop << endl;
    cout << " К-сть агломерацій: " << _aglomeration_count << endl;
}

Megapolis* Megapolis::Clone()
{
    Megapolis* copied = new Megapolis(_country, _name, _pop, _aglomeration_count);

    return copied;
}

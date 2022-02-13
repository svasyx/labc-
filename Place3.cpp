#include "Place.h"

Place::Place()
{
    _name = "name";
    _country = "country";
    _pop = 0;
}

Place::Place(string country, string name, int pop)
{
    CheckPop(pop);
    _pop = pop;
    _country = country;
    _name = name;
}

int Place::GetPop() const
{
    return _pop;
}

string Place::GetCountry() const
{
    return _country;
}

string Place::GetName() const
{
    return _name;
}

bool Place::Compare(Place* obj)
{
    if (_country == obj->GetCountry() && _name == obj->GetName() && _pop == obj->GetPop() && GetInt() == obj->GetInt())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Place::SetPop(const int pop)
{
    CheckPop(pop);
    _pop = pop;
}

void Place::SetCountry(const string country)
{
    _country = country;
}

void Place::SetName(const string name)
{
    _name = name;
}

void Place::CheckPop(const int pop)
{
    if (pop<0)
    {
        cout << "Bad" << endl;
        exit(0);
    }
}

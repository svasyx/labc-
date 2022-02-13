
#include "Place.h"

int Place::GetPop()
{
	return _population;
}
string Place::GetCountry()
{
	return _country;
}
string Place::GetName()
{
	return _name;
}
void Place::SetPop(const int population)
{
	CheckPop();
	_population = population;
}
void Place::SetCountry(const string country)
{
	_country = country;
}
void Place::SetName(const string name)
{
	_name = name;
}
void Place::CheckPop()
{
	if (_population < 0)
	{
		cout << "bad" << endl;
		exit(0);
	}
}


Place::Place()
{

	_country = "country1";
	_name = "name1";
	_population = 0;


}
Place::Place(string counrty, string name, int pop)
{
	_country = counrty;
	_name = name;
	_population = pop;

}
bool Place::operator==(Place obj)
{

	if (_country == obj._country && _name == obj._name && _population == obj._population)
	{
		return true;

	}
	else
	{
		return false;
	}

}
bool Place::operator!=(Place obj)
{
	if (_country != obj._country || _name != obj._name || _population != obj._population)
	{
		return true;

	}
	else
	{
		return false;
	}
}


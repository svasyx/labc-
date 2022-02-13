#pragma once
#include "Header.h"
class Place
{
	friend ostream& operator<<(ostream& out, const Place& object);
	friend istream& operator>>(istream& in, Place& object);

public:
	Place();
	Place(string counrty, string name, int pop);
	int GetPop();
	string GetCountry();
	string GetName();
	void SetPop(const int population);
	void SetCountry(const string counrty);
	void SetName(const string name);
	void CheckPop();



	bool operator==(Place obj);
	bool operator!=(Place obj);


private:

	string _country;
	string _name;
	int _population;

};


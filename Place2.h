#pragma once
#include "Header.h"
class Place
{
public:

	Place();
	Place(string country, string name, int pop);
	int GetPop()const;
	string GetCountry()const;
	string GetName()const;
	void SetPop(const int pop);
	void SetCountry(const string country);
	void SetName(const string name);
	void CheckPop(const int pop);


	virtual void SetInt(const int pop) = 0;
	virtual int GetInt() const = 0;
	virtual void Print() = 0;
	virtual Place* Clone() = 0;

	bool Compare(Place* obj);


protected:
	string _country;
	string _name;
	int _pop;

};

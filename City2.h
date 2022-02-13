#pragma once
#include "Place.h"
class City:public Place
{
public:
	City();
	City(string country, string name, int pop, int routs);

	int GetInt() const override;
	void SetInt(const int num) override;

	void Print() override;

	City* Clone() override;
protected:
	int _routs;
};

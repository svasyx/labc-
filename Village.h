#pragma once
#include "Place.h"
class Vilage:public Place
{
public:
	Vilage();
	Vilage(string country, string name, int pop, int buildings);

	int GetInt() const override;
	void SetInt(const int buildings) override;

	void Print() override;

	Vilage* Clone() override;
protected:
	int _buildings;
};

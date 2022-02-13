#pragma once
#include "Place.h"
class Megapolis: public Place 
{
public:

	Megapolis();
	Megapolis(string country, string name, int pop, int aglomeration_count);

	int GetInt() const override;
	void SetInt(const int aglomeration_count) override;

	void Print() override;

	Megapolis* Clone() override;

protected:
	int _aglomeration_count;
};

#pragma once
#include "Header.h"
#include "List.h"
class Region
{
public:

	Region();
	void Print();
	~Region();
	int GetAmount();
	int GetCount();

	List Iterator_pop(bool(*action)(Place, int), const int pop);
	List Iterator_str(bool(*action)(Place, string), const string smth);

	Region& operator+(Place obj);
	Region& operator-(Place obj);
	Region& operator=(const Region& obj);

private:

	int _popAmount;
	int _count;
	List _list;

};

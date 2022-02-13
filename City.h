#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>


using namespace std;

class Place
{
	private:

		char* _country;
		char* _name;
		int _population;
		void checkpop(int population);

    public:

		Place();
		Place(const char* country, const char* name, int population);
		Place(const Place& city);

		void SetCountry(const char* country);
		char* GetCountry();
		void SetName(const char* name);
		char* GetName();
		void SetCount(int count);
		int GetCount();
		void EnterName(char* name);
		void EnterCountry(char* country);
		void EnterCount();

		
		~Place();
	
		void Print();

	
};


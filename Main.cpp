#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include "time.h"
#include"City.h"


//Додати меню
//Зчитування з клавіатури(меню)



Place NoObject(Place& city)
{
	Place tmp(city);
	tmp.SetCountry("Name");
	tmp.SetName("Name1");
	tmp.SetCount(100000);
	return tmp;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

	//Place a("Ukraine", "Kyiv", 1000000);
	//a.Print();


	//Place b(a);
	//b.Print();

	//Place* place = new Place("Ukraine", "Kyiv", 213413);//Вказівник на компоненту-функцію
	//place->Print();

	//

	//Place c;
	//c.SetCount(1234);
	//c.SetCountry("Ukraine");
	//c.SetName("Kyiv");
 //   c.Print();

	//Place d;
	//d.SetName("Ukraine");
	//d.SetCountry("Kyiv");
	//d.SetCount(10000);
	//
	//cout << d.GetName()  << endl;
	//cout << d.GetCountry() <<endl;
	//cout << d.GetCount() <<endl;
	//
	//Place* p;
	//p = new Place[3]; 
	//p->SetCountry("Country");
	//p->SetName("City");
	//p->SetCount(10000);
	//p->Print();

	Place f;

	char country[256] ;
	char name[256] ;


	f.EnterCountry(country);
	f.EnterName(name);
	
	f.EnterCount();

	cout << country;
	cout << name;
	cout << f.GetCount() <<endl;



	//Place e = NoObject(a);
	//e.Print();
	
	
}

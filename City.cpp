#include "City.h"



void Place::SetCountry(const char* country) /*���� � ������*/
{
	delete[]_country;
	int len = strlen(country);
	this->_country = new char[len + 1];
	strcpy(this->_country, country);
	cout << "\n����������� � ����������� ���������� ��� �ᒺ��� " << this << "\n" << endl;
}

char* Place::GetCountry()/*���� � ������*/
{
	return this->_country;
	cout << "\n����������� � ����������� ���������� ��� �ᒺ��� " << this << "\n" << endl;
}

void Place::SetName(const char* name)/*���� � ������*/
{
	delete[]_name;
	int len = strlen(name);
	this->_name = new char[len + 1];
	strcpy(this->_name, name);
	cout << "\n����������� � ����������� ���������� ��� �ᒺ��� " << this << "\n" << endl;

}

char* Place::GetName()/*���� � ������*/
{
	return this->_name;
	cout << "\n����������� � ����������� ���������� ��� �ᒺ��� " << this << "\n" << endl;
}

void Place::SetCount(int population)/*���� � ����������*/
{
	
	this->_population = population;
	checkpop(population);
	
	cout << "\n����������� � ����������� ���������� ��� �ᒺ��� " << this << "\n" << endl;
}

int Place::GetCount()/*���� � ����������*/
{
	return this->_population;
	cout << "\n����������� � ����������� ���������� ��� �ᒺ��� " << this <<"\n"<< endl;
}

void Place::EnterName(char* name)/*�������� ����� � ���������*/
{

	
	cout << "������ �����" << endl;

	
	fgets(name, 1024, stdin);

	name[strlen(name) - 1] = ' ';

	

}

void Place::EnterCountry(char* country)/*�������� ����� � ���������*/
{
	
	cout <<"\n"<< "������ �����" << "\n" << endl;
	
	fgets(country, 1024, stdin);
	
	country[strlen(country) - 1] = ' ';


	
}

void Place::EnterCount()/*�������� ��������� � ���������*/
{
	int population;
	
	cout <<"\n"<< "������ ���������" << "\n" << endl;
	cin >> population;
	checkpop(population);
	this->_population = population;
	


}

Place::~Place()/*����������*/
{
	delete[]this->_country;
	cout << "\n���������� ���������� ��� �ᒺ��� \n" << this <<"\n"<< endl;
	delete[]this->_name;
	cout << "\n���������� ���������� ��� �ᒺ��� \n" << this <<"\n"<< endl;
	
}

void Place::checkpop(int population)/*�������� ���������*/
{
	if (population < 0)
	{
		cout << " naselenie < 0" << endl;
		exit(0);
	}
}

Place::Place() /*����������� �� �����������*/
{
	this->_population = 0;
	this->_name = nullptr;
	this->_country = nullptr;
}

Place::Place(const char* country, const char* name,  int population) /*����������� � �����������*/
{

	this->_population = population;
	checkpop(population);
	int len = strlen(name);
	int len1 = strlen(country);
	this->_country = new char[len1 +1];
	this->_name = new char[len +1];
	if (this->_country==NULL||this->_name==NULL)
	{
		cout << "Bad Allocketed" << endl;
	}
	strcpy(this->_country, country);
	strcpy(this->_name, name);
	cout << "\n����������� � ����������� ���������� ��� �ᒺ���  " << this << endl;
}

Place::Place(const Place& city) /*����������� ���������*/
{
	this->_population = city._population;
	checkpop(_population);
	int len = strlen(city._country);
	int len1 = strlen(city._name);
	this->_country = new char[len + 1];
	this->_name = new char[len1 + 1];
	if (this->_country==NULL||this->_name==NULL)
	{
		cout << "Bad Allocketed" << endl;
		exit(0);
	}
	strcpy(this->_country, city._country);
	strcpy(this->_name, city._name);
	cout << "\n����������� ��������� ���������� ��� �ᒺ��� " << this << endl;
}

void Place::Print()/*���� �����*/
{
	cout << "Country:" << this->_country << endl;
	cout << "Name:" << this->_name << endl;
	cout << "count:" << this->_population << endl;
		
}

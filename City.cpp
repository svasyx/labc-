#include "City.h"



void Place::SetCountry(const char* country) /*Сетр з країною*/
{
	delete[]_country;
	int len = strlen(country);
	this->_country = new char[len + 1];
	strcpy(this->_country, country);
	cout << "\nКонструктор з параметрами викликаний для об’єкта " << this << "\n" << endl;
}

char* Place::GetCountry()/*Гетр з країною*/
{
	return this->_country;
	cout << "\nКонструктор з параметрами викликаний для об’єкта " << this << "\n" << endl;
}

void Place::SetName(const char* name)/*Сетр з назвою*/
{
	delete[]_name;
	int len = strlen(name);
	this->_name = new char[len + 1];
	strcpy(this->_name, name);
	cout << "\nКонструктор з параметрами викликаний для об’єкта " << this << "\n" << endl;

}

char* Place::GetName()/*Гетр з назвою*/
{
	return this->_name;
	cout << "\nКонструктор з параметрами викликаний для об’єкта " << this << "\n" << endl;
}

void Place::SetCount(int population)/*Сетр з населенням*/
{
	
	this->_population = population;
	checkpop(population);
	
	cout << "\nКонструктор з параметрами викликаний для об’єкта " << this << "\n" << endl;
}

int Place::GetCount()/*гетр з населенням*/
{
	return this->_population;
	cout << "\nКонструктор з параметрами викликаний для об’єкта " << this <<"\n"<< endl;
}

void Place::EnterName(char* name)/*Введення назви з клавіатури*/
{

	
	cout << "Введіть назву" << endl;

	
	fgets(name, 1024, stdin);

	name[strlen(name) - 1] = ' ';

	

}

void Place::EnterCountry(char* country)/*Введення країни з клавіатури*/
{
	
	cout <<"\n"<< "Введіть країну" << "\n" << endl;
	
	fgets(country, 1024, stdin);
	
	country[strlen(country) - 1] = ' ';


	
}

void Place::EnterCount()/*Введення населення з клавіатури*/
{
	int population;
	
	cout <<"\n"<< "Введіть населення" << "\n" << endl;
	cin >> population;
	checkpop(population);
	this->_population = population;
	


}

Place::~Place()/*Деструктор*/
{
	delete[]this->_country;
	cout << "\nДеструктор викликаний для об’єкта \n" << this <<"\n"<< endl;
	delete[]this->_name;
	cout << "\nДеструктор викликаний для об’єкта \n" << this <<"\n"<< endl;
	
}

void Place::checkpop(int population)/*Перевірка населення*/
{
	if (population < 0)
	{
		cout << " naselenie < 0" << endl;
		exit(0);
	}
}

Place::Place() /*Конструктор за замовчанням*/
{
	this->_population = 0;
	this->_name = nullptr;
	this->_country = nullptr;
}

Place::Place(const char* country, const char* name,  int population) /*Конструктор з параметрами*/
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
	cout << "\nКонструктор з параметрами викликаний для об’єкта  " << this << endl;
}

Place::Place(const Place& city) /*Конструктор копіювання*/
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
	cout << "\nКонструктор копіювання викликаний для об’єкта " << this << endl;
}

void Place::Print()/*Друк класу*/
{
	cout << "Country:" << this->_country << endl;
	cout << "Name:" << this->_name << endl;
	cout << "count:" << this->_population << endl;
		
}

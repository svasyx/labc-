#pragma once
#include "Header.h"
#include "Place.h"
#include "Node.h"
class List
{

public:
	List();
	List(Place obj);
	List(const List& list);

	int GetSize()const;


	void DeleteElem();

	void Delete_list();



	List Iterator_pop(bool(*action)(Place, int), const int pop);
	List Iterator_str(bool(*action)(Place, string), const string smth);


	Place& operator[](const int index);
	List& operator+(Place obj);
	List& operator-(Place obj);
	List& operator=(const List& list);
	bool operator==(const List& list);
	~List();
private:

	void Add(const string country, const string name, int population);
	void Invert(const string country, const string name, int population);
	Node* _head;


};


#pragma once
#include "Header.h"
#include "Place.h"
class Node
{
	friend class List;
public:
	Place Get_data();

private:
	Place _data;
	Node* _next;
	Node(string _country, string _name, int _pop);
};



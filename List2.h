#pragma once
#include "Node.h"

class List
{
public:
    List();
    List(Node obj);
    List(const List& lst);

    int GetSize()const;

    void DelList();
    void Print();

    Place*& operator[](const int pos);
    List& operator+(Place* obj);
    List& operator-(Place* obj);
    List& operator=(const List& lst);
    bool operator!=(const List& lst);
    ~List();
private:
    void Add(const Node& obj);
    Node* _head;
};

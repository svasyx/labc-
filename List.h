#pragma once
#include "Node.h"
class List// клас списку
{
public:
    List();//конструктор списку     
   ~List();//деструктор списку
    List(const List& list); //конструктор копіювання
    List(char* arr, int size); //конструктор з параметами

    void MassiveAdd(char* mas); //додавання елементів до списку з масиву
    void DeleteFirst();//видалення першого елементу зі списку
    void DeleteList();//видалення списку повністю
    void Input();//введення та додавання елементів до списку з клавіатури
    int GetSize()const; //отримання поточного розміру списку
    

    char& operator[](const int index);// перевантажений оператор []
    List& operator+(const char symbol);// перевантажений оператор +
    List& operator-(const char symbol);// перевантажений оператор -
    List& operator=(const List& obj);// перевантажений оператор =
    List& operator==(const List& list)// перевантажений оператор ==
private:

    void Add(const char symbol); //додавання елементу в початок списку
    void InvertList(const char symbol); //інвертування списку
    Node* _head; //покажчик на голову списку
};

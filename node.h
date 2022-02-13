#pragma once
class Node
{
public:
    Node* _next;// покажчик на наступний елемент
    char _symbol;//data // елемент списку типу char
    Node(char symbol, Node* next=nullptr);// конструктор вузла списку
};

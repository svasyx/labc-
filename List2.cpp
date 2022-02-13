#include "List.h"

List::List()
{
    _head = nullptr;
}

List::List(Node object)
{
    _head = nullptr;
    Add(object);
}

List::List(const List& list)
{
    Node* tmp = list._head;
    for (int i = 0; i < list.GetSize(); i++)
    {
        Add(tmp->_data);
        tmp = tmp->_next;
    }
}

List::~List()
{
    while (GetSize() != 0)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
    }
}

int List::GetSize() const
{
    Node* tmp = _head;
    int counter = 0;
    if (_head == nullptr)
    {
        return 0;
    }
    else
    {
        while (tmp != nullptr)
        {
            counter++;
            tmp = tmp->_next;
        }
    }
    return counter;
}

void List::DelList()
{
    int count = GetSize();
    while (count != 0)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
        count--;
    }
}

void List::Print()
{
    Node* tmp = _head;
    while (tmp != nullptr)
    {
        tmp->Get_data()->Print();
        tmp = tmp->_next;
    }
}

void List::Add(const Node& object)
{
    if (_head == nullptr)
    {
        _head = new Node(object.Get_data());
    }
    else
    {
        Node* cur = _head;
        while (cur->_next != nullptr)
        {
            cur = cur->_next;
        }
        cur->_next = new Node(object.Get_data());
    }
}

Place*& List::operator[](const int index)
{
    int counter = 0;
    Node* cur = _head;
    if (index >= GetSize() || GetSize() <= 0)
    {
        exit(1);
    }
    while (cur != nullptr)
    {
        if (counter == index)
        {
            return cur->_data;
        }
        cur = cur->_next;
        counter++;
    }   
}

List& List::operator+(Place* object)
{
    Node node(object);
    Add(node); 
    return *this;
}

List& List::operator-(Place* object)
{
    Node* cur = _head;
    Node* tmp = nullptr;
    if (GetSize() == 0)
    {
        exit(1);
    }
    if (cur->_data->Compare(object))
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
        return *this;
    }
    while (cur->_next != nullptr)
    {

        if (cur->_next->_data->Compare(object))
        {
            tmp = cur->_next->_next;
            delete cur->_next;
            cur->_next = tmp;
            return *this;
        }
        cur = cur->_next;
    }
}

List& List::operator=(const List& list)
{
    if (this == &list)
    {
        return *this;
    }
    while (GetSize() != 0)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
    }
    _head = nullptr;
    Node* tmp = list._head;
    for (int i = 0; i < list.GetSize(); i++)
    {
        Add(tmp->_data);
        tmp = tmp->_next;
    }
    return *this;
}

bool List::operator!=(const List& list)
{
    int counter = 0;
    Node* cur = _head;
    Node* temp = list._head;
    if (GetSize() < list.GetSize() || GetSize() > list.GetSize())
    {
        return 1;
    }
    while (cur != nullptr)
    {
        if (cur->_data->Compare(temp->_data))
        {
            counter++;
        }
        temp = temp->_next;
        cur = cur->_next;
    }
    if (counter != GetSize())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


#include "list.h"
#include "Node.h"
#include "Header.h"

List::List()
{
    _head = nullptr;
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

List::List(char* array, int size)// додавання масиву у вузли
{
    if (strlen(array) == size) 
    {
       _head = nullptr;
        for (int i = 0; i < size; i++)
        {
            Add(array[i]);
        }
    }
}

int List::SizeOfList(const List& list)
{
    Node* tmp = list._head;
    int counter = 0;
    if (list._head == nullptr)
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
};


List::List(const List& list)
{
    Node* tmp = list._head;
    for (int i = 0; i < list.GetSize(); i++)
    {
        InvertList(tmp->_symbol);
        tmp = tmp->_next;
    }

}

void List::InvertList(const char data)// "Інвертування списку"
{
    if (_head == nullptr)
    {
        _head = new Node(data);
    }
    else
    {
        Node* cur = this->_head;
        while (cur->_next != nullptr)
        {
            cur = cur->_next;
        }
        cur->_next = new Node(data);
    }
}

   



void List::Add(const char data)
{
 
        _head = new Node(data, _head);
        if (!_head) {
            cout << "Wrong allocation" << endl;
        }
        
 
}

void List::MassiveAdd(char* mas)
{
    for (int i = 0; i < sizeof(mas) / sizeof(char); i++)
    {
  
            Add(mas[i]);
    }
}

void List::DeleteFirst()
{
    Node* temp = _head;

    _head = _head->_next;

    delete temp;

}

void List::DeleteList()
{
    while (GetSize() != 0)
    {
        DeleteFirst();
    }
}

void List::Input()
{
    char data;
    cin >> data;
    Add(data);
}

int List::GetSize()const
{
    Node* tmp = this->_head;
    int counter = 0;
    if (this->_head == nullptr)
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

char& List::operator[](const int index)
{
    int counter = 0;
    Node* cur = this->_head;
    while (cur != nullptr)
    {
        if (counter == index)
        {
            return cur->_symbol;
        }
        cur = cur->_next;
        counter++;
    }
}

List& List::operator+(const char symbol)
{
    Add(symbol);
    return *this ;
}

List& List::operator-(const char symbol)
{
    Node* cur = this->_head;
    Node* tmp = nullptr;
    if (cur->_symbol == symbol)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
        
    }
    while (cur->_next != nullptr)
    {
        if (cur->_next->_symbol == symbol)
        {
            tmp = cur->_next->_next;
            delete cur->_next;
            cur->_next = tmp;
            return *this;
            break;
        }
        cur = cur->_next;
    }
    
}
List& List::operator=(const List& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    while (GetSize() != 0)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
    }
    this->_head = nullptr;
    Node* tmp = obj._head;
    for (int i = 0; i < obj.GetSize(); i++)
    {
        Add(tmp->_symbol);
        tmp = tmp->_next;
    }
    return *this;

}

bool List::operator==(const List& list)// перегрузка оператору
{
    int counter = 0;
    Node* cur = this->_head;
    Node* temp = list._head;
    if (this->GetSize() < list.GetSize() || this->GetSize() > list.GetSize())
    {
        return false;
    }
    while (cur != nullptr)
    {
        if (cur->_symbol == temp->_symbol)
        {
            counter++;
        }
        temp = temp->_next;
        cur = cur->_next;
    }
    if (counter != this->GetSize())
    {
        return false;
    }
    else
    {
        return true;
    }
}

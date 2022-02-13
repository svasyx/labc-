#include "List.h"

List::List()
{
    _head = nullptr;
}

List::List(Place obj)
{
    _head = nullptr;
    Add(obj.GetCountry(), obj.GetName(), obj.GetPop());
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


List::List(const List& list)
{
    Node* tmp = list._head;
    for (int i = 0; i < list.GetSize(); i++)
    {
        Invert(tmp->_data.GetCountry(), tmp->_data.GetName(), tmp->_data.GetPop());
        tmp = tmp->_next;
    }
}

int List::GetSize() const
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






void List::DeleteElem()
{
    Node* temp = _head;

    _head = _head->_next;

    delete temp;

}

void List::Delete_list()
{
    while (GetSize() != 0)
    {
        DeleteElem();
    }
}

List List::Iterator_pop(bool(*action)(Place, int), const int pop)
{
    List obj;
    Node* temp = _head;
    while (temp != nullptr)
    {
        if (action(temp->Get_data(), pop) == 1)
        {
            obj + temp->Get_data();

        }
        temp = temp->_next;
    }

    return obj;
}

List List::Iterator_str(bool(*action)(Place, string), const string smth)
{
    List obj;
    Node* temp = _head;
    while (temp != nullptr)
    {
        if (action(temp->Get_data(), smth) == 1)
        {
            obj + temp->Get_data();

        }
        temp = temp->_next;
    }

    return obj;
}

Place& List::operator[](const int index)
{
    int counter = 0;
    Node* cur = this->_head;
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

List& List::operator+(Place obj)
{
    Add(obj.GetCountry(), obj.GetName(), obj.GetPop());
    return *this;
}

List& List::operator-(Place obj)
{
    Node* cur = this->_head;
    Node* tmp = nullptr;
    if (cur->_data == obj)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
        return *this;
    }
    while (cur->_next != nullptr)
    {
        if (cur->_next->_data == obj)
        {
            tmp = cur->_next->_next;
            delete cur->_next;
            cur->_next = tmp;
            break;
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
    this->_head = nullptr;
    Node* tmp = list._head;
    for (int i = 0; i < list.GetSize(); i++)
    {
        Add(tmp->_data.GetCountry(), tmp->_data.GetName(), tmp->_data.GetPop());
        tmp = tmp->_next;
    }
    return *this;

}



bool List::operator==(const List& list)
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
        if (cur->_data == temp->_data)
        {
            counter++;
        }
        temp = temp->_next;
        cur = cur->_next;
    }
    if (counter != this->GetSize())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void List::Add(const string country, const string name, int population)
{
    if (_head == nullptr)
    {
        _head = new Node(country, name, population);
        if (!_head) {
            cout << "Wrong allocation" << endl;
        }
    }
    else
    {
        _head = new Node(country, name, population);
        if (!_head) {
            cout << "Wrong allocation" << endl;
        }

    }
}

void List::Invert(const string country, const string name, int population)
{
    if (_head == nullptr)
    {
        _head = new Node(country, name, population);
    }
    else
    {
        Node* cur = this->_head;
        while (cur->_next != nullptr)
        {
            cur = cur->_next;
        }
        cur->_next = new Node(country, name, population);
    }

}

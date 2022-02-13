#include "Region.h"

Region::Region()
{
    _popAmount = 0;
    _count = 0;

}

void Region::Print()
{

    for (int i = 0; i < _list.GetSize(); i++)
    {
        cout << _list[i] << endl;
    }
}

Region::~Region()
{
    _list.Delete_list();
}

int Region::GetAmount()
{
    return _popAmount;
}
int Region::GetCount()
{
    return _count;
}



Region& Region::operator+(Place obj)
{
    _list + obj;
    _popAmount += obj.GetPop();
    _count++;
    return *this;
}

Region& Region::operator=(const Region& obj)
{
    _list = obj._list;
    this->_popAmount = obj._popAmount;
    this->_count = obj._count;
    return *this;
}

Region& Region::operator-(Place obj)
{
    _list - obj;
    _popAmount -= obj.GetPop();
    _count--;
    return *this;
}

List Region::Iterator_pop(bool(*action)(Place, int), const int pop)
{
    List obj = _list.Iterator_pop(action, pop);

    return obj;
}

List Region::Iterator_str(bool(*action)(Place, string), const string smth)
{
    List obj = _list.Iterator_str(action, smth);

    return obj;
}

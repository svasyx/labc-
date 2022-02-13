#include "Node.h"

Place Node::Get_data()
{
    return _data;
}



Node::Node(string _country, string _name, int _pop) :_data(_country, _name, _pop)
{
    this->_next = nullptr;
}

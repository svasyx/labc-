#include "Node.h"

Node::Node(char data, Node* next)
{
    this->_symbol = data;
    this->_next = next;
}

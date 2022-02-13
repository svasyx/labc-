#pragma once
#include "Header.h"
#include "Place.h"
#include "Megapolis.h"
#include "Vilage.h"
#include "City.h"

class Node
{
    friend class List;
public:
    Place* Get_data() const;
   // Node(const Node& node);
    ~Node();
private:
    Place* _data;
    Node* _next;
    Node(Place* obj);
};

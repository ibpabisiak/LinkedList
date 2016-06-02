#include "stdafx.h"
#include "Node.h"


Node::Node(std::string value, Node * next) : value(value), next(next) { }

Node::~Node() 
{
}

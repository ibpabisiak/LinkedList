#pragma once
#include <string>

class Node
{
	public:
		std::string value;
		Node * next;
		Node(std::string, Node * = NULL);
		~Node();

	private:
};

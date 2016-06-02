#pragma once
#include "stdafx.h"
#include "Node.h"

class List
{
	private:
		Node * head;

	public:
		List();
		~List();
		bool Add(std::string);
		bool Remove(std::string);
		bool Search(std::string);
		void ShowList();
		void Sort();
};

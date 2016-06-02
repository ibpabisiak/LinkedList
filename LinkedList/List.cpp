#include "stdafx.h"
#include "List.h"

List::List() : head( NULL ) { }

List::~List() 
{
	Node * tmp = this->head;
	while (tmp)
	{
		Node * copy = tmp;
		tmp = tmp->next;
		delete(copy);
	}
}

bool List::Add(std::string value)
{
	if (this->head == NULL) 
	{
		this->head = new Node(value);
		return true;
	}
	else 
	{
		Node * tmp = this->head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(value);
		return true;
	}

	return false;
}

bool List::Remove(std::string value)
{
	if (this->Search(value))
	{
		if (this->head->value.compare(value) == 0)
		{
			if (this->head->next != NULL)
			{
				Node * swap = this->head->next;
				delete(this->head);
				this->head = swap;
				
				return true;
			}
			else
			{
				delete(this->head);
				this->head = NULL;
				
				return true;
			}
		
		}
		else
		{
			Node * tmp = this->head;
			while (tmp->next)
			{
				if (tmp->next->value.compare(value) == 0)
					break;
				
				tmp = tmp->next;
			}

			Node * swap = tmp->next;
			tmp->next = swap->next;
			delete(swap);

			return true;
		}
	}
	return false;
}

bool List::Search(std::string value)
{
	if (this->head != NULL)
	{
		Node * tmp = this->head;
		while (tmp->next)
		{	
			if (tmp->value.compare(value) == 0)
				return true;

			tmp = tmp->next;
		}
		return (tmp->next == NULL && tmp->value.compare(value) == 0);
	}
	return false;
}

void List::ShowList()
{
	if (this->head)
	{
		Node * tmp = this->head;
		while (tmp->next)
		{
			std::cout << tmp->value << std::endl;
			tmp = tmp->next;
		}
		std::cout << tmp->value << std::endl;
	}
}

void List::Sort()
{
	int count = 0;
	Node * start = this->head, * curr = NULL, * trail = NULL, * temp = NULL, * i = this->head;

	while(i)
	{
		i = i->next;
		curr = trail = this->head;

		while (curr->next) {
			if (curr->value.compare(curr->next->value) > 0) 
			{
				temp = curr->next;
				curr->next = curr->next->next;
				temp->next = curr;

				if (curr == this->head)
					this->head = trail = temp;
				else 
					trail->next = temp;
				curr = temp; 
			}
			
			trail = curr;
			curr = curr->next;
		}
	}
}

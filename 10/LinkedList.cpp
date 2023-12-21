#include "LinkedList.h"
#include <iostream>
void LinkedList::push(int x)
{
	Node *p = new Node;
	p->key = x;
	p->next = head;
	head = p;
}

int LinkedList::pop()
{
	if (!isEmpty())
	{
		int value(head->key);
		Node* p = head->next;
		delete head;
		head = p;
		return value;
	}
	std::cout << "The list is empty!" << std::endl;
	exit(-6);
}

bool LinkedList::isEmpty()
{
	return head == nullptr;
}

void LinkedList::print()
{
	if (!isEmpty())
	{
		Node* p = head;
		do
		{
			std::cout << p->key << " ";
			p = p->next;
		} while (p != nullptr);
		std::cout <<std::endl;
	}
	else
	{
		std::cout << "The list is empty!" << std::endl;
	}	
}

void LinkedList::append(int x)
{
	Node *p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	Node *q = new Node;
	q->key = x;
	p->next = q;
}

Node* LinkedList::findValue(int x)
{
	Node* p = head;
	while (p != nullptr)
	{
		if (p->key == x)
		{
			return p;
		}
		p = p->next;
	}
	return nullptr;	
}

int LinkedList::popBack()
{
	Node* p = head;
	while (p->next->next != nullptr)
	{
		p = p->next;
	}
	int value(p->next->key);
	delete p->next;
	p->next = nullptr;
	return value;
}

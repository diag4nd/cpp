#ifndef LINKEDLIST_H
#define LINKEDLSIT_H
#include "Interface.h"
#include "Node.h"
class LinkedList: public Interface
{
public:
	Node* head;
	void push(int x);
	void append(int x);
	int pop();
	bool isEmpty();
	void print();
	Node* findValue(int x);
	int popBack();

};


#endif // !LINKEDLIST_H



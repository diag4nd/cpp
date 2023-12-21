#ifndef INTERFACE_H
#define INTERFACE_H
class Interface
{
public:
	virtual int pop() = 0;
	virtual void push(int value) = 0;
	virtual void print() = 0;
	virtual bool isEmpty() = 0;
};

#endif

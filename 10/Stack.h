#ifndef STACK_H
#define STACK_H
#include <vector>
class Stack
{
private:
	std::vector<int> linspace;
public:
	Stack(): linspace(0)
	{}
	Stack(std::initializer_list<int> initVector)
	{
		linspace = std::vector<int>(initVector);
	}
	int pop();
	void push(int value);
};

#endif
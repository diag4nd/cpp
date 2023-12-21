#include "Stack.h"
#include <iostream>

int Stack::pop()
{
	if (linspace.empty())
	{
		std::cout << "Stack is empty!" << std::endl;
		exit(-2);
	}
	int res = linspace[linspace.size() - 1];
	linspace.erase(linspace.end() - 1);
	return res;
}

void Stack::push(int value)
{
	auto iter = linspace.cend();
	linspace.insert(iter, value);
}
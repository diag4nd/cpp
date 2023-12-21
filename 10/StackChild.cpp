#include "StackChild.h"
#include <iostream>

int StackChild::pop()
{
	if (linspace.empty())
	{
		std::cout << "Stack is empty!" << std::endl;
		exit(-3);
	}
	int res = linspace[linspace.size() - 1];
	linspace.erase(linspace.end() - 1);
	return res;
}
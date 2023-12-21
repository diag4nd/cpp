#include "Queue.h"
#include <iostream>

int Queue::pop()
{
	if (linspace.empty())
	{
		std::cout << "Queue is empty!" << std::endl;
		exit(-1);
	}
	int res = linspace[0];
	linspace.erase(linspace.begin());
	return res;
}

void Queue::push(int value)
{
	linspace.insert(linspace.end(), value);
}
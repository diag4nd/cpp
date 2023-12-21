#include "StackData.h"
#include <iostream>

int StackData::pop()
{
	if (data.empty())
	{
		std::cout << "Stack is empty!" << std::endl;
		exit(-5);
	}
	int res = data[data.size() - 1];
	data.erase(data.end() - 1);
	return res;
}

bool StackData::isEmpty()
{
	return data.size() == 0;
}

void StackData::print()
{
	for (int i(0); i < getLen(); i++)
	{
		std::cout << getItem(i) << " ";
	}
	std::cout << std::endl;
}
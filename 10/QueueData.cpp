#include "QueueData.h"
#include <iostream>

int QueueData::pop()
{
	if (data.empty())
	{
		std::cout << "Queue is empty!" << std::endl;
		exit(-4);
	}
	int res = data[0];
	data.erase(data.begin());
	return res;
}
bool QueueData::isEmpty()
{
	return data.size() == 0;
}
void QueueData::print()
{
	for (int i(0); i < getLen(); i++)
	{
		std::cout << getItem(i) << " ";
	}
	std::cout << std::endl;
}

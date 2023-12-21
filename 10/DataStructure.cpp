#include "DataStructure.h"
#include <iostream>
void DataStructure::push(int value)
{
	auto iter = data.cend();
	data.insert(iter, value);
}
int DataStructure::getLen()
{
	return data.size();
}
int DataStructure::getItem(int index)
{
	return data[index];
}


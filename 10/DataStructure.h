#ifndef DATASTRUTURE_H
#define DATASTRUTURE_H

#include "Interface.h"
#include <vector>
class DataStructure: public Interface
{
protected:
	std::vector<int> data;
public:
	void push(int value);
	int getLen();
	int getItem(int index);
};

#endif // !DATASTRUTURE_H



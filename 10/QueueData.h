#ifndef QUEUEDATA_H
#define QUEUEDATA_H
#include "DataStructure.h"
class QueueData: public DataStructure
{
public:
	int pop();
	bool isEmpty();
	void print();
};

#endif
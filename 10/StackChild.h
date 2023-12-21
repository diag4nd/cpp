#ifndef STACKCHILD_H
#define STACKCHILD_H
#include "Queue.h"
#include <vector>
class StackChild: public Queue 
{
public:
	StackChild(std::initializer_list<int> initVector) : Queue(initVector){}
	int pop();
};

#endif
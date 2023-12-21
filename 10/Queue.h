#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
class Queue
{
protected:
	std::vector<int> linspace;
public:
	Queue(): linspace(0)
	{}
	Queue(int value, ...)
	{
		int* p = &value;
		int i(0);
		while (i++ < 20)
		{
			linspace.push_back(*(p));
			p++;
			//p++;
		}

	}
	Queue(std::initializer_list<int> initVector)
	{
		linspace = std::vector<int>(initVector);
	}
	int pop();
	void push(int value);
};

#endif
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "StackChild.h"
#include "QueueData.h"
#include "StackData.h"
#include "LinkedList.h"

template<class Type>
Type reverse(Type list)
{
    Type temp;
    for (int i(list.getLen() - 1); i >= 0; i--)
    {
        temp.push(list.getItem(i));
    }
    return temp;
}
template<>
LinkedList reverse<LinkedList>(LinkedList list)
{
    LinkedList temp;
    while (!list.isEmpty())
    {
        temp.push(list.pop());
    }
    return temp;
}


int main()
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.print();
    
    StackData sl;
    sl.push(4);
    sl.push(5);
    sl.push(6);
    sl.print();

    QueueData ql;
    ql.push(7);
    ql.push(8);
    ql.push(9);
    ql.print();

    LinkedList nll = reverse<LinkedList>(ll);
    nll.print();
    StackData nsl = reverse<StackData>(sl);
    nsl.print();
    QueueData nql = reverse<QueueData>(ql);
    nql.print();
}

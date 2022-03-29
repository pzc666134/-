#include "mStack.h"
#include <iostream>
using namespace std;


mStack::mStack()
{
	length = 0;
	base = NULL;
	top = NULL;
}
int mStack::push(mPoint point)
{
	mPoint* mpNode = new mPoint();
	*mpNode = point;
	if (length == 0)
		top = base = mpNode;
	else
	{
		top->next = mpNode;
		top = mpNode;
	}
	return ++length;
}
mPoint mStack::getTop()
{
	return *top;
}
mPoint mStack::pop()
{
	if (length <= 0)
		return NULL;
	mPoint retPoint = *top;
	top = base;
	while (top->next != NULL)
	{
		if (top->next->next == NULL)
		{
			delete(top->next);
			top->next = NULL;
			break;
		}
		top = top->next;
	}
	if (length == 1)
	{
		delete(base);
		base = top = NULL;
	}
	length--;
	return retPoint;
}

int mStack::getLength()
{
	return length;
}
void mStack::printStack()
{
	mPoint* p = base;
	while (p != NULL)
	{
		cout << "(" << p->x << "," << p->y << ")" << endl;
		p = p->next;
	}

}
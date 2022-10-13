#include <string>
#include "ArrayStack.h"

// using namespace std;

template <typename Object>
void ArrayStack<Object>::create(int sz)
{
	this->data = new Object[sz];
	this->arraySize = sz;
	this->top = 0;
}

template <typename Object>
void ArrayStack<Object>::increaseSize()
{
	// will be implemented later
}

template <typename Object>
ArrayStack<Object>::ArrayStack()
{
	this->create(STACK_SIZE_DEFAULT);
}

template <typename Object>
ArrayStack<Object>::ArrayStack(int sz)
{
	this->create(sz);
}

template <typename Object>
ArrayStack<Object>::~ArrayStack()
{
	delete[] this->data;
	this->data = NULL;
}

template <typename Object>
void ArrayStack<Object>::push(const Object & e)
{
	if(this->isFull())
	{
		this->increaseSize();
	}
	if(this->isFull())
	{
		throw string("ArrayStack is full!!");
	}

	this->data[this->top] = e;
	this->top++;
}

template <typename Object>
Object ArrayStack<Object>::pop()
{
	Object ro = this->peek();
	this->top--;
	return ro;
}

template <typename Object>
Object ArrayStack<Object>::peek() const
{
	if(this->isEmpty())
	{
		throw string("ArrayStack is empty!!");
	}

	return this->data[this->top-1];
}

template <typename Object>
bool ArrayStack<Object>::isEmpty() const
{
	return (this->top == 0);
}

template <typename Object>
bool ArrayStack<Object>::isFull() const
{
	return (this->top == this->arraySize);
}

template <typename Object>
long ArrayStack<Object>::size() const
{
	return this->top;
}

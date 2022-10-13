#ifndef Stack__Header
#define Stack__Header

#include "StackADT.h"

#define STACK_SIZE_DEFAULT 20

template <typename Object>
class ArrayStack : public Stack<Object>
{
	protected:
		Object *data;
		long arraySize;
		long top;

		void create(int);
		void increaseSize();
	public:
		ArrayStack();
		ArrayStack(int);
		~ArrayStack();

		void push(const Object &);
		Object pop();
		Object peek() const;
		bool isEmpty() const;
		bool isFull() const;
		long size() const;
};

#include "ArrayStack_Cpp.h"

#endif ArrayStack__Header

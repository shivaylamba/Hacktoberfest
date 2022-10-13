#include <iostream>
#include <string>

using namespace std;

#define STACK_SIZE_DEFAULT 20

class Stack
{
	public:
		virtual void push(const int &) = 0;
		virtual int pop() = 0;
		virtual int peek() const = 0;
		virtual bool isEmpty() const = 0;
		virtual long size() const = 0;
};

class ArrayStack : public Stack
{
	protected:
		int *data;
		long arraySize;
		long top;

		void create(int);
		void increaseSize();
	public:
		ArrayStack();
		ArrayStack(int);
		~ArrayStack();

		void push(const int &);
		int pop();
		int peek() const;
		bool isEmpty() const;
		bool isFull() const;
		long size() const;
};

void ArrayStack::create(int sz)
{
	this->data = new int[sz];
	this->arraySize = sz;
	this->top = 0;
}

void ArrayStack::increaseSize()
{
	// will be implemented later
}

ArrayStack::ArrayStack()
{
	this->create(STACK_SIZE_DEFAULT);
}

ArrayStack::ArrayStack(int sz)
{
	this->create(sz);
}

ArrayStack::~ArrayStack()
{
	delete[] this->data;
	this->data = NULL;
}

void ArrayStack::push(const int & e)
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

int ArrayStack::pop()
{
	int ro = this->peek();
	this->top--;
	return ro;
}

int ArrayStack::peek() const
{
	if(this->isEmpty())
	{
		throw string("ArrayStack is empty!!");
	}

	return this->data[this->top-1];
}

bool ArrayStack::isEmpty() const
{
	return (this->top == 0);
}

bool ArrayStack::isFull() const
{
	return (this->top == this->arraySize);
}

long ArrayStack::size() const
{
	return this->top;
}

int main()
{
	Stack *s = new ArrayStack;
	
	s->push(12);
	s->push(33);
	s->push(28);
	s->push(89);
	s->push(44);
	cout << s->pop() << endl;
	s->push(57);
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->peek() << endl;
	s->push(94);
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->peek() << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << (s->isEmpty() ? "Empty Stack" : "Non empty stack") << endl;
	try
	{
		cout << s->pop() << endl;
	}
	catch(string s)
	{
		cout << "Exception caught: " << s << endl;
	}
	
	delete s;
	
	return 0;
}
#ifndef Stack__ADT__Header
#define Stack__ADT__Header

template <typename Object>
class Stack
{
	public:
		virtual void push(const Object &) = 0;
		virtual Object pop() = 0;
		virtual Object peek() const = 0;
		virtual bool isEmpty() const = 0;
		virtual long size() const = 0;
};

#endif Stack__ADT__Header

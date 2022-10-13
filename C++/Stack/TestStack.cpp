#include <iostream>
#include <string>

#include "ArrayStack.h"

using namespace std;

int main()
{
	Stack<int> *s = new ArrayStack<int>;
	
	s->push(12);
	s->push(33);
	s->push(28);
	s->push(89);
	s->push(44);
	cout << s->pop() << endl;
	s->push(57);
	cout << s->pop() << endl;
	//cout << s->pop() << endl;
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
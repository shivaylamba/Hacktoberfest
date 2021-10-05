stack<int> s;
int minElement;
void push(int val)
{
	if(s.empty())
	{
		minElement = val;
		s.push(val);
	}
	if(val>=s.top()
		s.push(val);
    else
    {
    	s.push(2 * val - minElement);
    	minElement = val;
    }
}

void pop()
{
	if(s.size()==0)
		return -1;
	else
		{
		if(s.top() >= minElement)
		return s.pop();
	   else if(s.top() < minElement)
	   {
	   	minElement = 2 * minElement - s.top();
	   	s.pop();
	   }
	}
}

int top()
{
	if(s.size()==0)
		return -1;
	else if(s.top() > minElement)
		return s.top();
	else
		return minElement;
}
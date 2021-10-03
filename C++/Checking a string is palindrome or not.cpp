#include <iostream>
using namespace std;

int main()
{
	string a= "abba";
	int i = 0, j = a.length()-1;
	int flag=0;
        
		for(i=0;i < j ;i++)
		{
        if(a[i] != a[j-i-1])
		{
            flag = 1;
            break;
   		}
   		}

if (flag==1)
cout<<"Yes";

else
cout<<"No";

return 0;
}

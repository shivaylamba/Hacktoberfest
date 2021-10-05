#include<bits/stdc++.h>
using namespace std;
#define d 256
int main()
{
	string txt = "geeksforgeeks";
	string ptr = "for";
	int n = txt.size();
	int m = ptr.size();
	int h = 1;
	int q = 101;
	// hash value
	int p = 0;
	int t = 0;
	for(int i = 0 ; i < m-1;i++)
	{
		h = (h*d)%q;
	}
	// calculated the hash value
	// now calculating the hash value for the pattern and the text
	for(int i = 0 ; i<M ; i++)
	{
		 p = (p * d + ptr[i]) %q;
		 t = (t*d + txt[i]) % q;
	}
	for (int i = 0; i <= N - M; i++)
    {
 
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != ptr[j])
                    break;
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout<<"Pattern found at index "<< i<<endl;
        }
        // next we need to calculate the value of the next hash function
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
 
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            t = (t + q);
        }s
}
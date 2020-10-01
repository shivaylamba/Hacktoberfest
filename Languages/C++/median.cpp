#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getMedian(vector<int> a, int n, int median)
{
    sort(a.begin(),a.end());
    int mid = a.at(n/2);
    int count = 0,i;
    if(mid == median)
        return 0;
    if(mid < median)
    {
        for(i = n/2; a.at(i) < median; i++)
        {
            while(a.at(i) < median)
            {
                a.at(i)++;
                count++;
            }
        }
        return count;
    }
    for(i = 0; i < n/2; i++)
    {
       while(a.at(i) > median)
       {
           a.at(i)--;
           count++;
       }
    }
    return count;
}


int main()
{
    int t = 0;
    cin >> t ;
    while(t--)
    {
        int n = 0, median = 0;
        cin >> n >> median;
        vector<int> a;
        int ip = 0,i;
        for( i = 0; i < n; i++)
        {
            cin >> ip ;
            a.push_back(ip);
        }
        cout << getMedian(a,n,median) << endl;
    }
    return 0;
}

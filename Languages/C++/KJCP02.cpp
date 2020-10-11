// Solution to the problem KJCP02
// Question link: https://www.codechef.com/problems/KJCP02
// Author: Nandini Gupta

#include <iostream>            
#include <string.h>
#include <map>
#include <stdlib.h>
#include <math.h>
#include<stdio.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for (int k = 0; k < t; k++)
    {
        int n;
        scanf("%d",&n);
        map<long int, int> mymap;
        int m;
        scanf("%d",&m);
        for(int i=0;i<n;i++){
            long int x;
            scanf("%ld",&x);
            mymap[x]++;
        }
        map<long int,int>::iterator it;
        
        for(int i=0;i<m;i++){
            long int x;
            scanf("%ld",&x);
            it=mymap.find(x);
            if(it==mymap.end()){
                printf("NO\n");
            }
            else {
                printf("YES\n");
            }
            mymap[x]++;
        }
        
    }
}

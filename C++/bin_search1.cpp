#include <bits/stdc++.h>
using namespace std;

int bin_search(int a[], int n, int key)  // this is most basic version which returns 1 when element is found else -1
{
    if(n<1) return 0;
    if (n == 1)
    {
        if (a[0] == key)
            return 1;
        else
            return 0;
    }

    if (a[n / 2] == key)
        return 1;
    else if (key < a[n / 2])
        return bin_search(a, n / 2, key);
    else
        return bin_search(a + (n / 2)+1, n - n / 2 - 1, key);
}
int binary_search(int a[],int l, int r,int key)   // L-start index R-last index   (Improved version return index if element is found else -1)
{
    if(l>=r) 
        return -1;

    
    int m=l+(r-l)/2;

    if(a[m]==key) return m;
    else if(a[m]>key) return binary_search(a,l,m,key);
    else return binary_search(a,m+1,r,key);
    

}  

int main()
{
    int a[] = {2,4,5,6,7};
    cout << bin_search(a,5, 8);
    cout << binary_search(a,0,5,8);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void bsort(int* a, int n) {

    int t;

    for(int i = 0; i < n-1; i++) {

        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";

}

int main() {

    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int a[n];
    cout<<"Enter array: ";
    for(int i = 0; i < n; i++)
        cin>>a[i];

    bsort(a, n);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<str> vs;
typedef vector<vector <int> > vvi;
typedef vector<vector <ll> > vvl;

const ll remi=1000000007;
const ll remi2=998244353;
const ll inf=1e18+1e17+1e16+1e15+1e14;

#define pi 3.141592653589
#define pb push_back
#define F first
#define S second
#define el "\n"
#define sp " "
void quickSort(int arr[], int low, int high);
void swap(int* a, int* b);
int partition (int arr[], int low, int high) ;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); int i;
    int n;
    cin>>n;
     int arr[n]; 
    for(i=0;i<n;i++)
    cin>>arr[i];
    quickSort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    for(i=0;i<n;i++)
    cout<<arr[i]<<sp;
    return 0;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int p = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
#include<bits/stdc++.h>

using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define input(a,n) for(ll i=0;i<n;i++){ll y;cin>>y;a.pb(y);}
#define print(x) for(auto it:x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(),(x).end()
#define clr(x) memset(x,0,sizeof(x))
#define fn(a,n) for(ll i = a; i < n; ++i)
#define f(n) for(ll i = 0; i < n; i++)
#define endl '\n'
#define test ll t;cin>>t;while(t--)
#define INF 1000000000
#define MAX 100001
#define pyes cout<<"YES"<<endl;
#define pno cout<<"NO"<<endl;
#define sz(x) (x).size()

const ll mod=1000000007;

void insertionSort(vector<int> &arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


int main()
{
    io;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char temp;
        cin >> n;
        int a[n][n];
        scanf(" %c",&temp);
        for (int i = 0; i < n; i++){
            scanf("%c",&temp);            
            for (int j = 0; j < n; j++)
            {
                int t;
                scanf("%d %c",&t,&temp);
                a[i][j] = t;
            }
            scanf("%c",&temp);            

        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                if(i>j)
                    swap(a[i][j],a[j][i]);
            }
        }
        cout << '[';
        for (int i = 0; i < n ; i++)
        {
            cout << '[';
            for (int j = n-1; j >= 0; j--)
            {
                if(j != 0)
                    cout << a[i][j] << ',';
                else
                {
                    cout << a[i][j];
                }
                
            }
            if(i != n-1)
                cout << ']'<< ',';
            else
            {
                cout << ']';
            }
            
        }
        cout << ']' << '\n';

    }
    
    
    return 0;
}

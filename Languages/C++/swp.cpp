#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        //Boundary Case-1
        if(n == 0){
            cout << '0' << '\n';
            continue;
        }

        list<int> l;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            l.emplace_back(temp);
        }
        //Boundary Case-2
        if(n == 2){
            for(auto x: l){
                cout << x << " ";
            }
            cout <<'\n';
            continue;
        }

        list<int>::iterator it1 = l.begin();
        list<int>::iterator it2 = l.begin();
        list<int>::iterator it3 = l.end();
        list<int>::iterator it4 = l.end();
        advance(it3,-2);
        it4--;
        advance(it1,2);
        advance(it2,3);

        for (int i = 0; i < l.size(); i++)
        {
            if(it2 != it4 && it1 != it3){
                iter_swap(it1,it2);
                advance(it1,2);
                advance(it2,2);
            }    
        }
        for(auto x: l){
            cout << x << " ";
        }
        cout << '\n';
    }

    
    return 0;
}

    #include<bits/stdc++.h>
    using namespace std;
    void gmedian(vector<int>&vec,int k)
    {
        sort(vec.begin(),vec.end());
        int n=vec.size();
        int m=(n/2);
        int x=0,j;
        for( j=0;j<n;j++)
        {
            if(k==vec[j])
            break;
        }

        if(vec[m]<k)
        {
            for(int i=m;i<j;i++){
                x=x+(vec[j]-vec[i]);}
        }
       if(vec[m]>k)
        {
            for(int i=j;i<m;i++){

                x=x+(vec[m]-vec[i]);}
        }
        cout<<x;
        cout<<endl;

    }












        int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
           // vector<pair<int,int>>a;
            int x,n,k;
            cin>>n;
            cin>>k;
            vector<int>vec;

            for(int i=0;i<n;i++)
            {
                cin>>x;
                vec.push_back(x);


            }
            gmedian(vec,k);
        }
        return 0;
    }

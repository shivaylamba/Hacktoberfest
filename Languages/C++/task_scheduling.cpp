    #include<bits/stdc++.h>
    using namespace std;
    void selection(vector<int>vec,vector<int>index)
    {
         vector<int>vec2;
        int sum=0,sum1=0;
        vector<pair<int,int>>a;
        for(int i=0;i<vec.size();i++){
            a.push_back(make_pair(vec[i],index[i]));
    }
           sort(a.begin(),a.end());
           for(int i=0;i<vec.size();i++)
           {

               sum=sum+a[i].first;
               vec2.push_back(sum);
           }

           for(int i=0;i<vec.size();i++)
           {
               cout<<a[i].second<<endl;
           }
           for(int i=0;i<vec2.size();i++)
           {
               sum1=sum1+vec2[i];
           }
           double avg=(double(sum1)/(double)vec2.size());
           cout<<avg;
           cout<<endl;
    }
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
           // vector<pair<int,int>>a;
            int x,n;
            cin>>n;

            vector<int>vec;
            vector<int>index;

            for(int i=0;i<n;i++)
            {
                cin>>x;
                vec.push_back(x);


            }
            for(int i=1;i<=n;i++)
            {


                index.push_back(i);
            }
            selection(vec,index);
        }
        return 0;
    }

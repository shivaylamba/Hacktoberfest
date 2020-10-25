    #include<bits/stdc++.h>
    using namespace std;
    void ls(vector<int>vec,int k)
    {
        vector<int>vec2;
        int sum=0;
        int n=vec.size();
        for(int i=0;i<n;i++){
            sum=sum+vec[i];
            if(sum/(i+1)<k)
            {
                vec2.push_back(vec[i]);
            }}
            cout<<vec2.size()<<endl;
            for(int i=0;i<vec2.size();i++){
                    cout<<vec2[i]<<" ";}
                    cout<<endl;
    }
        int main()
    {
        int t;
        cin>>t;
        while(t--)
        {

            int x,n,k;
            cin>>n;
            cin>>k;
            vector<int>vec;

            for(int i=0;i<n;i++)
            {
                cin>>x;
                vec.push_back(x);


            }
           ls(vec,k);
        }
        return 0;
    }

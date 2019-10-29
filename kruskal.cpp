#include<bits/stdc++.h>
using namespace std;

class item{
	public:
    int p1, p2, wt;
};

bool compare( item a, item b )
{
    return ( a.wt<b.wt );
}

int findparent( int *parent, int a )
{
    if(parent[a]==a)
        return a;
    return findparent(parent, parent[a]); 
    
}


int main()
{
    int e, v;
    cin>>v>>e;
    item *input = new item[e];
    item *output = new item[v-1];
    for( int i=0; i<e; i++ )
    {
        cin>>input[i].p1>>input[i].p2>>input[i].wt;
    }
    
    sort( input, input+e, compare );
    
    int *parent = new int[v];
    for( int i=0; i<v; i++ )
    {
        parent[i] = i;
    }
    
    int count = 0;
    while( count<v-1 )
    {
        for( int i=0; i<e; i++ )
        {
            int x = findparent(parent, input[i].p1);
            int y = findparent(parent, input[i].p2);
            if( x!=y )
            {
                output[count++] = input[i];
                parent[x] = y;
            }
        }
    }
    
    for( int i=0; i<v-1; i++ )
    {
        cout<<min( output[i].p1, output[i].p2 )<<" "<<max( output[i].p1, output[i].p2)<<" "<<output[i].wt<<endl;
    }
    
    return 0;
}

// every node is the parent of itself


int parent[100000];
int rank[100000];
void makeset()
{
	for(int i = 1 ; i <=n ; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}
void findparent(int u)
{
	if(parent[u]==u)
		return u;
	return parent[u] = findparent(parent[u]);
	//doing path compression
}
void unionfunc(int a , int b)
{
int  u = findparent(a);
int b = findparent(b);
if(rank[u] > rank[v])
	parent[v] = u;
else if(rank[v] > rank[u])
	parent[u] = v;
else
{
	parent[v] = u;
	rank[u]++;
 }
}
int main()
{
	makeset();
}
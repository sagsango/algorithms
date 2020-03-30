vector<vector<int>>g;
vector<int> tin;
vector<int> tout;
vector<vector<int>>up;
int t,n,lgN;

void dfs(int u=1,int p=0)
{
	tin[u]=++t;
	up[u][0]=p;
	for(int i=1;i<=lgN;i++)
	{
		up[u][i]=up[ up[u][i-1] ][i-1];
	}
	for(auto v:g[u])
	{
		if( v!= p)
		{
			dfs(v,u);
		}
	}
	tout[u]=++t;
}

int isAncestor(int u,int v)
{
	return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int LCA(int u,int v)
{
	if( isAncestor(u,v) )return u;
	if( isAncestor(v,u) )return v;
	
	for(int i=lgN;i>=0;i--)
	if( up[u][i] && !isAncestor(up[u][i],v))
	u=up[u][i];
	
	return up[u][0];
}

void init()
{
	    lgN=20;
		t=0;
		g=vector<vector<int>>(n+1);
		up=vector<vector<int>>(n+1,vector<int>(lgN+1));
		tin=vector<int>(n+1);
		tout=vector<int>(n+1);
}

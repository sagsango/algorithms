/////////////////////  Binary Lifting ///////////////////////////
vector<vector<pair<int,int>>>G;
vector<int> tin;
vector<int> tout;
vector<vector<int>>up;
vector<vector<int>>X;
int t;

void dfs(int u,int p,int w)
{
	tin[u]=++t;
	up[u][0]=p;
	X[u][0]=w;
	for(int i=1;i<=lgN;i++)
	{
		up[u][i]=up[ up[u][i-1] ][i-1];
		X[u][i]=X[ up[u][i-1] ][i-1] ^ X[u][i-1];
	}
	for(auto it:G[u])
	{
		int v=it.first;
		int i=it.second;
		if( v!= p)
		{
			dfs(v,u,W[i]);
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

int XorQuery(int u,int v)
{
	
	int l = LCA(u,v);
	int x = 0;
	if( u!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[u][i] && !isAncestor(up[u][i],l))
	    {
			x=(x ^ X [u][i]);
			u=up[u][i];
		}
	x=(x ^ X [u][0]);
	}
	if( v!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[v][i] && !isAncestor(up[v][i],l))
	    {
			x=(x ^ X [v][i]);
			v=up[v][i];
		}
		x=(x ^ X [v][0]);
	}
	return x;
}
/////////////////////////////////////////////////////////

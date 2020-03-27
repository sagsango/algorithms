// Not tested
class BinaryLift{
	/* for unweighted tree assign weight = 1 */
	public:
	int n,lgn,t;
    vector<vector<pair<int,int>>>g;
    vector<int> tin;
    vector<int> tout;
    vector<vector<int>>up;
    vector<vector<int>>h;
    BinaryLift(int N=1000'000,int LGN=20)
    {
		n=N;
		lgn=LGN;
		t=0;
		g=vector<vector<pair<int,int>>>(n+1);
		tin=vector<int>(n+1);
		tout=vector<int>(n+1);
		up=vector<vector<int>>(n+1,vector<int>(lgn+1));
		h=vector<vector<int>>(n+1,vector<int>(lgn+1));
	}

    void init(int u=1,int w=0,int p=0)
    {
    	tin[u]=++t;
    	h[u][0]=w;
    	up[u][0]=p;
    	for(int i=1;i<=lgn;i++)
    	{
			up[u][i]=up[ up[u][i-1] ][i-1];
			h[u][i] = h[ up[u][i-1] ][i-1] + h[u][i-1];
		}

    	for(auto it:g[u])
    	{
			int v = it.first;
			int w = it.second;
			if(v!=p)
			{
				init(v,w,u);
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

    	for(int i=lgn;i>=0;i--)
    	if( up[u][i] && !isAncestor(up[u][i],v))
    	u=up[u][i];

    	return up[u][0];
    }

    int Distance(int u,int v)
    {
    	int l = LCA(u,v);
    	int dis = 0;
    	if( u!=l )
    	{
			for(int i=lgn;i>=0;i--)
			if( up[u][i] && !isAncestor(up[u][i],l))
			{
				dis+=h[u][i];
				u=up[u][i];
			}
			dis+=up[u][0];
		}
		if( v!=l )
		{
			for(int i=lgn;i>=0;i--)
			if( up[v][i] && !isAncestor(up[v][i],l))
			{
				dis+=h[v][i];
				v=up[v][i];
			}
			dis+=up[v][0];
		}
		return dis;
    }
};


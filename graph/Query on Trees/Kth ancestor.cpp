source    :   Competitive Programmer’s Handbook ,Antti Laaksonen ,Draft July 3, 2018 [ page : 164 ]

/* what will be kth ancestor of the node v : log(n) */
const int L=30;
const int N=1e6;
vector<int>g[N+1];
vector<vector<int>>up(N+1,vector<int>(L+1));

int dfs(int u,int p)
{
	up[u][0]=p;
	for(int i=1;i<=L;i++)
		up[u][i]=up[ up[u][i-1] ][i-1];
	for(auto v:g[u])
		if(v!=p)dfs(v,u);
}

int kth_ancestor(int u,int k)
{
	// TODO: Remove it
	/*if(!k)return u;
		for(int i=L;i>=0;i--)
		if(k - (1LL<<i) &&  up[u][i])
		{
		u=up[u][i];
		k-=1LL<<i;
		}
		return up[u][0];*/

	for(int i=0;i<=L;++i){
		if( k >> i & 1 ){
			u = par[u][i];
		}
	}
	return u;


}

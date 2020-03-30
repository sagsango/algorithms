https://codeforces.com/blog/entry/16221
https://cp-algorithms.com/graph/lca_binary_lifting.html

vector<vector<int>>g;
vector<int>h;
vector<int>par;
int n;

void dfs(int u=1,int p = 0){

	h[u] = h[p] + 1;
	par[u] = p;
	for(auto v : g[u])	
	{
		if(v!=p)
		{
			dfs(v,u);
		}
	}
}

int LCA(int v,int u){
	while( u!=v )
	{
		if( h[v] > h[u] ) v = par[v];
		else u=par[u];
	}
	return u;
}



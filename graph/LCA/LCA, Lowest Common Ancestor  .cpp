https://codeforces.com/blog/entry/16221
https://cp-algorithms.com/graph/lca_binary_lifting.html

1.Brute Force:
Preprocessing:
void dfs(int v,int p = -1){
	if(par + 1)
		h[v] = h[p] + 1;
	par[v] = p;
	for(auto u : adj[v])	if(p - u)
		dfs(u,v);
}
Query :
int LCA(int v,int u){
	if(v == u)
		return v;
	if(h[v] < h[u])
		swap(v,u);
	return LCA(par[v], u);
}


2.Binary Lifting [ 2^i th  ancestor ]:
int n, l;
vector<vector<int>> adj;

int timer=0;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (up[u][i] && !is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
dfs(1,0);


3.Binary Lifting with weight [ 2^i th ancestor and its height ]
https://codeforces.com/gym/255313/problem/F
void dfs(int u,int p,int w)
{
	int[u]=timer++;
	
	l[u][0]=p;
	h[u][0]=w;
	for(int i=1;i<=L;i++)
	{
		l[u][i]= l[ l[u][i-1] ][i-1];
		d[u][i]= d[ l[u][i-1] ][i-1] + d[u][i-1];
	}
	
	for(auto[v,w1]:g[u])
	{
		if(v!=p)dfs(v,u,w1);
	}
}


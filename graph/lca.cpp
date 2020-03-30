https://codeforces.com/blog/entry/16221
https://cp-algorithms.com/graph/lca_binary_lifting.html

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



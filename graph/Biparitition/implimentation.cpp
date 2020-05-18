vector<vector<int>>g;
vector<int>clr,vis;
int n,bipartite;
void dfs(int u,int c){
	vis[u]=1;
	clr[u]=c;
	for(auto v:g[u]){
		if( !vis[v]){
			dfs(v,c^1);
		}
		else if( clr[u]==clr[v] ){
			bipartite = 0;
		}
	}
}

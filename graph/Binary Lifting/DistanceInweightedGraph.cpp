const int maxn = 1e5+10, lgN = 20;
vector<vector<pair<int,int>>>g(maxn);
vector<int> tin(maxn);
vector<int> tout(maxn);
vector<vector<int>>par(maxn,vector<int>(lgN+1));
vector<vector<int>>dis(maxn,vector<int>(lgN+1));
int timer = 0, n;

void dfs(int u=1,int p=0,int w=0){
	tin[u]=++timer;
	par[u][0]=p;
	dis[u][0]=w;
	for(int i=1;i<=lgN;i++){
		par[u][i]=par[ par[u][i-1] ][i-1];
		dis[u][i]=dis[ par[u][i-1] ][i-1]+dis[u][i-1];
	}
	for(auto it:g[u]){
		int v=it.first;
		int w=it.second;
		if( v!= p){
			dfs(v,u,w);
		}
	}
	tout[u]=++timer;
}

int isAncestor(int u,int v){
	return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int lca(int u,int v){
	if( isAncestor(u,v) )return u;
	if( isAncestor(v,u) )return v;
	for(int i=lgN;i>=0;i--){
		if( par[u][i] && !isAncestor(par[u][i],v)){
			u=par[u][i];
		}
	}
	return par[u][0];
}

int disQuery(int u,int v){
	int l = lca(u,v);
	int d = 0;
	auto shiftup =[&](int u){
		if( u!=l ){
			for(int i=lgN;i>=0;i--){
				if( par[u][i] && !isAncestor(par[u][i],l)){
					d+=dis[u][i];
					u=par[u][i];
				}
			}
			d+=dis[u][0];
		}
	};
	shiftup(u);
	shiftup(v);
	return d;
}

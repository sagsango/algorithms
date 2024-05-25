1. lca using hld faster than binary lifting : at least 2 times      https://cses.fi/problemset/result/506768/
2. Updation/Query of nodes lies in Path u and v                     https://cp-algorithms.com/graph/hld.html
3. Updation/Query of nodes lies is Path root to u                   https://codeforces.com/gym/284118/submission/83903790
4. Updation/Query of node lies in subtree.                          https://codeforces.com/gym/284118/submission/83903790
Note : dfs order is always best                                     https://codeforces.com/blog/entry/21693

void dfs(int u,int p){
	par[u]=p;
	subtree[u]=1;
	for(auto v:g[u]){
		if( v!=p ){
			dfs(v,u);
			subtree[u]+=subtree[v];
			if( subtree[v] > subtree[ heavy[u] ]){
				heavy[u]=v;
			}
		}
	}
}
void decompose(int u,int p,int h){
	head[u]=h;
	pos[u]=++curr_pos;
	if( heavy[u] )decompose(heavy[u],u,h);
	for(auto v:g[u]){
		if( v==p || v == heavy[u] )continue;
		decompose(v,u,v);
	}
}
// https://cses.fi/problemset/result/506825/
int pathSum(int u){ // u to root
	int s = 0;
	while( u ){
		d+= query(1,1,n,pos[head[u]],pos[u]);
		u = par[ head[u] ];
	}
	return s;
}

int pathSum(int u,int l){ // u to lca
	int d = 0;
	while( head[l] != head[u] ){
		d+= query(1,1,n,pos[head[u]],pos[u]);
		u=par[head[u]];
	}
	if( u != l ){
		d+= query(1,1,n,pos[l],pos[u]);
	}
}
// https://cp-algorithms.com/graph/hld.html
int pathSum(int u,int v){ // any two vertex u and v
	while( head[u] != head[v] ){
		if( dep[head[u]] < dep[head[v]] ){
			swap(u,v);
		}
		d+=query(1,1,n,pos[head[u]],pos[u]);
		u = par[head[u]];
	}
	if( dep[u] < dep[v] ){
		swap(u,v);
		d+=query(1,1,n,pos[v],pos[u]);
	}
}
//  https://cses.fi/problemset/result/506768/
int lca(int u,int v){
	while( head[u] != head[v] ){
		if( dep[ head[u] ] < dep[ head[v] ] ){
			swap(u,v);
		}
		u = par[head[u]];
	}
	if( dep[u] < dep[v] ){
		swap(u,v);
	}
	return v;
}
	          

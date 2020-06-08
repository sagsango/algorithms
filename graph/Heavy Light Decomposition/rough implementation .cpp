/* Nothing is Tested */
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
int pathSum(int u,int v){ // u and v
	while( head[u] != head[v] ){
		if( dep[head[u]] < dep[head[v]] ){
			swap(u,v);
		}
		d+=query(1,1,n,pos[head[u]],pos[u]);
		u = par[head[u]];
	}
	if( dep[u] < dep[v] ){
		swap(u,v);
		d+=query(1,1,n,pos[v],dep[u]);
	}
}
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
	


//  things matters in life  : head , pos , heavy
void dfs(int u,int p){
        par[u]=p , depth[u]=depth[p]+1 , subtree[u]=1;
        int h = 0 , maxsize = 0;
        for(auto v:g[u]){
                if(v==p)continue;
                dfs(v,u);
                subtree[u]+=subtree[v];
                if( subtree[v] > maxsize ){
                        h = v;
                        maxsize=subtree[v];
                        heavy[u]=h;
                }
        }
}


void decompose(int u=1,int h=1){
        head[u]=h , pos[u]=curr_pos++ ;
        if(heavy[u]){
                decompose(heavy[u],h);
        }
        for(auto v:g[u]){
                if( v == par[u] || v == heavy[u] )continue;
                decompose(v,v);
        }
}


int Query(int a,int b){
        int max_query = 0;
        for(; head[a]!=head[b] ;b=par[head[b]]){
                if( depth[head[a]] > depth[head[b]] ){
                        swap(a,b);
                }
                int curr_query = segtreeQuery(pos[head[b]],pos[b]);
                max_query = max( max_query , curr_query );
        }
        if( depth[a] > depth[b] ){
                swap(a,b);
        }
        int curr_query = seqtreeQuery(pos[a],pos[b]);
         max_query = max( max_query , curr_query );
        return max_query;
}
                

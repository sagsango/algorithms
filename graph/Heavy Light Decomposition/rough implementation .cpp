/* see cp.algoritham */

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
                

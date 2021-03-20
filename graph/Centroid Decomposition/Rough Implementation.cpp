

void dfs(int u,int par){
        subtree[u]=1;
        nodes++;
        for(auto v:g[u]){
                if(v==par)continue;
                dfs(v,u);
                subtree[u]+=subtree[v];
        }
}


int center(int u,int par){
        for(auto v:g[u]){
                if( v == par ) continue;
                if( subtree[v] > (nodes>>1) ){
                        return center(v,u);
                }
        }
        return u;
}
        


void decompose(int u=1,int par=0){

        /* find centroid of curr subtree */
        nodes=0;
        dfs(u,u);
        int c = center(u,u);
        centroidpar[c]=par;
        
        
        
        
        /* solve here for curr subtree */
        
       
        
        
        
        /* Decomose recursivily and solve rest*/
        for(auto v:g[c]){
                g[v].erase(u);// erase(c)
                decompose(v,c);
        }
}

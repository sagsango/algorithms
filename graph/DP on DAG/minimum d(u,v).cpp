int N=1e6;
vector<pair<int,int>>g[N+1];
vector<int>vis(N+1);

void dfs(int u,int t,int d,int &min_d)
{
    vis[u]=1;
    if(u==t){min_d=min(min_d,d);return;}
    for(auto [v,w]:g[u])
    if(!vis[v])dfs(v,t,d+w,mid_d);
}

int min_distance(int s,int t)
{
    int min_d=inf;
    dfs(s,t,0,min_d);
    return min_d;
}
    

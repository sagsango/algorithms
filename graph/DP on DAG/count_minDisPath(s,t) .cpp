source    : Competitive Programmer’s Handbook Antti Laaksonen Draft July 3, 2018  [ Page - 151 ]
vector<int>dis(N+1,inf);
vector<int>cnt(N+1,0);
vector<int>topo;
dis[s]=0;
cnt[s]=1;
int count_minDisPath(int s,int t)
{
    dijkhstra(s);
    topo_sort();
    for(auto u:topo)
      for(auto [v,w]:g[u])
          if(dis[u]+w==dis[v])cnt[v]+=cnt[u];
    return cnt[t];
}
    

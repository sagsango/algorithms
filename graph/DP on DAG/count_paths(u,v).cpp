Referance  : Competitive Programmer’s Handbook Antti Laaksonen Draft July 3, 2018  [ Page - 151 ]
/*iterative*/
vector<int>cnt(N+1,-1);
cnt[s]=1;
int count_path(int s,int t)
{
    if(cnt[t]!=-1)return cnt[t];
    cnt[t]=0;
    for(auto v:g[s])
    cnt[t]+=count_path(s,v);
    return cnt[t];
}


/*recursive*/
int count_path(int s,int t)
{
    vector<int>cnt(N+1,0);
    cnt[s]=1;
    topo_sort();
    for(auto u:topo)
      for(auto v:g[u])
        cnt[v]+=cnt[u];
    return cnt[t];
}

Referance  : Competitive Programmer’s Handbook Antti Laaksonen Draft July 3, 2018  [ Page - 151 ]

    /* sortest path in O(n) how cool is it :) */
/*recursive*/
vector<int>dis(N+1,-1);
dis[s]=0;
int min_dis(int s,int t)
{
    /* It will be more optimal is there is only one query , because it will do not do extra work */
    /* for multiple query from same source: O(n) + O(q) * O(1) */
     if( dis[t]!=-1 )return dis[t];
     dis[t]=1e9;
     for(auto [v,w]:g[t])
         dis[t]=min(dis[t],dis(s,v)+w);
     return dis[t];
}
   
/*iterative*/
int min_dis(int s,int t)
{
    /*after running the algo , dis[v] contains min_dis(s,v) for every v */
     vector<int>dis(N+1,inf);
     topo_sort();
     dis[s]=0;
     for(auto u:topo)
        for(auto [v,w]:g[u])
            dis[v]=min(dis[v],dis[u]+w);
     return dis[t];
}

source   :   https://www.geeksforgeeks.org/number-shortest-paths-unweighted-directed-graph/
/*UdUwCG : undirected unwaited cyclic graph */
vector<int>dis(N+1,inf);
vector<int>cnt(N+1,0);
vector<int>vis(N+1);
int count_minPath(int s,int v)
{
    queue<int>q;
    dis[s]=0;
    cnt[s]=1;
    vis[s]=1;
    q.push(s);
    while( q.size() )
    {
        int u=q.top();q.pop();
        for(auto v:g[u])
        {
              if(!vis[v])
              {
                  vis[v]=1;
                  q.push(v);
              }
              if(dis[v]>dis[u]+1)
              {
                  dis[v]=dis[u]+1;
                  cnt[v]=cnt[u];
              }
              else if(dis[v]==dis[u]+1)
                  cnt[v]+=cnt[u];
        }
     }
     return dis[t];
 }
              

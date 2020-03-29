// https://cp-algorithms.com/graph/bellman_ford.html

/*  O( n*m )  : Diected and Undirected */
vector<vector<pair<int,int>>>g;
int n,m;
bool isNegtiveCycle(int s=1)
{
      vector<int>d(n+1,1e15);
      vector<int>inq(n+1);
      vector<int>cnt(n+1);
      queue<int>q;
      d[s]=0;
      inq[s]=1;
      q.push(s);
      while( q.size() )
      {
            int u=q.front();q.pop();
            inq[u]=0;
            for(auto it:g[u])
            {
                  int v=it.first;
                  int w=it.second;
                  if( d[v] > d[u] + w )
                  {
                        d[v]=d[u]+w;
                        cnt[v]++;
                        if(cnt[v]>=n)return 1;
                        if(!inq[v])
                        {
                              q.push(v);
                              inq[v]=1;
                        }
                  }
            }
      }
      return 0;
}

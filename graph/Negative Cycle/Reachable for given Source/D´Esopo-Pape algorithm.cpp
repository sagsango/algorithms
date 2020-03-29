https://cp-algorithms.com/graph/desopo_pape.html

/*  O( n*m )  : Diected and Undirected */
vector<vector<pair<int,int>>>g;
int n,m;
bool isNagtiveCycle(int s)
{
      vector<int>clr(n+1);     // 0: yet to process    1:is being process    2:has been procesed
      vector<int>d(n+1,1e15);
      vector<int>cnt(n+1);
      dequeue<int>q;
      q.push(s);
      while( q.size())
      {
          int u=q.front();q.pop_front();
          clr[u]=2;
          for(auto it:g[u])
          {
              int v=it.first;
              int w=it.second;
              if( d[v] > d[u] + w )
              {
                  d[v]=d[u]+w;
                  cnt[u]++;
                  
                  if( cnt[v] > n ) return 1;
                  
                  if( clr[v] == 2 )
                  {
                      clr[v]=1;
                      q.push_front(v);
                  }
                  else if(clr[v]==0)
                  {
                      clr[v]=1;
                      q.push_back(v);
                  }
              }
          }
      }
      return 0;
      
}

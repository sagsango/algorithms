/*  O( n*m )  */
vector<vector<pair<int,int>>>g;
int n,m;
bool isNagtiveCycle(int s)
{ 
  vector<int>d(n+1,1e15);
  vector<int>inq(n+1);
  queue<int>q;
  d[s]=0;
  inq[s]++;
  q.push(s);
  while( q.size() )
  {
    int u=q.front();q.pop();
    inq[u]++;
    for(auto it:g[u])
    {
      int v=it.first;
      int w=it.second;
      if( d[v] > d[u] + w )
      {
        d[v]=d[u]+w;
        if( (inq[v]&1)^1 )
        {
          q.push(v);
          inq[v]++;
          if( inq[v] >= 2*n )return 1;
        }
      }
    }
  }
  return 0;
}
           
  


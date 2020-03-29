// https://cp-algorithms.com/graph/bellman_ford.html

/*  O( n*m )   */
cont int N = 2000 , M = 2000;
vector<int>U(N+1),V(N+1),W(M+1);
int n,m;
bool isNagtiveCycle(int s)
{
      vector<int>d(n+1,1e15);
      int any = 0;
      d[s]=0;
      for(int i=1;i<=n;i++)
      {
          any = 0;
          for(int j=1;j<=m;j++)
          {
              int u = U[j];
              int v = V[j];
              int w = W[j];
              if( d[u] > d[v] + w )
              {
                  d[u]=d[v]+w;
                  any=1;
              }
          }
      }
      return any;
}

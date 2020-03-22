// https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
d[N][N] : D[i][i] = 0;
          D[i][j] = w;
p[N][N] : p[i][j] = k;[path throught]

for(int i=1;i<=n;i++)
{
      for(int j=1;j<=n;j++)
      {
            for(int k=1;k<=n;k++)
            {
                  if( d[i][k] > d[i][j] + d[j][k] )
                  {
                        d[i][k]=d[i][j]+d[j][k];
                        p[i][k]=j;
                  }
            }
      }
}

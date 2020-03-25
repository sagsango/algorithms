// https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
// works for negative edges
// d[i][i] < 0 meanse negative cycle is found
d[N][N] : D[i][i] = 0;
          D[i][j] = w;
p[N][N] : p[i][j] = k;[path throught]

for(int i=1;i<=n;i++) // adding one vertex one by one
{
      for(int j=1;j<=n;j++)
      {
            for(int k=1;k<=n;k++)
            {
            /* changing order of loop give WA */
                  if( d[j][k] > d[j][i] + d[i][k] ) // relax all path passing treough i
                  {
                        d[j][k]=d[j][i]+d[i][k];
                        p[j][k]=i;
                  }
            }
      }
}

// https://github.com/sagsango/UVA/blob/master/10724.cpp
// https://codeforces.com/gym/258375/submission/74251160

Idea      :   https://cp-algorithms.com/graph/fixed_length_paths.html
Problem   :   For given Graph  G find no of paths of given length k between  any two vertex
          :   O(n*n*n*log(k) )     
          :   Uses Bianry Exponentiation :-
          :   G[u][v]=w if edge u--->v  [ for undirected G[u][v]=G[v][u]=1 ]
          :   Dp(k+1)[u][v]=min(Dp(k)[u][1] * G[1][v] + Dp(k)[u][1] * G(k)[1][v] + -------- + Dp(k)[u][n] * G[n][v]);
              Dp(k)=G * G * G  ... G = G^k  [ but during multiplication we have take min values not sum]
© 2019 GitHub, Inc.

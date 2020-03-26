1.Total Path of K using edges between every pair.
  G[k] = G[k-1] @ G[1]
         @ is an operator:
	 for(int p=1;p<=n;p++)
	 for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	 G[u][v][k+1]=G[u][p][k]*G[p][v][1]
  so using binary exponentiation we can solve it in O(n*n*n*log(k))
  // https://cp-algorithms.com/graph/fixed_length_paths.html
  
2.Minimum path length between every pair using k edges.
 G[k] = G[k-1] @ G[1]
        @ is an operator:
	 for(int p=1;p<=n;p++)
	 for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	 G[u][v][k+1]=min( G[u][p][k] , G[u][p][k]+G[p][v][1]);
  so using binary exponentiation we can solve it in O(n*n*n*log(k))
  // https://cp-algorithms.com/graph/fixed_length_paths.html
  
3.Generalization of the problems for paths with length up to k
  The above solutions solve the problems for a fixed k. However the solutions can be adapted for solving problems for
  which the paths are allowed to contain no more than k edges.

  This can be done by slightly modifying the input graph.

  We duplicate each vertex: for each vertex v we create one more vertex v′ and add the edge (v,v′) and the loop (v′,v′). 
  The number of paths between i and j with at most k edges is the same number as the number of paths between i and j′ 
  with exactly k+1 edges, since there is a bijection that maps every path [p0=i, p1, …, pm−1, pm=j] of length m≤k to 
  the path [p0=i, p1, …, pm−1, pm=j,j′,…,j′] of length k+1.

  The same trick can be applied to compute the shortest paths with at most k edges. We again duplicate each vertex 
  and add the two mentioned edges with weight 0.
  
  // https://cp-algorithms.com/graph/fixed_length_paths.html
	 

/*

1) k is not an intermediate vertex in shortest path from i to j. 
   We keep the value of dist[i][j] as it is.
2) k is an intermediate vertex in shortest path from i to j.
   We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
4) After all relaxation if any diagonal is negative then graph must have negative cycle.

*/

Floyd-Warshal()
	d[v][u] = inf for each pair (v,u)
	d[v][v] = 0 for each vertex v
	for k = 1 to n
		for i = 1 to n
			for j = 1 to n
				d[i][j] = min(d[i][j], d[i][k] + d[k][j])
© 2020 GitHub, Inc.

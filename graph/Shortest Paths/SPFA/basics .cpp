SPFA (Shortest Path Faster Algorithm) is a fast and simple algorithm (single source) that its complexity is not calculated yet.
But if m = O(n2) it's better to use the first implementation of Dijkstra.
Its code looks like the combination of Dijkstra and BFS :

source    :    https://codeforces.com/blog/entry/16221
SPFA(v):
	d[i] = inf for each vertex i
	d[v] = 0
	queue q
	q.push(v)
	while q is not empty
		u = q.front()
		q.pop()
		for each i in adj[u]
			if d[i] > d[u] + w(u,i)
				then d[i] = d[u] + w(u,i)
				if i is not in q
					then q.push(i)
          
          
 source  :  https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm        
 procedure Shortest-Path-Faster-Algorithm(G, s)
  1    for each vertex v ≠ s in V(G)
  2        d(v) := ∞
  3    d(s) := 0
  4    offer s into Q
  5    while Q is not empty
  6        u := poll Q
  7        for each edge (u, v) in E(G)
  8            if d(u) + w(u, v) < d(v) then
  9                d(v) := d(u) + w(u, v)
 10                if v is not in Q then
 11                    offer v into Q

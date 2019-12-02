Bellman-Ford
Bellman-Ford is an algorithm for single source shortest path where edges can be negative 
(but if there is a cycle with negative weight, then this problem will be NP).

The main idea is to relax all the edges exactly n - 1 times (read relaxation above in dijkstra).
You can prove this algorithm using induction.
	
If in the n - th step, we relax an edge, then we have a negative cycle (this is if and only if).

Code :

Bellman-Ford(int v)
	d[i] = inf for each vertex i
	d[v] = 0
	for step = 1 to n
		for all edges like e
			i = e.first // first end
			j = e.second // second end
			w = e.weight
			if d[j] > d[i] + w
				if step == n
					then return "Negative cycle found"
				d[j] = d[i] + w
Time complexity : O(nm).


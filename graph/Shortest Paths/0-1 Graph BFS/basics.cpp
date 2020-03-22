/**
*  I think find no of cmoponents using only 0 edges
*  Then no of 1 edges will be (no of components - 1)
**/

https://codeforces.com/blog/entry/22276


for all v in vertices:
	dist[v] = inf
dist[source] = 0;
deque d
d.push_front(source)
while d.empty() == false:
	vertex = get front element and pop as in BFS.
	for all edges e of form (vertex , u):
		if travelling e relaxes distance to u:
			relax dist[u]
			if e.weight = 1:
				d.push_back(u)
			else:
				d.push_front(u)
        
this is quite similar to BFS + Dijkstra. But the time complexity of this code is O(E + V) , 
which is linear and more efficient than Dijkstra. The analysis and proof of correctness is also same as that of BFS.
And optimization : we can make our queue sorted all the time so no need of the pqiority_queue that remove log(v) factor.

void dfs(int node) {
   //Traverse through the 0-connected component
   for(auto v : G0[node])
      if(!Seen[v]) {
         Seen[v] = 1;
         D[v] = D[node];
         dfs(v);
      }
   //Push the unvisited 1-cost neighbours
   for(auto v : G1[node])
      if(!Seen[v]) {
         Seen[v] = 1;
         D[v] = D[node] + 1;
         Q.push(v);
      }
}

void bfs1_0(int start) {
   Q.push(start);
   Seen[start] = 1;

   while(!Q.empty()) {
      int top = Q.front();
      Q.pop();
      dfs(top);
   }
}


Note : if graph contains only w1 w2 w3 w4 waight make 4 queues for itearative solution
                                                      first G1 then G2 then G3 then G4 for recursive.

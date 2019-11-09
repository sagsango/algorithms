https://codeforces.com/blog/entry/63020
vector<int> euler;
void dfs(int v,int p = -1){
	euler.push_back(v);
	for(auto u : adj[v])if(p - u)dfs(u,v);
  euler.push_back(v);
}



Consider 2 copies for a single node in the Euler tour, one for entry and one for exit. When you want to add a value v 
to the subtree, maintain a fenwick tree, and do +=v on in[node] and -=v on out[node]. Path sum query can be broken down 
to sum from root to any node. For the root to node sum query, just return prefix sum of in[node] from BIT.
Now why does this work? Think about a single subtree update and then querying for prefix sum. Let's assume you updated 
subtree of node x with value v. Now, if you query for some node which is not in the subtree of x, the answer will be 0, 
either in[node]<in[x] then it's obviously 0, or in[node]>out[x] then in[x] and out[x] cancel out, so it's still 0. 
For the nodes inside the subtree of x, in[x]<in[node]<out[x]. So, they'll all return the value v. So effectively we've 
updated the subtree of x with value v

https://codeforces.com/blog/entry/63020
vector<int> euler;
void dfs(int v,int p = -1){
	euler.push_back(v);
	for(auto u : adj[v])if(p - u)dfs(u,v);
  euler.push_back(v);
}

/*NOTE: I think it is subtree update + node query, in[u]+=val, out[u]-=val, and node val = forInrngeSum(in[u]) - forOutrangeSum(in[u])
1.Update all subtree  + path sum query. [ sum of path between u - v : which can be broken down to root-v sum]
Consider 2 copies for a single node in the Euler tour, one for entry and one for exit. When you want to add a value v 
to the subtree, maintain a fenwick tree, and do +=v on in[node] and -=v on out[node]. Path sum query can be broken down 
to sum from root to any node. For the root to node sum query, just return prefix sum of in[node] from BIT.
Now why does this work? Think about a single subtree update and then querying for prefix sum. Let's assume you updated 
subtree of node x with value v. Now, if you query for some node which is not in the subtree of x, the answer will be 0, 
either in[node]<in[x] then it's obviously 0, or in[node]>out[x] then in[x] and out[x] cancel out, so it's still 0. 
For the nodes inside the subtree of x, in[x]<in[node]<out[x]. So, they'll all return the value v. So effectively we've 
updated the subtree of x with value v.
	
	

2.Update node + path sum query. [ sum of path between u - v : which can be broken down to root-v sum]
The one you've shown it can also be used to update values at each node in  time and query the sum from a node all the 
way to the root in  time. Simply create two segment trees over the Euler Tour, one where the values of each node are stored 
in the positions of their first appearance, and one where the values of each node are stored in the positions of their 
second appearance. For example, on your tree, the two segment trees would look something like:

[1,2,3,0,4,0,0,5,0,6,0,0]

[0,0,0,3,0,4,2,0,5,0,6,1]

Then, if you wanted to get the sums of the numbers from node 3 to the root, you would simply take two range sum queries:

[1,2,3, 0,4,0,0,5,0,6,0, 0]

[0,0,0, 3,0,4,2,0,5,0,6, 1]

and subtract the first query from the second query, giving us 3+2+1!

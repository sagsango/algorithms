https://codeforces.com/blog/entry/63020
vector<int> euler;
void dfs(int v,int p = -1){
	for(auto u : adj[v])
  {
      euler.push_back(v);
      if(p - u)
      dfs(u,v);
  } 
}


1.LCA query
Euler Tour that's useful is one where you add in the node every time its stack frame reappears in the DFS. For the given tree, the Tour would look like:

[1,2,3,2,4,2,1,5,1,6,1]

Then, one nice thing about this tour is that you can compute LCA using it, by creating a segment tree with the nodes in this order, and stores pairs of {depth, node}. So, the segment tree would be created over the array

[{0, 1}, {1, 2}, {2, 3}, {1, 2}, {2, 4}, {1, 2}, {0, 1}, {1, 5}, {0, 1}, {1, 6}, {0, 1}]

If you create a Range Min Query over this, and want to find, say, the LCA of nodes 3 and 4, then you just take a Range Min Query of the indices that they appear at:

[{0, 1}, {1, 2}, {2, 3}, {1, 2}, {2, 4}, {1, 2}, {0, 1}, {1, 5}, {0, 1}, {1, 6}, {0, 1}]

And the lowest {depth, node} pair we find is {1, 2}, meaning that node 2 is the LCA.

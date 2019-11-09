https://codeforces.com/blog/entry/63020

vector<int> euler;
void dfs(int v,int p = -1){
	euler.push_back(v);
	for(auto u : adj[v])if(p - u)dfs(u,v);
}



The idea I was already familiar was this: we create events when we enter a node but not when we exit. 
We can then query subtrees and update a node in O(logn) with some tree to maintain prefix sums.

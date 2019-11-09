vector<int> euler;
void dfs(int v,int p = -1){
	euler.push_back(v);
	for(auto u : adj[v])if(p - u)dfs(u,v);
  euler.push_back(v);
}

https://codeforces.com/blog/entry/63020

here magic comes

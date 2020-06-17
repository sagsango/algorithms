// https://codeforces.com/gym/284118/submission/84062274
vector<vector<int>> bridge_tree(int n,vector<pair<int,int>>edges){ // n = number of nodes [1...n], m edges numbered from [0...m-1]
  vector<int>par(n+1,-1);
  function<int(int)>root=[&](int v){return par[v] < 0 ? v : (par[v] = root(par[v]));};
  function<void(int,int)>merge=[&](int x,int y){	//	x and y are some tools (vertices)
          if((x = root(x)) == (y = root(y)) )    return ;
    if(par[y] < par[x])	// balancing the height of the tree
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
  };

  int m = edges.size();
  vector<vector<pair<int,int>>> adj(n+1); // adjacency list of graph  u->[v,edge_id]
  vector<int>bridge(m);
  vector<vector<int>>g(n+1); // bridge graph

  vector<bool> visited(n+1,false);
  vector<int> tin(n+1,-1), low(n+1,-1);
  int timer=0;

  function<void(int,int)>dfs=[&](int v, int p = -1) {
      /* Use bool to cut[e]=1, because cut[e]  may updated more than once */
      visited[v] = true;
      tin[v] = low[v] = timer++;
      for (auto it : adj[v]) {
  		int to = it.first;
  		int id = it.second;
          if (to == p) continue;
          if (visited[to]) {
              low[v] = min(low[v], tin[to]);
          } else {
              dfs(to, v);
              low[v] = min(low[v], low[to]);
              if (low[to] > tin[v])
                  /*BRIDGE(v, to);*/
                  bridge[id]=1;
          }
      }
  };
  for(int i=0;i<m;i++){
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back({v,i});
    adj[v].push_back({u,i});
  }
  for (int i = 1; i <= n; ++i) {
      if (!visited[i])
          dfs(i,-1);
  }
  for(int i=0;i<m;i++){
    if( !bridge[i] ){
      int u = edges[i].first;
      int v = edges[i].second;
      merge(u,v);
    }
  }
  for(int i=0;i<m;i++){
    int u = root(edges[i].first);
    int v = root(edges[i].second);
    if( u != v ){
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  return g;
}

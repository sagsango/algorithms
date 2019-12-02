  /* If DAG is disconnected then also it works fine */
  int N=1e6;
  vector<int>g[N+1];
  vector<int>vis(N+1);
  vector<int>topo;
` int n;
  void dfs(int u)
  {
      vis[u]=1;
      for(auto v:g[u])
        if(!vis[v])dfs(u);
      topo.push_back(u);
  }
  void find_topo()
  {
      for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i);
      sort(topo.rbegin(),topo.rend());
  }





/*Explanation*/
privisit[ v  ]  =  time when we r going to start all the neighbours of v.
postvisit[ v ]  =  time when we have finished exploration all the neighbours of v.

if we sort the verticies in reverse order of their postvisit number then it will form a possible topological sort.
because sources have greater postvisit number and sinc have smaller postvisit number.

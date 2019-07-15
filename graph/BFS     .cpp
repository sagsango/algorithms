

    vvi G(N);
    vi level(N,-1);
    vb vis(N,0);
 
	queue<int>q;
	q.push(1);
	level[1]=0;
	vis[1]=1;
	while(q.size())
	{
		int u=q.front();q.pop();
		for(auto v:G[u])
		{
			if(!vis[v])
			{
				q.push(v);
				level[v]=level[u]+1;
				vis[v]=1;
			}
		}
	}
	cout<<level[n]<<endl;

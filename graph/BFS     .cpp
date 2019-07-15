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

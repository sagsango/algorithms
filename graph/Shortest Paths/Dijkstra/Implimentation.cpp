vector<int> dijkstra(int u)
{
	// vertex from 0 to n-1
	vector<int>d(n,1e15);
	vector<int>vis(n);
	d[u]=0;
	priority_queue< pair< int,int > , vector< pair<int,int> > , greater< pair<int,int> > >pq;
	pq.push({d[u],u});
	while( pq.size() )
	{
		int u = pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v = it.first;
			int w = it.second;
			if( d[v] > d[u] + w )
			{
				d[v]=d[u]+w;
				pq.push({d[v],v});
			}
		}
	}
	return d;
}







vector<int> dijkstra(int u)
{
	// vertex from 1 to n
	vector<int>d(n+1,1e15);
	vector<int>vis(n+1);
	d[u]=0;
	priority_queue< pair< int,int > , vector< pair<int,int> > , greater< pair<int,int> > >pq;
	pq.push({d[u],u});
	while( pq.size() )
	{
		int u = pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v = it.first;
			int w = it.second;
			if( d[v] > d[u] + w )
			{
				d[v]=d[u]+w;
				pq.push({d[v],v});
			}
		}
	}
	return d;
}













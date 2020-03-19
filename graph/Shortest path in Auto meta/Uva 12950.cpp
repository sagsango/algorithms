#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<vector<pair<int,int>>>g;
int n , m ;
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
int32_t main()
{
	//IOS
	while( cin >> n >> m )
	{
		n<<=1;
		g=vector<vector<pair<int,int>>>(n);
		for(int i=1;i<=m;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			u--;
			v--;
			g[2*u].push_back({2*v+1,w});
			g[2*v].push_back({2*u+1,w});
			g[2*v+1].push_back({2*u,w});
			g[2*u+1].push_back({2*v,w});
		}
		vector<int>d=dijkstra(0);
		cout << ( d[n-2] < 1e15 ? d[n-2] : -1 ) << endl;
		
	}
	
}
	
	

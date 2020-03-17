// https://codeforces.com/gym/258375/submission/73529997
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
	IOS
	int n , m ; cin >> n >> m;
	vector<pair<int,int>>g[n];
	for(int i=0;i<m;i++)
	{
		int u , v , w; cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	priority_queue< pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>> > pq;
	vector<int>d(n,1e15);
	vector<int>vis(n);
	vector<int>par(n,-1);
	int s = 0 , e = n-1;
	d[s]=0;
	pq.push({d[s],s});
	while( pq.size() )
	{
		int u=pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v=it.first;
			int w=it.second;
			if( d[v] > d[u] + w )
			{
				d[v]=d[u]+w;
				par[v]=u;
				pq.push({d[v],v});
			}
		}
	}
	if( d[e] >= 1e15 ) cout << -1 << endl;
	else
	{
		list<int>path;
		while( e!=-1 )
		{
			path.push_front(e);
			e=par[e];
		}
		for(auto e:path)
		cout<<e+1<<" ";
		cout<<endl;
	}
	
	
	
	
}

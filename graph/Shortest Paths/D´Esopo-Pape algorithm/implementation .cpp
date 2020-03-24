// https://cp-algorithms.com/graph/desopo_pape.html
// Works on Negative weights but Not on negatice cycle
// Faster than Dijkstra's algorithm with exceptional case where it takes exponential time.

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
	IOS
	int n , m ;cin >> n >> m;
	int s = 1 , t = n;
	vector<vector<pair<int,int>>>g(n+1);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	
	
	/* D´Esopo-Pape */
	vector<int>d(n+1,1e15);
	vector<int>par(n+1,0);
	vector<int>clr(n+1,2); //0 : has relaexed, 1:being relax 2:yet to relax
	deque<int>q;
	d[s]=0;
	q.push_front(s);
	while( q.size() )
	{
		int u=q.front();q.pop_front();
		clr[u]=0;
		for(auto it:g[u])
		{
			int v = it.first;
			int w = it.second;
			if( d[v] > d[u] + w )
			{
				d[v]=d[u]+w;
				par[v]=u;
				if( clr[v] == 0 )
				{
					clr[v]=1;
					q.push_front(v);
				}
				else if(clr[v]==2)
				{
					clr[v]=1;
					q.push_back(v);
				}
			}
		}
	}
	cout << d[t] << endl;
}






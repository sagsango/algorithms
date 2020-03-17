/* Minimam move for final state in Autometa */
/* Similar Idea [Last point] https://cp-algorithms.com/graph/breadth-first-search.html */
/* Problem Link https://acm.timus.ru/problem.aspx?space=1&num=1930 */
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
	int n , m ; cin >> n >> m;
	vector< pair<int,int> >g[2*n];
	vector<int>vis(2*n);
	vector<int>par(2*n,-1);
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		u--;
		v--;
		g[2*u+1].push_back({2*v+1,0});
		g[2*v].push_back({2*u,0});	
	}
	for(int i=0;i<n;i++)
	{
		g[2*i].push_back({2*i+1,1});
		g[2*i+1].push_back({2*i,1});
	}
	int s , e ; cin >> s >> e;
	s--;
	e--;
	vector<int>d(2*n,1e9);
	d[2*s]=0;
	d[2*s+1]=0;
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
	pq.push({0,2*s});
	pq.push({0,2*s+1});
	while( pq.size() )
	{
		int u=pq.top().second;pq.pop();
		if( vis[u] )continue;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v = it.first;
			int w = it.second;
			if( d[v] > d[u] +  w )
			{
				d[v]=d[u] + w;
				pq.push({d[v],v});
				par[v]=u;
			}
		}
	}
	cout << min( par[2*e] >= 0 ? d[2*e] : 1000000000LL , par[2*e+1] >=0 ?  d[2*e+1] : 1000000000LL )<< endl;
}
	
	
	

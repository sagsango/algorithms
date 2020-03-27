// https://www.spoj.com/problems/MST/

/*
  Prims
  No neg cycle
  Undirected only  [ besauce all the vertix may not be recahble from s / you have to check from every vertex as s]
  Multiple edges valid
*/
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct Edge{
	int v,w,id;
};
const int N = 100000 , M = 1000000;
vector<vector<Edge>>g(N+1);
vector<int>par(N+1);          // parent of every node
vector<int>used(M+1);         // pertcular edge id has been used or not
vector<int>U(M+1),V(M+1),W(M+1);
int n,m;

int prims(int s=1 )
{
	/*          clear the graph           */   
	
	//////// Multiple tests  ///////////
	fill(par.begin(),par.begin()+n+1,0);
	fill(used.begin(),used.begin()+m+1,0);
	////////////////////////////////////
	
	/* chenge distance initialisation */
	vector<int>d(n+1,1e15);
	
	vector<int>edgeid(n+1);
	vector<int>vis(n+1);
	
	/* Change priority queue type */
	priority_queue< pair<int,int> , vector< pair<int,int> > , greater<pair<int,int>> >pq;    
	
	d[s]=0; /* change source distance */
	
	pq.push({d[s],s});
	while( pq.size() )
	{
		int u=pq.top().second ; pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v=it.v;
			int id=it.id;
			int w =it.w;
			
			/* chenge relaxsation */
			if( !vis[v] && d[v] > w )// !vis[v] meanse v has relaxed all his neibhours &  u  will not going to relax v again with same edge.
			{
				d[v]=w;
				edgeid[v]=id;
				par[v]=u;
				pq.push({d[v],v});
			}
		}
	}
	int min_spaning_wt = 0;
	for(int i=1;i<=n;i++)
	{
		used[ edgeid[i] ]=1;
		min_spaning_wt+=d[i];
	}
	return min_spaning_wt;
}
	

int32_t main()
{
	IOS
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>U[i]>>V[i]>>W[i];
		g[ U[i] ].push_back({V[i],W[i],i});
		g[ V[i] ].push_back({U[i],W[i],i});
	}
	cout << prims() << endl;
		
		
	
}
	


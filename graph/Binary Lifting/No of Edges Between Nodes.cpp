Problem   :  https://codeforces.com/gym/272284/problem/A
Solution  :  https://codeforces.com/gym/272284/submission/73340387

#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;	
	
const int N = 1e5 , lgN = 20 ;
vector<int> g[N+1];
vector<int> tin(N+1);
vector<int> tout(N+1);
vector<int> h(N+1);
vector<vector<int>>up(N+1,vector<int>(lgN+1));
int t=0 , n ;

void dfs(int u,int p)
{
	tin[u]=++t;
	h[u]=h[p]+1;
	up[u][0]=p;
	for(int i=1;i<=lgN;i++)
	up[u][i]=up[ up[u][i-1] ][i-1];
	
	for(auto v:g[u])if(v!=p)dfs(v,u);
	
	tout[u]=++t;
}

int isAncestor(int u,int v)
{
	return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int LCA(int u,int v)
{
	if( isAncestor(u,v) )return u;
	if( isAncestor(v,u) )return v;
	
	for(int i=lgN;i>=0;i--)
	if( up[u][i] && !isAncestor(up[u][i],v))
	u=up[u][i];
	
	return up[u][0];
}

int Distance(int u,int v)
{
	int l = LCA(u,v);
	return h[u]-h[l] + h[v]-h[l];
}

int32_t main()
{   
	IOS
	cin >> n ;
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	
	int q;cin>>q;
	while( q-- )
	{
		int x,y,a,b,k;cin>>x>>y>>a>>b>>k;
		int ok = 0 , d;
		// a b
		if( (((d=Distance(a,b))&1)==(k&1)) && (d<=k) )ok=1;
		// a x y b
		if( (((d=Distance(a,x)+1+Distance(y,b))&1)==(k&1)) && (d<=k) )ok=1;
		// a y x b
		if( (((d=Distance(a,y)+1+Distance(x,b))&1)==(k&1)) && (d<=k) )ok=1;
		
		cout << (ok ? "YES" : "NO") << endl;
	}
		
	
	
}




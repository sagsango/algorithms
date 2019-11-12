#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define MOD ((int)(1e9+7  ))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define float long double
#define sqrt sqrtl
#define cbrt cbrtl
#define endl '\n'
typedef vector<int> vi;
typedef vector<float> vf;
typedef pair<float,int> fi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<fi> vfi;
typedef vector<vi> vvi;
typedef vector<vf> vvf;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;
typedef priority_queue<fi> pqfi;
typedef priority_queue <int, vector<int>, greater<int> > rpqi; 
typedef priority_queue <ii, vector<ii>, greater<ii> > rpqii; 
typedef priority_queue <fi, vector<fi>, greater<fi> > rpqfi;

const int N=1e5;
vector<int>g[N+1];
vector<int>h(N+1,0000);
vector<int>d(N+1,1e15);
vector<int>vis(N+1,00);
vector<int>par(N+1,00);
vector<int>ccnt(N+1,0);
int cnt=0;

void dfs(int u,int p,int x)
{
	par[u]=p;
	vis[u]=1;
	h[u]=x;
	d[u]=x;
	for(auto v:g[u])
	{
		//if(g[u].size()==1)
		if(v==p)continue;
		if(!vis[v])
	    {
		   dfs(v,u,x+1);
		   //cout<<u<<" "<<h[u]<<"|"<<v<<" "<<d[v]<<endl;
		   if(h[u] && h[u] >= d[v])
		   {
			  ccnt[u]=ccnt[v];
		   }
		   d[u]=min(d[u],d[v]);
	    }
	    else if(d[u] > h[v])
	    {
			 d[u]=min(d[u],h[v]); 
			 ccnt[u]=ccnt[v]=++cnt;
		}
	}
}
	
int32_t main()
{
	IOS
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1,0,0);
	
	/*
	cout<<"--------------------------"<<endl;
	for(int u=1;u<=n;u++)
	{
		for(auto v:span[u])
		cout<<u<<" "<<v<<endl;
	}
	cout<<"--------------------------"<<endl;
	*/
	
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<par[i]<<" "<<h[i]<<" "<<d[i]<<" "<<ccnt[i]<<endl;
	}
				
	
	
	
	
}



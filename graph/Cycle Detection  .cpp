/*
1. When the graph contains more than n - 1 edges. This graph contains at least one cycle. 
   This propery can be used to detect cycle
2. If graph contains exactly n-1 edges then it must be tree
*/


/*
Both programs count no of acyclic comonents of graph
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define MOD ((int)(1e9+7))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define float long double
#define sqrt sqrtl
#define cbrt cbrtl
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

const int N=100010;
vvi G(N);vb B(N);
int cycle;
void dfs(int I,int p)
{
	B[I]=1;
	for(int i=0;i<(int)G[I].size();i++)
	{
		if(!B[G[I][i]])dfs(G[I][i],I);
		else if(G[I][i]!=p)cycle++;//Here we consider no multiple edges
	}
	
}

int32_t main()
{
	IOS
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!B[i])
		{
			cycle=0;
			dfs(i,-1);
			cycle/=2;//cycles counted twise
			if(cycle==0)ans++;
		}
	}
	cout<<ans<<endl;
}
			
		
	







#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define MOD ((int)(1e9+7))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define float long double
#define sqrt sqrtl
#define cbrt cbrtl
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

const int N=1e5+10;
vvi G(N);vb B(N);
int edges,nodes;
void dfs(int I)
{
	B[I]=1;nodes++;edges+=G[I].size();
	for(int i=0;i<(int)G[I].size();i++)
	{
		if(!B[G[I][i]])dfs(G[I][i]);
	}
	
}

int32_t main()
{
	IOS
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!B[i])
		{
			edges=0;nodes=0;
			dfs(i);
			edges/=2;//edges counted twise
			ans+=(edges < nodes);
		}
	}
	cout<<ans<<endl;
}
			
	


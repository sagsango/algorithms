subtree size when we use u->v edge in a tree : O(n) preprocessing 


#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=2e5;
vector<int> g[N+1];
map<pair<int,int>,int>sub;
int n;

int dfs(int u,int p)
{
	int cnt=1;
	for(auto v:g[u])
	{
		if(v!=p)cnt+=( sub[{u,v}] = dfs(v,u) );
	}
	sub[{p,u}]=cnt;
	if(p!=0)sub[{u,p}]=n-sub[{p,u}];
	return cnt;
}

int32_t main()
{
	IOS   
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(auto [f,s]:sub)
	{
		cout<<f.first<<"->"<<f.second<<":"<<s<<endl;
	}
	
}

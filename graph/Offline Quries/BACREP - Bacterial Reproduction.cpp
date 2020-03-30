// have bug
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
 
struct box{
	int type , t , cnt;
	// type =1 updation
	// type =0 question
};
const int N = 5e5 , T0 = 5e5 + 10 , MAXTIME = 1e6 + 20;
vector<int>B(MAXTIME+1);
vector<int>h(N+1);
vector<vector<box>>q(N+1);
vector<vector<int>>g(N+1);
vector<int>ans(N+1,-1);
int n,m;
void Update(int I,int val)
{
	while( I && I <= MAXTIME )
	{
		B[I]+=val;
		I+=I&-I;
	}
}
int Query(int I)
{
	int sum = 0;
	while( I > 0 )
	{
		sum+=B[I];
		I-=I&-I;
	}
	return sum;
}
void dfs(int u,int p)
{
	h[u]=h[p]+1;
	int base = T0 - h[u];
	for(size_t i=0;i<q[u].size();i++)
	{
		if( q[u][i].type )
		{
			Update(base+q[u][i].t,+q[u][i].cnt);
		}
	}
	for(size_t i=0;i<q[u].size();i++)
	{
		if( !q[u][i].type )
		{
			if( g[u].size() == 1 || g[u].size() == 0) // leaf
			{
				ans[q[u][i].t]= Query(base+q[u][i].t);
			}
			else
			{
				ans[q[u][i].t]=Query(base+q[u][i].t) - Query(base+q[u][i].t-1);
			}
		}
	}
	for(auto v:g[u])
	{
		if(v!=p)
		{
			dfs(v,u);
		}
	}
	for(size_t i=0;i<q[u].size();i++)
	{
		if( q[u][i].type )
		{
			Update(base+q[u][i].t,-q[u][i].cnt);
		}
	}
}

	
	
int32_t main()
{
	IOS
	cin >> n >> m ;
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		q[i].push_back({1,0,x});
	}
	for(int i=1;i<=m;i++)
	{
		char ch;cin>>ch;
		if( ch=='+' )
		{
			int x,y;cin>>x>>y;
			q[x].push_back({1,i,y});
		}
		else
		{
			int x;cin>>x;
			q[x].push_back({0,i,0});
		}
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		if(ans[i]!=-1)
	    {
			cout<<ans[i]<<" ";
		}
	}
	cout<<endl;
}

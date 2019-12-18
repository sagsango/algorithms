problem  :  https://codeforces.com/gym/261324/problem/I


#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const  int N=200000;
vector<int> g[N+1];
vector<vector<int>> sum(N+1,vector<int>(2));
vector<vector<int>> cnt(N+1,vector<int>(2));
int ans=0;

/*  This dfs  will fill dp: even and odd level node path sum , and their count from u: In its subtree */
void dfs(int u,int p)
{
	for(auto v:g[u])
	if(p!=v)
	{
		dfs(v,u);
		
		sum[u][0]+=sum[v][1]+cnt[v][1];
		sum[u][1]+=sum[v][0]+cnt[v][0];
		cnt[u][0]+=cnt[v][1];
		cnt[u][1]+=cnt[v][0];
	}
	cnt[u][0]+=1;
	sum[u][0]+=0;
}


/* This dfs will fill dp: even and odd level node path sum , and their count from u: In its whole tree  */
void dfs2(int u , int p)
{
	int newpcnt[2];
	int newpsum[2];
	/* now parent is root so remove the eff of subtree of u */
	newpsum[0] = sum[p][0] - ( sum[u][1] + cnt[u][1] );
	newpsum[1] = sum[p][1] - ( sum[u][0] + cnt[u][0] );
	
	newpcnt[0] = cnt[p][0] - cnt[u][1];
	newpcnt[1] = cnt[p][1] - cnt[u][0];
	
	int newucnt[2];
	int newusum[2];
	/* using the updated parent make u as root */
	newusum[0] = sum[u][0] + ( newpsum[1] + newpcnt[1] );
	newusum[1] = sum[u][1] + ( newpsum[0] + newpcnt[0] );
	
	newucnt[0] = cnt[u][0] + newpcnt[1];
	newucnt[1] = cnt[u][1] + newpcnt[0];
	
	if( p!= 0 )
	{
		swap(newusum[0],sum[u][0]);
		swap(newusum[1],sum[u][1]);
		swap(newucnt[0],cnt[u][0]);
		swap(newucnt[1],cnt[u][1]);
	}
	
	/* update the ans */
	ans+=(sum[u][0])/2 + (sum[u][1]-cnt[u][1])/2 + cnt[u][1];
	
	/* dfs its subtree */
	for(auto v:g[u])
	if(v!=p)dfs2(v,u);
	
	/* Again recover  originoal state of u*/
	if( p!= 0 )
	{
		swap(newusum[0],sum[u][0]);
		swap(newusum[1],sum[u][1]);
		swap(newucnt[0],cnt[u][0]);
		swap(newucnt[1],cnt[u][1]);
	}
}

int32_t main()
{
	IOS
	int n;cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,0);
	
	cout<<ans/2<<endl;
	
	
	
}

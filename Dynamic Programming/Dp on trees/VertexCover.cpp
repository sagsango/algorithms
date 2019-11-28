Problem   :   https://www.spoj.com/problems/PT07X/
Statement :   You are given an unweighted, undirected tree. Write a program to find a vertex set of minimum size 
              in this tree such that each edge has as least one of its end-points in that set.
              
              
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100000;
vector<vector<int>>dp(N+1,vector<int>(2));
vector<int>g[N+1];
void dfs(int u,int p)
{
	for(auto v:g[u])
	if(v!=p)dfs(v,u);
	dp[u][1]=1;
	for(auto v:g[u])
	if(v!=p)
	{
		dp[u][1]+=min(dp[v][1],dp[v][0]);
		dp[u][0]+=dp[v][1];
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
	cout<<max(1LL,min(dp[1][0],dp[1][1]))<<endl;
	
}
		
	
	
	
	

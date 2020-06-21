// https://codeforces.com/gym/284118/submission/84062274
int diameter(int n,vector<vector<int>>g){ // nodes 1 to n
	vector<int>vis(n+1),dp(n+1);      // g : forest 
	int dia = 0;
	function<void(int)> dfs = [&](int u){
		dp[u]=0;
		vis[u]=1;
		for(auto v:g[u]){
			if(!vis[v]){
				dfs(v);
				dia=max(dia,dp[u]+dp[v]+1);
				dp[u]=max(dp[u],dp[v]+1);
			}
		}
	};
	for(int i=1;i<=n;i++){
		if( !vis[i] ){
			dfs(i);
		}
	}
	return dia;
}

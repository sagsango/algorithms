// Not Tested : same file in cut edges
vector<int> find_cut_edges(int n,int m,vector<vector<pair<int,int>>>&g){ // g[u].push_back({v,id})
	// assuming graph is connected otherwise no meaning
	vector<int>h(n+1),mn(n+1),cEdge(n+1); 
	auto dfs=[&](int u){
		vis[u] = 1, h[u] = h[p]+1, mn[u] = 1e9;
		for(auto [v,i]:g[u]){
			if( !vis[v] ){
				dfs(v,u);
				if( mn[v] > h[u] )  // mn[v] should be atleat h[u] : back edge to me or my predeceros
					cEdge[i] = 1;
				mn[u] = min(mn[u],mn[v]);
			}else
				mn[u] = min(mn[u],h[v]);
		}
	};
	dfs(1,0);
	return cEdge;
}
vector<int> find_cut_vertex(int n,int m,vector<vector<int>>&g){ // g[u].push_back(v)
	// assuming graph is connected otherwise no meaning
	vector<int>h(n+1),mn(n+1),cVtex(n+1); 
	auto dfs=[&](int u){
		vis[u] = 1, h[u] = mn[u] = h[p]+1;
		for(auto v:g[u]){
			if( !vis[v] ){
				dfs(v,u);
				mn[u] = min(mn[u],mn[v]);
			}else
				mn[u] = min(mn[u],h[v]);
		}
		if( mn[u] >= h[u] )   // back edge should go to predeceros
			cVtex[u] = 1;
	}
	dfs(1,0);
	return cVtex;
}

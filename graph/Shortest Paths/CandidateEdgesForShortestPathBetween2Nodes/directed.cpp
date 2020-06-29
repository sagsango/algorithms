const int maxn = 105, maxm = 10005;
vector<pair<int,int>>g[maxn],gr[maxn];
vector<int>U(maxm),V(maxm),W(maxm),candidate(maxm);
int n,m;
void CandidateEdgesForShortestPathBetweenSourceAndTerminal(int s,int t){  // source and terminal [ according to tpl sort ]
	function<vector<int>(vector<vector<pair<int,int>>>&,int)>spfa=[&](vector<vector<pair<int,int>>>&g,int s){
		vector<int>dis(n+1,1e15);
		vector<int>inq(n+1);
		queue<int>q;
		dis[s]=0;
		inq[s]=1;
		q.push(s);
		while( q.size() ){
			int u = q.front();q.pop();inq[u]=0;
			for(auto [v,i]:g[u]){
				if( dis[v] > dis[u] + W[i] ){
					dis[v] = dis[u] + W[i];
					if( !inq[v] ){
						inq[v]=1;
						q.push(v);
					}
				}
			}
		}
		return dis;
	};
	vector<int>d1 = spfa(g,s);
	vector<int>d2 = spfa(gr,t);
	for(int i=1;i<=m;i++){
		if( d1[U[i]] + W[i] + d2[V[i]] == d1[t] ){
			candidate[i] = 1;
		}
	}
}

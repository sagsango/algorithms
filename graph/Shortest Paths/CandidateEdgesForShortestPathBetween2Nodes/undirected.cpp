const int maxn = 105, maxm = 10005;
vector<pair<int,int>>g[maxn];
vector<int>U(maxm),V(maxm),W(maxm),candidate(maxm);
int n,m;
void CandidateEdgesForShortestPathBetween2Nodes(int s1,int s2){
	function<vector<int>(int)>spfa=[&](int s){
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
	vector<int>d1 = spfa(s1);
	vector<int>d2 = spfa(s2);
	for(int i=1;i<=m;i++){
		if( d1[U[i]] + W[i] + d2[V[i]] == d1[s2] || d1[V[i]] + W[i] + d2[U[i]] == d1[s2]){
			candidate[i] = 1;
		}
	}
}

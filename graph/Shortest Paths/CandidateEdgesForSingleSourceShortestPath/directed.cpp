const int maxn = 105, maxm = 10005;
vector<pair<int,int>>g[maxn],gr[maxn];
vector<int>U(maxm),V(maxm),W(maxm),candidate(maxm);
int n,m;
void CandidateEdgesForShortestPathFromSingleSource(int s){
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
	for(int i=1;i<=m;i++){
		if( dis[U[i]] + W[i] == dis[V[i]] ){
			candidate[i]=1;
		}
	}
}

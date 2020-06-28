//   https://cp-algorithms.com/graph/bellman_ford.html
//   The worst case of this algorithm is equal to the O(nm) of the Bellman-Ford, but in practice it works much faster and some people claim that it works even in O(m) on average. However be careful, because this algorithm is deterministic and it is easy to create counterexamples that make the algorithm run in O(nm).
//   With negative weigth [ No negative cycle ]


// Not Tested
const int maxn = 2e5+10;
vector<pair<int,int>>g[maxn];
int n;
bool NegCycle(){
    vector<int>dis(maxn),inq(maxn),cnt(maxn),vis(maxn);
	function<bool(int)>spfa=[&](int s){
		queue<int>q;
		dis[s]=0;
		q.push(s);
		inq[s]=1;
		vis[s]=1;
		while( q.size() ){
			int u = q.front();q.pop();inq[u]=0;
			for(auto [v,w]:g[u]){
				if( dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					vis[v] = 1;
					if( !inq[v] ){
						q.push(v);
						inq[v]=1;
						cnt[v]++;
						if( cnt[v] > n ){
							return true;
						}
					}
				}
			}
		}
		return false;
	};
	fill(dis.begin(),dis.end(),1e15);
	for(int i=1;i<=n;i++){
		if( !vis[i] ){
			if( spfa(i) ){
				return 1;
			}
		}
	}
	return 0;
}

// https://codeforces.com/gym/284118/submission/83863679
const int maxn = 1e6+10;
vector<int>g[maxn],vis(maxn),dis(maxn),par(maxn); // g : forest
pair<int,int> DiaAndCenter(int s){
	// s = non vis node of tree
	// <dia,center> : O(n) overall
	function<int(int)>farthest=[&](int s){
		queue<int>q;
		q.push(s);
		dis[s]=0;
		vis[s]=1;
		int ans = s;
		while( q.size() ){
			int u = q.front(); q.pop();
			for(auto v:g[u]){
				if(vis[v]!=1){
					q.push(v);
					vis[v]=1;
					dis[v]=dis[u]+1;
					if( dis[v] > dis[ans] ){
						ans = v;
					}
				}
			}
		}
		return ans;
        };
	s = farthest(s);
	queue<int>q;
	q.push(s);
	par[s]=0;
	dis[s]=0;
	vis[s]=2;
	int x = s;
	while( q.size() ){
		int u = q.front(); q.pop();
		for(auto v:g[u]){
			if(vis[v]!=2){
				q.push(v);
				dis[v]=dis[u]+1;
				par[v]=u;
				vis[v]=2;
				if( dis[v] > dis[x] ){
					x = v;
				}
			}
		}
	}
	int dia = dis[x];
	while( dis[x] > dia >> 1 ){
		x = par[x];
	}
	return make_pair(dia,x);
}
int32_t main(){
	IOS
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<pair<int,int>>a;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a.push_back(DiaAndCenter(i));
		}
	}
}

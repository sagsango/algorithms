// https://atcoder.jp/contests/abc022/tasks/abc022_c

// using spfa
const int maxn = 300+5, maxm = 90000;
vector<pair<int,int>>g[maxn]; // [v , edge_id ]
vector<int>dis(maxn),inq(maxn),w(maxm);
int n,m;
int spfa(int bad,int s,int t){
	fill(dis.begin(),dis.end(),1e10);
	fill(inq.begin(),inq.end(),0);
	queue<int>q;
	dis[s]=0;
	q.push(s);
	inq[s]=1;
	while( q.size() ){
		int u = q.front();q.pop();inq[u]=0;
		for(auto [v,i]:g[u]){
			if( i == bad )continue;
			if( dis[v] > dis[u] + w[i]){
				dis[v] = dis[u] + w[i];
				if( !inq[v] ){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return w[bad] + dis[t];
}

int minWeightCycleThrough( int s ){
	int ans = 1e10;
	for(auto [v,i]:g[s]){
		ans = min( ans , spfa(i,s,v) );
	}
	return ans;
}
		
int32_t main(){
	IOS
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v>>w[i];
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	int ans =  minWeightCycleThrough(1);
	cout << ( ans < 1e10 ? ans : -1 ) << endl;
}



//using Floyd Warsall's
const int MAX = 1001;
const int INFTY = 1e9;
 
int cost[MAX][MAX];
 
int main(){
    int N,M; cin >> N >> M;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cost[i][j] = INFTY;
        }
    }
 
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        cost[a][b] = c;
        cost[b][a] = c;
    }
 
    for(int k=1;k<N;k++){
        for(int i=1;i<N;i++){
            for(int j=1;j<N;j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    int ans = INFTY;
    for(int i=1;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(cost[0][i] != INFTY && cost[0][j] != INFTY){
                ans = min(ans, cost[i][j] + cost[0][i] + cost[0][j]);
            }
        }
    }
 
    if(ans == INFTY){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}

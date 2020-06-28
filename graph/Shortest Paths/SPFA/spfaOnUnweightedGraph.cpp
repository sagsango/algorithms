const int maxn = 2e5+10;
vector<int>g[maxn],dis(maxn),inq(maxn);
int n;
void spfa(int s){
	fill(dis.begin(),dis.end(),1e15);
	fill(inq.begin(),inq.end(),0);
	queue<int>q;
	dis[s]=0;
	q.push(s);
	inq[s]=1;
	while( q.size() ){
		int u = q.front();q.pop();inq[u]=0;
		for(auto v:g[u]){
			if( dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				if( !inq[v] ){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}

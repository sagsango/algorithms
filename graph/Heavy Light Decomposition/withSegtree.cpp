// https://codeforces.com/gym/284118/submission/83907187
const int maxn = 5e5+10;
vector<int>g[maxn],subtree(maxn),par(maxn),heavy(maxn),head(maxn),pos(maxn),t(maxn<<2),lazy(maxn<<2,-1);
int n,curr_pos=0;
void push(int rt,int tl,int tr){
	if( lazy[rt] == -1 )return;
	int m = (tl+tr)>>1;
	t[rt<<1]=lazy[rt]*(m-tl+1);
	t[rt<<1|1]=lazy[rt]*(tr-m);
	lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
	lazy[rt]=-1;
}
void update(int rt,int tl,int tr,int l,int r,int new_val){
	if( l > r )return;
	if( l == tl && r == tr ){t[rt]=new_val*(tr-tl+1);lazy[rt]=new_val;return;}
	push(rt,tl,tr);
	update(rt<<1,tl,(tl+tr)>>1,l,min(r,(tl+tr)>>1),new_val);
	update(rt<<1|1,((tl+tr)>>1)+1,tr,max(((tl+tr)>>1)+1,l),r,new_val);
	t[rt]=t[rt<<1]+t[rt<<1|1];
}
int query(int rt,int tl,int tr,int l,int r){
	if( l > r )return 0;
	if( tl == l && tr == r )return t[rt];
	push(rt,tl,tr);
	int ans = query(rt<<1,tl,(tl+tr)>>1,l,min((tl+tr)>>1,r))+query(rt<<1|1,((tl+tr)>>1)+1,tr,max(((tl+tr)>>1)+1,l),r);
	t[rt]=t[rt<<1]+t[rt<<1|1];
	return ans;
}	
void dfs(int u,int p){
	par[u]=p;
	subtree[u]=1;
	for(auto v:g[u]){
		if( v!=p ){
			dfs(v,u);
			subtree[u]+=subtree[v];
			if( subtree[v] > subtree[ heavy[u] ]){
				heavy[u]=v;
			}
		}
	}
}
void decompose(int u,int p,int h){
	head[u]=h;
	pos[u]=++curr_pos;
	if( heavy[u] )decompose(heavy[u],u,h);
	for(auto v:g[u]){
		if( v==p || v == heavy[u] )continue;
		decompose(v,u,v);
	}
}
int32_t main(){
	IOS
	cin >> n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	decompose(1,0,1);
	int m;cin>>m;
	for(int i=1;i<=m;i++){
		int type,u;cin>>type>>u;
		if(type==1){
			update(1,1,n,pos[u],pos[u]+subtree[u]-1,1);
		}else if(type==2){
			while( u ){
				update(1,1,n,pos[head[u]],pos[u],0);
				u=par[head[u]];
			}
		}else if(type==3){
			cout << query(1,1,n,pos[u],pos[u]) << endl;
		}
	}
}

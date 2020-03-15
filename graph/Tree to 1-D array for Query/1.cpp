/* In 1D tree we use BIT or segtree to answer the quries */
Problem : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/tree-query-3-5d98588f/
Solution:

#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N =1e6+1;
vector<int> g[N];
vector<int> h(N); // hight
vector<int> b(N); // begin time
vector<int> e(N); // end time
vector<int> a(N); // array to feed segtree : no of cool ancestors
vector< pair<int,int> > t(4*N); // segtree min and cnt
vector<int> lazy(4*N); // lazytree
vector<int> c(N); // node is on or off
int T=0;

void dfs(int u,int p)
{
	b[u]=++T;
	h[u]=h[p]+1;
	a[b[u]]=h[u];
	for(auto v:g[u])if(v!=p)dfs(v,u);
	e[u]=++T;
	a[e[u]]=h[u];
}

void build(int v,int tl,int tr)
{
	if( tl > tr ) return;
	if( tl == tr )t[v]={0,1};
	else
	{
		int tm = (tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		t[v].first=min(t[2*v].first,t[2*v+1].first);
		t[v].second=0;
		if(t[v].first == t[2*v].first )t[v].second+=t[2*v].second;
		if(t[v].first == t[2*v+1].first)t[v].second+=t[2*v+1].second;
	}
}

void push(int v)
{
	t[2*v].first+=lazy[v];
	lazy[2*v]+=lazy[v];
	t[2*v+1].first+=lazy[v];
	lazy[2*v+1]+=lazy[v];
	lazy[v]=0;
}

void update(int v,int tl,int tr,int l,int r,int addend)
{
	if( l > r )return;
	if( l == tl && r == tr )
	{
		t[v].first+=addend;
		lazy[v]+=addend;
	}
	else
	{
		push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v].first=min(t[2*v].first,t[2*v+1].first);
        t[v].second=0;
		if(t[v].first == t[2*v].first )t[v].second+=t[2*v].second;
		if(t[v].first == t[2*v+1].first)t[v].second+=t[2*v+1].second;
	}
}

pair<int,int> query(int v,int tl,int tr,int l,int r)
{
	if( l > r ) return {1e9,0};
	if( l == tl && r==tr )
	{
		return t[v];
	}
	push(v);
	int tm = (tl + tr) / 2;
    pair<int,int> lq=query(v*2, tl, tm, l, min(r, tm));
    pair<int,int> rq=query(v*2+1, tm+1, tr, max(l, tm+1), r);
    
    pair<int,int>ans;
    ans.first = min( lq.first, rq.first );
    if( ans.first == lq.first )ans.second+=lq.second;
    if( ans.first == rq.first )ans.second+=rq.second;
    
    return ans;
}
		
	
int32_t main(void)
{   
	IOS
	int n , q; cin >> n >> q;
	fill(c.begin(),c.begin()+2*n,1);
	for(int i=1;i<n;i++)
	{
		int u , v ; cin >> u >> v ;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	build(1,1,2*n);
	
	while(q--)
	{
		int x,u;cin>>x>>u;
		if( x == 1)
		{
			update(1,1,2*n,b[u],e[u],(c[u]?+1:-1));
			c[u]^=1;
		}
		else
		{
			if( c[u]^1 )cout<<0<<endl;
			else cout<< query(1,1,2*n,b[u],e[u]).second/2 << endl;
		}
	}
}




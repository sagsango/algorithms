Problem  :      https://acm.timus.ru/problem.aspx?space=1&num=1671


#include<bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=1e5;
vector<int>par(N+1,-1);
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)) )    return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
int32_t main()
{
	IOS
	int n,m;cin>>n>>m;
	vector<int>u(m+1),v(m+1);
	for(int i=1;i<=m;i++)
	cin>>u[i]>>v[i];
	int q;cin>>q;
	vector<int>Q(q+1);
	vector<int>ans(q+1);
	vector<int>used(m+1,1);
	for(int i=1;i<=q;i++)
	{
		cin>>Q[i];
		used[Q[i]]=0;
	}
	for(int i=1;i<=m;i++)
	if(used[i])
	{
		merge(u[i],v[i]);
	}
	int cmp=0;
	for(int i=1;i<=n;i++)
	cmp+=par[i]<0;
	
	for(int i=q;i>=1;i--)
	{
		ans[i]=cmp;
		int I=Q[i];
		int x=root(u[I]);
		int y=root(v[I]);
		if( x == y )continue;
		merge(x,y);
		cmp--;
	}
	for(int i=1;i<=q;i++)
	cout<<ans[i]<<" ";
	cout<<endl;
	
	
}


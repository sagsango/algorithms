problem  :  https://www.spoj.com/problems/CLFLARR/

#include<bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define next NNKUHILUH
const int N=2e5+10;
vector<int>par(N+1,-1);
vector<int>next(N+1);
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)) )    return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	next[x]=max(next[x],next[y]);
	par[y] = x;
}
int32_t main()
{
	IOS
	for(int i=1;i<=N;i++)
	next[i]=i;
	
	int n,q;cin>>n>>q;
	vector<int>L(q+1),R(q+1),C(q+1),clr(n+1);
	for(int i=1;i<=q;i++)
	cin>>L[i]>>R[i]>>C[i];
	
	for(int i=q;i>=1;i--)
	{
		int l=L[i];
		int r=R[i];
		
		while( l <= r )
		{
			while( next[ root(l) ]!= l)
			{
				int rt=root(l);
				l=next[rt];
				merge(rt,L[i]);
			}
			if( l <= r )
			{
				clr[l]=C[i];
				merge(L[i],l);
			}
			l++;
		}
		next[root(L[i])]=max(R[i]+1,next[root(L[i])]);
	}
	for(int i=1;i<=n;i++)
	cout<<clr[i]<<" ";
	cout<<endl;
			
		
				
}


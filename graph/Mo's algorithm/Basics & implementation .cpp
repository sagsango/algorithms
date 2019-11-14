https://codeforces.com/blog/entry/43230
https://blog.anudeep2011.com/mos-algorithm/


Explanation of Blog:
Problem : Find no of distinct colour from path u to v
Solution: After flatterning the tree
          1, 2, 3, 4, 4, 3, 5, 6, 6, 5, 2, 7, 8, 8, 9, 9, 7, 1
          p=par(u,v)
          1.p==u or p==v  : process [ in[u] , in[v] ] Range
          2.p!=u or p!=v  : process [ out[u], in[v] ] +  [ in[p] ,in[p] ] Range
   
   

example     :    https://www.spoj.com/problems/COT2/
statement   :    You are given a tree with N nodes. The tree nodes are numbered from 1 to N. Each node has an integer colour.
                 We will ask you to perform the following operation:
                 u v : ask for how many different colour on the path from u to v.
solution    :



#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
struct query
{
    int l,r,k,i;
};
const int S=283;
bool cmp(query A, query B){
  if (A.l / S != B.l / S) return A.l < B.l;
  return A.l / S % 2 ? A.r > B.r : A.r < B.r;
}
 
const int N=4e4;
vector<int>arr(2*N+1);
vector<short int>parity(N+1);
unordered_map<int,int>cnt;
vector<int>clr(N+1);
vector<int>tin(N+1);
vector<int>tout(N+1);
vector<int>g[N+1];
int n,m,l=1,r=1,tc=0,sum=0;
const int L=16;
vector<vector<int>>up(N+1,vector<int>(L+1));
 
void dfs(int u,int p)
{
	tin[u]=++tc;arr[tin[u]]=u;
	up[u][0]=p;
	for(int i=1;i<=L;i++)
	up[u][i]=up[ up[u][i-1] ][i-1];
	for(auto v:g[u])if(v!=p)dfs(v,u);
	tout[u]=++tc;arr[tout[u]]=u;
}
bool is_ancestor(int u,int v){return tin[u]<=tin[v] && tout[v]<=tout[u];}
int lca(int u,int v)
{
	if(is_ancestor(u,v))return u;
	if(is_ancestor(v,u))return v;
	for(int i=L;i>=0;i--)
	if(up[u][i] && !is_ancestor(up[u][i],v))
	u=up[u][i];
	return up[u][0];
}
/**
 * Insert and Remove function are same 
 * It took me 3 Hours to debug it
 **/
void insert(int i)
{
	int v=arr[i];
	sum-=cnt[clr[v]]!=0;
	parity[v]^=1;
	if(parity[v])cnt[clr[v]]+=1;
	else cnt[clr[v]]-=1;
	sum+=cnt[clr[v]]!=0;
}
void remove(int i)
{
	int v=arr[i];
	sum-=cnt[clr[v]]!=0;
	parity[v]^=1;
	if(parity[v])cnt[clr[v]]+=1;
	else cnt[clr[v]]-=1;
	sum+=cnt[clr[v]]!=0;
}
int32_t main()
{
	IOS	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>clr[i];
	for(int i=1;i<=n-1;i++)
	{
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
		
	vector<query>q(m);
	vector<int>ans(m);
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		int l,r,k,p=lca(u,v);
	          if(p==u||p==v)
	          {
			if(tin[u] <= tin[v])l=tin[u],r=tin[v];
			else l=tin[v],r=tin[u];
			k=0;
		}
	          else
		{
			if(tout[u] < tin[v])l=tout[u],r=tin[v];
			else l=tout[v],r=tin[u];
			k=p;
		}
		q[i].l=l;
		q[i].r=r;
		q[i].k=k;
		q[i].i=i;
	}
		
	sort(q.begin(),q.end(),cmp);
	insert(1);
	for(int i=0;i<m;i++)
	{
		while(l > q[i].l)insert(--l);
		while(r < q[i].r)insert(++r);
		while(l < q[i].l)remove(l++);
		while(r > q[i].r)remove(r--);
 
                    if(q[i].k)insert(tin[q[i].k]);
		ans[q[i].i]=sum;
	          if(q[i].k)remove(tin[q[i].k]);
	}
	for(int i=0;i<m;i++)
	cout<<ans[i]<<" ";
	cout<<endl;
	
	
}



Note:
1.BTW, there is a standard solution for the first problem (see this link in Russian). For each of the colors order
all the vertices of this color according to the dfs traversal, let the vertices be labelled v1, v2, ..., vk. Add +1
to each of these verticies, and add -1 to the LCAs of the neighboring vertices lca(v1, v2), lca(v2, v3), ..., lca(vk - 1, vk).
If you sum up the values inside a subtree, you get the number of distinct elements in it.

Since the ordering can be done in O(n), and in theory you can answer lca queries for a static tree in O(1) with O(n)
pre-processing, you have a linear solution (assuming 0 ≤ A[x] < N).  [ Given on same Blog ]
	
2.Problem can be solve using set.Idea and code given on the blog.
	

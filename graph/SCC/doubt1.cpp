Problem :  https://codeforces.com/gym/262911/problem/O

I did't realise I can use Kosaraju Algorithm to find SSC.
I came up with this. Whay it is not correct ?


#include<bits/stdc++.h>
//#define int long long 
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N=100000;
vector<int>par(N+1,-1);
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)) )    return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
vector<int> g1[N+1];
vector<int> g2[N+1];
vector<int> t(N+1);
vector<int> clr(N+1);
int n,m,h;


int dfs(int u)
{
	//unite stongly connected components
	clr[u]=1;
	int cycle=0;
	for(auto v:g1[u])
	if(clr[v]==0)
	{
		if(dfs(v))
		{
			int ru=root(u);
			int rv=root(v);
			if(ru!=rv)
			{
				cycle=1;
				merge(ru,rv);
			}
		}
	}
	else if(clr[v]==1)
	{
		merge(u,v);
		cycle=1;
	}
	clr[u]=2;
	return cycle;
}




int32_t main()
{
	IOS
	n=25;
	g1[1]={2,6,23};
	g1[2]={3};
	g1[3]={4,18};
	g1[4]={5,19};
	g1[5]={1};
	g1[6]={7};
	g1[7]={8,17};
	g1[8]={9};
	g1[9]={1};
	g1[10]={11,15};
	g1[11]={12};
	g1[12]={13};
	g1[13]={14};
	g1[14]={10};
	g1[15]={16};
	g1[16]={};
	g1[17]={20};
	g1[18]={21};
	g1[19]={22};
	g1[20]={};
	g1[21]={};
	g1[22]={};
	g1[23]={24};
	g1[24]={25};
	g1[25]={};
	
	for(int i=1;i<=n;i++)
	if(!clr[i])dfs(i);
	
	for(int i=1;i<=n;i++)
	cout<<i<<":"<<root(i)<<endl;
	
	
	
}

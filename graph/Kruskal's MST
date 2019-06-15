#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define MOD ((int)(1e9+7))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define float long double
#define sqrt sqrtl
#define cbrt cbrtl
typedef vector<int> vi;
typedef vector<float> vf;
typedef pair<float,int> fi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<fi> vfi;
typedef vector<vi> vvi;
typedef vector<vf> vvf;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;
typedef priority_queue<fi> pqfi;
typedef priority_queue <int, vector<int>, greater<int> > rpqi; 
typedef priority_queue <ii, vector<ii>, greater<ii> > rpqii; 
typedef priority_queue <fi, vector<fi>, greater<fi> > rpqfi; 
 
vector<int>dx={0,1,0,-1},dy={1,0,-1,0};
const int N=2e5+10;
int sum=0,mx=-1e18,mn=1e18;
int n,m,u,v,w,q,g,l,r,ans=0;

//par which store the parent if it not else stores negative of no of child
vi par(N,-1),U(N),V(N),W(N);
//min heap priority queue to store weight ans its corrsponding edge
rpqii pq;

//disjoint set union
int root(int u)
{ 
	//if it is not root then updte himself by root as parent [ path compression ]
	return (par[u] < 0 ? u : par[u]=root(par[u]));
}
void merge(int u,int v)
{
	//if root of both the emelemets are same then they alredy are in same set
	if( (u=root(u)) ==  (v=root(v)))return;
	//if not we update them by ranking algorithm , the parent having more chield will be the final parent [ path compression ]
	if(par[u] < par[v])swap(u,v);
	par[v]+=par[u];
	par[u]=v;
}

int32_t main()
{
	IOS
	//taking number of verticies and edges
	cin>>n>>m;
	//tkaing every edge ans its weight as input and insert it into min heap priority quque
	for(int i=1;i<=m;i++)
	{
		cin>>U[i]>>V[i]>>W[i];
		pq.push({W[i],i});
	}
	//untill there is an edge in our min heap
	while(pq.size())
	{
		int I=pq.top().second;pq.pop();
		u=U[I];
		v=V[I];
		//if both of the verticies of the edge belongs to same set we don't have to add it [ means form cycle ]
		if( root(u) == root(v) )continue;
		else
		{
			//other wise we have to merge set of u and v, add it to MST
			ans+=W[I];merge(u,v);
		}
	}
	cout<<ans<<endl;
		
	
	
	
	
}
		

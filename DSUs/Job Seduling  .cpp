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
const int N=10010;
int sum=0,mx=-1e18,mn=1e18,mxi=0;
int n,m,u,v,w,q,g,l,r,ans=0;
#define time TIME
vi time(N+1),pre_time(N+1);


//returns first free slot before/till time t
int find_prev_time(int t)
{
	if(pre_time[t]==t)return t;
	else return pre_time[t]=find_prev_time(pre_time[t]);
}
//if slot is free then it book the slot othrewise tries to book some preivious free slot
void insert(int value,int max_t)
{
	if(max_t)//if time is nonzero 
	{
		if(pre_time[max_t]==max_t)//if first aviable slot is itself
		{
			//book the slot and update the privious slot
			time[max_t]=value;
			pre_time[max_t]=max_t-1;
		}
		else
		{
			//if it is not free try to book privious slots
			insert(value,find_prev_time(max_t));
		}
	}
}

int32_t main()
{
	IOS
	cin>>n;
	for(int i=0;i<=N;i++)
	{
		time[i]=0;
		pre_time[i]=i;
	}
	vii a(n);
	for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
	rsrt(a);
	
	for(int i=0;i<n;i++)
	{
		//greedly insert each job
		insert(a[i].first,a[i].second);
	}
	for(int i=0;i<=N;i++)
	{
	     ans+=time[i];
	}
	cout<<ans<<endl;	
	
}
		

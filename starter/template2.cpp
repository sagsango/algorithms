#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define lb(a,b) lower_bound(a.begin(),a.end(),b)
#define ub(a,b) upper_bound(a.begin(),a.end(),b)
#define MOD ((int)(1000000007 ))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define float long double
#define bigint __int128
#define sqrt sqrtl
#define cbrt cbrtl
#define endl '\n'

typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<vvi> vvvi;
typedef priority_queue <int> pqi;
typedef priority_queue <int, vector<int>, greater<int> > rpqi; 

typedef vector<float> vf;
typedef vector <vf> vvf;

typedef pair<int,int> ii;
typedef vector <ii>  vii;
typedef vector <vii> vvii;
typedef priority_queue <ii> pqii;
typedef priority_queue <ii, vector<ii>, greater<ii> > rpqii;
typedef priority_queue < pair<ii,int>, pair<ii,int>, greater<pair<ii,int>> > rpqiii; 


typedef pair<float,int> fi;
typedef vector <fi> vfi;
typedef priority_queue <fi> pqfi;
typedef priority_queue <fi, vector<fi>, greater<fi> > rpqfi;


typedef pair<float,float> ff;
typedef vector <ff> vff;

typedef vector <bool> vb;
typedef vector <string> vs;


template<class T,class L>bool smax(T&x,L y){return x<y?(x=y,1):0;}
template<class T,class L>bool smin(T&x,L y){return y<x?(x=y,1):0;}

	

int32_t main(){
	IOS
	int n,k;cin>>n>>k;
	ordered_set<int>st;
	vector<int>a(k),b(n);
	for(int i=0;i<k;i++)	
		cin>>a[i],--a[i];
	for(int i=0;i<n;i++){
		cin>>b[i];
		if( b[i] == -1 ){
			vector<int>tmp;
			for(int j=0;j<k;j++){
				auto it = st.find_by_order(a[j]);
				if( it == st.end() )
					break;
				tmp.push_back(*it);
			}
			for(auto x:tmp)
				st.erase(x);
		}else{
			st.insert(i);
		}
	}
	if( st.empty() )
		cout<<"Poor stack!";
	for(auto x:st){
		cout<<b[x];
	}
	cout<<endl;
}		
	
	
	
		
	
	
	
	
	
	
	

 



#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define bug1( x ) cerr << (#x) <<"="<< x << endl;
#define bug2( x , y ) cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;
#define bug3( x , y , z ) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;
#define bug4( x , y , z , w) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;
#define bug5( x , y , z , w ,p) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;
#define bug6( x , y , z , w ,p , q) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;
#define bugn( x , n ){ cerr<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl;}
#define bugnm( x , n , m ){ cerr<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;}}

using namespace std;
typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<vvi> vvvi;



// solution for : ( a or b) and ( c or ~k ) and ......
const int maxn = 2000+5;
vector<int>g[maxn],gr[maxn],tpl,vis(maxn),cmp(maxn),sat(maxn);
int n,c=0;
void dfs1(int u){
	vis[u]=1;
	for(auto v:gr[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}
	tpl.push_back(u);
}
void dfs2(int u){
	cmp[u]=c;
	for(auto v:g[u]){
		if(!cmp[v]){
			dfs2(v);
		}
	}
}
void add_edge(int u,int v){
	g[u].push_back(v);
	gr[v].push_back(u);
}
void add_imp(int u,int v){ 
	add_edge(u,v);
}
void add_equi(int u,int v){
	add_imp(u,v);
	add_imp(v,u);
}
void add_or(int u,int v){ 
	// a or b = ~a -> b and ~b -> a
	add_imp(u^1,v);
	add_imp(v^1,u);
}
void add_xor(int u,int v){
	// a ^ b = ( a and ~b ) or ( ~a and b ) = ( ( a and ~b ) or ~a ) and ( ( a and ~b ) or b )) = ( ( a or ~a ) and ( ~b or ~a ) and ( a or b ) and ( ~b or b) ) = ( ~b or ~a ) and ( a or b )
	add_or(u,v);
	add_or(u^1,v^1);
}
void add_xnor(int u,int v){
	// a ⊕ b = ( a and b ) or ( ~a and ~b ) = ( (( a and b ) or ~a ) and ( ( a and b ) or ~b)  )= ( ( a or ~a ) and ( b or ~a ) and ( a or ~b ) and ( b or ~b) ) = ( b or ~a ) and ( a or ~b )
	add_or(u^1,v);
	add_or(u,v^1);
}
void add_true(int u){
	// ~a -> a = ~(~a) or a = a or a = a
	add_imp(u^1,u);
}
void add_and(int u,int v){
	add_true(u);
	add_true(v);
}
bool solve(){
	for(int i=0;i<2*n;i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	for(int i=0;i<2*n;i++){
		int u = tpl[2*n-i-1];
		if( !cmp[u] ){
			c++;
			dfs2(u);
		}
	}
	for(int i=0;i<n;i++){
		if( cmp[i<<1|0] == cmp[i<<1|1] ){
			return 0;
		}
		if( cmp[i<<1|0] <  cmp[i<<1|1] ){ // ~a -> a = a 
			sat[i]=1;
		}
		else sat[i]=0;
	}
	return 1;
}
		
 
int32_t main(){
	IOS
	cin>>n;
	vector<string>a(n),b(n);
	for(int i=0;i<n;i++){
		string s1,s2;cin>>s1>>s2;
		a[i] = s1.substr(0,3);
		b[i] = s1.substr(0,2) + s2.substr(0,1);
	}
	// xor d not works here because 0/1 are independent but imp works
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if( i == j ) continue;
			
			if( a[i] == a[j] ){
				//add_imp(2*i,2*j+1);
				add_and(2*i+1,2*j+1);
			
				//add_xor(i<<1,j<<1);   may be both state r not chosen
				//add_and(i<<1|1,j<<1|1);
			}
			if( a[i] == b[j] ){
				add_imp(2*i,2*j);
				
				//add_xor(i<<1,j<<1|1); may be both state r not chosen
			}
			if( b[i] == a[j] ){
				add_imp(2*i+1,2*j+1);
				
				//add_xor(i<<1|1,j<<1); may be both state r not chosen
			}
			if( b[i] == b[j] ){
				add_imp(2*i+1,2*j);
				
				//add_xor(i<<1|1,j<<1|1); may be both state r not chosen
			}
		}
	}
	if( !solve( ) ){
		cout<<"NO"<<endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i=0;i<n;i++){
		cout << ( sat[i] ? a[i] : b[i] ) << endl ;
	}
	
	
}

// Problem form TCS
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
using namespace std;
typedef long long ll;
typedef long double ld;


pair<int,int> add(pair<int,int>a,pair<int,int>b){
	if( a.first == 0 )return b;
	if( b.first == 0 )return a;
	pair<int,int>c;
	c.first = a.first * b.second + b.first * a.second;
	c.second = a.second * b.second;
	int g = __gcd( c.first , c.second );
	c.first /= g;
	c.second /=g;
	return c;
}

pair<int,int> mul(pair<int,int>a,pair<int,int>b){
	if( a.first == 0 || b.first == 0 )return make_pair(0,1);
	pair<int,int>c;
	c.first = a.first * b.first ;
	c.second= a.second * b.second;
	int g = __gcd( c.first , c.second );
	c.first /= g;
	c.second /=g;
	return c;
}

int32_t main(){
	IOS
	int q;cin>>q;
	while(q--){
		int A,H,L1,L2,M,C;cin>>A>>H>>L1>>L2>>M>>C;
		vector<pair<int,int>>dp(H+1);
		dp[H]={1,1};
		pair<int,int>ans,p0,p1;
		p1 = {L1,L2};
		p0 = {L2-L1,L2};
		for(int i=1;i<=M;i++){
			vector<pair<int,int>>dp2(H+1);
			for(int j=1;j<=H;j++){
				if( j - A >= 1 ){
					dp2[j-A]=add(dp2[j-A],mul(dp[j],p0));
				}else{
					ans = add(ans,mul(dp[j],p0));
				}
				if( j - ( A + C ) >=1 ){
					dp2[j-(A+C)]=add(dp2[j-(A+C)],mul(dp[j],p1));
				}else{
					ans=add(ans,mul(dp[j],p1));
				}
			}
			dp=dp2;
		}
		if( ans.first == 0 )
			cout << "RIP" << endl;
		else
		    cout<<ans.first<<"/"<<ans.second<<endl;
	}
		
	
}

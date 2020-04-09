// https://www.spoj.com/problems/RMQSQ/
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005 , lgN = 20;
vector<vector<int>>dp(maxn,vector<int>(lgN));
int n;
int32_t main(){
	IOS
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin>>dp[i][0];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;i+(1LL<<j)-1<=n;j++){
			dp[i][j]=min(dp[i][(j-1)],dp[i+(1LL<<(j-1))][(j-1)]);
		}
	}
	
	
	
	int q;cin>>q;
	while( q-- ){
		int l,r;cin>>l>>r;
		l++,r++;
		int mn = 1e18;
		for(int j = lgN;j>=0;j--){
			if( l+(1LL<<j)-1 <= r){
				mn=min(mn,dp[l][j]);
				l+=1LL<<j;
			}
		}
		cout<<mn<<endl;
	}
}

// https://www.spoj.com/problems/THRBL/
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int maxn = 50000 , lgN = 20;
vector<vector<int>>dp(maxn+1,vector<int>(lgN+1));
int32_t main(){
	IOS
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>dp[i][0];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;i+(1LL<<j)-1<=n;j++){
			dp[i][j]=max(dp[i][j-1],dp[i+(1LL<<(j-1))][j-1]);
		}
	}
	int ans = 0;
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		int curr = dp[l][0];
		int mx   = 0;
		l++;
		r--;
		for(int j=lgN;j>=0;j--){
			if( l + (1LL<<j) -1 <= r){
				mx=max(mx,dp[l][j]);
				l+=1LL<<j;
			}
		}
		ans+= mx <= curr;
	}
	cout<<ans<<endl;
	
			
	
}

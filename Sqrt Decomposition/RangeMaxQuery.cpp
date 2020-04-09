// https://www.spoj.com/problems/THRBL/
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int32_t main(){
	IOS
	int n,m;cin>>n>>m;
	int s = sqrt(n);
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i/s]= b[i/s] > a[i] ? b[i/s] : a[i];
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		int curr = a[l];
		l++,r--;
		int mx = 0;
		for(int i=l;i<=r;){
			if( i%s==0 && i + s <= r){
				mx= mx > b[i/s] ? mx : b[i/s];
				i+=s;
			}
			else{
				mx=mx > a[i] ? mx : a[i];
				i++;
			}
		}
		ans+=mx<=curr;
	}
	cout<<ans<<endl;
				
			
	
}

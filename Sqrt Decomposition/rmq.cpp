// https://www.spoj.com/problems/RMQSQ/    [ for sqrt(n)+1 size block see submissions ]
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main(){
	IOS
	int n ; cin >> n ;
	int s = sqrt(n);
	vector<int>a(n+1),b(n+1,1e15);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i/s]=min(b[i/s],a[i]);
	}
	int q;cin>>q;
	while(q--){
		int l,r,mn=1e17;cin>>l>>r;
		l++,r++;
		for(int i=l;i<=r;){
			if( i%s==0 && i + s <= r ){
				mn=min(mn,b[i/s]);
				i+=s;
			}
			else {
				mn=min(mn,a[i]);
				i++;
			}
		}
		cout << mn << endl;
	}
	
}

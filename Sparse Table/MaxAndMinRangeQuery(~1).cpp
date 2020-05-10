// https://codeforces.com/gym/279715/submission/79659062

const int maxn = 1e5 + 5 , lgn = 21;
int mx[maxn][lgn],mn[maxn][lgn],n,k;

int32_t main(){
	IOS
	memset(mx,0,sizeof(mx));
	memset(mn,0,sizeof(mn));
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		mx[i][0]=mn[i][0]=x;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=1;i+(1LL<<j)-1<n;j++){
			mx[i][j]=max( mx[i+(1LL<<(j-1))][j-1],mx[i][j-1]);
			mn[i][j]=min( mn[i+(1LL<<(j-1))][j-1],mn[i][j-1]);
		}
	}
	auto query = [&](int l,int r){
		auto msb=[&](int x) {
	        	//  https://codeforces.com/blog/entry/10330
                	//  works with int32_t only.
	       	        union { double a; int b[2]; };
            		a = x;
	        	return (b[1] >> 20LL) - 1023LL;
		};
		int k = msb(r-l+1);
		int tmx = max( mx[l][k] , mx[r-(1LL<<k)+1][k] );
		int tmn = min( mn[l][k] , mn[r-(1LL<<k)+1][k] );
		return make_pair(tmx,tmn);
	};
}

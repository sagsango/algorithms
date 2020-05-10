//   https://codeforces.com/gym/279715/submission/79655435

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
                // for O(1) use log2() but in c++ it can give error because of pricisions.
		int tmx = -1e15 , tmn = +1e15;
		for(int i=lgn-1;i>=0;i--){
			if( l + (1LL<<i) -1 <= r ){
				tmx = max(tmx,mx[l][i]);
				tmn = min(tmn,mn[l][i]);
				l+=1LL<<i;
			}
		}
		return make_pair(tmx,tmn);
	};
}

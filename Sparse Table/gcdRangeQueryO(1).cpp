// https://codeforces.com/gym/282397/submission/81975008

#define gcd greatest_common_divisor
const int maxn = 3e5+10;
vector<vector<int>>gcd(maxn,vector<int>(21));
vector<int>lg(maxn),a(maxn);
int n;
int32_t main(){
	IOS
	lg[1]=0;
	for(int i=2;i<maxn;i++){
		lg[i]=lg[i/2]+1;
	}
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		gcd[i][0]=a[i];
		for(int j=1;i+(1<<j)-1<=n;j++){
			gcd[i][j]=__gcd(gcd[i][j-1],gcd[i+(1<<(j-1))][j-1]);
		}
	}
	
	
	auto query=[&](int l,int r){
		int k = lg[r-l+1];
		return __gcd(gcd[l][k],gcd[r-(1<<k)+1][k]);
	};
}

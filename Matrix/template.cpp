int mod = 1e9 + 7;
int add( int x , int y ){
		int ans = x + y ;
		if( ans >= mod ){
			ans -= mod;
		}
		return ans;
	}
int mul(int x,int y){
		if( x >= mod )x-=mod;
		if( y >= mod )y-=mod;
		int ans = x * y % mod;
		return ans;
}
struct Matrix{
	public:
	int n,m;
	vector<vector<int>>a;
	/////////////////////////////////////////////////
	Matrix(vector<vector<int>>&b){
		a = b;
		n = b.size();
		m = b[0].size();
	}
	Matrix(int n,int m){
		this->n = n;
		this->m = m;
		a = vector<vector<int>>(n,vector<int>(m));
	}
	Matrix(int n){
		this->n = n;
		this->m = n;
		a = vector<vector<int>>(n,vector<int>(n));
	}
	///////////////////////////////////////////////////
	void upperTrangular(int k=1){
		if( n != m ){
			cout << "Undefined Operation!!!" << endl;
			exit(-1);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if( j >= i ){
					a[i][k] = k;
				}
				else a[i][k]= 0;
			}
		}
	}
	void lowerTrangular(int k=1){
		if( n != m ){
			cout << "Undefined Operation!!!" << endl;
			exit(-1);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if( j <= i ){
					a[i][k] = k;
				}
				else a[i][k] =0;
			}
		}
	}
	void identity(int k=1){
		if( n != m ){
			cout << "Undefined Operation!!!" << endl;
			exit(-1);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if( i == j ){
					a[i][j]=k;
				}
				else a[i][j]=0;
			}
		}
	}
	///////////////////////////////////////////////////
	Matrix operator +(const Matrix b){
		if( b.a.size() != a.size() || b.a[0].size() != a[0].size() ){
			cout << "Undefined Operation!!!" << endl;
			exit(-1);
		}
		Matrix ans(n,m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ans.a[i][j]=add(a[i][j],b.a[i][j]);
			}
		}
		return ans;
	}
	Matrix operator *(const Matrix b){
		int r1 = a.size();
		int c1 = a[0].size();
		int r2 = b.a.size();
		int c2 = b.a[0].size();
		if( c1 != r2 ){
			cout << "Undefined Operation!!!" << endl;
			exit(-1);
		}
		Matrix ans(r1,c2);
		for(int i=0;i<r1;i++){
			for(int j=0;j<c2;j++){
				for(int k=0;k<c1;k++){
					ans.a[i][j]=add(ans.a[i][j],mul(a[i][k],b.a[k][j]));
				}
			}
		}
		return ans;
	}
	///////////////////////////////////////////////////
	void display(){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout <<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}		
};

Matrix binpow(Matrix a,int p){
	Matrix r(a);
	r.identity();
	while( p ){
		if( p & 1 ){
			r = r * a;
		}
		a = a * a;
		p >>= 1;
	}
	return r;
}
		
	
int32_t main(){
	IOS
	int t;cin>>t;
	while(t--){
		int a,b,c,n,m; cin >> a >> b >> c >> n >> m;
		mod = m;
		Matrix mat(3);
		mat.a = { {a,1,0},
			      {b,0,0},
			      {c,0,1} };
		n--;
		mat = binpow(mat,n);
		Matrix coeff(1,3);
		coeff.a = { {1,1,1} };
		coeff = coeff * mat;
		cout << coeff.a[0][1] << endl;
	}
		
	
	
}

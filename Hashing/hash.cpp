// nax : maximum length of string
// (1e9+7)^2, (1e9+9)^2, (1e9+21)^1  <= LONG_MAX : use long long to store product
const int nax = ( 2e6 /*change len*/ )+10, M[3] ={ (int)(1e9+7), (int)(1e9+9), (int)(1e9+21) }, P[3] = {29, 31, 37};
const int hashCount = 2; // no of hashes want to use
int coef[3][nax];

// n   : no of strings
// ph  : prefix hash
// sh  : suffix hash
int n;
vector<vector<int>>ph[3],sh[3];
vector<string>s(nax);

void compute(){
	// compute coef accordingly
	coef[0][0] = coef[0][1] = coef[0][2] =  1;
	for(int i=0;i<hashCount;++i){
		for(int j=1;j<nax;++j){
			coef[i][j]=1ll*coef[i][j-1]*P[i]%M[i];
		}
	}
	// initialise size of ph and sh accordingly
	for(int i=0;i<hashCount;++i){
		ph[i] = sh[i] = vector<vector<int>>(n);
		for(int j=0;j<n;++j){
			int m = s[j].size();
			ph[i][j] = sh[i][j] = vector<int>(m+2);
		}
	}
	// compute ph[0,1,2][jth string][kth index] and sh[0,1,2][jth string][kth index]
	for(int i=0;i<hashCount;++i){
		for(int j=0;j<n;++j){
			int m = s[j].size();
			for(int k=1;k<=m;++k)
				ph[i][j][k] = (ph[i][j][k-1] + 1ll*(s[j][k-1]-'a'+1)*coef[i][k-1])%M[i];
			for(int k=m;k>=1;--k)
				sh[i][j][k] = (sh[i][j][k+1] + 1ll*(s[j][k-1]-'a'+1)*coef[i][m-k])%M[i];
		}
	}
}
// s[x][l1..r1] == s[y][l2..r2]
int equal1(int x,int l1,int r1,int y,int l2,int r2){
	int equal = 1;
	for(int i=0;i<hashCount;++i)
		equal &= (ph[i][x][r1+1] - ph[i][x][l1] + M[i])%M[i]*1ll*coef[i][nax-1-l1]%M[i] == (ph[i][y][r2+1] - ph[i][y][l2] + M[i])%M[i]*1ll*coef[i][nax-1-l2]%M[i];
	return equal;
}
// s[x][l1..r1] == s[y][reverse(l2..r2)]
int equal2(int x,int l1,int r1,int y,int l2,int r2){
	int equal = 1, m = s[y].length();
	for(int i=0;i<hashCount;++i) // tle
		equal &= (ph[i][x][r1+1] - ph[i][x][l1] + M[i])%M[i]*1ll*coef[i][nax-1-l1]%M[i] == (sh[i][y][l2+1] - sh[i][y][r2+2] + M[i])%M[i]*1ll*coef[i][nax-1-(m-r2-1)]%M[i];
	return equal;
}

pair<int,int> longestPalindromeicSubstring(int k){ // k : index of string 
	int n = s[k].length();
	int maxl = 0, idx = 0;
	// odd length
	for(int i=0;i<n;++i){
		int l=0,r=min(i,n-i-1)+1; // how much can you expand
		while( l + 1 < r ){
			int m = (l+r)>>1;
			( equal2(k,i-m,i+m,k,i-m,i+m) ? l : r ) = m;
		}
		if( maxl < 1+2*l )
			maxl = 1+2*l, idx = i-l;
	}
	// even length
	for(int i=0;i+1<n;++i){
		if(s[k][i]!=s[k][i+1])
			continue;
		int l = 0, r = min(i,n-(i+1)-1)+1; // how much can you expand
		while( l + 1 < r ){
			int m = (l+r)>>1;
			( equal2(k,i-m,i+1+m,k,i-m,i+m+1) ? l : r ) = m;
		}
		if( maxl < 2+2*l )
			maxl = 2+2*l, idx = i-l;
	}
	return {idx,maxl};
}


int32_t main(){
	IOS
	
	n = 1;
	s = vector<string>(n);
	
	
	cin >> s[0];
	compute();
	pair<int,int> ans = longestPalindromeicSubstring(0);
	cout << s[0].substr(ans.first,ans.second) << endl;
}

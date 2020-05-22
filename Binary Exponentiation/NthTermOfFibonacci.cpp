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
typedef long long ll;
typedef long double ld;
using namespace std;



/*
we were solving problem for : f[i] = 2*f[i-2] + f[i]

fib:
 [ f[i] f[i-1] ] [ 1  1 ]  = f[i+1] f[i]
                   1  0

req:
 [ f[i] f[i-1] ] [ 1  1 ]  = f[i+1] f[i]
                   2  0
*/

vector<int> binpow(vector<int>a,vector<vector<int>>b,int n){
	while( n ){
		if( n & 1 ){
			int x = a[0] * b[0][0] + a[1] * b[1][0];
			int y = a[0] * b[0][1] + a[1] * b[1][1];
			a[0]=x;
			a[1]=y;
		}
		vector<vector<int>>temp(2,vector<int>(2));
		temp[0][0] = b[0][0] * b[0][0] + b[1][0] * b[0][1];
		temp[0][1] = b[0][0] * b[0][1] + b[1][0] * b[1][1];
		temp[1][0] = b[1][0] * b[0][0] + b[1][1] * b[0][1];
		temp[1][1] = b[1][0] * b[0][1] + b[1][1] * b[1][1];
		n>>=1;
		b = temp;
	}
	return a;
}
int32_t main(){
	IOS
	vector<int>a={1,1}; // 0th and 1st elemnt value is provided
	vector<vector<int>>b={ {1,1} , {1,0} }; //coefficient matix of fibbonacii
	int n;cin>>n;
	vector<int>ans = binpow(a,b,n-1); // we will caluclate : 1 , 2 , 3 , 4 , 5 ............... element 
	                                  // by muliplying coefficient matix n-1 times
	                                  // it is abous for n = 0 we have to answer explicitly.
	cout << ans[0] << endl;
	
}
 
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */

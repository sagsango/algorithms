problem   :   https://www.spoj.com/problems/MPOW/
          :   https://codeforces.com/gym/262909/submission/67076009

#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
class matrixExponentiation{
	public : 
	vector<vector<int>> multiply(vector<vector<int>>a ,vector<vector<int>> b , int n)
	{
		int M=1e9+7;
		vector<vector<int>>c(n,vector<int>(n));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			for(int ic=0,jr=0;ic<n && jr<n;ic++,jr++)
			{
				c[i][j]+=a[i][ic] * b[jr][j];
				c[i][j]%=M;                            /*      MOD Should be taken care of     */
			}
		}
		return c;
	}
	vector<vector<int>> MatixToThePowerP(vector<vector<int>>mat,int p)
	{
		int n=mat.size();
		vector<vector<int>>a(n,vector<int>(n));
		for(int i=0;i<n;i++)a[i][i]=1;
		while( p )
		{
			if( p & 1 )
			{
				a=multiply( a , mat , n);
			}
			mat=multiply( mat , mat , n);
			p>>=1;
		}
		return a;
	}
};

int32_t main()
{
	IOS
	int q;cin>>q;
	while( q-- )
	{
		int n,p;cin>>n>>p;
		vector<vector<int>> a(n,vector<int>(n));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		matrixExponentiation me;
		vector<vector<int>> b=me.MatixToThePowerP(a,p);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<b[i][j]<<" ";
			cout<<endl;
		}
	}
}
	

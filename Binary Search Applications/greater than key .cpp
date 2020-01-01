// https://codeforces.com/gym/262824/submission/68023179

#define greater kjhug876759bjkhb
int greater(int x,vector<int>&a)
{
	int n=a.size();
	int l=0,r=n-1;
	int cnt=0;
	while( l <= r )
	{
		int m=(l+r)/2;
		if( a[m] <= x )
		{
			l=m+1;
		}
		else
		{
			cnt = n - m;
			r=m-1;
		}
	}
	return cnt;
}

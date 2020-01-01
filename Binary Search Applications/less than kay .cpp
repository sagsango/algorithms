// https://codeforces.com/gym/262824/submission/68023179


#define less jhbhiftvyg87676765
int less(int &x,vector<int>&a)
{
	int n=a.size();
	int l=0,r=n-1;
	int cnt=0;
	while( l<=r )
	{
		int m=(l+r)/2;
		if( a[m] >= x )
		{
			r=m-1;
		}
		else
		{
			cnt=m+1;
			l=m+1;
		}
	}
	return cnt;
}

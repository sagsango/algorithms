Longest common subsequence

// dp solution  O(n*m)
// string processing and pattern matching UCSD
int32_t main()
{
	IOS
	string s1;
	string s2;

	cin>>s1>>s2;
	int n1=s1.length();
	int n2=s2.length();
	s1='$'+s1;
	s2='$'+s2;
	
	
	vvi dp(n1+1,vi(n2+1));
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i]==s2[j])
			{
				dp[i][j]=dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n1][n2]<<endl;

	
	
	
}

			

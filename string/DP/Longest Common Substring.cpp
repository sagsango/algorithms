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
  int max_length=0;
  int sub_index_end=-1;
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i]==s2[j])
			{
				dp[i][j]=dp[i-1][j-1] + 1;
        if(dp[i][j]>max_length)
        {
          max_length=dp[i][j];
          sub_index_end=i;//Indexing from  1
        }
			}
		
		}
	}
	cout<<max_length<<" "<<s1.substr(sub_index_end-max_length+1,max_length)<<endl;

	
	
	
}

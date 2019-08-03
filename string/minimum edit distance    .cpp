//https://www.techiedelight.com/levenshtein-distance-edit-distance-problem/
//https://www.geeksforgeeks.org/edit-distance-dp-5/
//https://practice.geeksforgeeks.org/problems/edit-distance/0

/*
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
1.Insert
2.Remove
3.Replace
All of the above operations are of equal cost.
*/

int edit_distance(string s1,string s2)
{
	int n1=s1.length();
	int n2=s2.length();
	vector<vector<int>>dp(n1+1,vector<int>(n2+1));
	s1='$'+s1;
	s2='$'+s2;
	for(int i=0;i<=n1;i++)dp[i][0]=i; // base case when s2 is NULL
	for(int i=0;i<=n2;i++)dp[0][i]=i; // base case when s1 is NULL
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i]==s2[j])
			{
				dp[i][j]=dp[i-1][j-1];        // no cost for already matching
			}
			else dp[i][j]=min({dp[i-1][j]+1       // delete  s1[i] wrt s2
                         ,dp[i][j-1]+1,                       // insert  s1[i] wrt s2
                         dp[i-1][j-1]+1});                    // replace s1[i] wrt s2
		}
	}
	return dp[n1][n2];
}		
int32_t main()
{
	IOS
	int q;cin>>q;
	while(q--)
	{
		 int n1,n2;cin>>n1>>n2;
	     string s1,s2;cin>>s1>>s2;
	     cout<<edit_distance(s1,s2)<<endl;
	 }
}

/********    Index start from 1 *************/
preprocessing

i [ 1 .... n ]
j [ 1..... m ]
dp[ n + 1 ][ m + 1 ]
for(int i = 1 ; i <= n ; i++)
{
  for(int j = 1 ; j <= m ; j++ )
  {
      dp[i][j]=dp[i-1][j]+dp[i][j-1]+arr[i][j] - dp[i-1][j-1]
  }
}

query

return dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]


/******** Index start from 0 ***********/
preprocessing
i [ 0.... n-1 ]
j [ 0.....m-1 ]
for(int i=0;i<n;i++)
{
  for(int j=1;j<m;j++)
  {
    dp[i][j]+=dp[i][j-1];
  }
}
for(int i=1;i<n;i++)
{
  for(int j=0;j<m;j++)
  {
    dp[i][j]+=dp[i-1][j];
  }
}

query

int ans=dp[x2][y2];
if(y1>0)ans-=dp[x2][y1-1];
if(x1>0)ans-=dp[x1-1][y2];
if(x1>0 && y1>0)ans+=dp[x1-1][y1-1];
return ans;

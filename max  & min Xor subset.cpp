// Problem     : https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1
// Application : https://codeforces.com/gym/272370/problem/A 

void update(int dp[],int n)
{
    for(int i=30;i>=0;i--)
    {
        if(n>>i)n^=dp[i];
    }
    for(int i=30;i>=0;i--)
    {
        if((n>>i) &1)
        {
            dp[i]=n;
            return;
        }
    }
}
int maxSubarrayXOR(int A[], int n)
{
    //Your code here
    int dp[31];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        update(dp,A[i]);
    }
    int ans = 0;
    for(int i=30;i>=0;i--)
    {
        if( (ans >>i &1)^1)
        {
            ans^=dp[i];
        }
    }
    return ans;
}

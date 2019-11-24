Problem      :  https://leetcode.com/contest/weekly-contest-164/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
Statement    :  You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 
                1 position to the right in the array or stay in the same place  (The pointer should not be placed outside 
                the array at any time).Given two integers steps and arrLen, return the number of ways such that your pointer 
                still at index 0 after exactly steps steps.
                Since the answer may be too large, return it modulo 10^9 + 7.


class Solution {
public:
    int numWays(int steps, int L) {
        long long M=1e9+7;
        L = min(L, steps + 1);
        vector<long long > dp(L);
        dp[0] = 1;
        for(int i=0;i<steps;i++)
        {
            vector<long long>dp2(L);
            for(int j=0;j<L;j++)
            {
                if(j-1 >= 0)dp2[j]=(dp2[j]+dp[j-1])%M;
                if(j+1 <  L)dp2[j]=(dp2[j]+dp[j+1])%M;
                dp2[j]=(dp2[j]+dp[j])%M;
            }
            dp=dp2;
        }
        return dp[0];
    }
};

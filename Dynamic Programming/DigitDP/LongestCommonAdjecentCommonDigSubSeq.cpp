https://www.geeksforgeeks.org/longest-subsequence-such-that-adjacent-elements-have-at-least-one-common-digit/

Longest subsequence such that adjacent elements have at least one common digit.

Input: arr[] = {1, 12, 44, 29, 33, 96, 89}
Output: 5
The longest sub-sequence is {1 12 29 96 89}

Input: arr[] = {12, 23, 45, 43, 36, 97}
Output: 4
The longest sub-sequence is {12 23 43 36}


int longest_adjecent_common_subsequence(vector<int>num)
{
        int n=num.size();
        vector<int>cnt(10);
        int ans=0;
        for(int i=0;i<n;i++)
        {
              int max_ending_here = 0;
              int tnum=num[i];
              while(tnum)
              {
                      max_ending_here = max( max_ending_here , cnt[ tnum%10 ]);
                      tnum/=10;
              }
              max_ending_here+=1;
              tnum=num;
              while(tnum)
              {
                      cnt[ tnum%10 ] = max( max_ending_here , cnt[ tnum%10 ]);
                      tnum/=10;
              }
              ans=max(ans,mx_ending_here);
         }
         return ans;
}
              
              
              

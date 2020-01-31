https://codeforces.com/blog/entry/22658
for (int i = m; i >= 1; i--)
     for (int j = n; j >= 1; j--) 
          if (t[i] == s[j])
              lcp[i][j] = lcp[i + 1][j + 1] + 1;
              
              
Problem:
https://codeforces.com/gym/267437/submission/69913166

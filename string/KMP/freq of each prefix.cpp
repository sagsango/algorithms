Counting the number of occurrences of each prefix


vector<int> freq_of_prefix(string s)
    { 
        vector<int>pi=prefix_function(s);
        vector<int> ans(n + 1);
        for (int i = 0; i < n; i++)
           ans[pi[i]]++;
        for (int i = n-1; i > 0; i--)
           ans[pi[i-1]] += ans[i];
        for (int i = 0; i <= n; i++)
           ans[i]++;
        return ans;
    }
    /**
    *  ans[i] : frquency of prifix having length i
    **/

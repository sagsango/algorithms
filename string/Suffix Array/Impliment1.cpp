vector<int> suffix_array(string s)
{
    int n = s.size();
    vector<int> sa(n), rank(n);
    for(int i = 0; i < n; i++)
        rank[i] = s[i],
        sa[i] = i;
    for(int k = 0; k < n; k ? k *= 2 : k = 1)
    {
        stable_sort(sa.begin(), sa.end(), [&](int i, int j)
             {
                 if(rank[i] == rank[j])
                    return rank[(i + k) % n] < rank[(j + k) % n];
                 return rank[i] < rank[j];
             });
        vector<int> nrank(n);
        int r = 0;
        for(int i = 1; i < n; i++)
        {
            if(rank[sa[i]] != rank[sa[i - 1]]) r++;
            else if(rank[(sa[i] + k) % n] != rank[(sa[i - 1] + k) % n]) r++;
            nrank[sa[i]] = r;
        }
        rank = nrank;
    }
    return sa;
}
 
vector<int> kasai(string s, vector<int> sa)
{
    int n = s.size(), k = 0;
    vector<int> ra(n), lcp(n);
    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    for(int i = 0; i < n; i++)
    {
        if(k) k--;
        if(ra[i] == n - 1) {k = 0; continue;}
        int j = sa[ra[i] + 1];
        while(k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
        lcp[ra[i]] = k;
        if(ra[(sa[ra[i]] + 1) % n] > ra[(sa[ra[j]] + 1) % n]) k = 0;
    }
    return lcp;
}

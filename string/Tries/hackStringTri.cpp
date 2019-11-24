Problem       :  https://leetcode.com/contest/weekly-contest-164/problems/search-suggestions-system/
Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product
names from products after each character of searchWord is typed. Suggested products should have common prefix with the 
searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
Return list of lists of the suggested products after each character of searchWord is typed. 

Solution     :  By 	hitonanode   [ at least better implimentation than I did but concept was same ]


#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& ps, string S) {
        sort(ps.begin(), ps.end());
        vector<vector<string>> ret;
        string q;
        for (auto c : S)
        {
            q += c;
            auto itr = lower_bound(ps.begin(), ps.end(), q);
            int i = itr - ps.begin();
            vector<string> app;
            FOR(j, i, i + 3) if (j < ps.size())
            {
                if (q == ps[j].substr(0, q.length())) app.push_back(ps[j]);
            }
            ret.push_back(app);
        }
        return ret;
    }
};

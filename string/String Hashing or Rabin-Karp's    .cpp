/*
    Counting No diff string of given length L
    Used 2 hashing function to avoid collision
    Problem:https://www.spoj.com/problems/ADACLEAN/
    Resources:https://cp-algorithms.com/string/string-hashing.html
              https://cp-algorithms.com/string/rabin-karp.html
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p1 = 31 ,p2=43;
const int m1 = 1e9 + 9,m2 = 1e9 +7;
const int N=1e6;
vector<long long> p_pow1(N),p_pow2(N);
 
long long count_unique_substrings(string const& s,int const&l){
        int n = s.size();
        vector<long long> h1(n + 1, 0),h2(n + 1, 0);
        for (int i = 0; i < n; i++){
        h1[i+1] = (h1[i] + (s[i] - 'a' + 1) * p_pow1[i]) % m1;
        h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;}
 
        int cnt = 0;
        map<long long,set<long long>>H;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h1 = (h1[i + l] + m1 - h1[i]) % m1;
            long long cur_h2 = (h2[i + l] + m2 - h2[i]) % m2;
            cur_h1 = (cur_h1 * p_pow1[n-i-1]) % m1;
            cur_h2 = (cur_h2 * p_pow2[n-i-1]) % m2;
            H[cur_h1].insert(cur_h2);
        }
        for(auto it:H)
        {
			 cnt+=it.second.size();
		  }
		  return cnt;
}
int32_t main()
{
	 int q;cin>>q;
	 p_pow1[0] = 1;
	 p_pow2[0] = 1;
    for (int i = 1; i < N; i++){
    p_pow1[i] = (p_pow1[i-1] * p1) % m1;
    p_pow2[i] = (p_pow2[i-1] * p2) % m2;}
	while(q--)
	{
		int n,l;cin>>n>>l;
		string s;cin>>s;
		cout<<count_unique_substrings(s,l)<<endl;
	}
}
 

/* 

  Calculating Hash value
  
*/
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}



/*

  Making groups of all same strings
  
*/
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());
    
    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}





/*

  Counting all diff substrings.
  For every diff length we will put them if diff groups .It will reduce the collision probability

*/
int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

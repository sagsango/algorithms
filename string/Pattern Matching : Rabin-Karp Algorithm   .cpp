/*
    Given string  test t , and pattern string s ,find no and posisition of substring which match with pattern
    For avoiding collision we have used two hashing functions
    Problem:https://www.spoj.com/problems/NAJPF/
    Referance:https://cp-algorithms.com/string/rabin-karp.html
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int p1=31 ,p2=43;
const long long m1=1e9+9,m2=1e9+7;
vector<long long>p_pow1(N+1),p_pow2(N+1);

vector<int> rabin_karp(string const& s, string const& t) {
  
    int S = s.size(), T = t.size();
    vector<long long> h1(T + 1),h2(T + 1); 
    for (int i = 0; i < T; i++){
        h1[i+1] = (h1[i] + (t[i] - 'a' + 1) * p_pow1[i]) % m1; 
        h2[i+1] = (h2[i] + (t[i] - 'a' + 1) * p_pow2[i]) % m2; }
    long long h_s1=0,h_s2= 0; 
    for (int i = 0; i < S; i++){
        h_s1 = (h_s1 + (s[i] - 'a' + 1) * p_pow1[i]) % m1; 
        h_s2 = (h_s2 + (s[i] - 'a' + 1) * p_pow2[i]) % m2; }

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h1 = (h1[i+S] + m1 - h1[i]) % m1; 
        long long cur_h2 = (h2[i+S] + m2 - h2[i]) % m2; 
        if( (cur_h1 == h_s1 * p_pow1[i] % m1)&&(cur_h2 == h_s2 * p_pow2[i] % m2) )
            occurences.push_back(i);
    }
    return occurences;
}
int32_t main()
{
	int q;cin>>q;
	p_pow1[0] = 1; 
	p_pow2[0] = 1; 
    for (int i = 1; i <=N ; i++){ 
        p_pow1[i] = (p_pow1[i-1] * p1) % m1;
        p_pow2[i] = (p_pow2[i-1] * p2) % m2;
	}
	while(q--)
	{
		string t,s;cin>>t>>s;
		vector<int>ans=rabin_karp( s, t);
		if(ans.size())
		{
			cout<<ans.size()<<endl;
			for(int i=0;i<(int)ans.size();i++)
			cout<<ans[i]+1<<" ";
			cout<<endl;
		}
		else cout<<"Not Found"<<endl;
	}
}
		
	

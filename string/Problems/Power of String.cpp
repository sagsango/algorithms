Problem  : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/suffix-trees/practice-problems/algorithm/power-of-string-3/
Statement: For a given integer K and a string S of length N, we denote power of S, as the length of a longest substring 
           occurring in S at least K times.Given K and S, find the power of S.
         : Suffix + Rabin-Karp + Binary Search [ 100 sec ]
         : Pure suffix  [ 10-15 sec ] Impliement it.
           
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

const int N=1000000;
const long long P[2]={31,37};
const long long M[2]={1000000007,1000000009};
vector<vector<long long>>pwr(N+1,vector<long long>(2));
vector<vector<long long>>h(N+1,vector<long long>(2));
string s;
int k,n;

void process()
{
	pwr[0][0]=1;
	pwr[0][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<2;j++)
	pwr[i][j]=(pwr[i-1][j]*P[j])%M[j];
	
	for(int i=0;i<n;i++)
	for(int j=0;j<2;j++)
	h[i+1][j]=(h[i][j] + (s[i]-'a'+1)*pwr[i][j])%M[j];
}
pair<long long ,long long> get_hash(int i,int l)
{
	if(i+l > n)return {-1,-1};
	return {  ((h[i+l][0]-h[i][0]+M[0])*pwr[n-i][0])%M[0] , ((h[i+l][1]-h[i][1]+M[1])*pwr[n-i][1])%M[1] };
}

bool is_possible(vector<int>&a,int l)
{
	map<pair<long long,long long>,int>box;
	for(int i=0;i<k && i<n;i++)
	box[get_hash(a[i],l)]++;
	
	if( box.size()==1  && box.begin()->first.first >=0 && box.begin()->first.second >=0)return 1;
	for(int i=k;i<n;i++)
	{
		pair<int,int>p1=get_hash(a[i-k],l);
		box[p1]--;
		if(box[p1]==0)box.erase(p1);
		pair<int,int>p2=get_hash(a[i],l);
		box[p2]++;
		if( box.size()==1  && box.begin()->first.first >=0 && box.begin()->first.second >=0)return 1;
	}
	return 0;
}
int32_t main()
{
	IOS
	cin>>k>>n;
	cin>>s;
	vector<int>a=suffix_array_construction(s);
	process();
	int l=0,r=n,ans=0;
	while( l <= r )
	{
		int m=(l+r)/2;
		if(is_possible(a,m))
		{
			ans=max(m,ans);
			l=m+1;
		}
		else r=m-1;
	}
	cout<<ans<<endl;
	
	
}
		
	
	

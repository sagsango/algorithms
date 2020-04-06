https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104e05

#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct tri{
	int val;
	struct tri*c[26];
};
tri * root;
int ans;
void Insert(string s)
{
	int n=s.length();
	tri* curr = root;
	for(int i=0;i<n;i++)
	{
		if( !curr->c[ s[i]-'A' ] )curr->c[ s[i]-'A' ]=new tri();
		curr=curr->c[ s[i]-'A' ];
	}
	curr->val+=1;
}

int dfs(tri*curr){
	if(curr==NULL)return 0;
	int sum = curr->val;
	for(int i=0;i<26;i++){
		sum+=dfs(curr->c[i]);
	}
	if( sum >=2 )ans+=1,sum-=2;
	return sum;
}

int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;cin>>n;
		root = new tri();
		ans  = 0;
		for(int i=0;i<n;i++)
		{
			string s;cin>>s;
			reverse(s.begin(),s.end());
			Insert(s);
		}
		for(int i=0;i<26;i++)
		dfs(root->c[i]);
		cout <<"Case #"<<t<<": "<< ans*2 << endl;
	}
 }
			
		
	



https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104f1a


#include<bits/stdc++.h>
//#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
	//IOS
	int T,N,M;cin>>T>>N>>M;
	for(int t=1;t<=T;t++)
	{
		vector<int>cnt(M+1);
		vector<int>prime={5,7,9,11,13,16,17};
		for(auto i:prime)
		{
			for(int j=1;j<=18;j++)
			cout<<i<<( j==18 ? "\n" : " ");
			fflush(stdout);
			
			int dx=0,sum=0;
			for(int j=1;j<=18;j++)
			cin>>dx,sum+=dx;
			
			for(int j=sum;j<=M;j+=i)
			cnt[j]+=1;
		}
		int ans=1;
		for(int i=1;i<=M;i++){
			if(cnt[i]==7){
				ans=i;
				break;
			}
		}
		
		cout<<ans<<endl;
		fflush(stdout);
		
		int status;cin>>status;
		if(status==-1)exit(-1);

	}
 }
			
		
	



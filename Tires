//Search Engine [ hackerearth ]

#include<bits/stdc++.h>
using namespace std;
struct tree{
	tree*c[150];
	int w=0;
};
void insert(tree*root,string s,int w)
{
	tree*crt=root;
	for(int i=0;i<(int)s.length();i++)
	{
		if(!crt->c[s[i]-'a'])crt->c[s[i]-'a']=new tree;
		crt->w=max(crt->w,w);
		crt=crt->c[s[i]-'a'];
	}
}
int query(tree*root,string s)
{
	tree*crt=root;
	for(int i=0;i<(int)s.length();i++)
	{
		if(!crt->c[s[i]-'a'])return -1;
		else crt=crt->c[s[i]-'a'];
	}
	return crt->w;
}
int main()
{
	int n,q;cin>>n>>q;
	tree*root=new tree;
	while(n--)
	{
		string s;int w;cin>>s>>w;
		insert(root,s,w);
	}
	while(q--)
	{
		string s;cin>>s;
		cout<<query(root,s)<<endl;
	}
}





// Maximum xor value pair

#include<bits/stdc++.h>
#define int long long
using namespace std;

class tries{
	public:
	tries *left;
	tries *right;
};

void insert(tries*root,int n)
{
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			if(!current->right)current->right=new tries;
			current=current->right;
		}
		else
		{
			if(!current->left)current->left=new tries;
			current=current->left;
		}
	}
}

int max_xor(tries*root,int n)
{
	int _xor=0;
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			if(current->left)
			{
				current=current->left;
				_xor+=1<<i;
			}
			else
			{
				current=current->right;
			}
		}
		else
		{
			if(current->right)
			{
				current=current->right;
				_xor+=1<<i;
			}
			else
			{
				current=current->left;
			}
		}
	}
	return _xor;
}
int32_t main()
{
	tries *root = new tries;
	int n,ans=0;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++)insert(root,a[i]);
	for(int i=0;i<n;i++)ans=max(ans,max_xor(root,a[i]));
	cout<<ans<<endl;
} 




//maximum xor subarray 

#include<bits/stdc++.h>
#define int long long
using namespace std;

class tries{
	public:
	tries *left;
	tries *right;
};

void insert(tries*root,int n)
{
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			if(!current->right)current->right=new tries;
			current=current->right;
		}
		else
		{
			if(!current->left)current->left=new tries;
			current=current->left;
		}
	}
}

int max_xor(tries*root,int n)
{
	int _xor=0;
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			if(current->left)
			{
				current=current->left;
				_xor+=1<<i;
			}
			else
			{
				current=current->right;
			}
		}
		else
		{
			if(current->right)
			{
				current=current->right;
				_xor+=1<<i;
			}
			else
			{
				current=current->left;
			}
		}
	}
	return _xor;
}
int32_t main()
{
	tries *root = new tries;
	int n,ans=0;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=1;i<n;i++)a[i]^=a[i-1];
	
	for(int i=0;i<n;i++)insert(root,a[i]);
	for(int i=0;i<n;i++)ans=max(ans,max_xor(root,a[i]));
	cout<<ans<<endl;
} 







//minimum xor pair

#include<bits/stdc++.h>
#define int long long
using namespace std;

class tries{
	public:
	tries *left;
	tries *right;
};

void insert(tries*root,int n)
{
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			if(!current->right)current->right=new tries;
			current=current->right;
		}
		else
		{
			if(!current->left)current->left=new tries;
			current=current->left;
		}
	}
}

int min_xor(tries*root,int n)
{
	int _xor=0;
	tries *current=root;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b)
		{
			
			if(current->right)
			{
				current=current->right;
			}
			else 
			{
				current=current->left;
				_xor+=1<<i;
			}
		}
		else
		{
			if(current->left)
			{
				current=current->left;
			}
			else 
			{
				current=current->right;
				_xor+=1<<i;
			}
		}
	}
	return _xor;
}
int32_t main()
{
	tries *root = new tries;
	int n,ans=LLONG_MAX;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
		ans=min(ans,min_xor(root,a[i]));
		insert(root,a[i]);
	}
	cout<<ans<<endl;
} 




//??
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tree{
	int count=0;
	tree*left=NULL;
	tree*right=NULL;
};

void insert(tree*root,int n)
{
	tree*current=root;
	current->count++;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1LL;
		if(b)
		{
			if(!current->right)current->right=new tree;
			current=current->right;
		}
		else
		{
			if(!current->left)current->left=new tree;
			current=current->left;
		}
		current->count++;
	}
}

int counter(tree*root,int n,int k)
{
	int count=0;
	tree*current=root;
	for(int i=31;i>=0 && current;i--)
	{
		int bit_n=(n>>i)&1LL;
		int bit_k=(k>>i)&1LL;
		if(bit_k==0)
		{
			if(bit_n==0)
			{
				current=current->left;
			}
			else
			{
				current=current->right;
			}
		}
		else
		{
			if(bit_n==0)
			{
				if(current->left)count+=(current->left)->count;
				current=current->right;
			}
			else
			{
				if(current->right)count+=(current->right)->count;
				current=current->left;
			}
		}
	}
	return count;
}
	

int32_t main()
{
	int q;cin>>q;
	while(q--)
	{
		int n,k,ans=0;cin>>n>>k;
		tree*root=new tree;
		vector<int>a(n+1);
		insert(root,a[0]);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]^=a[i-1];
			insert(root,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			ans+=counter(root,a[i],k);
		}
		cout<<ans<<endl;
	}
}

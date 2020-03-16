// copy pasted part :  https://cp-algorithms.com/graph/strongly-connected-components.html
// concept : all strongly componets are part of cycle excpt : componet size 1 and having no loop
// problem : https://www.codechef.com/problems/CHEFRRUN
#include<bits/stdc++.h>
#define int long long 
using namespace std;


    vector < vector<int> > g, gr;
    vector<bool> used;
    vector<int> order, component;

    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i)
            if (!used[ g[v][i] ])
                dfs1 (g[v][i]);
        order.push_back (v);
    }

    void dfs2 (int v) {
        used[v] = true;
        component.push_back (v);
        for (size_t i=0; i<gr[v].size(); ++i)
            if (!used[ gr[v][i] ])
                dfs2 (gr[v][i]);
    }

    int32_t main() {
	int q;cin>>q;
	while( q-- )
	{
        int n ;
        cin >>  n ;
        g=vector<vector<int>>(n);
        gr=vector<vector<int>>(n);
        used=vector<bool>(n);
        vector<int>d(n);
        vector<int>part_of_cycle(n);
        for(int i=0;i<n;i++)
        cin>>d[i];
        order.clear();
        component.clear();
        
        for (int i = 0 ;i < n;i++) {
            int a, b;
            a =  i ;
            b =  ( a + d[a] +1  )%n;
            if(a!=b)
            {
               g[a].push_back (b);
               gr[b].push_back (a);
		   }
        }

        used.assign (n, false);
        for (int i=0; i<n; ++i)
            if (!used[i])
                dfs1 (i);
        used.assign (n, false);
        for (int i=0; i<n; ++i) {
            int v = order[n-1-i];
            if (!used[v]) {
                dfs2 (v);
                //... printing next component ...
                if( component.size() == 1 )
                {
					int a = component[0];
					int b = ( a + d[a] + 1)%n;
					if( a==b )
					{
						 part_of_cycle[a]=1;
					}
					//cout << a <<":"<< (a==b) << endl;
				 }
				 else
				 {
					 for(size_t i = 0 ; i < component.size() ; i++ )
					 {
						 
						 int a = component[i];
						 part_of_cycle[a]=1;
						 //cout << a <<" ";
					 }
					 //cout << endl;
				 }
                component.clear();
            }
        }
        int cnt = 0 ;
        for(int i=0;i<n;i++)
        cnt+=part_of_cycle[i];
        
        cout << cnt << endl;
	}
  }






Alternate Solution :
/* All the v have only one child so part_of_cycle[v] will be only one times so this is good TL */
#include<bits/stdc++.h>
#define int long long 
using namespace std;

vector < vector<int> > g;
vector < int > clr;
vector < int > part_of_cycle;
vector < int > par;

void dfs(int u ,int p )
{
	clr[u]=1;
	par[u]=p;
	for(auto v:g[u])
	{
		if(!clr[v])
		{
			dfs(v,u);
		}
		else if( clr[v]==1 )
		{
			int x = u ; 
			while( x!= v)
			{
				part_of_cycle[x]=1;
				x=par[x];
			}
			part_of_cycle[x]=1;
		}
	}
	clr[u]=2;
}
int32_t main()
{
	int q;cin>>q;
	while(q--)
	{
		int n;cin>>n;
		g = vector<vector<int>>(n+1);
		clr = vector<int>(n+1);
		part_of_cycle = vector<int>(n+1);
		par = vector<int>(n+1);
	
		for(int i=0;i<n;i++)
		{
			int d ; cin >> d;
			int a = i ;
			int b = ( a + d +1)%n;
			
			g[a+1].push_back(b+1);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(!clr[i])
			{
				dfs(i,0);
			}
		}
		
		int cnt = 0;
		for(int i=1;i<=n;i++)
		cnt+=part_of_cycle[i];
		cout << cnt << endl;
	}
}
		


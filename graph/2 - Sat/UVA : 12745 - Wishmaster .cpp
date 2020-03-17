Problem  :  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=4598&mosmsg=Submission+received+with+ID+24716540

#include<bits/stdc++.h>
using namespace std;
//source code   :   https://cp-algorithms.com/graph/2SAT.html
int n , m;
vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

int32_t main()
{
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin >> n >> m;
		n<<=1;
		
		g  =  vector<vector<int>>(n);
		gt =  vector<vector<int>>(n);
		order.clear();
		used = vector<bool>(n);
		assignment = vector<bool>(n);
		comp = vector<int>(n);
		
		for(int i=0;i<m;i++)
		{
			int u , v ; cin >> u >> v;
			int ub = u  > 0 ;
			int vb = v  > 0 ;
			u=((abs(u)-1)<<1)^ub;
			v=((abs(v)-1)<<1)^vb;
			
			/* + :true  
			 * - :false
			 * 
			 * given : -[ u ^ v ]  = [ -u V -v ]
			 *       : u-> -v 
			 *       : v-> -u
			 */
			 
			 g[u].push_back(v^1);
			 g[v].push_back(u^1);
			 
			 gt[v^1].push_back(u);
			 gt[u^1].push_back(v);
		 }
		 cout <<"Case "<<t<<": "<< ( solve_2SAT() ? "Yes" : "No" ) << endl;
	 }
 }
			
			 
		

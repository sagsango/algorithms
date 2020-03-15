// https://cp-algorithms.com/graph/bridge-searching.html

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}




/* Another implimentation */
vector<vector<int>>g;
vector<int>h;
vector<int>hmin;
vector<int>clr;
map<pair<int,int>,int>dp;

void dfs(int u,int p)
{
	if( p!=-1 )
	{
		h[u]=h[p]+1;
	}
	clr[u]=1;
	for(auto v:g[u])
	{
		if(!clr[v])
		{
			dfs(v,u);
			hmin[u]=min(hmin[u],hmin[v]);
			if( h[v] <= hmin[v] )
			{
				 int x = min( u , v );
		         int y = max( u , v );
		         dp[{x,y}]=1;
			}
				
		}
		else if(v!=p)
		{
			hmin[u]=min(hmin[u],h[v]);
		}
	}
	clr[u]=2;
}

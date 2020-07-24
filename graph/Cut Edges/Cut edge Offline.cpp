// https://cp-algorithms.com/graph/bridge-searching.html

/* Node are numbered from 1 to n , edgeds are numbers 1 to m */
int n,m; // number of nodes and edges
vector<vector<pair<int,int>>> adj; // adjacency list of graph  u->[v,edge_id]
vector<int>U,V,bridge;

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int pid = -1) {
    /* Use bool to cut[e]=1, because cut[e]  may updated more than once */
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (auto it : adj[v]) {
	int to = it.first;
	int id = it.second;
        if (id == pid) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, id); // to deal deal with multiple edges
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                /*BRIDGE(v, to);*/
                bridge[id]=1;
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

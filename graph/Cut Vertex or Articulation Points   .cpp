1.https://www.youtube.com/watch?v=aZXi1unBdJA&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=13



2.https://codeforces.com/blog/entry/16221
h[root] = 0
par[v] = -1
dfs (v):
        d[v] = h[v]
        color[v] = gray
        for u in adj[v]:
                if color[u] == white
                        then par[u] = v and dfs(u) and d[v] = min(d[v], d[u])
                        if d[u] >= h[v] and (v != root or number_of_children(v) > 1)
                                then the edge v is a cut vertex
                else if u != par[v])
                        then d[v] = min(d[v], h[u])
        color[v] = black




3.Copy Pasted Part : http://ideone.com/vcbqE0
https://codeforces.com/blog/entry/44692

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
const int UNVISITED = -1;
const int VISITED = 0;
vector<int> graph[105];
bool isArticulationPoint[105];
int dfs_status[105];
int dfs_parent[105];
int dfs_depth[105];
int dfs_low[105];
 
void dfsArticulationPoints(int u)
{
    dfs_status[u] = VISITED;
    dfs_low[u] = dfs_depth[u];
    int childrensCount = 0;
    bool articulationPoint = false;
 
    for (auto v: graph[u])
    {
        if (dfs_status[v] == UNVISITED)
        {
            dfs_depth[v] = dfs_depth[u] + 1;
            childrensCount++;
            dfs_parent[v] = u;
            dfsArticulationPoints(v);
            if (dfs_low[v] >= dfs_depth[u])
            {
                articulationPoint = true;
            }
            else
            {
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }
        }
        else if (dfs_parent[u] != v)
        {
            dfs_low[u] = min(dfs_low[u], dfs_depth[v]);
        }
    }
    if ((dfs_parent[u] == -1 && childrensCount >= 2) || (dfs_parent[u] != -1 && articulationPoint))
    {
        isArticulationPoint[u] = true;
    }
}
 
int main()
{
    #ifdef VSP4
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // VSP4
 
    int t, i, j, n, m, u, v, ans, zeroColored, oneColored;
    string str;
    stringstream ss;
 
    while (cin >> n >> ws, n)
    {
        for (i = 1; i <= n; i++)
        {
            graph[i].clear();
        }
 
        while (getline(cin, str), ss.clear(), ss.str(str), ss >> u, u)
        {
            while (ss >> v)
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
                //cout << u << "-" << v << "\n";
            }
        }
 
        memset(dfs_status, UNVISITED, sizeof(dfs_status));
        memset(isArticulationPoint, false, sizeof(isArticulationPoint));
 
        dfs_depth[1] = 0;
        dfs_parent[1] = -1;
        dfsArticulationPoints(1);
 
        ans = 0; //records no of articulation points
 
        for (i = 1; i <= n; i++)
        {
            if (isArticulationPoint[i])
            {
                ans++;
            }
        }
 
        cout << ans << "\n";
    }
 
    return 0;
}
 

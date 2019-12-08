https://codeforces.com/blog/entry/16221
h[root] = 0
par[v] = -1
dfs (v):
        d[v] = h[v]
        color[v] = gray
        for u in adj[v]:
                if color[u] == white
                        then par[u] = v and dfs(u) and d[v] = min(d[v], d[u])
                        if d[u] > h[v]
                                then the edge v-u is a cut edge
                else if u != par[v])
                        then d[v] = min(d[v], h[u])
        color[v] = black

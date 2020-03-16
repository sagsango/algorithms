Source  Code  :   https://codeforces.com/blog/entry/16221
Problem       :   https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251
Problem Sugg  :   https://cp-algorithms.com/graph/bridge-searching.html

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

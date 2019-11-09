vector E
dfs (v):
        color[v] = gray
        for u in adj[v]:
                erase the edge v-u and dfs(u)
        color[v] = black
        push v at the end of e
        
       
       
 https://codeforces.com/blog/entry/16221

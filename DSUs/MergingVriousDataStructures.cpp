source       :    https://cp-algorithms.com/data_structures/disjoint_set_union.html
Application  :    we are given a tree, each leaf has a number assigned (same number can appear multiple times on different   
                  leaves). We want to compute the number of different numbers in the subtree for every node of the tree.
                     
                  This case you can use set at every vertex and do dfs and after exploring child you have to merge all child
                  container then at this node you can give answer query offline.
                  psedo code :-
                  dfs(int u,int p)
                  {
                      for(auto v:g[u])
                        if(v!=p)dfs(v,u),merge(u,v);
                      ans[query.index]=st[u].size();
                  }
 
Example      :
  

vector<int> lst[MAXN];
int parent[MAXN];

void make_set(int v) {
    lst[v] = vector<int>(1, v);
    parent[v] = v;
}

int find_set(int v) {
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap(a, b);
        while (!lst[b].empty()) {      /* Here merging is done betwwen nodes and root will contain all its subtree as child */
            int v = lst[b].back();     /* In the vector and it will become parent of those                                  */
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
    }
}

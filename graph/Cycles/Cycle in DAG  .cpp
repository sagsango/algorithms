// Problem   : https://www.spoj.com/problems/GHOSTS/
// Solution  : https://github.com/t3nsor/SPOJ/blob/master/ghosts.cpp
// Theory    : https://www.sciencedirect.com/science/article/pii/0304397586900988

// 2017-07-08
// See G.F. Italiano, "Amortized efficiency of a path retrieval data
// structure", Theoretical Computer Science 48 (1986): 273-281
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
struct Node {
    int vertex;
    Node* parent = nullptr;
    vector<Node*> children;
};
struct Graph {
    Graph(int n) : n(n), pool(n), index(n, vector<Node*>(n)) {
        for (int i = 0; i < n; i++) {
            pool[i].vertex = i;
            index[i][i] = &pool[i];
        }
    }
    bool is_reachable(int i, int j) { return index[i][j]; }
    void add(int i, int j) {
        if (index[i][j]) return;
        for (int x = 0; x < n; x++) {
            if (index[x][i] && !index[x][j]) {
                meld(x, j, i, j);
            }
        }
    }
    void meld(int x, int j, int u, int v) {
        pool.emplace_back();
        Node* new_node = &pool.back();
        new_node->vertex = v;
        new_node->parent = index[x][u];
        index[x][v] = new_node;
        index[x][u]->children.push_back(new_node);
        for (const Node* w : index[j][v]->children) {
            if (!index[x][w->vertex]) meld(x, j, v, w->vertex);
        }
    }
    int n;
    deque<Node> pool;
    vector<vector<Node*>> index;
};
int main() {
    int K, T; scanf("%d %d", &K, &T);
    Graph g(K);
    while (T--) {
        int a, b; scanf("%d %d", &a, &b);
        if (g.is_reachable(b - 1, a - 1)) printf("%d %d\n", a, b);
        else g.add(a - 1, b - 1);
    }
    puts("0 0");
}



//  https://github.com/fazlerahmanejazi/SPOJ/blob/master/GHOSTS%20-%20Ghosts%20having%20fun.cpp
#include <bits/stdc++.h>
using namespace std ;

int n, m, u, v ;
vector<vector<int>> adj ;
vector<bool> visit ;
bitset<1010> mask[1010] ;  // using bitset

void dfs(int v)
  {
    int to ;
    visit[v]=true ;
    for(int i=0 ; i<adj[v].size() ; i++)
      {
        to=adj[v][i] ;
        if(!visit[to]) dfs(to) ;
        mask[v] |= mask[to];
        mask[v].set(to);
      }
   }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        if(mask[v][u] || u==v) cout<< u << " " << v << endl ;
        else if(mask[u][v]) continue ;
        else
          {
            adj[u].push_back(v) ;
            visit.assign(n+1, false) ;
            for(int i=1 ; i<=n ; i++)
              if(!visit[i]) dfs(i) ;
          }
      }
    cout<< 0 << " " << 0 << endl ;
  }

source    :   Competitive Programmer’s Handbook ,Antti Laaksonen ,Draft July 3, 2018 [ page : 170 ]
/* alternative : use binary lifting technique */

const int   N=1e6;
vector<int> g[N+1];
vector<int> h(N+1);
vector<int> q_point(N+1);
vector<pair<int,int>>query_arry;
int t=0;

void dfs(int u,int p,int ht)
{
    q_point[u]=t++;
    h[u]=ht;
    query_array.push_back({h[u],u});
    for(auto v:g[u])
      if(v!=p)
      {
           dfs(v,u,ht+1);
           t++;
           query_array.push_back({h[u],u});
      }
}

void init(int root=1)
{
    dfs(1,0,0);
    make_segment_tree( query_array );  //segtree< pair<int,int> > seg : range min query only.
}

int find_lca(int u,int v)
{
    pair<int,int> a = find_min_pair(q_point[u],q_point[v]);//In segtree
    return a.second;
}

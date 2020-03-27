// Not tested
class Kruskal{
  public:
      vector<int>U,V,W;
      vector<int>used;
      vector<int>par;
      int n,m,cost;
      Kruskal(int N=1'000'000,int M=1'000'000)
      {
		  n=N;
		  m=M;
		  U=vector<int>(M+1);
		  V=vector<int>(M+1);
		  W=vector<int>(M+1);
		  used=vector<int>(M+1);
		  par=vector<int>(n+1);
	  }
      int root(int u){return par[u]<0?u:par[u]=root(par[u]);}
      void merge(int u,int v)
      {
      	if( (u=root(u)) == (v=root(v)) )return ;
      	if( par[u] > par[v] )swap(u,v);
      	par[u]+=par[v];
      	par[v]=u;
      }
      int init(int s=1 )
      {
      	/////////// Multiple test ///////////
      	fill(used.begin(),used.begin()+m+1,0);
      	fill(par.begin(),par.begin()+n+1,-1);
      	/////////////////////////////////////

      	vector<pair<int,int>>edges(m+1);
      	for(int i=1;i<=m;i++)
      	edges[i]={W[i],i};

      	sort(edges.begin(),edges.end());

        cost=0;
      	for(int i=1;i<=m;i++)
      	{
      		int id = edges[i].second;
      		if( root(U[id]) != root(V[id]) )
      		{
      			merge(U[id],V[id]);
      			used[id]=1;
      			cost+=W[id];
      		}
      	}
      	return cost;
      }
};

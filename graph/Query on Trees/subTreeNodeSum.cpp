source    :   Competitive Programmer’s Handbook ,Antti Laaksonen ,Draft July 3, 2018 [ page : 164 ]

/* find sum of all the nodes in the subtree of the given node v */
/* and update all the node value of the perticular node */
/* using in time only */

const int N=1e6+1;
vector<int> g[N+1];
vector<int> val(N+1);
vector<int> subsize(N+1);
vector<int> in(N+1);
int t=0;
BIT(N) B; // BIT : point update and range query type.

int dfs(int u,int p)
{
    int currsize=1;
    in[u]=t++;
    for(auto v:g[u])
      if(v!=p)currsize+=dp(v,u);
    return subsize[u]=currsize;
 }
 
 void init(int root,int n)
 {  
    dfs(root,0);
    for(int u=1;u<=n;u++)
      B.update(in[u],val[u]);
 }
 
 int subTreeNodeSum(int u)
 {  
    return B.sum(in[u],in[u]+size[u]-1);
 }
 
 void updateNodeValue(int u,int addent)
 {
    B.update(in[u],addent);
 }
 
 
    
    
    
    




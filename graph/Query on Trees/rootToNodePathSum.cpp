source    :   Competitive Programmer’s Handbook ,Antti Laaksonen ,Draft July 3, 2018 [ page : 164 ]
/* update node value   */
/* find path sum root to node v */
/* Alternative : using in[v] and out[v]  values , see eulerian magic */


/* Idea  : dp[v] contains sum from root to v
         : if val[v] is updated, it will effect all the nodes val in its subtree
*/

const int N=1e6+1;
vector<int> g[N+1];
vector<int> val(N+1);
vector<int> subsize(N+1);
vector<int> in(N+1);
int t=1;
BIT(N) B; // BIT : range updation and point query

int dfs(int u,int p,int valsum)
{
    int currsize=1;
    valsum+=val[u];
    B.update(in[u],in[u],valsum);
    in[u]=t++;
    for(auto v:g[u])
      if(v!=p)currsize+=dp(v,u,valsum);
    return subsize[u]=currsize;
 }
 void init(int root,int n)
 {  
    dfs(root,0);
 }
 int subTreeNodeSum(int u)
 {  
    return B.sum(in[u],int[u]+size[u]-1);
 }
 void updateNodeValue(int u,int newval)
 {
    B.update(in[u],int[u]+subsize[u]-1,newval-val[u]);
    val[u]=newval;
 }
 
 
    




https://www.youtube.com/watch?v=KiCBXu4P-2Y&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=5
Shortest Path 
BFS
DP
Topological Short
BFS In Grid using queue : Think what data structure you will use and how ?
Make Grath from Given Grid or Given conditions 
Adjencancy List or Adjencency Matrix => Dense or Sparse


/*
	 Also Can Make a Par[] array for parent 
 */
vector<int>g[N+1];
vector<int>l(N+1);
vector<int>par(N+1);
vector<int>vis(N+1);
 
queue<int>q;
q.push(1);
par[1]=0;
l[1]=0;
vis[1]=1;
while(q.size())
{
	int u=q.front();q.pop();
	for(auto v:G[u])
	{
		if(!vis[v]) 
		{
			q.push(v);
			par[v]=u;
			l[v]=l[u]+1;
			vis[v]=1;
		}
	}
}

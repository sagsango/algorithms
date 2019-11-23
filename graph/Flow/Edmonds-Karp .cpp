Sources   :      https://cp-algorithms.com/graph/edmonds_karp.html#integral-theorem
Problem   :      http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
          :      O(V*E*E)
          
          
          

#include<bits/stdc++.h>
#define INF 1e6
using namespace std;

int n,m;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main()
{
  cin>>n>>m;
	capacity=vector<vector<int>>(n,vector<int>(n));
	adj=vector<vector<int>>(n);
	for(int i=0;i<m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		capacity[u][v]=w;
	}
	cout<< maxflow(0,n-1)<<endl;
}
          

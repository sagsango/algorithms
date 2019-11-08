you have to find total no of components using lighter edeges
      then havier edgeds will be equal to no_of_components -1
      
Problem   : https://codeforces.com/contest/1242/problem/B
Solution  : https://codeforces.com/contest/1242/submission/64375742




int n,m,comp;
set<int> lef, bad[MX];
 
int main() {
	setIO(); re(n,m);
	F0R(i,m) {
		int a,b; re(a,b);
		bad[a].insert(b), bad[b].insert(a);
	}
	FOR(i,1,n+1) lef.insert(i);
	FOR(i,1,n+1) if (lef.count(i)) {
		comp ++;
		queue<int> q; q.push(i); lef.erase(i);
		while (sz(q)) {
			auto a = q.front(); q.pop();
			vi cool;
			trav(t,lef) if (!bad[a].count(t)) cool.pb(t);
			trav(t,cool) {
				lef.erase(t);
				q.push(t);
			}
		}
	}
	ps(comp-1);
	// you should actually read the stuff at the bottom
}

https://codeforces.com/blog/entry/44244


Maybe you'd also consider this a 'complex algorithm', but I just solved it in the following manner:

Fix some node u.
Run Dijkstra's algorithm with source u, denote the distance of a vertex v to u as d v. If you store parents, this will give you a shortest-path tree rooted at u.
Preprocess the tree for LCA queries.
Consider some edge e = {v, x} that is not in the shortest-path tree. If lca(v, x) = u, then the path  is a simple cycle containing u, with weight d v + d x + w(e). The answer for vertex u is the minimum weight over all such cycles.

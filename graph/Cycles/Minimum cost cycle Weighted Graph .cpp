https://codeforces.com/blog/entry/68073

We will solve independently for each component. Let’s find Dijstra. Now every edge which is not included in Dijkstra saycet cycle. Iterate over all such edges and relax answer with length of this cycle. It can be done with binary lifting.

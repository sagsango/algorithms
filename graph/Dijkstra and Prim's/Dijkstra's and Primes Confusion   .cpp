1.https://stackoverflow.com/questions/14144279/difference-between-prims-and-dijkstras-algorithms
2.Dijkstra's algorithm doesn't create a MST, it finds the shortest path.
Consider this graph

       5     5
  s *-----*-----* t
     \         /
       -------
         9
The shortest path is 9, while the MST is a different 'path' at 10.


3.Prim and Dijkstra algorithm are almost the same, except for the "relax function".

In Prim:

MST-PRIM (G, w, r) {

        for each key ∈ G.V

            u.key = ∞
            u.parent = NIL

        r.key = 0
        Q = G.V
        while (Q ≠ ø)

            u = Extract-Min(Q)
            for each v ∈ G.Adj[u]

                if (v ∈ Q) and w(u,v) < v.key

                    v.parent = u
                    v.key = w(u,v)    <== relax function, Pay attention here

}
In Dijkstra:

Dijkstra (G, w, r) {

        for each key ∈ G.V

            u.key = ∞
            u.parent = NIL

        r.key = 0
        Q = G.V
        while (Q ≠ ø)

            u = Extract-Min(Q)
            for each v ∈ G.Adj[u]

                if (v ∈ Q) and w(u,v) < v.key

                    v.parent = u
                    v.key = w(u,v) + u.key  <== relax function, Pay attention here

}

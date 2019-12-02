-- Referance  : Competitive Programmer’s Handbook Antti Laaksonen Draft July 3, 2018  [ Page - 137 ]
From every node what is the max path in the tree?

1. Using DP
2. Using Diameter property


1.Using DP:-
 a) If vertex is root then max path may end at any of the leaf [ easily found using dfs ]
 b) If vertex is not root then Max path may go from vertex v to some leaf of its subtree [ [ easily found using dfs ]
                            or
    Max path may go throught its parent then some leaf
    [ we store max 2 path from every node ]
    so from parent the one with does not go through the vertex that may be the longest path.
    
    => Note one of possible solution is 2 dfs
       1st dfs will update max 2 lengths from its child.
       2nd dfs will update max_length[v] = max( max_2_lengths_from_child , max_1_length_which_does_not_go_though_v + 1);
       
       or some recursion techinque which require only one fucntion call.
       

2.Using Diameter Property.
  Last diameter is a<----->b then 
  from any vertex v max path will end at a or b.
  
  using this property first we would find the both a and b , a<---->b
  then after from every node max_length.
  
  so -> choose any vertex v  make dfs and find fartherest node a.
        from vertex a make dfs and find fartheres node b.
        now from evey vertex v , max_length[v]=max( distance(a,v) , distance(b,v) )
        distance(a,v) query can be done in log(n) using LCA technique.
  

/*


UCSD string processing and pattern matching
1. do topological sort on grath
   now all the vectex length will we depends on
   Lmax[ v ] = max(  W[ v ][ u1 ] + Lmax[ u1 ]  ,  W[ v ][ u2 ] + Lmax[ u2 ] , ...    )
   u1 , u2 .... are adjecnt of v having lower topological value
   its privious verticies length
2. Like a dp we can process one by one 
   we will fill adject having heigher topological value accordingly max.




*/

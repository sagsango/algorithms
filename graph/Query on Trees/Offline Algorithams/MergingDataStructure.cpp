source    :   Competitive Programmer’s Handbook ,Antti Laaksonen ,Draft July 3, 2018 [ page : 164 ]
Idea      :
One method to construct an offline algorithm is to perform a depth-first tree
traversal and maintain data structures in nodes. At each node s , we create a
data structure d [ s ] that is based on the data structures of the children of s . Then,
using this data structure, all queries related to s are processed.


Problems :
As an example, consider the following problem: We are given a tree where
each node has some value. Our task is to process queries of the form ”calculate
the number of nodes with value x in the subtree of node s”

Solution :
In this problem, we can use map structures to answer the queries.
If we create such a data structure for each node, we can easily process all
given queries, because we can handle all queries related to a node immediately
after creating its data structure.
The merging at node s can be done as follows: We go through the children
of s and at each child u merge d [ s ] and d [ u ]. We always copy the contents from
d [ u ] to d [ s ]. However, before this, we swap the contents of d [ s ] and d [ u ] if d [ s ] is
smaller than d [ u ]. By doing this, each value is copied only O (log n ) times during
the tree traversal, which ensures that the algorithm is efficient.
To swap the contents of two data structures a and b efficiently, we can just
use the following code:
swap(a,b);
It is guaranteed that the above code works in constant time when a and b are
C++ standard library data structures.



Problem : 
Bactirea on codeforces. I have done it.

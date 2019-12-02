source   :  Competitive Programmer’s Handbook Antti Laaksonen Draft July 3, 2018 [ page 153 ]

Representing problems as graphs :-
Actually, any dynamic programming problem can be represented as a directed, acyclic graph. In such a graph,
each node corresponds to a dynamic programming state and the edges indicate how the states depend on each other.
As an example, consider the problem of forming a sum of money n using coins { c 1 , c 2 , . . . , c k }. 
In this problem, we can construct a graph where each node corresponds to a sum of money, and the edges show
how the coins can be chosen.For example, for coins {1, 3, 4} and n = 6, the graph is as follows:

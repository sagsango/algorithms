https://cp-algorithms.com/graph/depth-first-search.html
Find strongly connected components in a directed graph:
First do a topological sorting of the graph. Then transpose the graph and run another series of depth first searches 
in the order defined by the topological sort. For each DFS call the component created by it is a strongly connected component.

------------------------------------------------------------------------------------------------------------------------------

In directed graph set of verticies which are reachable from eath others , forms strongly connected components.

we reverse the direction of the edges .
then do dfs with storing their postvisit numbers.
the sort them in reverse order of their postvisit number.
then perform dfs to get connected components there r strongly conncted components.

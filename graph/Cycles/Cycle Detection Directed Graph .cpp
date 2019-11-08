https://codeforces.com/blog/entry/4907
https://codeforces.com/blog/entry/64903


void dfs(int v, int p){
  color[v] = 1; // GREY
  for(int w : g[v]){
    if(color[w] == 1){
      // you found a cycle, it's easy to recover it now.
    }
    if(color[w] == 0) dfs(w, v);
  }
  color[v] = 2; // BLACK
}

for(int i = 0; i < n; i++)
  if(color[i] == 0) dfs(i, -1);




Use the following approach: consider we have three colors, and each vertex should be painted with one of these colors. 
"White color" means that the vertex hasn't been visited yet. "Gray" means that we've visited the vertex but haven't visited all
vertices in its subtree. "Black" means we've visited all vertices in subtree and left the vertex. 
So, initially all vertices are white. When we visit the vertex, we should paint it gray. 
When we leave the vertex (that is we are at the end of the dfs() function, after going throung all edges from the vertex), 
we should paint it black. If you use that approach, you just need to change dfs() a little bit. 
Assume we are going to walk through the edge v->u. If u is white, go there. If u is black, don't do anything. 
If u is gray, you've found the cycle because you haven't left u yet (it's gray, not black), but you come there one more time 
after walking throung some path.

To keep vertices' colors replace boolean array with char or integer array and just use values in range [0..2].


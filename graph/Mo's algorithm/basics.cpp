https://codeforces.com/blog/entry/43230
https://blog.anudeep2011.com/mos-algorithm/


Explanation of Blog:
Problem : Find no of distinct colour from path u to v
Solution: After flatterning the tree
          1, 2, 3, 4, 4, 3, 5, 6, 6, 5, 2, 7, 8, 8, 9, 9, 7, 1
          p=par(u,v)
          1.p==u or p==v  : process [ in[u] , in[v] ] Range
          2.p!=u or p!=v  : process [ out[u], in[v] ] +  [ in[p] ,in[p] ] Range
          


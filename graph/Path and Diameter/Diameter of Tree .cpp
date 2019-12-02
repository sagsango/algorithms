-- Referance  : Competitive Programmer’s Handbook Antti Laaksonen Draft July 3, 2018  [ Page - 137 ]
1. Using DP on Trees 
2. 2 DFS

1. Find maxDia at  every v belongs to tree   
   // DP on Trees
   // Need only 2 max values at evey node
   int dfsForDia(int u,int p,int &maxDia)
   {
      vector<int>childDis;
      for(auto v:g[u])
      if(v!=p)childDis.push_back(dfsForDia(v,u,maxDia);
      sort(childDis.rbegin(),childDis.rend());
      if(childDis.size() >= 2)maxDia=max(maxDia,childDis[0]+childDis[1]);
      else if(childDis.size()==1)maxDia=max(maxDia,childDis[0]);
      return 1 + (childDis.size()?childDis[0]:0);
   }

2. let a<------>b be the diameter
   then maximum distance  node from every node will be one of the a or b  [ so get a or b using 1st dfs ]
   now maximum distance node from a/b will be b/a                         [ so get both a and b using 2nd dfs ]
   

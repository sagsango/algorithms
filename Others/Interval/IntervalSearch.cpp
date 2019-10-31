1. given vector<pair<int,int>>intervlas;
   find which pint is pariticipating in how may intervals
   dp[l]+=1;
   dp[r+1]-1;
   after : dp[i]+=dp[i-1];
   now dp[i]=no of points in which it is paricipating
   
2. given vector<pair<int,int>>intervlas;
   find which interval[l,r] is pariticipating in how may intervals
   sort them according to l
   and make another vector which correspond to r vale of every interval
   now for every interval
   dp[ith_interval]+=1;
   dp[lower_boud(R.begin(),R.end(),ri+1)-R.begin()]-=1;
   after dp[i]+=dp[i-1];
   now dp[i]=no of interval verlapping with ith innterval
   
   ICPC:2019
3.given set of intervals which may overlap with each other
  now for each query Li,Ri find no of intervals which is overlaing with it
  sort the given intervals by ri
  now binary search for lower_bound (Li,0) 
              after that index we have to check for all indexs
              Better than O(n)

4.given set of intervals which not overlap with each other
  now for each query Li,Ri find no of intervals which is overlaing with it
  put all li ri in same array
  sort
  even index correspond to l
  odd index correspond to r
  now binary search for in Li and Ri 
              give ans accordingly
              O(nlogn)
   

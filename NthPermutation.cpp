// https://stackoverflow.com/questions/7918806/finding-n-th-permutation-without-computing-others


vector<int> ithPermutation(const int n, int i){
   
   vector<int>fact(n),perm(n);
   fact[0]=1;
   for(int i = 1; i < n; ++i){
	   fact[i] = fact[i-1] * i;
   }

   for(int k = 0; k < n; ++k){
      perm[k] = i / fact[n - 1 - k];
      i = i % fact[n - 1 - k];
   }

   for(int k = n - 1; k > 0; --k){
      for(int j = k - 1; j >= 0; --j){
			if(perm[j] <= perm[k]){
				perm[k]++;
			}
		}
	}
   
    vector<int>ans(n);
    for(int k = 0; k < n; ++k){
	    ans[k]=perm[k];
    }
    
	return ans;
    
}

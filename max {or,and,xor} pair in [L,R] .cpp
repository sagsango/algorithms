We want to choose exactly two integers (not necessarily distinct) from the interval [L,R]. 
1:Find the maximum possible value of the bitwise OR of the chosen integers
2:Find the maximum possible value of the bitwise XOR of the chosen integers
3:Find the maximum possible value of the bitwise AND of the chosen integers

sol1:
   From MSB
   Untill bits are same in l and r ,ans bit be same
   after 1st diff bits of l and r all bits be 1.
   int l,r;cin>>l>>r;
		int ans=0,diff=0;
		for(int b=63;b>=0;b--)
		{
			if( ((l>>b)&1)!= ((r>>b)&1) )diff=1;
			
			if(diff)ans|=1LL<<b;
			else ans|=((r>>b)&1)<<b;
		}
		cout<<ans<<endl;
    https://www.codechef.com/viewsolution/27513936


sol2:
   From MSB
   Untill bits are same in l and r, ans bit be 0
   after 1st diff bit all bit will we set
   int l,r;cin>>l>>r;
		int ans=0,diff=0;
		for(int b=63;b>=0;b--)
		{
			if( ((l>>b)&1)!= ((r>>b)&1) )diff=1;
			
			if(diff)ans|=0;
			else ans|=1LL<<b;
		}
		cout<<ans<<endl;
    https://www.geeksforgeeks.org/maximum-xor-value-of-a-pair-from-a-range/
    
    
 sol3:
    int l,r,ans=0;// l+1<r
    cin>>l>>r;
    cout<<max( r & (r-1) , (r-1)&(r-2) );
    https://www.geeksforgeeks.org/maximum-bitwise-and-pair-from-given-range/
   
   
   

1:Find the maximum possible value of the bitwise OR of the chosen integers
2:Find the maximum possible value of the bitwise XOR of the chosen integers
3:Find the maximum possible value of the bitwise AND of the chosen integers

#We want to choose exactly two integers (not necessarily distinct) from the interval [L,R]. 
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
   

#we want two distint elemnts in the array.
sol1.
sol2. see tri section  in datastructure.
sol3. https://www.geeksforgeeks.org/maximum-value-pair-array/

// CPP Program to find maximum AND value of a pair 
#include<bits/stdc++.h> 
using namespace std; 

// Utility function to check number of elements 
// having set msb as of pattern 
int checkBit(int pattern, int arr[], int n) 
{ 
	int count = 0; 
	for (int i = 0; i < n; i++) 
		if ((pattern & arr[i]) == pattern) 
			count++; 
	return count; 
} 

// Function for finding maximum and value pair 
int maxAND (int arr[], int n) 
{ 
	int res = 0, count; 

	// iterate over total of 30bits from msb to lsb 
	for (int bit = 31; bit >= 0; bit--) 
	{ 
		// find the count of element having set msb 
		count = checkBit(res | (1 << bit),arr,n); 

		// if count >= 2 set particular bit in result 
		if ( count >= 2 )		 
			res |= (1 << bit);		 
	} 

	return res; 
} 

// Driver function 
int main() 
{ 
	int arr[] = {4, 8, 6, 2}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Maximum AND Value = " << maxAND(arr,n); 
	return 0; 
} 

   

# max or value with x :
                gievn x and array;
                fill all the array in tri
		now serah max or with n*logn complexity.

   

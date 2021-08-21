=> n&(n-1) : removes last setbit
=> n&(-n ) : gives last setbit

=>Maximum Xor pair:
1. tries

=>Minimum Xor pair
1. sort then xor of cnsecultive elements
2. tries

=>Mximum and pair:
1. tries
2. https://www.geeksforgeeks.org/maximum-value-pair-array/

=>Minimum and pair
and operation of first two minimum elements
[ sees wrong ]



#include<bits/stdc++.h> 
using namespace std; 
int checkBit(int pattern, int arr[], int n) 
{ 
    int count = 0; 
    for (int i = 0; i < n; i++) 
        if ((pattern & arr[i]) == pattern) 
            count++; 
    return count; 
} 
int maxAND (int arr[], int n) 
{ 
    int res = 0, count; 
    for (int bit = 31; bit >= 0; bit--) 
    { 
        count = checkBit(res | (1 << bit),arr,n); 
        // if count >= 2 set particular bit in result 
        if ( count >= 2 )         
            res |= (1 << bit);         
    }
    return res; 
} 
int main() 
{ 
    int arr[] = {4, 8, 6, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Maximum AND Value = " << maxAND(arr,n); 
    return 0; 
} 




https://www.hackerearth.com/practice/algorithms/searching/ternary-search/tutorial/


/*

given  : sorted array : arr[ 1,2.....n ]
       : key
return : index of the key if present
       : otherwise -1
*/


//recursive
int ternary_search(int l,int r,int key)
{
    if(l > r)return -1;
    int m1=l+(r-l)/3;
    int m2=r-(r-l)/3;
    
    if( arr[m1] == key )return m1;
    if( arr[m2] == key )return m2;
    
    if( arr[m1] > key  )return ternary_search(l,m1-1,key);
    if( arr[m2] < key  )return ternary_search(m2+1,r,key);
    return ternary_search(m1+1,m2-1,key);
}



//iterative
int l=1,r=n,index=-1;
while(l<=r)
{
    int m1=l+(r-l)/3;
    int m2=r-(r-l)/3;
    
    if( arr[m1] == key ){ index = m1 ; break ;}
    if( arr[m2] == key ){ index = m2 ; break ;}
    
    if( arr[m1] > key  )r=m1-1;
    else if( arr[m2] < key  )l=m2+1;
    else {l=m1+1; r=m2-1;}
}
    

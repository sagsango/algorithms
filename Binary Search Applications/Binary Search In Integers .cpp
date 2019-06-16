
//recursive binary search
int b_search(int l,int r,int key)
{
    if(l > r)return -1;
    
    int m=l+(r-l)/2;
    if( arr[m] == key )return m;
    else if( arr[m] < key  )l=m+1;
    else r=m-1;
    return b_search(l,r,key);
}



//iterative binary search
int l=1,r=n,index=-1;
while(l<=r)
{
   int m=l+(r-l)/2;
   if( arr[m] == key )
   {  
      index=m;
      break;
   }
   else if( arr[m] < key )l=m+1;
   else r=m-1;
}

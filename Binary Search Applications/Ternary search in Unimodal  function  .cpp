https://en.wikipedia.org/wiki/Ternary_search

/*


int m1 = l + (r-l)/3 ;
int m2 = r - (r-l)/3 ;

if( arr[m1]  <  arr[m2] ) update result = arr[m2]  and search in [m1+1,r]
if( arr[m1]  >  arr[m2] ) update result = arr[m1]  and search in [l,m2-1]
if( arr[m1] ==  arr[m2] ) update result = arr[m1]  and search in [m1+1,m2-1]

we will combine 3rd case in any one of the above two



*/



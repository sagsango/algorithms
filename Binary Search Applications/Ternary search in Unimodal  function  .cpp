https://en.wikipedia.org/wiki/Ternary_search

/*


int m1 = l + (r-l)/3 ;
int m2 = r - (r-l)/3 ;

if( f(m1)  <  f(m2) ) update result = arr[m2]  and search in [m1+1,r]
if( f(m1)  >  f(m2) ) update result = arr[m1]  and search in [l,m2-1]
if( f(m1) ==  f(m2) ) update result = arr[m1]  and search in [m1+1,m2-1]

we will combine 3rd case in any one of the above two



*/


//recursive
int input;
void ternary_search(int l,int r)
{
    if( l > r )return ;
    int m1 = l + (r-l)/3;
    int m2 = r - (r-l)/3;
    
    if( f(m1) < f(m2) )
    {
         input=m2;
         l=m1+1;
    }
    else
    {
         input=m1;
         r=m2-1;
    }
    ternary_search(l,r);
}


//iterative
int l=1,r=n,input;
while( l <= r)
{
    int m1 = l + (r - l)/3;
    int m2 = r - (r - l)/3;
    
   if( f(m1) < f(m2) )
    {
         input=m2;
         l=m1+1;
    }
    else
    {
         input=m1;
         r=m2-1;
    }
}
      

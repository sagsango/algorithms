
we have to search floating points according to given error presition
https://en.wikipedia.org/wiki/Ternary_search
erittocho



//recursive
long double b_search(long double l,long double r,long double key)
{
    if(  (r - l) <= absolutePrecision  )return (r+l)/2;
    
    long double m = (l+r)/2;
    if( key <= m )l=m;
    else r=m;
    b_search(l,r,key);
}


//iterative
long double l=min_value,r=max_value;
while( (r-l) > absolutePrecision )
{
     long double m = (l+r)/2;
     if( key <= m )l=m;
     else r=m;
}

long double result=(l+r)/2;

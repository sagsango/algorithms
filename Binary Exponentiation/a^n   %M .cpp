int power(int a,int n,int M)
{
    if( M ==  1 ) return 0;    // Never Forget
    int r=1;
    while( n )
    {
        if(n&1)r=(r*a)%M;
        a=(a*a)%M;
        n>>=1;
    }
    return r;
 }

int power(int a,int n,int M)
{
    int r=1;
    while( n )
    {
        if(n&1)r=(r*a)%M;
        a=(a*a)%M;
        n>>=1;
    }
    return r;
 }

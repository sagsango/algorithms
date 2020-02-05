https://www.geeksforgeeks.org/segmented-sieve/
https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edb/00000000001707b9


make seive[1 to 1e6];
     store those primes.
     if( n <= 1e6 you will use Naive seive to answer the query)
     if( there are multiple querires  where max n <= 1e12  and [ max N - min N  <= 1e6 ] ){
           make segseive[0..1e6]
               where BASE = MIN_N
               for(auto p:prims)
               {
                    int x = Base + (Base - Base%p); // first divisor of prime in our required range.
                    while( x <= Base + 1e6 )
                    {
                         segseive[x]=1;
                         x+=p;
                    }
               }
     }
          

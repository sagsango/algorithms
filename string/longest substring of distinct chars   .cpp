//given a string find the substring having macimum length which is formed by only distint chars
//https://www.techiedelight.com/find-longest-substring-given-string-containing-distinct-characters/

1.Observation : if sequence of distinct char of length L exist then there should be a sequence of length L-1 having 
               distint char
  Algo        : make prefix sum array of chars in it 
              : for chaecking if the string contatins diff chars then for each char dp[i+length]-dp[i] <= 1
              : use binary search for length 1 to L ( Here L = 26 which leads to another Algo )
              : Instead of binary search find for all posible length substring 1 , 2 ,3 , 4 ......26 . O( n * 26 )
2.Observation : Can we use sliding window ? Ofcource
  Algo        : Make a map [ or counter array of the chars ] of bool 
              : increase left pointer untill there is a char which position is already filled in our map
              : update maxLength
              : and increament the left pointer untill that char has not been removed from our map.
              
Note : Sliding window , Binary search , Rolling Hashing / Polynomial Hashing , have a lot of applications. 

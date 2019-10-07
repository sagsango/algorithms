The number of substrings of string of length n that are cyclic shifts of the another string length m in O((n + m)·log(n)) time

Let n — length of T. Duplicate T two times. Calculate polynomial hashes on strings S and T.
Put all hashes of substring length n in duplicated T and sort. 
Then we need to find substring with length n of string S in sorted vector of hashes T. 
Estimates: O(n log(n)) time and O(n) memory.

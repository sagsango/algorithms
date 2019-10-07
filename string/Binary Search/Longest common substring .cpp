:Searching for the largest common substring of two strings of lengths n and m (n ≥ m) 
in O((n + m·log(n))·log(m)) and O(n·log(m)) time

Firstly we need to calculate polynomial hashes on prefixes of strings A and B. S
uppose that we have found the largest common substring of length len, starting with the position pos of any of the strings. 
Then the common substring is any substring of length len-1, len-2, ..., 1, starting with pos, 
but len + 1 will be not a common substring. We see that the binary search conditions are satisfied. 
Binary search initialization: low = 0,high = N + 1. At each iteration of the search, we add all hashes 
of the line mid of the string A to the vector, sort it, and then go through the hash of the substrings with length
mid of the string B and search them in sorted array of hashes substrings of string A with length mid. 
Estimates of this solutions: O(n log(n)^2) time and O(n) memory.

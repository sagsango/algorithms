 Sorting of all cyclic shifts of a string of length n in lexicographic order in O(n·log(n)2) time
 
 Do not want to build a suffix array? So do I. But sometime after all it will be necessary to build it, 
 but for now we'll duplicate the string S and count the polynomial hash on the prefix. 
 Each cyclic shift will be represented as a number (initial position). Add all the positions to the vector, 
 and then apply a stable merge sort using the substring comparison operator. 
 Estimates: O (n log(n)^2) in time and O(n) from memory.

/*


  Suppose we are given a string s of length n. The Z-function for this string is an array of length n where 
  the i-th element is equal to the greatest number of characters starting from the position i that coincide 
  with the first characters of s.
  
  In other words, z[i] is the length of the longest common prefix between s and the suffix of s starting at i.
  
  The first element of Z-function, z[0], is generally not well defined.
  In this article we will assume it is zero (although it doesn't change anything in the algorithm implementation).
  
  This article presents an algorithm for calculating the Z-function in O(n) time, as well as various of its applications.
  
  For example, here are the values of the Z-function computed for different strings:
  "aaaaa" - [0,4,3,2,1]
  "aaabaab" - [0,2,1,0,2,1,0]
  "abacaba" - [0,0,1,0,3,0,1]
  
  
*/


vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

Finding the lexicographically minimal cyclic shift of a string of length n in O(n·log(n)) time
In this problem we need to use compare by great / less in O(log(n)) time using binary search by length of equal subsequence. 
Duplicate string S and calculate polynomial hashes on prefixes. Each cyclic shift will be represented as a number 
(initial position). Add all the positions to the vector, and then apply a linear algorithm for finding the minimum 
in the array using the substring comparison operator. Estimates: O(n log(n)) time and O(n) memory.



string minimum_cyclic_shift(string s)
{
    int n=s.length();
    s=s+s;
    vector<int>hash=rabin_karp(s);
    vector<int>cycles;
    for(int i=0;i<n;i++)
    {
      cycle.push_back(i);//adding all starting indexes of cyclic shifts
    }
    int min_index=0;
    for(int i=0;i<n;i++)
    {
      min_index=string_comaprison(min_index,i,n);//take starting index of two substring and return index of minimum substring
    }
    return s.substr(min_index,n);
}

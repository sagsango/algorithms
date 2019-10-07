 Finding the number of sub-palindromes of a string of length n in O(n·log(n)) time

Copy given string and reverse order of elements. Calculated polynomial hashes on prefixes original string and reversed string.
Let iterate over centres of palyndromes and use binary search for searching first position not equal symbol.
S — original string, T — reversed string. We need to compare hashes from substrings:
S[i...i+len-1] and T[j...j+len-1], where j = n - i + 1.
Now we calculated number of palyndromes even length. We need to compare hashes from substrings:
S[i+1...i+len] и T[j...j+len-1], где j = n - i + 1.

Estimates: O(nlog(n)) time and O(n) memory 

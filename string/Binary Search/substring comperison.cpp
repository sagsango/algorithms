Comparison by greater / less in O(log(n)) time
Consider two substrings of (possibly) different strings of lengths len1 and len2, (len1 ≤ len2), 
starting in the positions i and j respectively. Note that the ratio greater / less is determined 
by the first non-equal symbol in these substrings, and before this position strings are equal. 
Thus, we need to find the position of the first non-equal symbol by the binary search method, 
and then compare the found symbols. By comparing substrings to equality in O(1) time, we can solve 
the problem of comparing substrings by greater / less in O(log(len1)) time:

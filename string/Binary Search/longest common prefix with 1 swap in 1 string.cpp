 Largest common prefix of two strings length n with swapping two chars in one of them in O(n·log(n)) time
 
 Note that to improve the result, you must necessarily swap the element in the position of the first difference of the lines. 
 After finding this position, we try to change this symbol in turn with all the characters after it and find the length of 
 the largest common prefix by binary search. How can we recalculate a polynomial hash on the prefix of length len after 
 changing the characters in the positions i and j? Three cases:

The segment [0, len) does not contain i: the answer is pref(len)
The segment [0, len) does not contain j: the answer is pref(i) + a[j] * p^i + pref(len)-pref(i + 1)
Otherwise: pref(i) + a[j] * p^i + pref(j)-pref(i+1) + a[i] * p^j + pref(len)-pref(j + 1)

Estimates: O(n log(n)) time and O(n) memory

Search the substring

To avoid confusion, we call t the string of text, and p the pattern. 
The problem is: find all occurrences of the pattern pinside the text t.

To solve this problem, we create a new string s=p+⋄+t, that is,
we apply string concatenation to p and t but we also put a separator character ⋄ in the middle 
(we'll choose ⋄ so that it will certainly not be present anywhere in the strings p or t).

Compute the Z-function for s. Then, for any i in the interval [0;length(t)−1], we will consider the
corresponding value k=z[i+length(p)+1]. If k is equal to length(p) then we know there is one occurrence
of p in the i-th position of t, otherwise there is no occurrence of p in the i-th position of t.

The running time (and memory consumption) is O(length(t)+length(p)).

https://blog.anudeep2011.com/mos-algorithm/
https://codeforces.com/blog/entry/43230
https://www.hackerearth.com/practice/notes/mos-algorithm/

We must be able to write add and remove function then only Mo's is applicable
Problems
1.Count total unique elements int L,R queries[DQURY SPOJ] : O(q*sqrt(n))
2.Count total elemnts having frequency >=3 in L,R Queire  : O(q*sqrt(n))
3.Find Kth maimum element in L,R Quries                   : O(q*sqrt(n)*log(n)) [We have to use set here ]
4.Count total distinct clr in subtree [extend 1]


General Solution :
add(position):
  count[array[position]]++
  if count[array[position]] == 3:
    answer++

remove(position):
  count[array[position]]--
  if count[array[position]] == 2:
    answer--

currentL = 0
currentR = 0
answer = 0
count[] = 0
for each query:
  // currentL should go to L, currentR should go to R
  while currentL &amp;lt; L:
    remove(currentL)
    currentL++
  while currentL &amp;gt; L:
    add(currentL)
    currentL--
  while currentR &amp;lt; R:
    add(currentR)
    currentR++
  while currentR &amp;gt; R:
    remove(currentR)
    currentR--
  output answer


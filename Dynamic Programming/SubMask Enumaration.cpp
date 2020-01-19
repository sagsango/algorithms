Blog    : https://codeforces.com/blog/entry/45930
        : https://cp-algorithms.com/algebra/all-submasks.html
Problem : https://atcoder.jp/contests/dp/submissions/9636947



The easiest way I know is:

for(int submask = mask; submask; submask = (submask - 1) & mask) {
         // do something
}
If you want 0 as a submask:

for(int submask = mask; ; submask = (submask - 1) & mask) {
         // do something

        if(submask == 0) break;
}
You have to know if we want to do something with the submasks of every mask till 2^N the time complexity will be O(3^N) not O(4^N).

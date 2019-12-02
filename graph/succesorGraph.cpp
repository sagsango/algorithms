source         : Competitive Programmer’s Handbook Antti Laaksonen Draft July 3, 2018 [ page 154 ]

Sucessor Graph : Every vertex has out degree 1
               : Maximum 1 cycle exist in such graph
               : Real life graph
               : we store sucessor[u][0]=v     : sucessor[u][i] => sucessor of u at 2^i distance
                 for(int u=1;u<=n;u++)
                    for(int i=1;i<=l;i++)
                        sucessor[u][i] = sucessor[  sucessor[u][i-1]   ][i-1];
               : Now we can find sucessor at 2^i th level log(k) steps
               : finding the cycle lenth also in log(k) steps.
               :      O---------->O---------->O
                      ^                       |
                      |                       v
                      O<----------O<----------O
               :      O---------->O---------->O---------->O

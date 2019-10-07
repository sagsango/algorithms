it is modification of prefix function

let's pi[s.length()-1]=l1 =>l1 is also suffix which is prifix
      pi[l1-1]=l2         =>l2 is also suffix which is prifix
      pi[l2-1]=l3         =>l3 is also suffix which is prifix
      .
      .
      .
      pi[lm-1]=0          =>end
      
      
vector<int> pxifix_which_are_also_suffix(string s)
         {
              vector<int>pi=KMP(s);
              vector<int>ans;
              int l=s.length();
              l=pi[l-1];
              while(l)
              {
                ans.push_back(l);
                l=pi[l-1];
              }
              return ans;
         }

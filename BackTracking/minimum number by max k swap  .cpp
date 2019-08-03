//https://www.techiedelight.com/find-minimum-number-possible-k-swaps/
void minimim_numer(string s,int k)
{
   ans=min(ans,s);
   if(k)
   {
       for(int i=0;i<s.length();i++)
       {
           for(int j=i+1;j<s.length();j++)
           {
                if( s[i] > s[j] )
                {
                    swap(s[i],s[j]);
                    minimum_number(s,k-1);
                    swap(s[i],s[j]);
                }
            }
       }
   }
}

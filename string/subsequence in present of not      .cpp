//given a string and a pattern , find if patten is present as subsequence in the string or not ?
bool subsequence_search(string text,string pattern)
{
     int p=0;
     for(int t=0;t<text.length();t++)
     {
         if(p < pattern.length() && text[t]==pattern[p])p++;
     }
     return p==pattern.length();
}

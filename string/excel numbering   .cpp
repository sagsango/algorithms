//https://www.techiedelight.com/convert-given-number-corresponding-excel-column-name/
 A = 1
 B = 2
 Z = 26
 AA = 27
 AE = 31
 ALF = 994
 
int string_to_number(string s)
{
   int num=0;
   for(int i=0;i<s.length;i++)
   {
       num = num * 26 + (s[i]-'A' + 1);
   }
   return num;
}


string num_to_string(int num )
{
   string s="";
   while(num)
   {
      char ch = ( num - 1 ) % 26 + 'A';
      s = ch + s;
      num=(num-1)/26;
   }
   return s;
}

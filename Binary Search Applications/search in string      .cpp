  //https://codeforces.com/blog/entry/60445
  //serach for first index which is not eqal in given two strings
  //here we are using string comperision 
  //we can accelare it useing heasing of the prifixes
  //using first diff index we can compare the strings 

  
        /* Binanary Lifting can be used here */
        string s1="abcdefghijklmnopadffawe";
	string s2="abcdefghijklmnopadffawe";
	int r=min(s1.length(),s2.length())+1;
	int l=0;
	while( l + 1 < r )
	{
		int m=l+(r-l)/2;
		if(s1.substr(0,m)==s2.substr(0,m))
		{
			l=m;
		}
		else r=m;
	}
	cout<<l<<" "<<r<<endl;// r = first index which is diff.
	
	

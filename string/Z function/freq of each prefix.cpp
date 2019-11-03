O(n + n)
O(n) :z_function
O(n) :freq_of_each_prefix

vector<int> freq_of_each_prefix(string s)
{ 
  vector<int>z=z_function(s);
	z[0]=n;//in our discussion we had taken z[0]=0
	/**
	*z[0]=n 
	*will leads to add 1 to all originoal prifix
	**/
	vector<int>freq(n+2);
	for(int i=0;i<n;i++)
	if(z[i])
	{
		freq[z[i]+1]-=1;
		freq[1]+=1;
	}
	for(int i=1;i<=n;i++)
	freq[i]+=freq[i-1];
  return freq;
}
/**
* freq[i] : frequency of the prifix having length i
**/

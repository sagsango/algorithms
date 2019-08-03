//find maximum occouring substring in the given set of substrings
//https://www.techiedelight.com/find-maximum-occurring-word-given-set-strings/
#include<bits/stdc++.h>
using namespace std;


set<string>st;
const int maxchild=26;
class tri{
	int freq;
	tri*child[maxchild];
	public:
	tri()
	{
		this->freq=0;
		for(int i=0;i<maxchild;i++)
		this->child[i]=NULL;
	}
	void insert(string s)
	{
		tri*ptr=this;
		for(int i=0;i<(int)s.length();i++)
		{
			if(ptr->child[s[i]-'a']==NULL)ptr->child[s[i]-'a']=new tri;
			ptr=ptr->child[s[i]-'a'];
			ptr->freq++;
		}
	}
	int dfs1(tri*ptr)
	{
		int maxfreq=0;
		for(int i=0;i<maxchild;i++)
		if(ptr->child[i])maxfreq=max(maxfreq,dfs1(ptr->child[i]));
		return max(maxfreq,ptr->freq);
	}
	void dfs2(tri*ptr,int maxfreq,string s,char par)
	{
		if(ptr->freq==maxfreq)s+=par;
		else
		{
			if(s.length())st.insert(s);
			s="";
		}
		bool isleaf=true;
		for(int i=0;i<maxchild;i++)
		if(ptr->child[i])
		{
			dfs2(ptr->child[i],maxfreq,s,i+'a');
			isleaf=false;
		}
		if(isleaf && s.length())st.insert(s);
	}
	void max_freq_word()
	{
		int maxfreq=0;
		for(int i=0;i<maxchild;i++)
		{
			if(this->child[i])maxfreq=max(maxfreq,dfs1(this->child[i]));
		}
		cout<<maxfreq<<endl;
		for(int i=0;i<maxchild;i++)
		{
			if(this->child[i])dfs2(this->child[i],maxfreq,"",i+'a');
		}
		
	}
		
};

int main()
{
	tri T;
	//let these be the all prifixex of the given strings
	//our set will contain the max freq occouring world ["substring"]
	T.insert("a");
	T.insert("hello");
	T.insert("helloyou");
	T.insert("helloworld");
	T.insert("hellogoogle");
	
	T.insert("google");
	T.insert("google");
	T.insert("google");
	T.insert("google");
	
	T.max_freq_word();
	for(auto it:st)
	cout<<it<<" ";
	cout<<endl;
	
}

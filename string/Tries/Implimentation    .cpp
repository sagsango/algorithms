//https://www.techiedelight.com/cpp-implementation-trie-data-structure/
//Here delete operation is inefficient but somehow it is manage to fullfill the purpose

#include<bits/stdc++.h>
using namespace std;

const int maxchild=26;
class tri{
	bool leaf;
	tri*child[maxchild];
	public:
	tri()
	{
		this->leaf=false;
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
		}
		ptr->leaf=true;
	}
	bool find(string s)
	{
		tri*ptr=this;
		if(ptr==NULL)return false;
		for(int i=0;i<(int)s.length();i++)
		{
			if(ptr->child[s[i]-'a']==NULL)return false;
			ptr=ptr->child[s[i]-'a'];
		}
		return ptr->leaf;
	}		
	void erase(string s)
	{
		tri*ptr=this;
		if(ptr==NULL)return;
		for(int i=0;i<(int)s.length();i++)
		{
			if(ptr->child[s[i]-'a'])ptr=ptr->child[s[i]-'a'];
			else return;
		}
		ptr->leaf=false;
	}
	void dfs(tri*ptr,string s)
	{
		if(ptr->leaf)
		cout<<s<<endl;
		for(int i=0;i<(int)maxchild;i++)
		if( ptr->child[i] )
		{
			dfs(ptr->child[i],s+(char)(i+'a'));
		}
	
	}
	void display()
	{
		dfs(this,"");
	}
		
};

int main()
{
	tri T;
	T.insert("hello");
	T.insert("helloyou");
	T.insert("helloworld");
	T.insert("hellogoogle");
	
	cout<<T.find("hello")<<endl;
	cout<<T.find("helloyou")<<endl;
	cout<<T.find("helloworld")<<endl;
	cout<<T.find("hellogoogle")<<endl;
	
	cout<<T.find("hero")<<endl;
	cout<<T.find("halwa")<<endl;
	
	T.display();//display according to dictionary
	
    T.erase("hello");
	T.erase("helloyou");
	
	cout<<T.find("hello")<<endl;
	cout<<T.find("helloyou")<<endl;
	cout<<T.find("helloworld")<<endl;
	cout<<T.find("hellogoogle")<<endl;
	
	T.display();//display according to dictionary
}


/*************************************************************************************************************************/
const int N=26;
class tri{
	public:
	int val;
	tri*c[N];
	tri()
	{ 
		val=0;
	    for(int i=0;i<N;i++){
		   this->c[i]=NULL;
	    }
	}
};
void insert(tri * head,string s){
	for(int i=0;i<s.length();i++){
		if(head->c[s[i]-'a']==NULL)head->c[s[i]-'a']=new tri;
		head=head->c[s[i]-'a'];
		head->val++;
	}
}
int query(tri * head,string s){
	for(int i=0;i<s.length();i++){
		if(head->c[s[i]-'a']!=NULL)head=head->c[s[i]-'a'];
		else return 0;
	}
	return head->val;
}

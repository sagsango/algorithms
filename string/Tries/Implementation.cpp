// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3


// TODO: delete memory which you have allocated
#include<bits/stdc++.h>
using namespace std;
struct tri{
    tri * child[26];
    int cnt;
};
tri *head;
int n,k;
void insert(string s)
{
    tri * curr = head;
    for(size_t i=0;i<s.length();i++)
    {
        if( !curr->child[s[i]-'A'])curr->child[s[i]-'A']=new tri();
        curr=curr->child[s[i]-'A'];
        curr->cnt++;
    }
}
int query(tri*curr)
{
    int ans=curr->cnt/k;
    for(int i=0;i<26;i++)
    {
        if(curr->child[i])
        {
            ans+=query(curr->child[i]);
            
        }
    }
    return ans;
}

int main()
{
    int T;cin>>T;
    for(int t=1;t<=T;t++)
    {
        head = new tri();
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            string s;cin>>s;
            insert(s);
        }
        cout <<"Case #"<<t<<": "<< query(head) << endl;
    }
}

Source       :   https://cp-algorithms.com/string/suffix-tree-ukkonen.html
Problem      :   https://www.spoj.com/problems/SUB_PROB/
             :   Build    :O(T*log(types_of_char))
             :   Search   :O(pattern.length) < worst case , but in practice it will be very less >



string s;
const int MAXN=1e6;
int n;

struct node {
    int l, r, par, link;
    map<char,int> next;

    node (int l=0, int r=0, int par=-1)
        : l(l), r(r), par(par), link(-1) {}
    int len()  {  return r - l;  }
    int &get (char c) {
        if (!next.count(c))  next[c] = -1;
        return next[c];
    }
};
vector<node>t;
int sz;

struct state {
    int v, pos;
    state (int v, int pos) : v(v), pos(pos)  {}
};
state ptr (0, 0);

state go (state st, int l, int r) {
    while (l < r)
        if (st.pos == t[st.v].len()) {
            st = state (t[st.v].get( s[l] ), 0);
            if (st.v == -1)  return st;
        }
        else {
            if (s[ t[st.v].l + st.pos ] != s[l])
                return state (-1, -1);
            if (r-l < t[st.v].len() - st.pos)
                return state (st.v, st.pos + r-l);
            l += t[st.v].len() - st.pos;
            st.pos = t[st.v].len();
        }
    return st;
}

int split (state st) {
    if (st.pos == t[st.v].len())
        return st.v;
    if (st.pos == 0)
        return t[st.v].par;
    node v = t[st.v];
    int id = sz++;
    t[id] = node (v.l, v.l+st.pos, v.par);
    t[v.par].get( s[v.l] ) = id;
    t[id].get( s[v.l+st.pos] ) = st.v;
    t[st.v].par = id;
    t[st.v].l += st.pos;
    return id;
}

int get_link (int v) {
    if (t[v].link != -1)  return t[v].link;
    if (t[v].par == -1)  return 0;
    int to = get_link (t[v].par);
    return t[v].link = split (go (state(to,t[to].len()), t[v].l + (t[v].par==0), t[v].r));
}

void tree_extend (int pos) {
    for(;;) {
        state nptr = go (ptr, pos, pos+1);
        if (nptr.v != -1) {
            ptr = nptr;
            return;
        }

        int mid = split (ptr);
        int leaf = sz++;
        t[leaf] = node (pos, n, mid);
        t[mid].get( s[pos] ) = leaf;

        ptr.v = get_link (mid);
        ptr.pos = t[ptr.v].len();
        if (!mid)  break;
    }
}

void build_tree() {
    sz = 1;
    for (int i=0; i<n; ++i)
        tree_extend (i);
}

void dfs(int v,string path)
{
	path+=s.substr(t[v].l,t[v].r-t[v].l);
	for(auto u:t[v].next)
	{
		dfs(u.second,path);
	}
	if(t[v].next.size()==0)
	cout<<"Ola:"<<path<<endl;
}

bool search(int v,string p,int I)
{
	for(int i=t[v].l;i<t[v].r && I<p.length();i++,I++)
	if(s[i]!=p[I])return false;
	if( I == p.length() )return true;
	if( t[v].next.find(p[I])!=t[v].next.end() )return search(t[v].next[p[I]],p,I);
	return false;
}
		
	
int32_t main()
{
	IOS
	int q=1;
	while(q--)
	{
		t=vector<node>(MAXN+100);
		cin>>s;
		n=s.length();
	    build_tree();
	
	
	/*
	dfs(0,"");
	for(int i=0;i<sz;i++)
	{
		cout<<t[i].l<<" "<<t[i].r<<" "<<t[i].par<<" "<<t[i].link<<" "<<endl;
		for(auto it:t[i].next)
		{
			cout<<it.first<<" "<<it.second<<"|";
		}
		cout<<endl;
	}
	*/
	    int x;cin>>x;
	    while(x--)
	    {
	        string p;
	        cin>>p;
            cout<<(search(0,p,0)?"Y":"N")<<endl;
		}
	}
	
	
}
 

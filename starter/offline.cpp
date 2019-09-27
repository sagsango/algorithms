/*-------------------------------------------Problem Observation-------------------------------------------------------------------
 * 
 *   n + n/2 + n/3 + n/4 + n/5 + ........n/n =>n*log(n)
 *   n + n/3 + n/5 + n/7 + n/11+.............=>n*log(log(n))
 *   1 , 3 , 5 , 7 , 9 , 11 , 13 , 15 .......=>gcd( a[i] , a[i+1] , a[i+2] )=1;
 *   2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 ......=>upto 1e6 max diff a[i], a[i+1] ~ 150
 *   N ~ 1e9 , have maximum 30 unique prime factors 2^30 ~ 1e9 , even much less than that
 *   Every even integer greater than 2 can be expressed as the sum of two primes.[1]  : https://en.wikipedia.org/wiki/Goldbach%27s_conjecture
 *   printf("%03d\n",k);
 *   scanf("%d/%d/%d",&d,&m,&y); 
*Prime Number List http://compoasso.free.fr/primelistweb/page/prime/liste_online_en.php
29	31	37	41	43
47	53	59	61	67	71	73	79	83	89

1000000007	1000000009	1000000021	1000000033	1000000087	1000000093
1000000097	1000000103	1000000123	1000000181	1000000207	1000000223	1000000241	1000000271	1000000289	1000000297
 *  ---------------------------------------------------------------------------------------------------------------------------------
 */
 
 /*---------------------------Bit --------------------------------------------------------------------------------------------------
  * int lowbit(int n){return n&(-n);}
  * toggle least set bit  n=n&(n-1); // becomes zero if power of 2
  * __builtin_popcount(x); //return number of 1 in binary representation of x
  * builtin_ctz (count trailing zeros)
  * builtin_clz (count leading zeros)
  */
 



/*----------------------------------------Miscillinious------------------------------------------------------------------------------



  *s.rbegin()=*(--s.end())
   sort(v.begin(),v.end()) = negative of v[i] , sort(v.begin(),v.end())

    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);

	    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

         s.erase(itl,itr);// delete the elements from itl to itr-1
		 s.erase(it,it.end()) delete all emenets from it to end
		 
		 cout << fixed << setprecision(10) << pi <<endl;

  __builtin_popcount(x); //return number of 1 in binary representation of x
  builtin_ctz (count trailing zeros)
  builtin_clz (count leading zeros)
 
memset(array, 0, sizeof(array[0][0]) * m * n);
memset(array, 0, sizeof(array))

 *s.rbegin()=*(--s.end())
  sort(v.rbegin(),v.rend()) = negative of v[i] , sort(v.begin(),v.end());
  sort(v.begin()+l_index,v.begin()+r_index+1);

 for(auto &it:v)cin>>it; 
 
set_union (v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) //v1,v2 are sorted and v3 is new container
set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) //v1,v2 are sorted and v3 is new container
set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) //v1,v2 are sorted and v3 is new container
set_symmetric_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) //v1,v2 are sorted and v3 is new container



struct marks{
	int m1,m2;
};
bool compare(marks a,marks b)
{
	if( a.m1 > b.m1);
}
sort(a.begin(),a.end(),compare);




class compare{
	public:
    bool operator ()( ii x ,ii y)
    {
		if( x.first != y.first )return x.first > y.first;
		else return x.second < y.second;
    }
};
priority_queue< ii , vector<ii> , compare > pq;



sort(R.begin(),R.end(),[](const marks&a,const marks&b){
		return a.m1c > b.m1;});
	
	
 merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin(),compare);   [    O(n) ]
  
 
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
  
------------------------------------------------------------------------------------------------------------------------------------*/





/*---------------------------------------------------Vector STL/Function----------------------------------------------------------
 * auto it=equal_range(A.begin(),A.end(),key) it.first=lower_bound_pointer it.second =upper_bound_pointer
 * 
 * vlli v2(v.begin(),v.begin()+size);
 * vlli v2(v)
 * sort(v.begin(),v.end())
 * reverse(v.begin(),v.end())
 * (bool) binary_search(v.begin(),v.end(),key)
 * (iterator) lower_bound(v.begin(),v.end(),key);
 * (iterator) upper_bound(v.bein(),v.end(),key);
 * (iterator) v.lower_bound(key);
 * (iterator) v.upper_bound(key);
 * v.erase(v.begin()+i)
 * v.erase(unique(v.begin(),v.end()),v.end())
 * v.erase(v.begin()+i,v.end()-j)  ||    v.erase(v.begin(),v.begin()+j)
 * v.erase(remove(v.begin(),v.end(),data),v.end())  //erase  all the 'data' from the vector
 * v.erase(v.begin(),v.upper_bound(data)) //all element lower or equal to data are deleted
 * (bool)next_premutation(v.begin(),v.end())
 * (bool)prev_premutation(v.begin(),v.end())
 * v.insert(it,data) || v.insert(i,data)  
 * v.insert(it,no_of_times,data) || v.insert(i,no_of_times,data)
 * 
 * v.push_back(data)
 * v.pop_back(data)
 * (data) v.front() 
 * (data) v.back() 
 * (data) v[index] 
 * (iterator) v.begin() 
 * (iterator) v.end()
 * (lli) max_e(v) ,(lli)min_e(v) ,lli fmax_i(v) ,lli lmax_i(v) ,lli fmin_i(v) ,lli lmin_i(v)
 * vector<vector<int>>v(r,vector<int>(c));
 *--------------------------------------------------------------------------------------------------------------------------------------*/ 
 
 
 
 
 /*--------------------------------------------------Vector of pairs----------------------------------------------------------------
  * vector<pair<key_type,data type>> vp
  * vp.push_back(make_pair(key,data))
  * 
  * sort by key/first element (then data/second)
  * sort(vp.begin(),vp.end()) 
  * 
  * sort by sec element(only by sec)
  * bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
  * { 
  *       return (a.second < b.second); 
  * }
  * sort(vp.begin(),vp.end(),sortbysec) 
  * 
  * (data) vp[i].first ,(data) vp[i].second ,
  *-----------------------------------------------------------------------------------------------------------------------------------*/
  
  
  
  
  /*----------------------------------------------String Manupulation -------------------------------------------------------------
   * string str2(str1)
   * string str2=str1.substr(index_1)   //It will give whole string from index index_1
   * string str2(str1.begin(),str1.begin()+length)
   * string s=str.substr(starting_index,length) 
   * 
   * transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
   * transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
   * 
   * int (index) str.find("substr")     //first starting index of substr 
   * s.erase(s.begin()+index)
   * s.erase(s.begin()+index,s.end()-index)  ||  s.erase(s.begin()+index(),s.begin()+index)
   * s.erase(unique(s.begin(),s.end()),s.end())  ::adjecent will not be same
   * sort(s.begin(),s.end());
   * reverse(s.begin(),s.end())
   * #reverse(s.begin()+i,s.begin()+j+1);  //from index i to j  ,NOT SAME AS VECTOR
   * str.erase(remove(str.begin(),str.end(),'ch'),str.end()); //erase all the 'ch' from string
   * str1.insert(6, str2); 
   * str.insert(it,'ch')  ||  str.insert(i,'ch')
   * str.insert(it,no_of_times,'ch') ||  str.insert(i,no_of_times,'ch')
   * auto c=count(str.begin(),str.end(),'char') //count all char in the given string
   * 
   * getline(cin,string_name) cin.egnore();//add this before getline()
   * stringstream(string_name)>>type1_>>type2_>>type3_.........>>typeN_;
   * stringstream STREAM_name(string_name)
   * STREAM_name>>type1_>>type2_>>type3>>type4_>>type5_;
   * s=to_string(2018)
   *-----------------------------------------------------------------------------------------------------------------------------------*/
   
   
   
   
 /* -------------------------------------------------STACK----------------------------------------------------------------------------
  * stack<data_type>s
  * push()              :s.push(data)           :O(1)
  * pop()               :s.pop()                :O(1)
  * top()               :s.top()                :O(1)
  * empty()             :s.empty()              :O(1)
  * size()              :s.size()               :O(1)
  *------------------------------------------------------------------------------------------------------------------------------------*/
  
  
  
 /* -------------------------------------------------QUEUE------------------------------------------------------------------------------         
  * queue<data_type>q    
  * 
  * push()               :q.push(data)          :O(1)
  * pop()                :q.pop()               :O(1)
  * front()              :q.front()             :O(1)
  * back()               :q.back()              :O(1)
  * empty()              :q.empty()             :O(1)
  * size()               :q.size()              :O(1)
  *--------------------------------------------------------------------------------------------------------------------------------------*/
  
  
  
  
 /*------------------------------------------ priority_queue(default MAX HEAP)-------------------------------
  * priority_queue<data_type>pq
  * priority_queue <int, vector<int>, greater<int> > pq; 
  * push()               :pq.push(data)         :O(log(n))
  * pop()                :pq.pop()              :O(long(n))
  * top()                :pq.top()              :O(1)
  * size()               :pq.size()             :O(1)
  * empty()              :pq.empty()            :O(1)
  *----------------------------------------------------------------------------------------------------------*/



 /*-------------------------------SET:Element in sorted order(increasing) and UNIQUE*****----------------------
 * declaration     :set<lli>s
 * declaration     :set<int,greater<int>>s
 * insertion       :s.insert(data)  //insert if it is not present     :O(log(n))             
 * size            :s.size()                                          :O(1) 
 * find            :auto it=s.find(data) //if it!=s.end -> data found :O(log(n))
 * s.lower_bound() :it=s.lower_bound(data)
 * s.upper_bound() :it=s.upper_bound(data)
 * lower_bound()   :it=lower_bound(s.begin(),s.end(),data)
 * upper_bound()   :it=upper_bound(s.begin(),s.end(),data)
 * erase()         :erase(it)
 * erase()         :s.erase(it1,it2)
 * s.erase()       :s.erase(data)
 * loop            :for(auto it=s.begin();it!=s.end();it++)
 *-----------------------------------------------------------------------------------------------------------------*/
 
 
 
 /*------------------------------------------MAP:Elemnet r SORTED,unlike set we insert (key and data/frequency)--------------------------
 * declaration   :map<key_type,data_type>m
 * declaration   :map<int,string,greater<int>>M
 * insert        :m.insert(make_pair(key,data));                     :O(log(n))
 *               :m.insert(pair<type,type>(key,data))
 * find          :auto it=m.find(key) //if(it!=m.end)it->first=key   :O(log(n))
 * []            :m[key]++      //data=data+1 ,at that key           :O(log(n))
 * size          :m.size()                                           :O(1)
 * m.lower_bound :it=m.lower_bound(key)
 * m.upper_bound :it=m.lower_bound(key)
 * lower_bound   :it=lower_bound(m.begin(),m.end(),key)
 * upper_bound   :it=upper_bound(m.begin(),m.end(),key)
 * erase()       :s.erase(it)
 *               :s.erase(it1,it2)
 *               :s.erase(key)
 * loop          :for(auto it=m.begin();it!=s.end();it++)
 * 
 * it->first ,it->second ,
 *-------------------------------------------------------------------------------------------------------------------*/
 
 
 
 
 /*------------------------------------------Unorderd SET  :Elements in unsorted order(used hasing to store data)------------------------------------
 * declaration   :unordered_set<lli>s        
 * unordered_set<int,greater<int>>s;
 * insertion     :s.insert(data)                                     :O(1)
 * size          :s.size()                                           :O(1)
 * find          :auto it=s.find(data)//if it!=s.end ->data found    :O(1)     ||  worst case O(n)
 * loop          :for(auto it=s.begin();it!=s.end();it++)
 *---------------------------------------------------------------------------------------------------------------------------------------------------*/



 /*-------------------------------------Unordered MAP:Element r UNSORTED,unlike unordered set we insert (key and data)||----------------------------- 
 * declaration   :unorderd_map<key_type,data_type> m               
 * unorderded_map<int,string,greater<int>>M
 * insert        :insert(make_pair(key,data))                        :O(1) 
 * find          :auto it=m.find(key) //if (it!=m.end)it->first=key  :O(1)
 * []            :m[key]++      //data=data+1 ,at that key           :O(1)
 * size          :m.size()                                           :O(1)
 * loop          :for(auto it=s.begin();it!=s.end();it++)
 *--------------------------------------------------------------------------------------------------------------------------------------------------*/
 
 
 
 /*--------------------------------------- mutiset:similar to set but have duplicate element--------------------------------------------------------
  * multiset<data_type>ms        multiset<int,greater<int>>ms
  * insert()               :ms.insert(data)         :O(log(n))
  * find()                 :auto it=ms.find(data)   :O(long(n))
  * size()                 :ms.size()               :O(1)
  *-------------------------------------------------------------------------------------------------------------------------------------------------*/
  
  
  
  /* --------------------------multimap:similar to MAP but can have duplicate keys  :search O(logn):insert O(logn):delete O(logn)------------------  
   * mulimap<key_type,data_type>mm             multimap<int,string,greater<int>>mm
   * mm.insert(pair<key_type,data_type>(key,data))        :O(long(n))
   * multimap<key_type,data_type> mm2(mm.begin(),mm.end())  
   * find()                :it=mm.find(key)  //first it   :O(long(n))
   * mm.lower_bound(key)->second //data      mm.lower_bound(key)=it  1st elemet having the key  or mm.end()
   * mm.upper_bound(key)->second //data      mm.upper_bound(key)=it  1st element just after the key or mm.end()
   * mm.erase(key)         :erase all element of the key value
   * mm.erase(mm.begin(),mm.find(key))    :remove all having(key) less than the given key
   * mm.size()                                             :O(1)
   * for(auto it=mm.begin();it!=mm.end;it++)     :traversal
   *----------------------------------------------------------------------------------------------------------------------------------------------*/
   
   
   
   /*-------------------------------------------------------------LIST(doubly linked list)--------------------------------------------------------------------------------
    * advantage: quick insertion and deletion ,bigger size
    * disadvantage: slow traversal 
    * list<data_type>l
    * (data) l.front()
    * (data) l.back()
    * l.push_front(data)
    * l.push_back(data)
    * l.pop_front()
    * l.pop_back()
    * (it) l.begin()
    * (it) l.end()
    * (bool) l.empty()
    * ---------------------------------------------------------------------------------------------------------------------------------*/
  
  
/*-------------------------------------------------------------Red Black tree------------------------------------------------------------
ordered_set<int>  s;
	s.insert(1); 
	s.insert(3);
	cout << s.order_of_key(2) << endl; // tnumber of items in a set that are strictly smaller than k=2           log(no of elements)
	cout << *s.find_by_order(0) << endl; // returns an iterator to the k=0 [ or index ] largest element (counting from zero), log(no of elements)
-----------------------------------------------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------Rough Section--------------------------------------------------------------------
sort_by_length
auto SortByLength=[](const auto &a,const auto &b){return a.size()<b.size();}; //called lemda expression
sort(v.begin(),v.end(),SortByLength);
stable_sort(v.begin(),v.end(),SortByLength); //maintain order (stability) as possible

 
(int)distance(it1,it2)
rotate(v.begin(),v.begin()+2,v.end()); {(1,2,3,4,5)->(3,4,5,1,2)}
any_of ,all_of,none_of (v.begin(),v.end(),____); ____=predicate or lemda {isdigit,is_even}


------------------------------------------------------------------------------------------------------------------------------------------*/



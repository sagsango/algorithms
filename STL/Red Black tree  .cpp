#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
 
A red-black tree is a kind of BST that after each query, BST will be balanced in such a way that it's height remains O(log(n)).
C++ already has a red-black tree inside, set .
You can read about them in C++ references.

        Average     Worst case

Space   O(n)        O(n) 

Search  O(log n)    O(log n)

Insert  O(log n)    O(log n)

Delete  O(log n)    O(log n)

*/

int main(){
	ordered_set<int>  s;
	s.insert(1); 
	s.insert(3);
	cout << s.order_of_key(2) << endl; // tnumber of items in a set that are strictly smaller than k=2           log(no of elements)
	cout << *s.find_by_order(0) << endl; // returns an iterator to the k=0 largest element (counting from zero), log(no of elements)
}

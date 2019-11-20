https://www.geeksforgeeks.org/count-numbers-in-given-range-such-that-sum-of-even-digits-is-greater-than-sum-of-odd-digits/

Count numbers in given range such that sum of even digits is greater than sum of odd digits

// C++ code to count number in the range 
// having the sum of even digits greater 
// than the sum of odd digits 
#include <bits/stdc++.h> 

// as the number can be up to 10^18 
#define int long long 

using namespace std; 

vector<int> v; 

int dp[18][180][180][2]; 

int memo(int index, int evenSum, 
					int oddSum, int tight) 
{ 
	// Base Case 

	if (index == v.size()) { 
		// check if condition satisfied or not 
		if (evenSum > oddSum) 
			return 1; 
		else
			return 0; 
	} 

	// If this result is already computed 
	// simply return it 
	if (dp[index][evenSum][oddSum][tight] != -1) 
		return dp[index][evenSum][oddSum][tight]; 

	// Maximum limit upto which we can place 
	// digit. If tight is 0, means number has 
	// already become smaller so we can place 
	// any digit, otherwise num[pos] 

	int limit = (tight) ? v[index] : 9; 

	int ans = 0; 

	for (int d = 0; d <= limit; d++) { 
		int currTight = 0; 

		if (d == v[index]) 
			currTight = tight; 

		// if current digit is odd 
		if (d % 2 != 0) 
			ans += memo(index + 1, evenSum, 
						oddSum + d, currTight); 

		// if current digit is even 
		else
			ans += memo(index + 1, evenSum + d, 
						oddSum, currTight); 
	} 

	dp[index][evenSum][oddSum][tight] = ans; 
	return ans; 
} 
// Function to convert n into its 
// digit vector and uses memo() function 
// to return the required count 
int CountNum(int n) 
{ 
	v.clear(); 
	while (n) { 
		v.push_back(n % 10); 
		n = n / 10; 
	} 

	reverse(v.begin(), v.end()); 

	// Initialize DP 
	memset(dp, -1, sizeof(dp)); 
	return memo(0, 0, 0, 1); 
} 

// Driver Code 

int32_t main() 
{ 
	int L, R; 
	L = 2; 
	R = 10; 
	cout << CountNum(R) - CountNum(L - 1) << "\n"; 
	return 0; 
} 

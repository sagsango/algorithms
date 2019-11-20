https://www.geeksforgeeks.org/count-of-numbers-in-a-range-divisible-by-m-and-having-digit-d-in-even-positions/

Given a range represented by two positive integers l and r and two integers d and m.
Find the count of numbers lying in the range which is divisible by m and have digit d
at even positions of the number. (i.e. digit d should not occur on odd position). 


// CPP Program to find the count of 
// numbers in a range divisible by m 
// having digit d at even positions 
#include <bits/stdc++.h> 
using namespace std; 

const int M = 20; 

// states - position, rem, tight 
int dp[M][M][2]; 

// d is required digit and number should 
// be divisible by m 
int d, m; 

// This function returns the count of 
// required numbers from 0 to num 
int count(int pos, int rem, int tight, 
		vector<int> num) 
{ 
	// Last position 
	if (pos == num.size()) { 
		if (rem == 0) 
			return 1; 
		return 0; 
	} 

	// If this result is already computed 
	// simply return it 
	if (dp[pos][rem][tight] != -1) 
		return dp[pos][rem][tight]; 

	// If the current position is even, place 
	// digit d, but since we have considered 
	// 0-indexing, check for odd positions 
	if (pos % 2) { 
		if (tight == 0 && d > num[pos]) 
			return 0; 

		int currTight = tight; 

		// At this position, number becomes 
		// smaller 
		if (d < num[pos]) 
			currTight = 1; 

		int res = count(pos + 1, (10 * rem + d) 
									% m, 
						currTight, num); 
		return dp[pos][rem][tight] = res; 
	} 

	int ans = 0; 

	// Maximum limit upto which we can place 
	// digit. If tight is 1, means number has 
	// already become smaller so we can place 
	// any digit, otherwise num[pos] 
	int limit = (tight ? 9 : num[pos]); 

	for (int dig = 0; dig <= limit; dig++) { 

		if (dig == d) 
			continue; 

		int currTight = tight; 

		// At this position, number becomes 
		// smaller 
		if (dig < num[pos]) 
			currTight = 1; 

		// Next recursive call, also set nonz 
		// to 1 if current digit is non zero 
		ans += count(pos + 1, (10 * rem + dig) 
								% m, 
					currTight, num); 
	} 
	return dp[pos][rem][tight] = ans; 
} 

// Function to convert x into its digit vector 
// and uses count() function to return the 
// required count 
int solve(int x) 
{ 
	vector<int> num; 
	while (x) { 
		num.push_back(x % 10); 
		x /= 10; 
	} 
	reverse(num.begin(), num.end()); 

	// Initialize dp 
	memset(dp, -1, sizeof(dp)); 
	return count(0, 0, 0, num); 
} 

// Driver Code to test above functions 
int main() 
{ 
	int L = 10, R = 99; 
	d = 8, m = 2; 
	cout << solve(R) - solve(L) << endl; 

	return 0; 
} 

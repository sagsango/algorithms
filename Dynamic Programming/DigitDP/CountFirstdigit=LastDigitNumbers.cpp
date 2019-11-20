https://www.geeksforgeeks.org/count-of-numbers-in-range-where-the-number-does-not-contain-more-than-k-non-zero-digits/

/************************************
**** Tight = 0 means Tight is on  ***
************************************/

//Count of Numbers in Range where first digit
//is equal to last digit of the number

#include <bits/stdc++.h> 

using namespace std; 

const int M = 20; 

// states - position, first digit, 
// last digit, tight 
int dp[M][M][M][2]; 

// This function returns the count of 
// required numbers from 0 to num 
int count(int pos, int firstD, int lastD, 
		int tight, vector<int> num) 
{ 
	// Last position 
	if (pos == num.size()) { 

		// If first digit is equal to 
		// last digit 
		if (firstD == lastD) 
			return 1; 
		return 0; 
	} 

	// If this result is already computed 
	// simply return it 
	if (dp[pos][firstD][lastD][tight] != -1) 
		return dp[pos][firstD][lastD][tight]; 

	int ans = 0; 

	// Maximum limit upto which we can place 
	// digit. If tight is 1, means number has 
	// already become smaller so we can place 
	// any digit, otherwise num[pos] 
	int limit = (tight ? 9 : num[pos]); 

	for (int dig = 0; dig <= limit; dig++) { 
		int currFirst = firstD; 

		// If the position is 0, current 
		// digit can be first digit 
		if (pos == 0) 
			currFirst = dig; 

		// In current call, if the first 
		// digit is zero and current digit 
		// is nonzero, update currFirst 
		if (!currFirst && dig) 
			currFirst = dig; 

		int currTight = tight; 

		// At this position, number becomes 
		// smaller 
		if (dig < num[pos]) 
			currTight = 1; 

		// Next recursive call, set last 
		// digit as dig 
		ans += count(pos + 1, currFirst, 
					dig, currTight, num); 
	} 
	return dp[pos][firstD][lastD][tight] = ans; 
} 

// This function converts a number into its 
// digit vector and uses above function to compute 
// the answer 
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
	return count(0, 0, 0, 0, num); 
} 

// Driver Code 
int main() 
{ 
	int L = 2, R = 60; 
	cout << solve(R) - solve(L - 1) << endl; 

	L = 1, R = 1000; 
	cout << solve(R) - solve(L - 1) << endl; 
	
	return 0; 
} 

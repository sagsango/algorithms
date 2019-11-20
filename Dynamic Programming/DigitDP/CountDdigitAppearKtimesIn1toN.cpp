https://www.geeksforgeeks.org/count-of-numbers-in-a-range-where-digit-d-occurs-exactly-k-times/



/**
* Note D digit may be zero so we are taking dp[index][d_dig_count][tight][non_zero_d]
* if D were only [1,9] then dp[index][d_dig_count][tight] is enough
**/

// CPP Program to find the count of 
// numbers in a range where digit d 
// occurs exactly K times 
#include <bits/stdc++.h> 
using namespace std; 

const int M = 20; 

// states - position, count, tight, nonz 
int dp[M][M][2][2]; 

// d is required digit and K is occurrence 
int d, K; 

// This function returns the count of 
// required numbers from 0 to num 
int count(int pos, int cnt, int tight, 
		int nonz, vector<int> num) 
{ 
	// Last position 
	if (pos == num.size()) { 
		if (cnt == K) 
			return 1; 
		return 0; 
	} 

	// If this result is already computed 
	// simply return it 
	if (dp[pos][cnt][tight][nonz] != -1) 
		return dp[pos][cnt][tight][nonz]; 

	int ans = 0; 

	// Maximum limit upto which we can place 
	// digit. If tight is 1, means number has 
	// already become smaller so we can place 
	// any digit, otherwise num[pos] 
	int limit = (tight ? 9 : num[pos]); 

	for (int dig = 0; dig <= limit; dig++) { 
		int currCnt = cnt; 

		// Nonz is true if we placed a non 
		// zero digit at the starting of 
		// the number 
		if (dig == d) { 
			if (d != 0 || (!d && nonz)) 
				currCnt++; 
		} 

		int currTight = tight; 

		// At this position, number becomes 
		// smaller 
		if (dig < num[pos]) 
			currTight = 1; 

		// Next recursive call, also set nonz 
		// to 1 if current digit is non zero 
		ans += count(pos + 1, currCnt, 
					currTight, nonz || (dig != 0), num); 
	} 
	return dp[pos][cnt][tight][nonz] = ans; 
} 

// Function to convert x into its digit vector and uses 
// count() function to return the required count 
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

// Driver Code to test above functions 
int main() 
{ 
	int L = 11, R = 100; 
	d = 2, K = 1; 
	cout << solve(R) - solve(L - 1) << endl; 

	return 0; 
} 

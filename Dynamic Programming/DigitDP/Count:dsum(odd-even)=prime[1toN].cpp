https://www.geeksforgeeks.org/count-numbers-in-range-with-difference-between-sum-of-digits-at-even-and-odd-positions-as-prime/

Count Numbers in Range with difference between Sum of digits at even and odd positions as Prime.

// C++ implementation of the above approach 

#include <bits/stdc++.h> 
using namespace std; 

const int M = 18; 
int a, b, dp[M][90][90][2]; 

// Prime numbers upto 100 
int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 
				29, 31, 37, 43, 47, 53, 59, 61, 
				67, 71, 73, 79, 83, 89, 97 }; 

// Function to return the count of 
// required numbers from 0 to num 
int count(int pos, int even, int odd, int tight, 
		vector<int> num) 
{ 
	// Base Case 
	if (pos == num.size()) { 
		if (num.size() & 1) 
			swap(odd, even); 
		int d = even - odd; 

		// check if the difference is equal 
		// to any prime number 
		for (int i = 0; i < 24; i++) 
			if (d == prime[i]) 
				return 1; 
				
		return 0; 
	} 

	// If this result is already computed 
	// simply return it 
	if (dp[pos][even][odd][tight] != -1) 
		return dp[pos][even][odd][tight]; 

	int ans = 0; 

	// Maximum limit upto which we can place 
	// digit. If tight is 1, means number has 
	// already become smaller so we can place 
	// any digit, otherwise num[pos] 
	int limit = (tight ? 9 : num[pos]); 

	for (int d = 0; d <= limit; d++) { 
		int currF = tight, currEven = even; 
		int currOdd = odd; 
		
		if (d < num[pos]) 
			currF = 1; 

		// If the current position is odd 
		// add it to currOdd, otherwise to 
		// currEven 
		if (pos & 1) 
			currOdd += d; 
		else
			currEven += d; 
			
		ans += count(pos + 1, currEven, currOdd, 
					currF, num); 
	} 
	
	return dp[pos][even][odd][tight] = ans; 
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
	return count(0, 0, 0, 0, num); 
} 

// Driver Code 
int main() 
{ 
	int L = 1, R = 50; 
	cout << solve(R) - solve(L - 1) << endl; 

	L = 50, R = 100; 
	cout << solve(R) - solve(L - 1) << endl; 
	
	return 0; 
} 

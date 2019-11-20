Link     :   https://www.geeksforgeeks.org/digit-dp-introduction/
Problem  :   Given two integers a and b. Your task is to print the sum of
             all the digits appearing in the integers between a and b.
comlexity:   O( 10 * 20 * 180 * 2 ) 

  
// Given two integers a and b. The task is to print 
// sum of all the digits appearing in the 
// integers between a and b 
#include "bits/stdc++.h" 
#define int long long
using namespace std; 
int dp[20][180][2]; 

// Stores the digits in x in a vector digit 
int getDigits(int x, vector <int> &digit) 
{ 
	while (x) 
	{ 
		digit.push_back(x%10); 
		x /= 10; 
	} 
} 

/*********************************************************************
** NOTE : tight is the only thing in this dp that makes it digit dp **
**********************************************************************/

// Return sum of digits from 1 to integer in digit vector 
int digitSum(int idx,int sum, int tight,vector <int> &digit) 
{ 
	// base case 
	if (idx == -1) 
	return sum; 

	// checking if already calculated this state 
	//if (dp[idx][sum][tight] != -1 and tight != 1) 
	if (dp[idx][sum][tight] != -1 ) 
		return dp[idx][sum][tight]; 
  
  int ret = 0; 
  
	// calculating range value 
	int k = (tight)? digit[idx] : 9; 

	for (int i = 0; i <= k ; i++) 
	{ 
		// caclulating newTight value for next state 
		int newTight = (digit[idx] == i)? tight : 0; 

		// fetching answer from next state 
		ret += digitSum(idx-1, sum+i, newTight, digit); 
	} 

	//if (!tight) 
	dp[idx][sum][tight] = ret; 

	return ret; 
} 

// Returns sum of digits in numbers from a to b. 
int rangeDigitSum(int a,int b) 
{ 
	// initializing dp with -1 
	memset(dp, -1, sizeof(dp)); 

	// storing digits of a-1 in digit vector 
	vector<int> digitA; 
	getDigits(a-1, digitA); 

	// Finding sum of digits from 1 to "a-1" which is passed 
	// as digitA. 
	int ans1 = digitSum(digitA.size()-1, 0, 1, digitA); 

	// Storing digits of b in digit vector 
	vector<int> digitB; 
	getDigits(b, digitB); 

	// Finding sum of digits from 1 to "b" which is passed 
	// as digitB. 
	int ans2 = digitSum(digitB.size()-1, 0, 1, digitB); 

	return (ans2 - ans1); 
} 

// driver function to call above function 
int main() 
{ 
	int a = 1, b = 1e18; 
	cout << "digit sum for given range : "
		<< rangeDigitSum(a,b) << endl; 
	return 0; 
} 

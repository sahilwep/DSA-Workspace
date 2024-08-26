/*

// Sum of Digits of a Number


// Observations: 
    * We are given number n, we have to print the sum of it's digits.

// Example: 
    n = 99999
    Output: 45
    Explanation: sum of digits of n is 45, 9+9+9+9+9+9

// Complexity: 
    * TC: O(logn)

// Intrusion: 
    * We first write the base case, i.e: if(n == 0) return 0
    * Then the recursive case: 
        lastDigit + Upcoming Calls that gives last digits
        (n % 10) + func(n / 10)


*/

#include <iostream>
using namespace std;

class Solution{
public:
    int sumOfDigits(int n){
        if(n == 0) return 0;
        return (n % 10) + sumOfDigits(n / 10);
    }
};

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<<obj.sumOfDigits(n)<<endl;
	}
	return 0;
}
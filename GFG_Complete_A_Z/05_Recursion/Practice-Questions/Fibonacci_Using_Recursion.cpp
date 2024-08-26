/*

// Fibonacci Using Recursion

// Observations: 
    * We are given number n, we need to find nth fibonacci number.
    * f(n) = f(n-1) + f(n-2), where f(1) = 1 and f(2) = 1

// Example:
    Input:  n = 1
    Output: 1
        Explanation: The first fibonacci number is 1

    Input:  n = 20
    Output:6765
        Explanation: The 20th fibonacci number is 6765


// Intrusion: 
    * Fibonacci Number: 1 1 2 3 5 8 13 21 34....
    * if(n == 0) return 0
    * if(n == 1) return 1


// Recursive Calls: 

    fib(6)  -> return 8
        |--->fib(5) -> return 5
        |       |--->fib(4) -> return 3
        |       |       |--->fib(3) -> return 2
        |       |       |       |--->fib(2) -> return 1
        |       |       |       |       |--->fib(1) -> return 1
        |       |       |       |       |--->fib(0) -> return 0
        |       |       |       |
        |       |       |       |--->fib(1) -> return 1
        |       |       |
        |       |       |--->fib(2) -> return 1
        |       |               |--->fib(1) -> return 1
        |       |               |--->fib(0) -> return 0
        |       |       
        |       |--->fib(3) -> return 2
        |               |--->fib(2) -> return 1
        |               |       |--->fib(1) -> return 1
        |               |       |--->fib(0) -> return 0
        |               |
        |               |--->fib(1) -> return 1
        |
        |--->fib(4) -> return 3
              |--->fib(3)   -> return 2
              |     |--->fib(2) -> return 1
              |     |       |--->fib(1) -> return 1
              |     |       |--->fib(0) -> return 0
              |     |       
              |     |--->fib(1) -> return 1
              |
              |--->fib(2)   -> return 1
                    |--->fib(1) -> return 1
                    |--->fib(0) -> return 0



*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int fibonacci(int n){
        if(n == 0 || n == 1) return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }
};

int main() {
	int T;
	
	cin>>T;
	while (T--){
	    int n;
	    cin>>n;
	    Solution ob;
	    cout<<ob.fibonacci(n)<<endl;
	    
	}
	return 0;
}
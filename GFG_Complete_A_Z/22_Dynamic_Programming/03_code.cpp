/*

// Dynamic Programming: Tabulations

// Bottom Up: 
    * The idea is to leave recursion, have an array or a table & build your solutions bottom up manner.
    * Example: 
        * If we need solution for input n, this n is dependent upon (n-1) and (n-2)
        * In bottom up solution we go this way, that we first compute 0, 1, 3, 4.. 
        * so that we need solution for n, which is dependent upon n-1, n-2, they are already computed, that's why we call it bottom up.
    * In top-down we simply calling for n, & when we realize we don't have the solution, we call for n-1, n-2, that is why we call it top-down.
    * So, we make an array, & the rules for the dimensions of array or the size of array are same, 
        * the number of parameter that change in your recursive solution that decide the dimension
        * and the range of these parameter that decides the size of your array.


// Example of tabulations with fibonacci number:

    Example: n = 5
    
    * Create a table of size n+1, & assign the base case values of fibonacci number i.e f[0] = 0, f[1] = 1

    [ 0 | 1 |   |   |   |   ]   -> create a table of size n+1
      0   1   2   3   4   5

        * Using fib function we can generate the solution of current problem with previous solved sub-problem -> Bottom up

        f[2] =  f[1] + f[0]  -> 1

    [ 0 | 1 | 1 |   |   |   ] 
      0   1   2   3   4   5

        f[3] =  f[2] + f[1]  -> 2

    [ 0 | 1 | 1 | 2 |   |   ] 
      0   1   2   3   4   5

        f[4] =  f[3] + f[2]  -> 3

    [ 0 | 1 | 1 | 2 | 3 |   ] 
      0   1   2   3   4   5

        f[5] =  f[4] + f[3]  -> 5

    [ 0 | 1 | 1 | 2 | 3 | 5 ] 
      0   1   2   3   4   5
    
    

    * At Last we return f[5]
    * TC: O(n)
    * AS: O(n)

    // NOTE: When we are using tabulations, we need to remember to take care of one thing that is "dependency"
        * If your main problem is dependent upon n-1, or n-2, or let say, when our function f(n) is dependent f(n-1), & f(n-2)...
        * We need to fill the table of first previous values, example: 
                f(n) = f(n-1) + f(n-2) 
            * Here f(n) is dependent upon f(n-1), & f(n-2) in order to get the solution for f(n)
            * So, we need to have our value f(n-1) & f(n-2) in our table, so that we can generate the output of f(n)
            * In Conclusion, whatever the values required to generate the current solution, that values should be already computed..




// Comparision b/w Memoization & tabulations
    * Memoization: 
        * Easy to implement once we have a recursive solution.
        * Slow
    * Tabulations: 
        * Difficult to implement
        * Fast

*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Fibonacci function: 
int fib(int n){
    int dp[n+1];    // create a table of size n+1
    dp[0] = 0, dp[1] = 1;   // Storing fist two values in table

    // storing the values into table by taking previous solutions:
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];   // returning the nth fib number.
}

void solve(){
    int n;
    cin >> n;

    cout << fib(n) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
/*
// Dynamic Programming Memoization:

// Find the nth fibonacci number for a given number:

    fibonacci number: 0 1 1 2 3 5 8....

    I/p: n = 3
    O/p: 2

// logic:
    int fib(int n){
        if(n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }

    * For a simple small n, we are computing same subproblem many times...
    * For n = 100, which is very big, we will compute same subproblem many times, & which is not worth computing again & again for performance..
    * Let's see the recursive tree: 
           
                                                      fib(5)
                                                        |
                                 fib(4)--------------------------------------fib(3)
                                    |                                           |
                            fib(3)-------------fib(2)               fib(2)------------fib(1)
                            |                   |                     |
                    fib(2)-----fib(1)    fib(1)----fib(0)       fib(1)----fib(0)
                        |
                fib(1)----fib(0)


    * Like in this sub-tree, fib(3), fib(2) these are computed again & again...
    * We can use memoization, based technique to store the result of subproblems..
    * This will restrict to compute same portions of recursive calls again & again...

        * We can maintain memo[] {-1, -1, -1, -1, -1,..., -1} array to store the result of subproblems.
            * We have use "-1" here, because this value can't be possible in a case of fib..
            * also we can put any value that we want...


// after using DP, & Maintaining memo array:

                                                fib(5)
                                                 |
                                   fib(4)-------------------fib(3)
                                      |
                            fib(3)--------fib(2)
                              |
                      fib(2)-----fib(1)
                        |
                fib(1)----fib(0)
            
            * We made n function call in stack (left side of tree) & n-1 function call (right side of tree)..
            * So total made (2n-1) function calls in stack, & We are dong constant work in every function call, we don't have any loop...
            * Total: (2n-1) * theta(1)  ->  O(n) in worse case

    // Observations: 
    * Maintaining memo array of size n+1 [-1, -1, -1, -1, -1, -1]
                                          0   1    2   3   4  5
                            first call  fib(4)  -> store result [-1, -1, -1, -1, -1, -1]
                            second call  fib(3) -> store result [-1, -1, -1, -1, -1, -1]
                            third call  fib(2)  -> store result [-1, -1, -1, -1, -1, -1]
                            fourth call  fib(1) -> store result [-1, 1, -1, -1, -1, -1]    -> update 1 to memo
                            fifth call  fib(0)  -> store result [0, 1, -1, -1, -1, -1]    -> update 0 to memo
                            * after these call it will call for right side of every left call stack..
                                for call stack fib(2) -> store the sum of fib(1) + fib(0) to fib(2)
                                                        [0, 1, 1, -1, -1, -1]
                                return to fib(2) & call fib(1) & get value from memo & store it on memo of fib(3)
                                                        [0, 1, 1, 2, -1, -1]
                                return to fib(3) * call fib(2) & get value from memo & store it on memo of fib(4)
                                                        [0, 1, 1, 2, 3, -1]
                                return to fib(4) * call for fib(3) & get value form memo & store it on memo of (fib5)
                                                        [0, 1, 1, 2, 3, 5]
                                * After this it returns memo[n] to previous called function, in this case we have main.




// Note: size in this case, we can take [n+1], as maximum it will goes to that index..

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// for input case n = 5
// we can maintain memo array in any global section:
int memo[5+1];   // we can take size, let 10^6 in this case...

// Fib using memo array
int fib(int n){
    // if solution is not computed earlier, it goes in if scope
    if(memo[n] == -1){  
        int res;    // creating res to store the result..
        // if n is 1 or 0, in this case we return n.
        if(n <= 1){
            res = n;
        }
        // else for others case we have to compute the result..
        else{
            // calls fib(n-1) & fib(n-2), then sum up & store it in result
            res = fib(n-1) + fib(n-2);
        }
        memo[n] = res;  // last we will store result in momo[n] array.
    }
    // else if it's already computed, directly return the result.
    return memo[n];
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(memo, -1, sizeof(memo));     // this function is used to give specific value to block of memory, like in our case "-1", throughout the array..
        cout << fib(n) << endl;
        // for(auto i : memo) cout << i << endl;    // uses to print the memo array...
    }   
    
    return 0;
}
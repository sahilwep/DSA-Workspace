/*

//  Evaluate Expression to True Boolean Parenthesization Recursive 

//  Problem Statement:
    * Given a boolean expression s, with following symbol:
            'T' ---> true
            'F' ---> false
    * and following operators:
            &   ---> boolean AND
            |   ---> boolean OR
            ^   ---> boolean XOR
    * Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true


// Example: 

    Input: 
    n = 7
    s = T|T&F^T
    Output: 
    4
    Explaination: The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

    Input: 
    n = 5
    s = T^F|F
    Output: 
    2
    Explaination: ((T^F)|F) and (T^(F|F)) are the only ways.


// MCM Identification: 
    * We are given an instruction that we can apply brackets in order to get true, & we need to count of them..
    * In Worse case, we will apply brackets at every possible index, so that we can make our solution..
        * Example:
                s = "T|T&F^T"
                    (T|(T&(F^T)))

        * So, we are doing partition at every possible index in range (start --- end)


// Problem Visualization: 
    * Let's solve this question with MCM Format: -> We will be solving this question using recursive solution, then afterwards we will memoized this.......

        // Identification of Solve() -> function & it's parameters:

    
        // Identification of (i & j) -> Starting & ending ranges:

        // Identification of Base Condition: 

        // Identification of 'k' partitions: 

            // Identification of 'k' increment:

        
        // Function that evaluates temporary solution: 




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define mod 1000000007


int evaluateExpression(string &s, int i, int j, bool isTrue){
    // Base Condition:
    if(i > j) return 0;

    // When we have single element:
    if(i == j){
        if(isTrue){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    ll ways = 0;
    
    for(int k=i+1;k<=j-1;k=k+2){
        ll lT = evaluateExpression(s, i, k-1, 1);
        ll lF = evaluateExpression(s, i, k-1, 0);

        ll rT = evaluateExpression(s, k+1, j, 1);
        ll rF = evaluateExpression(s, k+1, j, 0);

        //  '&' 
        if(s[k] == '&'){
            // condition for true:
            if(isTrue){
                ways = (ways + (rT * lT) % mod) % mod;
            }
            // condition for false:
            else{
                ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
            }
        }
        //  '|'
        else if(s[k] == '|'){
            if(isTrue){
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
            }
            else{
                ways = (ways + (lF * rF) % mod) % mod;
            }
        }
        //  '^' -> T T -> F, F F -> F, T F -> T, F T -> T
        else{
            if(isTrue){
                ways = (ways + (lT * rF) % mod+ (lF * rT) % mod) % mod;
            }
            else{
                ways += ((lT * rT) % mod+ (lF * rF) % mod) % mod;
            }
        }
    }
    
    return ways;
}


void solve(){
    string s;
    cin >> s;

    int n = s.size();
    cout << evaluateExpression(s, 0, n-1, 1) << endl;
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
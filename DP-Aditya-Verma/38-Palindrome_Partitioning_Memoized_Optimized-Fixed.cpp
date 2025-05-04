/*

//  38 Palindrome Partitioning Memoized Optimized -> Fixed.


//  Problem Statement:
    * we are given a string s, & we need to perform minimum partition, such that after the partitioning our string will become a Palindrome:
    * Example:
        I/p: s = nitin
        O/p: 0

            * We will be needed 0 partition, because this string is already a palindrome, 
            * but let's analyze this question if we needed some partition, that in that case what will happened:
          
                    n i t i n

                    n |i t i| n
                      P1    P2      -> Partition

            If we perform 2 partition, all the substring become palindrome...
                
                    "n" "iti" "n" -> All of them become palindrome..


            The number of partition we are doing, which we need to minimize.

            In Worse case, when all the string characters are distinct, we will have (n-1) partitions, (n = size of string)





// Further Optimization: 
        * When we were calling for temp answer:

                int tempAns = 1 + palindromePartition(s, i, k, t) + palindromePartition(s, k+1, j, t);

            What if palindromePartition(s, i, k, t) -> left side is already solved.
            or what if palindromePartition(s, k+1, j, t) -> right side is already solved.
            if any of these subproblem are already solved, then we will be wasting our recursive calls, for partitioning & rechecking..

            So, it's better we should check first which one is already solved & which one is not, & then take decision to solve these subproblems

            So, instead of wiring this line in for loop ->  (int tempAns = 1 + palindromePartition(s, i, k, t) + palindromePartition(s, k+1, j, t);)
            we will write this one: for checks

                    -------------
                        int left = 0, right = 0;
                        // Checking for left part:
                        if(t[i][k] != -1){
                            left = t[i][k];
                        }
                        else{
                            left = palindromePartition(s, i, k, t);
                            t[i][k] = left;
                        }

                        // Checking for right part:
                        if(t[k+1][j] != -1){
                            right = t[k+1][j];
                        }else{
                            right = palindromePartition(s, k+1, j, t);
                        }
                        // last we will return the temp answer:
                        int tempAns = 1 + left + right;
                    -------------


            * Problems in above Optimization: 
                * When optimizing the palindrome partitioning code, the goal was to minimize redundant recursive calls by leveraging previously computed results stored in a memoization table. 
                * However, the following issues were identified with the initial optimization attempt:
                    * Redundant Checks: 
                        * The initial attempt to check if subproblems were already solved could lead to unnecessary calls to palindromePartition, 
                        * especially if the partition checks were not directly tied to the palindrome status of the substrings.

                    * Incorrect Usage of Memoization: 
                        * The memoization array was meant to store the minimum number of partitions required for specific substring indices. However, 
                        * if the checks for previously computed results were done without ensuring they were tied to the palindrome checks, it could result in missed optimizations.

                    * Inefficient Structure: 
                        * The structure of checking both sides of the partition separately did not efficiently combine the results or minimize the checks for the palindrome condition, 
                        * leading to an overall increase in function calls.




            * Solution for this Problem:
                * To fix the issues identified in the earlier optimization attempt, a more streamlined approach was implemented. 
                * The focus was placed on directly leveraging the palindrome checks for the relevant partitions and utilizing memoization effectively:
                * Key Changes Made:
                    * Direct Checks: 
                        * The fixed optimization directly checks if either the left or right substring is a palindrome before making further recursive calls. This eliminates the need for unnecessary computations and ensures that only valid partitions are explored.
                    
                    * Utilization of Memoization: 
                        * The memoization table is utilized efficiently, storing results only after confirming a substring is not a palindrome, thereby minimizing repeated calculations for known substrings.

                    * Concise Logic: 
                        * The logic is more concise and focused on finding the minimum partitions based on actual palindrome status rather than checking previously computed results, leading to a more efficient algorithm.

                
                    --------------------
                    FIXED Optimization: 

                        // We can check left side Palindrome:
                        if(isPalindrome(s, i, k)){
                            int tempAns = 1 + solve(s, k+1, j, t);

                            // finding minimum among them..
                            ans = min(tempAns, ans);
                        }

                        // OR Check right side Palindrome:
                        if(isPalindrome(s, k+1, j)){
                            int tempAns = 1 + solve(s, i, k, t);

                            // finding minimum among them..
                            ans = min(tempAns, ans);
                        }

                    --------------------




            * Crux: 
                // We can check left side Palindrome: instead of checking the table,
                // which will first compute the result by partitioning the string & going into recursive calls.
 



// Intrusion:
    * Same intrusion as we have discussed in memoization code.
    * Create a memo array & store the result of subproblems..
    * When it's needed we will return directly that result without going into the recursive calls.



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Palindrome Checker function
bool isPalindrome(string s, int i, int j){
    if(i == j) return 1;    // palindrome for single element.
    if(i > j) return 1; // palindrome for empty string
    while(i < j){
        if(s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

// Palindrome Partition Recursive Code:
int palindromePartition(string &s, int i, int j, vector<vector<int> > &t){

    // for size = 0 & 1, we can't have any further partition:
    if(i >= j) return t[i][j] = 0;

    // checking for subproblem result from the memo array:
    if(t[i][j] != -1){
        return t[i][j];     // returning if we have solution.
    }

    // if string part is already a palindrome, no need of further partition:
    if(isPalindrome(s, i, j) == true) return t[i][j] = 0;

    // Checking for every partition of 'K'
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        // We can check left side Palindrome: instead of checking the table,
        // which will first compute the result by partitioning the string & going into recursive calls.
        if(isPalindrome(s, i, k)){
            t[k+1][j] = palindromePartition(s, k+1, j, t);
            int tempAns = 1 + t[k+1][j];

            // finding minimum among them..
            ans = min(tempAns, ans);
        }

        // OR Check right side Palindrome:
        // if(isPalindrome(s, k+1, j)){
        //     t[i][k] = palindromePartition(s, i, k, t);
        //     int tempAns = 1 + t[i][k];
        //     // finding minimum among them..
        //     ans = min(tempAns, ans);
        // }

    }

    return t[i][j] =  ans;
}

void solve(){
    string s;
    cin >> s;

    // Memoization: 
    int n = s.size();
    // Initializing memo array:
    vector<vector<int> > t(n+1, vector<int> (n+1, -1));

    // calling function with valid (i = 0 & j = n-1) index.
    cout << palindromePartition(s, 0, n-1, t) << endl;
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
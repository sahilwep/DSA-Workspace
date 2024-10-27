/*

//  39 Palindrome Partitioning Memoized Optimized


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
    if(i >= j) return 0;

    // checking for subproblem result from the memo array:
    if(t[i][j] != -1){
        return t[i][j];     // returning if we have solution.
    }

    // if string part is already a palindrome, no need of further partition:
    if(isPalindrome(s, i, j) == true) return t[i][j] = 0;

    // Checking for every partition of 'K'
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
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

        // Checking for Minimum Partition answer:
        ans = min(tempAns, ans);
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
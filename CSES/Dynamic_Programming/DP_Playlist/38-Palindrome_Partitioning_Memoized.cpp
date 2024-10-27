/*

//  38 Palindrome Partitioning Memoized




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


// MCM Identification: 
    * In worse case we are doing partition at every index..
    * Similarly, in MCM we were doing partition at every index...
    * This is why this question is of MCM type...

                s = nitin

                    n i t i n
                    i |     j       -> choosing i & j index
                      k             -> performing partition
                    
                    [n i] + (cost) + [t i n]
                  (i to k)   |      (k+1 to j)
                             |
                             1 -> this cost is 1, because we are performing 1 partition..

                    
                    The cost of (i to k) + (k+1 to j) + (cost of single k) -> will give the answer..

                further we will do partition on 
                    (i to k) -> & find the minimum...
                Similarly we will do partition on 
                    (k+1 to j) -> and find the minimum...

                Note cost = 1, because after solving (left side) & (right side), we need to solve for both, which will take cost = 1, because we are performing 1 partition cost b/w both of them...

                After solving partition at every 'k', every time we will have temporary answer, so we will take minimum from them..


// MCM Format:
    * Format Rules:
        1. find (i & j)
        2. find base condition
        3. find k loop
        4. apply some function on tempAnswer to find final answer.
    

        // Finding (i & j)

                    n i t i n
                    i       j       -> If we put i & j at beg & last index there is no problem.. 

                                    Don't compare it with MCM, because there (A(i) = arr[i-1] * arr[i]) equation to form matrix, this is why we have started i from 1..
                                    But here we don't have to take care of anything.

                    i = 0
                    j = size - 1
    
        // Finding Base condition:
                    
                    * Case 1:
                        0               (n-1)   -> index
                        |-------|-|-------|
                                j i       

                        (i > j) -> size = 0 -> which is invalid input return -> 0
                                
                    
                        s = "" -> empty string -> no partition needed, -> return 0

                    * Case 2: 

                        0               (n-1)   -> index
                        |-------|---------|
                                ij 

                        (i == j) -> size = 1 -> means (i == j) -> we will have single character.
                        If we have single element, still we will have to perform 0 partitions.


                    * Extra: 
                        If s = "abcba" -> how many partitions we needed ?
                        Answer is '0' -> because string itself is a palindrome.

                        * So, we will make one function: isPalindrome() -> This will check whether the given string is palindrome or not?
                        * Based on the return type of isPalindrome() -> we will return our answer..
                        * If this function return true, we will return 0
                        * We are saying that if the string is palindrome, then there is no need of partition...

                    * Concluding on the fact that 
                            if(i >= j) return 0
                            if(isPalindrome(s, i, j) == 1) -> return 0


        // Finding correct 'k'

                    If we start k from i
                              0 1 2 3 4 5
                            [ | | | | | ]
                            i           j
                            k

                            partition:
                                  0    1        5
                                [ ]    [        ]
                                  i             j
                                  k           
                            (i to k) & (k+1 to j)

                    If k goes till j

                              0 1 2 3 4 5
                            [ | | | | | ]
                            i           j
                                        k

                            partition:
                                0      5    6       ..
                                [      ]    [        ]
                                i      j    invalid
                                       k

                            (i to k) & (k+1 to j) -> (k+1 to j) is invalid
                        
                        So, partition will performed till (j - 1)
                        Then only we will have one partition on right side which is (k+1 to j)

                    Partition scheme: we can choose any of them..
                          start        end                leftSolve       rightSolve
                      1.  k = i        k = j-1            (i to k)        (k+1 to j)    -> We will prefer this one..
                      2.  k = i+1      k = j              (i to k-1)      (k to j)


                    * Note increment (k++) can be sometime (k+2), so we will have to look about it, but here we have (k++) only.



        // apply some function on tempAnswer to find final answer:

                                    k
                         [n i]      |        [t i n]
                           |        |            |
                           |     partition       |
                           |     cost = 1        |
                           |                     |
                This will give                  this will give 
                the cost of min.                the cost of min.
                number of palindrome            number of palindrome
                partition needed                partition needed
                    = C1                            = C2

                    C3 = and, for partition both the side we needed 1 partition cost, So, middle cost = 1

                    tempAns = C1 + C2 + C3 -> this is the temporary answer...

                    After getting the temporary answer will will find the minimum for every 'k' partitions.

// Intrusion: 
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

    // if string part is already a palindrome, no need of further partition:
    if(isPalindrome(s, i, j) == true) return 0;

    // checking for subproblem result from the memo array:
    if(t[i][j] != -1){
        return t[i][j];     // returning if we have solution.
    }
    
    // Checking for every partition of 'K'
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int tempAns = 1 + palindromePartition(s, i, k, t) + palindromePartition(s, k+1, j, t);
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
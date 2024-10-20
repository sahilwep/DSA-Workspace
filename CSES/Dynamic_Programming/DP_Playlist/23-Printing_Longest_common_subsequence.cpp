/*

//  Printing Longest common subsequence: Tabulation



// Problem Statement: 
    We are given two strings 's1' and 's2', and we need to print the longest common subsequence from both strings.



// What is a Subsequence?
    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. The characters do not need to be contiguous but must appear in the same order.

    - 'Example':
        - For the string "abcde", the subsequences include "ace", "bde", and "abcde."
        - However, "aec" is not a valid subsequence because it does not follow the original order.




// Solution: We will use Tabulation Approach:

        - Implementation of 'Bottom-Up' is very easy once we have implemented 'Recursive Solution'.

        - 'Tabulation Implementation': 
            - 'Initialization':
                - Create a table/matrix of size: 'n+1 & m+1'
                - Table size are choosen from those values which are changing in recursive solution.
                - From the base condition when '(n == 0 || m == 0) -> return 0', means 'first row' & 'first column' filled with '0'.

            - Filling the Rest of the table based on 'decision Tree':
                - We have already filled first row & first column, so iteration will start from 'row = 1 to n+1' & 'col = 1 to m+1'
                - Replace 'n -> i' & 'm -> j'
                - Replace recursive calls with matrix name:
                    -  'lcs' -> 't[][]'
                    -  Replace 'n - 1' & 'm - 1' -> 'i - 1' & 'j - 1'
                    -  'lcs(s1, s2, n-1, m-1)' ->  't[i-1][j-1]'
                - Replace 'return' -> 't[i][j]'
                - Rest of the logic is same, no change there..

            - At, Last return the last element from the table:
                -  't[n][m]' -> This will store our solution.


            - Matrix:
            
                let say: n = 5, n = 5   -> matrix will be:

                                           <------- m + 1 ----->
                                          0   1   2   3   4   5    
                                    0   | 0 | 0 | 0 | 0 | 0 | 0 |
                             ^      1   | 0 |   |   |   |   |   |
                             |      2   | 0 |   |   |   |   |   |
                            n+1     3   | 0 |   |   |   |   |   |
                             |      4   | 0 |   |   |   |   |   |
                             |      5   | 0 |   |   |   |   |   |   matrix = t[n+1][m+1]



        - Once, matrix is filled we will look on the matrix & find those element that are valid to be result.
        - In table we will look two element from wherever we are: (upward & left)

                |        |    Up   |
                |  left  |    x    |

                    -> for any element x we will look upward & leftward.


            - Example:
                s1 = acbcf   s2 = abcdaf

                            ∅     a     b     c     d     a     f
                    ∅    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                    a    |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
                    c    |  0  |  1  |  1  |  2  |  2  |  2  |  2  |
                    b    |  0  |  1  |  2  |  2  |  2  |  2  |  2  |
                    c    |  0  |  1  |  2  |  3  |  3  |  3  |  3  |
                    g    |  0  |  1  |  2  |  3  |  3  |  3  |  4  |        -> Table

                - We will start traversing from back:
                    i = n, j = m
                    while(i > 0 && j > 0)
                
                - we will check if (s1[i-1] == s2[j-1])  -> i-- & j--

                - if it's not same:
                    - we will take maximum from (t[i-1][j], t[i][j-1]), & depending upon we will move our i or j
                    - if(t[i-1][j] > t[i][j-1]) => move i--
                    - else => move j--
                
                - Example:

                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                        |   a    |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
                        i   c    |  0  |  1  |  1  |  2  |  2  |  2  |  2  |
                        |   b    |  0  |  1  |  2  |  2  |  2  |  2  |  2  |
                        |   c    |  0  |  1  |  2  |  3  |  3  |  3  |  3  |
                        |   g    |  0  |  1  |  2  |  3  |  3  |  3  | {4} |        -> Table

                        -> start from here, i = n, j = m

                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                        |   a    |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
                        i   c    |  0  |  1  |  1  |  2  |  2  |  2  |  2  |
                        |   b    |  0  |  1  |  2  |  2  |  2  |  2  |  2  |
                        |   c    |  0  |  1  |  2  |  3  |  3  |  3  | [3] |
                        |   g    |  0  |  1  |  2  |  3  |  3  | [3] | {4} |        -> Table

                        -> Compare if s[i-1] == s[j-1] => f,f -> Yes
                            -> store result in string = "f"
                            -> move i-- & j--
                        
                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                        |   a    |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
                        i   c    |  0  |  1  |  1  |  2  |  2  |  2  |  2  |
                        |   b    |  0  |  1  |  2  |  2  |  2  | [2] |  2  |
                        |   c    |  0  |  1  |  2  |  3  | [3] | {3} |  3  |
                        |   g    |  0  |  1  |  2  |  3  |  3  |  3  |  4  |        -> Table

                        -> Compare if s[i-1] == s[j-1] => c,a -> No
                            -> get maximum from both of them: 
                                max(t[i-1][j] => 3 -> max
                                    t[i][j-1] => 2
                                    );
                                so, move i--
                
                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                        |   a    |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
                        i   c    |  0  |  1  |  1  |  2  |  2  |  2  |  2  |
                        |   b    |  0  |  1  |  2  |  2  | [2] |  2  |  2  |
                        |   c    |  0  |  1  |  2  | [3] | {3} |  3  |  3  |
                        |   g    |  0  |  1  |  2  |  3  |  3  |  3  |  4  |        -> Table

                        -> Compare if s[i-1] == s[j-1] => c,d -> No
                            -> get maximum from both of them:
                                max([t-1][j], => 3  -> max
                                    t[i][j-1] => 2
                                    );
                                so move i--

                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                        |   a    |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
                        i   c    |  0  |  1  |  1  |  2  |  2  |  2  |  2  |
                        |   b    |  0  |  1  |  2  | [2] |  2  |  2  |  2  |
                        |   c    |  0  |  1  | [2] | {3} |  3  |  3  |  3  |
                        |   g    |  0  |  1  |  2  |  3  |  3  |  3  |  4  |        -> Table

                        -> Compare if s[i-1] == s[j-1] => c,c -> Yes
                            -> store result in string = "fc"
                            -> move i-- & j--
                        
                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                        |   a    |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
                        i   c    |  0  |  1  | [1] |  2  |  2  |  2  |  2  |
                        |   b    |  0  | [1] | {2} |  2  |  2  |  2  |  2  |
                        |   c    |  0  |  1  |  2  |  3  |  3  |  3  |  3  |
                        |   g    |  0  |  1  |  2  |  3  |  3  |  3  |  4  |        -> Table

                        -> Compare if s[i-1] == s[j-1] => b,b -> Yes
                            -> store result in string = "fcb"
                            -> move i-- & j--
                        
                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                        |   a    |  0  | [1] |  1  |  1  |  1  |  1  |  1  |
                        i   c    | [0] | {1} |  1  |  2  |  2  |  2  |  2  |
                        |   b    |  0  |  1  |  2  |  2  |  2  |  2  |  2  |
                        |   c    |  0  |  1  |  2  |  3  |  3  |  3  |  3  |
                        |   g    |  0  |  1  |  2  |  3  |  3  |  3  |  4  |        -> Table

                        -> Compare if s[i-1] == s[j-1] => c,a -> NO
                                -> get maximum from both of them:
                                max([t-1][j], => 0  
                                    t[i][j-1] => 1  -> max
                                    );
                                so move j--
                        
                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    |  0  | [0] |  0  |  0  |  0  |  0  |  0  |
                        |   a    | [0] | {1} |  1  |  1  |  1  |  1  |  1  |
                        i   c    |  0  |  1  |  1  |  2  |  2  |  2  |  2  |
                        |   b    |  0  |  1  |  2  |  2  |  2  |  2  |  2  |
                        |   c    |  0  |  1  |  2  |  3  |  3  |  3  |  3  |
                        |   g    |  0  |  1  |  2  |  3  |  3  |  3  |  4  |        -> Table

                        -> Compare if s[i-1] == s[j-1] => a,a -> Yes
                            -> store result in string = "fcba"
                            -> move i-- & j--
                        
                                    ∅     a     b     c     d     a     f    --> j
                        |   ∅    | {0} |  0 |  0  |  0  |  0  |  0  |  0  |
                        |   a    |  0  |  1  |  1  |  1  |  1  |  1  |  1  |
                        i   c    |  0  |  1  |  1  |  2  |  2  |  2  |  2  |
                        |   b    |  0  |  1  |  2  |  2  |  2  |  2  |  2  |
                        |   c    |  0  |  1  |  2  |  3  |  3  |  3  |  3  |
                        |   g    |  0  |  1  |  2  |  3  |  3  |  3  |  4  |        -> Table

                        -> We are at ∅ -> means there is no element in our string, so, we will exit from the loop.


                        -> At last we will reverse our result string -> "fcba"  -> abcf & return the result.


// Complexity:

    * Time complexity: O(n*m)
    * Space complexity:O(n*m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 


// Print Longest Common Subsequence: Tabulation
string lcs(string &s1, string &s2, int n, int m){
    if(n == 0 || m == 0) return 0;  // when any of the string is with empty size, return 0

    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (m+1, 0));   // initialize memo array

    // When m = 0, we can't have any common subsequence...
    for(int i=0;i<n+1;i++){
        t[i][0] = 0;
    }
    // When n = 0, we can't have any common subsequence..
    for(int i=0;i<m+1;i++){
        t[0][i] = 0;
    }

    // Filling the rest of the table:
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // when both the characters are common:
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            // when both the characters are not common:
            else{
                t[i][j] = max(
                    t[i-1][j],
                    t[i][j-1]
                );
            }
        }
    }

    // Printing the LCS String:
    string res = "";

    // for(int i = n, j = m; i>0  && j > 0 ;){
    //     if(s1[i-1] == s2[j-1]){
    //         res += s1[i-1];
    //         i--;
    //         j--;
    //     }
    //     else{
    //         if(t[i-1][j] > t[i][j-1]){
    //             i--;
    //         }
    //         else{
    //             j--;
    //         }
    //     }
    // }

    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        // When there is a match, we will move diagonally upward, by minimizing both the pointer by 1.
        if(s1[i-1] == s2[j-1]){
            i--;
            j--;
            res += s1[i];
        }
        // When we don't have match:
        else{
            // We will check if left i pointer has maximum value stored:
            if(t[i-1][j] > t[i][j-1]){
                i--;    // move to left, by i--
            }
            // else upward j pointer has maximum value:
            else{
                j--;    // move upward, by j--
            }
        }
    }

    reverse(res.begin(), res.end());    // reverse the result

    return res; // return the result
}

void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // Tabulation implemented lcs:
    cout << lcs(s1, s2, n, m) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
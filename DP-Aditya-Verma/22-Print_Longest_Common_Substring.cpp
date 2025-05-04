/*

// Print longest Common Substring Tabulations


// Example:

    Input :  X = "GeeksforGeeks", Y = "GeeksQuiz"
    Output : Geeks

    Input : X = "zxabcdezy", Y = "yzabcdezx"
    Output : abcdez



// Intrusion:
    * This question is simillar to previous questions that we have solved "Longest Common Substring"
    * Here we just need to print the longest common substring.
    * Example: 
        
        s1 = "sahil", s2 = "prahit"

            size => s1 = 5, s2 = 6,

            Create DP table of size t[5+1][6+1]

                -> during the filling of dp table, when we have match case, we fill it with '1', & when we don't have match, we fill it with '0'.

                             p   r   a   h   i   t
                         0   1   2   3   4   5   6 
                   0   | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
                s  1   | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 
                a  2   | 0 | 0 | 0 |[1]| 0 | 0 | 0 | 
                h  3   | 0 | 0 | 0 | 0 |[2]| 0 | 0 | 
                i  4   | 0 | 0 | 0 | 0 | 0 |[3]| 0 | 
                l  5   | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 


            This example shows a single contiguous subarray, but for larger strings, there can be multiple subarrays, and we need to find the maximum size subarray.

            Similar to traversing backward in the "Print LCS" problem, we need a similar approach with some modifications. Specifically, 
            we must traverse backward in the DP table, but first, we must store the maximum size subarray's index locations (row and column).
            By doing this, we can traverse backward and print the longest subarray.

            Let's understand this with a larger example where there are multiple subarrays:


            Example: 

                s1 = sahilsharma(size -> 11)     s2 = princesahilkumar(size -> 15)      O/p: "sahil" -> longest common subarray


                    -> create Dp table of size t[11+1][15+1]

                                p   r   i   n   c   e   s   a   h  i   l   k   u   m   a   r  
                            0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16
                     0    | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
                 s   1    | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[1]| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
                 a   2    | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[2]| 0 | 0 | 0 | 0 | 0 | 0 |[1]| 0 |
                 h   3    | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[3]| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
                 i   4    | 0 | 0 | 0 |[1]| 0 | 0 | 0 | 0 | 0 | 0 |[4]| 0 | 0 | 0 | 0 | 0 | 0 |
                 l   5    | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[5]| 0 | 0 | 0 | 0 | 0 |
                 s   6    | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[1]| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
                 h   7    | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[1]| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
                 a   8    | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[1]| 0 | 0 | 0 | 0 | 0 | 0 |[1]| 0 |
                 r   9    | 0 | 0 |[1]| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[2]|
                 m   10   | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[1]| 0 | 0 |
                 a   11   | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |[1]| 0 | 0 | 0 | 0 | 0 | 0 |[2]| 0 |


                    -> from this table, Possible Common Subarrays are:

                                    a
                                    s
                                    h
                                    r
                                    i
                                    a
                                    ma
                                    sahil
                        


                            -> The longest one is: "sahil"
                            -> While finding the longest common subarray, whenever we encounter a match, we store the index of that subarray (row, column).

                    -> Once we have (row, column), we just need to iterate in the DP table until we reach '0'.
                    -> We can use a while loop to traverse backward and store the characters. At the end, we reverse the string to get our answer.


// Complexity:
    * TC: O(n*m)
    * AS: O(n*m)


*/

#include <bits/stdc++.h>
using namespace std;


string printLongestCommonSubstring(string s1, string s2) {
    // Normal Logic that we used to find size of "longest common Subarray"
    if(s1.empty() || s2.empty()) return "";

    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int> > t(n+1, vector<int> (m+1, 0));
    int len = 0;
    int row = -1, col = -1;     // these variables are used to store the index of "longest common subarray"

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // When we have match case:
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];  // normal logic that we used to do in "longest common subarray"

                // Extra:
                // Check if the new length is greater than the previous length, and update accordingly
                // We need to print longest common substring, this is why we are checking with len variable every time, so that we can store the index:
                if(t[i][j] > len){
                    
                    len = t[i][j];  // Update the maximum length

                    // update row & column for substring part:
                    row = i;
                    col = j;
                }
            }
            else{   // No match case:
                t[i][j] = 0;
            }
        }
    }


    
    // Print the longest common substring from the DP table:
    // If length is zero, means there is no common substring, return empty string.
    if(len == 0){
        return "";  // If no common substring found
    }
    
    // else : we got substring portions from dp table, & we can print it by traversing backward in dp table using (row, col):
    string res = "";    // String to store the result
    
    while(t[row][col] != 0){    // Traverse backward from (row, col) until we reach '0'

        res += s1[row-1];      // Add character to result
        // res += s2[col-1];   // we can also use this one, it will give us same result.
        
        row--;  // Move row back
        col--;  // Move column back
    }
    
    reverse(res.begin(), res.end());   // Reverse the string to get the correct order
    
    return res;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << printLongestCommonSubstring(s1, s2) << endl;

    }
}
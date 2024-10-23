/*

//  Minimum number of insertion in a string to make it a palindrome 


// Problem statement:
    * We are given a string s, & we need to find the minimum number of insertion in order to make this string a palindrome.
    * Example:
        s = "aebcbda"
        
        we need to find the minimum number of element which we can insert in this given string so that we can make this string palindrome.


// Visualization:
    * We will recall the question "Minimum number of deletion in a string to make it a palindrome"
        * We were duplicate that give string & reverse, & then finding the lcs & then we were subtracting form their size, & finding the number of element which we were needed to make our string into a palindrome..
    
    * If we apply Simillar logic, we can convert this string into palindrome by finding lcs first, & then perform some operations...

    * Example:
            s = "aebcbda"

                        a e b c b d a

                        a e d b c b d e a
                            |         |
                            d         e

                        * If we insert "d e" -> in our string we can make this a palindrome...
            

                    [a] e [b] [c] [b] d [a]   -> string
                    [a] d [b] [c] [b] e [a]   -> string.reverse()
                --------------------------------    
                    a      b   c   b     a    -> Reversal of that string

                    -> only {e, d} are two element which are need to be remove that make this string a palindrome.
                    -> or we can say {e, d} are two element which are required to make this string a palindrome.
                    -> So, these are the minimum number of insertion we needed..

// Intrusion:
    * reverse the given string & find lcs of it..
    * After that subtract it from the size, which will give us minimum number of insertion to make our string a palindrome.


// TC: O(n*n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int minimumInsertionToMakePalindrome(string s){
    // Duplicate that string & reverse it.
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int n = s1.size();
    int m = s2.size();
    
    // finding lcs:
    vector<vector<int> > t(n+1, vector<int> (m+1, 0));  // initialize table & fill it with 0.

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // if both the string has same character:
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];  // adding 1 to lcs & minimizing the size of both the string
            }
            // when both the string has different character:
            else{
                t[i][j] = max(
                    t[i-1][j],  // minimizing the size of first string
                    t[i][j-1]   // minimizing the size of second string
                );  // taking maximum from both of them...
            }
        }
    }

    int lcs = t[n][m];  // storing lsc

    // finding the number of insertion which is required to make our string palindrome.
    int requiredNum = n - lcs;  // give string size - lcs size

    return requiredNum;
}

void solve(){
    string s;
    cin >> s;

    cout << minimumInsertionToMakePalindrome(s) << endl; 
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
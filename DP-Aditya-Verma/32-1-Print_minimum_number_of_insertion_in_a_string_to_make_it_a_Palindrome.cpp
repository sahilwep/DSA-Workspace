/*

//  Print Minimum number of insertion in a string to make it a palindrome 


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

                * To print these values, we need to backtrack into our lcs table & store those values which are not matching..
                    
                        string = riaebcbdagi

                            r i a e b c  b d a g i
                            
                            ri[g]a[d]ebcb[e]dagi[r]

                            "gder" -> this is the string which needs to be inserted..


// Intrusion:
    * reverse the given string & find lcs of it..
    * After that subtract it from the size, which will give us minimum number of insertion to make our string a palindrome.
    * After getting lcs, we can backtrack into the table & we will find those value which are not matching, & store that into a temp string, 
    * Print only half of the string, Because half of the strings element will give us all the element which needs to be insertion in order to make our string a palindrome.

// TC: O(n*n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

string PrintMinimumInsertionToMakePalindrome(string s){
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


    int i = n, j = m;
    string pal = "";
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            // pal += s[i-1];
            i--;
            j--;
        }else{
            if(t[i-1][j] > t[i][j-1]){
                pal += s1[i-1];
                i--;
            }else{
                pal += s2[j-1];
                j--;
            }
        }
    }
    while(i > 0){
        pal += s1[i-1];
        i--;
    }
    while(j > 0){
        pal += s2[j-1];
        j--;
    }

    reverse(pal.begin(), pal.end());  // Reverse the string to get the correct order
    // // Print only the first half of the insertion string
    // for(int i=0;i<pal.size()/2;i++){
    //     cout << pal[i];
    // }

    return pal.substr(0, pal.size()/2); // sending only half of the string
}

void solve(){
    string s;
    cin >> s;

    cout << PrintMinimumInsertionToMakePalindrome(s) << endl; 
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}


/*




*/
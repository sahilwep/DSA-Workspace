/*

// Longest Palindromic Subsequence:


//  Problem Statement: 
    * we are given a string 's', & we need to find longest Palindromic Subsequence from it.

// Example:
    S = "bbabcbcab"
    Output: 7
    Explanation: S u b s e q uencebabcbab" is the
    longest subsequence which is also a palindrom
   Example 2:   Input: 
    S = "abcd"
    Output: 1
    Explanation: "a", "b", "c" and "d" are
    palindromic and all have a length 1.



// Visualization:
    
          S = "bbabcbcab"
                    
                        b b a b c b c a b       => string
                          ---------   ---       => Longest Palindromic subsequence
                    ---------------------------------
                        b a b c b a b
                        | | | | | | |
                        | | | | | | |
                        | | |___| | |
                        | |_______| |
                        |___________|

                    -> Longest Palindromic subsequence.


        * If we Visualize this question with lcs:
            * lcs has 2 string -> s1 & s2...
            * We were finding longest common subsequence from both the string...
            * we were finding the common subsequence from both the string.
        
        * Here in Longest Palindromic Subsequence:
            * We are given single string.
            * From that single string we need to find the longest palindromic subsequence.
            * Observation:
                * Palindrome String: reversal of the string is same as original string.
                * Example:
                   
                      s = b b a b c b c a b
                            ---------   ---
                        
                        [b]  b  [a] [b] [c] [b]  c  [a] [b]       -> s
                        [b] [a]  c  [b] [c] [b] [a]  b  [b]       -> s.rev()
                    ----------------------------------------      -> from both the string the ->  lcs are
                        b    a       b   c   b   a       b        -> 7 (Longest Palindrome size)

                                b a b c b a b
                                | | | | | | |
                                | | | | | | |
                                | | |___| | |
                                | |_______| |
                                |___________|

                                Longest palindromic subsequence -> 7

// IntrusioN:
    * we just need to create temp string & reverse it.
    * Pass original string as s1 & temp string as s2
    * get the lcs & that will be our longest palindromic subsequence


// Complexity: 
    * TC: O(n*m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007

// Longest Palindromic Subsequence:
int lps(string s){

    string s1 = s;
    string s2 = s;
    int n = s1.size();
    int m = s2.size();

    reverse(s2.begin(), s2.end());  // reversing one string will find find the longest palindromic subsequence


    // LCS Logic:-------------------------
    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (m+1));

    // filling base cases:
    for(int i=0;i<n+1;i++){
        t[i][0] = 0;
    }

    for(int i=0;i<m+1;i++){
        t[0][i] = 0;
    }


    // filling rest of the table:
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(
                    t[i-1][j],
                    t[i][j-1]
                );
            }
        }
    }

    return t[n][m]; // returning the result
}

void solve(){
    string s;
    cin >> s;

    cout << lps(s) << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
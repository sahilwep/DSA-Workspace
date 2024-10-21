/*

// Shortest Common SuperSequence

//  Problem statement: 
    * we are given two string, s1, & s2, we need to merge them & generate such a string where we will find both the string inside them.


// Example:
    Input:   s1 = “geek”,  s2 = “eke”
    Output: 5
    Explanation: String “geeke” has both string “geek” 
        and “eke” as subsequences.


    Input:   s1 = "AGGTAB",  s2 = “GXTXAYB”
    Output:  9
    Explanation: String “AGXGTXAYB” has both string 
        "AGGTAB" and “GXTXAYB” as subsequences.


// Visualization:
    * Note -> Sequence should be in order, or timely manner.
        sequence -> s[1] -> s[2] -> s[3].. s[n]      This should be in order.
        But it's not necessary that it should be in continuous order.

    Example:
        s1 = "geek", s2 = "eke"

            Possible merge: 
                geekeke -> geek, eke    -> Worse case we will merge it with duplicate
                geeke   -> geek, eke    -> This is the best possible merge 

                geeke -> This is the shortest possible supersequence



    Example:
        s1 = "AGGTAB"   s2 = "GXTXAYB"

            Possible merge: 
                AGGTABGXTXAYB   -> Worse case we will merge it with duplicate
                
                AGGXTXAYB  -> This will be the possible merge, because:

                        AGG T A B   -> s1
                          GXTXAYB   -> s2
                    -----------------
                        AGGXTXAYB   -> Shortest possible merge
        
              
                - - -   -   -   -       => s1
                A G G X T X A Y B
                    - - - - - - -       => s2
                
        
                -  -  -     -     -     -
                A  G [G] X [T] X [A] Y [B]       => common form both of them
                      -  -  -  -  -  -  -
            ------------------------------------

                    G T A B -> This is the common from both of them...
            
        
        * Now, again if we visualize:
            * We get the string that are common from both of them are: "G T A B"
            * Rest remaining string will be unique from both of them: "AGXXY"   -> In both of the string these characters in string are unique.
        
        * If we are given two string: s1 = "AGGTAB"   s2 = "GXTXAYB" 
            * In worse case we will merge them as: 
                                
                                 s1 + s2 =>  AGGTABGXTXAYB

                                 A G G T A B G X T X A Y B      -> from this common elements: 
                                     - - - -
                                     G T A B    -> This is the common element from both of the string 

                    * Previously we were given two string, & we were finding lcs -> Longest common subsequence from two given string.
                             s1 = "A G G T A B"   s2 = "G X T X A Y B" 
                                       - - - -          -   -   -   -
                             lcs = 4 => GTAB
                    


            * So, from this Naive calculated string:
                        
                        s1 + s2 =>  AGGTABGXTXAYB
                                        |
                                /---------------\
                              GTAB              GTAB    -> we are calculating lcs twice in this solution..

                        * If we remove one GTAB from our solution we will get our common super-sequence.
                            * Because in both the string only "GTAB" is common & rest are unique element.
                            * So, if we remove one "GTAB" -> we will have all the values    ->      ((common from both the string) & (unique from both the string))
                    
                        s1 + s2 - lcs => Super-Sequence

            * In simple terms: 
                s1.size() + s2.size() - lcs => length of supersequence.

// Intrusion:
    * Implementation is same as lcs, we just need to subtract lcs from s1.size() + s2.size()


// Complexity:
    * TC: O(n*m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DP Approach: Tabulation
int ShortestCommonSuperSequence(string s1, string s2, int n, int m){

    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (m+1)); // Create a table of variable size from the recursive calls.


    // Filling first row & first col, -> when (n = 0 || m = 0) -> there is no lcs.
    for(int i=0;i<n+1;i++){ // filling first column
        t[i][0] = 0;
    }
    
    for(int j=0;j<m+1;j++){ // filling first row
        t[0][j] = 0;
    }

    // filling the rest of the table:
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // when we have same string character:
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            // when we don't have matching character:
            else{
                // Two options: -> (minimize first string & go form matching) || (minimize second string & go for matching) -> take maximum from both of them.
                t[i][j] = max(
                    t[i-1][j],  // minimizing fist string
                    t[i][j-1]   // minimizing second string
                );  // taking maximum from both of them.
            }
        }
    }

    int lcs = t[n][m];  // lcs

    int scss = n + m - lcs; // super string

    return scss;
}



void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();


    // Tabulation implemented lcs:
    cout << ShortestCommonSuperSequence(s1, s2, n, m) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
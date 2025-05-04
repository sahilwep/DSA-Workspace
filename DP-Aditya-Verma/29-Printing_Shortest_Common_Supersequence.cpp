/*

// Print Shortest Common SuperSequence

//  Problem statement: 
    * we are given two string, s1, & s2, we need to merge them & generate such a string where we will find both the string inside them.
    * We need to print that superSequence.


// Example:


    Input: s1 = "HELLO",  s2 = "GEEK"
    Output: "GEHEKLLO" OR "GHEEKLLO"
    OR Any string that represents shortest 
    supersequence of s1 and s2

    Input:   s1 = “geek”,  s2 = “eke”
    Output: geeke
    Explanation: String “geeke” has both string “geek” 
        and “eke” as subsequences.

    Input:   s1 = "AGGTAB",  s2 = “GXTXAYB”
    Output: "AGXGTXAYB" OR "AGGXTXAYB" 
    OR Any string that represents shortest
    supersequence of s1 and s2



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

            
            * Now, once we got the lcs, we only need to remove those element from the n+m string.

    * Now, for printing lcs: 
        * We were doing back track in matrix table of lcs:
        * i -> n, & j -> m  ==> traverse till 0
        * Whenever we were having match, we used to add those element into our lcs string..
        * At last we were reversing that lcs & return that result..

    * Similarly, in Supersequence 
            => n + m => we were having two lcs, so, we used to subtract one lcs from this (n + m)
            => Now, for Supersequence when we don't have match, will add those element also.
            => because, Supersequence = n(all unique of n) + m(all unique of m) - lcs(lcs only one times)


          - Visualization Example:

                s1 = acbcf   s2 = abcdaf

                                -----> j
                            ∅     a     b     c     d     a     f
            |       ∅    | {0} |  0  |  0  |  0  |  0  |  0  |  0  |
            |       a    |  0  | {1} |  1  |  1  |  1  |  1  |  1  |
            i       c    |  0  | {1} |  1  |  2  |  2  |  2  |  2  |
            |       b    |  0  |  1  | {2} |  2  |  2  |  2  |  2  |
            |       c    |  0  |  1  |  2  | {3} | {3} | {3} |  3  |
            |       f    |  0  |  1  |  2  |  3  |  3  |  3  | {4} |        -> Table


                    -> for element {4} -> Compare (t[i-1][j], t[i][j-1]) => (3, 3) -> same
                    -> first store the result in scs & then move the pointers:
                    -> res = "f"
                    -> move (i--, j--) => diagonally upward

                    -> for element {3} -> Compare (t[i-1][j], t[i][j-1]) => (2, 3) -> not same
                    -> first store the result in scs & then move the pointers:
                    -> as t[j-1]  -> is grater so store s[j-1] -> a
                    -> res = "fa"
                    -> move pointer on the max side -> j-- => leftward

                    -> for element {3} -> Compare (t[i-1][j], t[i][j-1]) => (2, 3) -> not same
                    -> first store the result in scs & then move the pointers:
                    -> as t[j-1]  -> is grater so store s[j-1] -> d
                    -> res = "fad"
                    -> move pointer ont the max side -> j-- => leftward

                    -> for element{3} -> Compare (t[i-1][j], t[i][j-1]) => (2, 2) -> same
                    -> first store the result in scs & then move the pointers:
                    -> as (s1[i-1] == s2[j-1]) -> so, we can store any of them.. -> s1[i-1] -> c
                    -> res = "fadc" 
                    -> move both the pointer i--, j-- => diagonally upward

                    -> for element {2} -> Compare (t[i-1][j], t[i][j-1]) => (1, 1) -> same
                    -> first store the result in scs & then move the pointers:
                    -> as (s1[i-1] == s2[j-1]) -> so, we can store any of them.. -> s1[i-1] -> b
                    -> res = "fadcb" 
                    -> move both the pointer i--, j-- => diagonally upward

                    -> for element {1} -> Compare (t[i-1][j], t[i][j-1]) => (1, 0) -> not same
                    -> first store the result in scs & then move the pointers:
                    -> as t[i-1] -> is greater so store s1[i-1] -> c
                    -> res = "fadcbc"
                    -> move pointer i-- => upward

                    -> for element {1} -> Compare (t[i-1][j], t[i][j-1]) => (0, 0) -> same
                    -> first store the result in scs & then move the pointers:
                    -> as (s1[i-1] == s2[j-1]) -> so, we can store any of them.. -> s1[i-1] -> a
                    -> res = "fadcbca" 
                    -> move both the pointer i--, j-- => diagonally upward

                    -> exit as we have reach to end.
                    

                    -> NOTE: When string size are not same, there were some leftover, which we also need to insert into our result.


                    res = "fadcbca" -> reverse it
                    res = "acbcdaf" -> this is our Supersequence


                    s1 = acbcf   s2 = abcdaf

                            a c b c     f   -> s1
                            a c b c d a f     -> SuperSequence
                            a   b c d a f   -> s2


            * Conclusion: 
                * We will store our lcs as we used to do in print lcs logic, additionally
                * We will add those element also which are unique from both the string..
                * After that we will have to insert the leftover from both the string..
                * At the end we will reverse the result & return it.

// Complexity:
    * TC: O(n*m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DP Approach: Tabulation
string printShortestCommonSuperSequence(string s1, string s2, int n, int m){

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

    int lcs = t[n][m];      // lcs


    // Finding Shortest common superString:
    string superString = "";
    // Storing lcs:
    int i = n, j = m;
    while(i > 0 && j > 0){
        // when we have match:
        if(s1[i-1] == s2[j-1]){
            superString += s1[i-1]; // This will Store the lcs in Supersequence only once
            // minimizing both the pointer -> this will move diagonally upward:
            i--;    
            j--;
        }
        // when we don't have match:
        else{
            // We will store both the element:
            if(t[i-1][j] > t[i][j-1]){
                superString.push_back(s1[i-1]); // first include & then move the pointer -> as [i-1] is greater so, insert s1[i-1]
                i--;   // moving pointer leftward     
            }else{
                superString.push_back(s2[j-1]); // first include & then move the pointer -> as [j-1] is greater so, insert s2[j-1]
                j--;   // moving pointer upward
            }
        }
    }


    // Filling leftover in i & j or from both of the string:
    while(i > 0){
        superString.push_back(s1[i-1]);
        i--;
    }
    
    while(j > 0){
        superString.push_back(s2[j-1]);
        j--;
    }


    reverse(superString.begin(), superString.end());    // reversing the result

    return superString; // return the result.
}


void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();


    // Tabulation implemented lcs:
    cout << printShortestCommonSuperSequence(s1, s2, n, m) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
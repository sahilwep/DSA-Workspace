/*

//  Minimum Number of Insertion and Deletion to convert String a to String b 

// Problem Statement:
    * We are given two string s1, & s2, 
    * we need to remove or insert as minimum element as possible, 
    * in order to transform string s1 into s2.
    * It could be possible that we will have to remove no element if both of the string is same.
    * In simple words we need to perform insertion & deletion operation in string s1, so that it can be equal to s2.


// Example:

    Input : s1 = "heap", s2 = "pea" 
    Output : 3
        Minimum Deletion = 2 and
        Minimum Insertion = 1
    Explanation:
        p and h deleted from heap
        Then, p is inserted at the beginning
        One thing to note, though p was required yet
        it was removed/deleted first from its position and
        then it is inserted to some other position.
        Thus, p contributes one to the deletion_count
        and one to the insertion_count.

                        (13 - 5 = 8) +   (5 - 5 = 0) => 8
    Input : str1 = "geeksforgeeks", str2 = "geeks"
    Output: 8
    Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".


// Visualization:

            Input : s1 = "heap", s2 = "pea"   =>        Output : 3

                -> worse case:

                        h e a p  ->    p e a

                        p [e] [a]
                        h [e] [a] p
                    ------------------
                           [e]  [a]     -> lcs = 2

                    deletion_from_S1 => s1 - lcs => 4 - 2 = 2
                    insertion_into_S1 => s2 - lcs => 3 - 2 = 1
                
                    total = deletion_from_S1 + insertion_into_S1
                    
                    total = 3
                

                Input : s1 = "geeksforgeeks", s2 = "geeks"          Output: 8
                    
                    n = 13, m = 5
                    lcs = 5

                    deletion_from_S1 = s1 - lcs     // from here we will get the element that are not fall into lcs & needs to be removed from s1, in order to make s1 -> s2
                    insertion_into_S1 = s2 - lcs    // we will get the element that are not fall into lcs in s2, & needs to be inserted into s1.

                    total = deletion_from_S1 + insertion_into_S1 
                    total = (13 - 5) + (5 - 5)
                    total = 8
        

        
// Intrusion:
    * calculate lcs
    * Perform this operations:
        * deletion_from_S1 => s1 - lcs
        * insertion_into_S1 => s2 - lcs 
    * Find total => insertion_into_S1 + deletion_from_S1




// Complexity:
    * TC: O(n*m)
    * AS: O(n*m)    -> DP - Table       n = s1.size(), m = s2.size()



*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


int longestInsertionDeletion(string s1, string s2, int n, int m){

    // Initialization: 
    vector<vector<int> > t(n+1, vector<int> (m+1));

    // Filling the first row & first column as ((n || m) == 0) -> there is no common subsequence.
    for(int i=0;i<n+1;i++){ // filling the first column
        t[i][0] = 0;
    }

    for(int i=0;i<m+1;i++){ // filling the first row
        t[0][i] = 0;
    }

    // Filling the rest of the table:
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // if character of string are same:
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];  // add 1 to the diagonally upward element & store it in current -> [i][j]
            }
            // if character of string are not same:
            else{
                // we will have two options: -> minimize size of first element / minimize size of second element & take maximum from both of them..
                t[i][j] = max(
                    t[i-1][j],  // minimizing the size of first string.
                    t[i][j-1]   // minimizing the size of second string.
                );
            }
        }
    }

    int lcs = t[n][m];
    int deletion_from_S1 = n - lcs;
    int insertion_into_S1 = m - lcs;
    int total = insertion_into_S1 + deletion_from_S1;

    return total;
}


void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();


    // Tabulation implemented lcs:
    cout << longestInsertionDeletion(s1, s2, n, m) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
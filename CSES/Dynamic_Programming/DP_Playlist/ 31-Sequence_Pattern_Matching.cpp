/*

//  Sequence Pattern Matching 


//  Problem Statement: 
    * We are given two string s1 and s2, we need to find whether the string s1 is present in string s2 as a subsequence or not?
    * Example:
            s1 = "AXY"      s2 = "ADXCPY"

            * We need to check whether string s1, is present in s2 as a subsequence or not?


// Visualization:
    * Relate this question with lcs:
    * In lcs, we were finding common subsequence from both the string...
        
        s1 = "AXY"      s2 = "ADXCPY"

        lcs = AXY, because AXY is present in s2

        Think logically, if we found lcs from both the string, & those lcs has all the value of string s1, we can say that sequence is matching..

        IF by any change LCS = AX -> "Y" is missing, so we can't say it's matching..

        This means after finding the lcs, if lcs is equal to string s1, we can say it's matching, else it's not matching..


// Intrusion: 
    * First we will find the lcs form both the string..
    * If lcs string is matched with s1, we will say, sequence is matching..
    * or, if lcs string size is matched with s1, we can directly say it's matching..


// TC: O(s1.size() * s2.size())


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Function to find the sequence pattern matching:
int SequencePatternMatching(string s1, string s2){

    // LCS Logics:
    // Initialization:
    vector<vector<int> > t(s1.size() + 1, vector<int> (s2.size() + 1));

    // filling the base case:
    for(int i=0;i<s1.size();i++){   // when s2.size() == 0
        t[i][0] = 0;
    }
    for(int i=1;i<s2.size();i++){   // when s1.size() == 0
        t[0][i] = 0;
    }

    // filing the rest of the table:
    for(int i=1;i<s1.size()+1;i++){
        for(int j=1;j<s2.size()+1;j++){
            // when both the string characters are matched..
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];  // adding 1 to result & minimizing both string size.
            }
            else{
                // if we have unmatched case: take max(s1.size() - 1, s2.size()-1)
                t[i][j] = max(
                    t[i-1][j],  // minimizing the size of first string.
                    t[i][j-1]   // minimizing the size of second string.
                );  // taking maximum from both of them.
            }
        }
    }

    int lcs = t[s1.size()][s2.size()];      // getting the lcs



    // Method 1: we will extract lcs string & then match with it..
    // if lcs is equal to that given pattern s1, we will say it's true : otherwise it's false
    // int i = s1.size(), j = s2.size();
    // string lcsStr = "";
    // while(i > 0 && j > 0){
    //     if(s1[i-1] == s2[j-1]){
    //         lcsStr += s1[i-1];
    //         // minimizing both the pointers.
    //         i--;
    //         j--;
    //     }
    //     else{
    //         if(t[i-1][j] > t[i][j-1]){
    //             i--;    // minimizing the first pointer
    //         }else{
    //             j--;    // minimizing the second pointer
    //         }
    //     }
    // }

    // reverse(lcsStr.begin(), lcsStr.end());    // reverse the string

    // return (lcsStr == s1);      // if it's equal then we can say it's the subsequence...



    // Method 2: we know the size of string s1, & if the lcs is equal to the s1 size, we will say true..
    return (lcs == s1.size());
}

void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    (SequencePatternMatching(s1, s2)) ? cout << "Yes" : cout << "No";
    cout << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
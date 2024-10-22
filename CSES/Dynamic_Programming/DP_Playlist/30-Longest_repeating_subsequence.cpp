/*

//  Longest repeating subsequence 


//  Problem Statement:
    * we are given a string s, we need to find the longest repeating subsequence form that string.
    * In simple we need to find the string which is repeating as subsequence.


// Example:
    Input: str = "abc"
    Output: 0
    There is no repeating subsequence

    Input: str = "aab"
    Output: 1
    The two subsequence are 'a'(first) and 'a'(second). 
    Note that 'b' cannot be considered as part of subsequence 
    as it would be at same index in both.

    Input: str = "aabb"
    Output: 2

    Input: str = "axxxy"
    Output: 2


// Visualization: 
    * Example:
            s = "AABEBCDD"

                        A A B E B C D D


                lrs = 3 ->       AA BB DD           -> this is longest repeating subsequence.


                -> From this string we have, found longest repeating subsequence..

                            A A B E B C D D
                            -   -       -

                        -> "ABD" this can also be a subsequence, but it's not repeating..

                        -> Once we get any subsequence, we need to remove those element from our string, & then again we will find that subsequence, if that subsequence is found, 

                            A A B E B C D D
                            --  -   -   - -

                        -> This is the repeating subsequence.

                        -> Let say, If we have multiple repeating subsequence, the from these we will have to find the longest.
                        
                            A A B E B C D D
                            --  -   -   - -

                            Possible Subsequences:
                                A B
                                A D
                                A B D
                                ...
                            
                            -> From all of these, we will have to find the longest one, which is "ABD"

                
                -> We will have to print the length of longest repeating subsequence -> 3
                
                -> Conclusion:
                    We are given a string, & we will be finding the subsequence which is longest & repeating..
            

    * Coming back on point => longest repeating subsequence:

                    string = A A B E B C D D
                
                * If we visualize this: 

                        A A B E B C D D
                        - - -   -   - -
                
                * We need only repeating value from our string

                * If we duplicate this string & try to observe this with lcs:

                    s1 =     A A B E B C D D
                    s2 =     A A B E B C D D
                             - - - | - | - -

                        -> '|' = (E, B), We don't need these values..
                        -> These values lies on same index on both the string..


                * But If we observe with index:

                        index:       0 1 2 3 4 5 6 7
                            s1 =     A A B E B C D D
                            s2 =     A A B E B C D D
                        index:       0 1 2 3 4 5 6 7
                                     _ _ _   _   _ _ 
                                     A A B   B   D D

                            -> "AABBDD" -> these value also lies on same index,

                            -> But if we carefully observe the repeating characters from both the string:

                                           3
                                    s1 =   E 
                                    s2 =   E
                                           3
                            
                            -> In both the string E is lcs, but their index is same..
                            -> If we observe a case when we have duplicate values:

                                           0   1
                                    s1 =  [A]  A
                                    s2 =   A  [A]
                                           0   1

                            -> These two [A], from both the string lies on the different index on both the string.
                            -> Although, these also lies on same index as well, but we will focus here when we have same character that falls on different index.
                            -> for any repeating values in our string, we will always have different index if we duplicate the string...
                            -> and if we want only those value which are repeating in string, "we can choose those common value which are not in same index"


                        * Logically if we see:
                            * repeating values fall on different index on the same string..

                              s =    A A B E B C D D
                                     0 1 2 3 4 5 6 7    -> index
                                     | | 

                                duplicate values

                            * So, if we duplicate same sting & find the lcs, with constrains that index of both the string should not be same.
                            * then we can find the longest repeating subsequence.
                        
                        * It's logical that, we need only those value which are longest repeating subsequence..
                        * In lcs we use to find the longest common subsequence from two string..
                            * In lcs if we choose those values which has different index, we can find longest repeating subsequence.


// Code Variations:
    * In LCS, when we have matching case, we will choose those values only which are not in same index.
    * This is how we can get the longest repeating subsequence.
    * NOTE: During matching (i != j) -> for case lrs


// TC: O(n*n)



*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Longest repeating subsequence
int lrs(string s){
    // Duplicate same string:
    string s1 = s;
    string s2 = s;
    int n = s1.size();
    int m = s2.size();


    // lcs:
    vector<vector<int> > t(n+1, vector<int> (n+1, 0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            // if we have match & index are not same: -> case for repeating character, which are valid to become substring..
            if(s1[i-1] == s2[j-1] && i != j){
                t[i][j] =  1 + t[i-1][j-1];     // by adding 1 to the lcs result, we can get the longest subsequence...
            }
            // when we don't have any match:
            else{
                t[i][j] = max(
                    t[i-1][j],  // minimizing the first string
                    t[i][j-1]   // minimizing the second string
                );  // getting maximum from both of them.
            }
        }
    }

    return t[n][m];     // return lrs
}

void solve(){
    string s;
    cin >> s;

    cout << lrs(s) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
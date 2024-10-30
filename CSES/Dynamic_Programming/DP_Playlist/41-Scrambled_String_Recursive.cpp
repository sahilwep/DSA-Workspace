/*

//  Scrambled String Recursive 



//  Problem Statement:
    * Given two string s1, & s2 of equal length, the task is to determine if S2 is scrambled from S1.
    * Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
    * Below is one possible representation of str = coder:

                            coder
                           /    \
                          co    der
                         / \    /  \
                        c   o  d   er
                                   / \
                                  e   r 

        * To scramble the string, we may choose any non-leaf node and swap its two children. 
        * Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
        * Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.

    * Note: Scrambled string is not same as an Anagram


    * Example:

                Below is one possible representation of str = “coder”:

                            coder
                           /    \
                          co    der
                         / \    /  \
                        c   o  d   er
                                   / \
                                  e   r

                To scramble the string, we may choose any non-leaf node and swap its two children. 
                Suppose, we choose the node “co” and swap its two children, it produces a scrambled string “ocder”.


                            ocder
                           /    \
                          oc    der
                         / \    /  \
                        o   c  d   er
                                   / \
                                  e   r

                Thus, “ocder” is a scrambled string of “coder”.
                Similarly, if we continue to swap the children of nodes “der” and “er”, it produces a scrambled string “ocred”.


                            ocred
                           /    \
                          oc    red
                         / \    /  \
                        o   c  re  d
                               / \
                              r   e

                Thus, “ocred” is a scrambled string of “coder”.


// Example:

    Input: S1="coder", S2="ocder"
    Output: Yes

    Explanation: ocder is a scrambled form of coder.
    
            ocder
           /    \
          oc    der
         / \    
        o   c  
    

    As "ocder" can represent it as a binary tree by partitioning it into two non-empty substrings. 
    We just have to swap 'o' and 'c' to get "coder".

    
    
    Input: S1="abcde", S2="caebd" 
    Output: No

    Explanation: caebd is not a 
    scrambled form of abcde.



// Visualization: 

            From given string: s1 = "great",   s2 = "rgeat"

            We can break this into binary tree ->  2 childs

                            great
                           /    \
                          gr    eat
                         / \    /  \
                        g   r  e   at
                                   / \
                                  a   t 

            Empty child are not allowed:

                            great
                            /   \
                      "great"    ""     -> Not allowed

            
            * For a given string whether is't scrambled or not?
            * For scrambled we have two choices:

                        [Scrambled ?] 
                          /       \
                    [Swapped]    [Not Swapped]
            

            Swapped case: 

                    s1                       s2
                [------|-----]          [------|-----]    
                    |      |                |     |
                    |      |________________|     |
                    |                             |
                    |_____________________________|

                    we will have to perform checking on these part of string                           
            
            Not-Swapped case: 

                    |-----------------------|
                    |                       |                  
                [------|-----] S1       [------|-----] S2 
                          |                       |
                          |                       |
                          |                       |
                          |_______________________|

                    we will have to perform checking on these part of string


        * If any of the decision tree gives true result, we will say -> "Scrambled" : else say "Not Scrambled"



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool isScramble(string s1, string s2){
    // Condition when both string are matched -> string1.compare(string2) -> return 0 if it's equal
    if(s1.compare(s2) == 0){
        return 1;   // scrambled
    }


    // If string is of empty or 1 size, we will say not scrambled, we can check any of the string.
    // From the above Base condition, that will handel the case when we have both have single characters & were equal.
    // It will handel the case when we have single character & that is not not equal, from the above base case...
    if(s1.size() <= 1){
        return 0;   // not scrambled, as single characters are not equal
    }

    int n = s1.size();
    bool isScrambleFlag = false;
    // iteration start from 1 & goes up to n-1.
    for(int i=1;i<=n-1;i++){
        // Condition1 = Swapped case
        if(isScramble( s1.substr(0, i), s2.substr(n-i, i)) && isScramble( s1.substr(i, n-i), s2.substr(0, n-i))){
            isScrambleFlag = true;
            break;
        }

        // Condition 2 -> Not swapped case
        if(isScramble( s1.substr(0, i), s2.substr(0, i)) && isScramble( s1.substr(i, n-i), s2.substr(i, n-i))){
            isScrambleFlag = true;
            break;
        }
    }

    return isScrambleFlag;
}


void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    

    // Initials Checks:
    if(n != m){ // when length is different -> Not scrambled
        cout << "No" << endl;
        return;
    }
    if(n == 0 || m == 0){   // when both string empty -> Scrambled
        cout << "Yes" << endl;
        return;
    }

    (isScramble(s1, s2)) ? cout << "Yes" : cout << "No";
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
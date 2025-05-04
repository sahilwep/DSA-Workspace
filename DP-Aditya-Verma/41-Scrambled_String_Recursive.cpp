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



// Problem Visualization: 

        // We are given a problem where we have to check the string is scrambled or not?
    
            * From given string: s1 = "great",   s2 = "rgeat"

            * We can break this into binary tree ->  2 childs
            * Possible breaks:

                            great            |               great               |          ...
                           /    \            |               /   \               |          ...
                          gr    eat          |             gre   at              |          There are multiple cases also..
                         / \    /  \         |            /  \   / \             |
                        g   r  e   at        |          g    re  a   t           |
                                   / \       |              /  \                 |
                                  a   t      |             r    e                |


            * But, Empty child are not allowed:

                            great
                            /   \
                      "great"    ""     -> Not allowed

            * We are allowed to swap Non-Leaf Nodes:

                           [great]        
                           /    \        
                         [gr]   [eat]      
                         / \    /  \     
                        g   r  e   [at]    
                                   / \   
                                  a   t  

                We can perform zero or more swapping on non-leaf node: -> means we can swap non-leaf childs
                If we swap "[gr]" childs -> (g, r)

                            rgeat            
                           /    \            
                          rg    eat             
                         / \    /  \         
                        r   g  e   at        
                                   / \       
                                  a   t      

                Binary tree looks something like this, & string "great" becomes "rgeat"
                So, these string "great" & "rgeat" are scrambled.
                Similary we can perform more swapping, like: "gr" & "eat", if we swap both of them the final string becomes -> "rgate" & these both string are scrambled.


        // Identification of MCM:
            * We can swap at any possible string & form scrambled strings.
            * So we can divide this string at every possible index.
        
        // MCM Format: 

            // Identification of i & j

                s = "great"

                Possible (i & j): 
                    
                       0   1   2   3   4
                     [ g | r | e | a | t ]
                       i
                
                    If we will take i = 0

                     [  ][g r e a t]
                          i
                    we will have one emtpy string, which is not valid for the given conditions..
                    So, we will take i = 1
                    
                       0   1   2   3   4
                     [ g | r | e | a | t ]
                           i
                    
                    Now, If we will take j = n-1
                    
                       0   1   2   3   4
                     [ g | r | e | a | t ]
                           i           j

                     [g r e a ][ t ]
                                 j  

                    We will have valid partition, So we will take i = 1 &  j = n - 1
                
                Possible Partition: 
                    i = 1
                    j = n-1



            // Visualization Of decisions:
                
                * We are given a string & we need to find whether strings are scrambled or not?

                          [gr|eat]         
                           /    \         
                         [gr]   [eat]       
                         / \    /  \      
                        g   r  e   [at]     
                                   / \    
                                  a   t   
                        
                        We can swap these non-leaf values..

                * If we have Not swapped the non-leaf values of string

                            gr|eat         
                           /    \         
                          gr    eat       
                         / \    /  \      
                        g   r  e   at     
                                   / \    
                                  a   t   

                            "great" & "great"   -> Scrambled String
                
                * If we have swapped the non-leaf values of string

                            gr|eat         
                           /     \         
                          eat     gr       
                         / \     /  \      
                        e   at  g   r     
                            / \    
                           a   t 

                        Now, we have swapped "gr" & "eat", new string will formed -> "eatgr"

                            "great" & "eatgr"   -> Scrambled String


                * From This visualization, we can say, for every 'i' we have two cases:

                    * Ether string can be "swapped" OR "Not-swapped"
                    * We can further solve the rest of string by swapping, but that is different things..
                    * But, the pattern we want to observe is: we will have two condition -> "Swapped" & "Not-Swapped"
                    * So, we can say for every index of 'i', either our string is "swapped" or "Not-Swapped"
                    

                            * For scrambled we have two choices:
                            
                                        [Scrambled String] 
                                        /       \
                                    [Swapped]    [Not-Swapped]  -> It can be divide into two possible Conditions.



                                    We are at: i = 2:

                                    Swapped:       "g r | e a t"        "e a t | g r"

                                    Not Swapped:   "g r | e a t "       "g r | e a t"

                                
                                * If we observe the pattern, for "Swapped" case: 
                                        
                                        "g r | e a t"        "e a t | g r"
                                         ---                         ----
                                          |___________________________|

                                        
                                        "g r | e a t"        "e a t | g r"
                                              ------          ------
                                                |________________|


                                    We have to match these Portions of strings.
                
                                
                                * If we observe the pattern, for "Not-Swapped" case: 
                                        
                                        "g r | e a t"        "g r | e a t"
                                         ---                  ---
                                          |____________________|


                                        "g r | e a t"        "g r | e a t"
                                               ------               ------
                                                 |____________________|

                                    We have to match these Portions of strings.


                                * We will check these recursively, so that we can further divide & check...
                                * From these two decision, if any of them is correct, we can say given string is scrambled..


                            * More Visualized Explanation:

                                * Swapped case: 

                                        s1                       s2

                                    [------|-----]          [------|-----]    
                                        |      |                |     |
                                        |      |________________|     |
                                        |                             |
                                        |_____________________________|

                                        we will have to perform checking on these part of string                           

                                * Not-Swapped case: 

                                        |-----------------------|
                                        |                       |                  
                                    [------|-----] S1       [------|-----] S2 
                                            |                       |
                                            |                       |
                                            |                       |
                                            |_______________________|

                                        we will have to perform checking on these part of string


                                * If any of the decision tree gives true result, we will say -> "Scrambled" : else say "Not Scrambled"

                                * Concluding the conditions:
                                                            s1                  s2
                                    Condition 1:        0 1   2 3 4          0 1 2 3 4 5
                                        Swapped:       "g r | e a t"        "e a t | g r"   -> S1 break at i = 2 
                                                            i                      i
                                            Checks:
                                                s1.substr(0, i) == s2.substr(n-i, i) && s1.substr(i, n-i) == s2.substr(0, n-i)   -> Matched ?


                                    Condition 2:        0 1   2 3 4          0 1   2 3 4
                                        Not-Swapped:   "g r | e a t "       "g r | e a t"   -> S1 break at i = 2
                                                            i                    i
                                            Checks:
                                                s1.substr(0, i) == s2.substr(0, i) && s1.substr(i, n-i) == s2.substr(i, n-i)    -> Matched ?


                                    If any of the string is returning true: -> We can say string are scrambled
                                        if( Condition1 == true || Condition 2 == true){
                                            return "Scrambled";
                                        }

                    * let say function names is isScramble(string s1, string s2) -> and have 2 string parameter:
                    * We will recursively check the string Portions: 


                        if(isScramble( s1.substr(0, i), s2.substr(n-i, i)) && isScramble( s1.substr(i, n-i), s2.substr(0, n-i)))        -> Cond. 1
                                        
                                        OR

                        if(isScramble( s1.substr(0, i), s2.substr(0, i)) && isScramble( s1.substr(i, n-i), s2.substr(i, n-i)))          -> Cond. 2
                        
                            -> return true, if any of them answer true.


                    * This is nothing but, 

                            if(isScramble(smaller_s1, smaller_s2) && isScramble(smaller_s1, smaller_s2))    -> Cond. 1
                                                || OR
                            if(isScramble(smaller_s1, smaller_s2) && isScramble(smaller_s1, smaller_s2))    -> Cond. 2


                            -> any of the conditions are true, return true.
                                        


            // Identification of Valid Base case:

                * Base Condition: Think of the smallest valid input:

                    If length of the string are not equal:

                        s1 = "great",   s2 = "rgreat"   -> Not valid

                        Whatever number of swaps we can do, the length remains same.
                        So, we can say if length is not equal, string are not scrambled -> return false.

                    
                            if(s1.size() != s2.size()) -> return false

                    if both string is empty:
                        s1 = "",    s2 = ""     -> Scrambled

                                if(s1.empty() && s2.empty()) -> return true
                        

                * NOW, when string further divides, & eventually when strings are equal => return true:

                    * recursive Checks:
                            |-------|
                        gr|eat  gr|ate
                        |________|     

                                gr == gr -> return true..

                        Now when "eat" & "ate" -> not matched, it will checks recursively..
                        It's look like swapped case of "eat" -> "ate"
                            
                            |--------------|
                            e|at        at|e
                              |__________|

                        After the recursive calls & spliting the string, we will have:

                            (e == e) and (at == at)

                    So, eventually it's matched..
                
                So, i just want to say that when the string are matched -> return true.
                
                            if(s1.compare(s2) == 0) -> return 0;                when compare function return 0, means string are equal.

                
                * Last base case, when we are dividing string in every recursive calls, if any of the string is empty we will return false

                            if(s1.size() <= 1) -> return false          -> we can check any of the string s1/s2, doesn't matter, because substring() partition happened with same size..

                        here, we are using equal condition, because from the above base condition if both string is of size 1, & they are not equal, then return "false"

                        means -> s1 = "a",  s2 = "a" -> string size is equal, so it will executes from the above base condition..
                        But, if s1 = "a",   s2 = "b" -> string size is equal, but string are not equal, because it doesn't fall in above base condition, so we will return "false"



            // Function Definition: 
                We will have to return our answer in True / False, & we are given two string as a parameter:

                    bool isScrambled(string s1, string s2){
                        // logic                   
                    }

                Now, we will write our base case:

                    bool isScrambled(string s1, string s2){
                        if(s1.compare(s2) == 0) return true;
                        if(s1.size() <= 1) return false;

                        int n = s1.size();
                        
                        bool isScrambledString = false;     // this flag will help us to break from the loop & return the value..

                        // we will break our string from 1 to n-1 & recursive check for scrambled string..
                        for(int i=1;i<=n-1;i++){
                            // if(condition_1 == true || condition_2 == true){
                                isScrambledString = true;
                                break;
                            }
                        }

                        return isScrambledString;
                    }

// Complexity: 
    * TC: O(2^n)
        * We are taking two decision from the decision tree, & going up to n possibility..
        * This is why we have 2^n, & it's exponentially high for larger input...
        * We will fix this using memoization.


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


    // we are taking string length, as string s1/s2 has same size so we can take any of them
    // because every time in recursive calls, we will have smaller portions of substring as a parameter.
    int n = s1.size();  


    bool isScrambleFlag = false;    // flag is used to check whether any of the condition return true or not, based on that we will return string is scrambled or not.

    // iteration start from 1 & goes up to n-1.
    for(int i=1;i<=n-1;i++){
        // If any of the string return true -> return true.
        // Condition1 = Swapped case -> Checks => (s1.first == s2.last) && (s1.last == s2.first)
        if(isScramble( s1.substr(0, i), s2.substr(n-i, i)) && isScramble( s1.substr(i, n-i), s2.substr(0, n-i))){
            isScrambleFlag = true;
            break;
        }

        // Condition 2 = Not swapped case -> Checks => (s1.first == s2.first) && (s1.last == s2.last)
        if(isScramble( s1.substr(0, i), s2.substr(0, i)) && isScramble( s1.substr(i, n-i), s2.substr(i, n-i))){
            isScrambleFlag = true;
            break;
        }
    }

    return isScrambleFlag;  // returning the flag value, whether they are swapped or not?
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
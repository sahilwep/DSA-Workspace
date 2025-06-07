/*

//  3170. Lexicographically Minimum String After Removing Stars


//  Problem Statement: 
-> You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
-> While there is a '*', do the following operation:
    -> Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
-> Return the resulting string after removing all '*' characters.

 
// Example: 
    Example 1:
        Input: s = "aaba*"
        Output: "aab"
        Explanation: We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

    Example 2:
        Input: s = "abc"
        Output: "abc"
        Explanation: There is no '*' in the string.


// Observations: 
    -> We are given a string contains '*'
    -> We have to remove all the stars from the string:
        -> for every stars check it's first smallest character & remove that from our answer.
        
    // BruteForce Approach: 
        -> Maintain a vector flagged which will keep track of every removed characters from string.
        -> For every '*' iterate from 0 to that index & get the index of last smallest character, & mark as flagged
        -> Now at last build answer by iterating in flagged & make sure to remove every '*' while iterating..


        // Complexity:  
            -> TC: O(N^2)
            -> SC: O(N)



    // Efficient Approach: 
        -> Now, for every stars, we only need to take care of how we can efficiently get the recent leftside smaller character index, so that we can exclude that from our answer.
        -> How we can achieve that ?
            -> LIFO: Last in First out => Stack yes
            -> Stack stores in LIFO order & for every character if we use stack, on top of stack we can get the recent pushed index
                -> Example:
                    "a a a a a" 
                     0 1 2 3 4      index
                     -----> move from 0 to s.size()


                     stack:| 4  |  <--- top element
                           | 3  |
                           | 2  |
                           | 1  |
                           | 0  |
                           ------
                             a
            -> We are working with only 26 characters, so we can use an array of stack for size 26 only:

                    |   |   |   |   |   |   ...     |   |
                    |   |   |   |   |   |   ...     |   |
                    |   |   |   |   |   |   ...     |   |
                    |   |   |   |   |   |   ...     |   |
                    -----   -----   -----   ...     -----
                      a       b       c               d

            -> While we move in string & we will hash every characters index

        -> now EveryTime when we got any '*' from string: 
            -> we can check our array freq(26): 
                -> get the first non-empty stack, which will be our smaller character
                -> get the top index from that character stack & pop() out that element from the stack.
                -> Now mark that index as flagged, so that we can exclude that index while build our answer.
                    -> we can directly overwrite s[i] = '*' so that that character index will be marked as flagged.
                            

        -> Example: 
            "a a b * a b c * a"
             0 1 2 3 4 5 6 7 8

                Stack: {a:
                        b:
                        c:
                        }  
            
            i = 0: 
                "a a b * a b c * a"
                 0 1 2 3 4 5 6 7 8
                 |
                 
                Stack: {a: 0
                        b:
                        c:
                        }  
            
            i = 1: 
                "a a b * a b c * a"
                 0 1 2 3 4 5 6 7 8
                   |

                Stack: {a: 0 1
                        b:
                        c:
                        }  
            
            i = 2: 
                "a a b * a b c * a"
                 0 1 2 3 4 5 6 7 8
                     |

                Stack: {a: 0 1
                        b: 2
                        c:
                        }  
            
            i = 3: 
                "a a b * a b c * a"
                 0 1 2 3 4 5 6 7 8
                       |
                    For Star => iterate in freq & remove the first character stacks top() index

                Stack: {a: 0 [1]
                        b: 2
                        c:
                        }  

            i = 4: 
                "a * b * a b c * a"
                 0 1 2 3 4 5 6 7 8
                         |

                Stack: {a: 0 4
                        b: 2
                        c:
                        }  

            i = 5: 
                "a * b * a b c * a"
                 0 1 2 3 4 5 6 7 8
                           |

                Stack: {a: 0 4
                        b: 2 5
                        c:
                        }  

            i = 6: 
                "a * b * a b c * a"
                 0 1 2 3 4 5 6 7 8
                             |

                Stack: {a: 0 4
                        b: 2 5
                        c: 6
                        }  

            i = 7: 
                "a * b * a b c * a"
                 0 1 2 3 4 5 6 7 8
                               |
                    For Star => iterate in freq & remove the first character stacks top() index

                Stack: {a: 0 [4]
                        b: 2 5
                        c: 6
                        }  

            i = 8: 
                "a * b * * b c * a"
                 0 1 2 3 4 5 6 7 8
                               |
                    For Star => iterate in freq & remove the first character stacks top() index

                Stack: {a: 0 8
                        b: 2 5
                        c: 6
                        }  

            => Final String: a * b * * b c * a
            => Result: a b b c a
            
        // Complexity:
            -> TC: O(n)
            -> SC: O(26 * n) => O(n)



// Extra -----------------------------------------------
    -> In this question we are required to perfrom some operations on recent hashed smaller || larger character use used LIFO => stack
    -> Now, if we required to perfrom some operations on first hashed smaller || larger character dpending upon the conditions, we will use FIFO => queue
    -> Similarly Observe the requirement & build our data-Structure to solve problems..
    

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: 
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        
        vector<stack<int>> freq(26); // used to store every characters index in LIFO Order, because we have to remove the first leftmost smaller character to every '*'
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {   // when we have non-stars:
                freq[s[i] - 'a'].push(i);    // for every character hash their index
            } 
            else { // when we have stars:
                // Remove the first smallest character from the left side to the star:
                for(int j = 0; j < 26; j++) {
                    if(!freq[j].empty()) {
                        int idx = freq[j].top();    // get the recent hashed index from stack
                        freq[j].pop();              // remove that hashed index from the stack 
                        s[idx] = '*';               // overwrite in s[i], so that we can skip that character.
                        break;                      // no-need to proceed further, our job is done
                    }
                }
            }
        }

        string ans = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') ans += s[i];
        }

        return ans;
    }
};


// BruteForce Solution: 
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();

        vector<bool> flagged(n, 1);
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                // For every '*' find it's rightMost minimum:
                char min = 'z';
                int idx = -1;
                for(int j = 0; j < i; j++) {
                    if(s[j] == '*') continue;   // skip stars.
                    // if we got any lesser value && that value is not yet visited.
                    if(min >= s[j] && flagged[j] == 1) {   // get the rightmost minimum before stars 
                        min = s[j];
                        idx = j;
                    }
                }

                // minimum found:
                if(idx != -1) {
                    flagged[idx] = 0;   // mark idx as invalid index in flagged
                }
                flagged[i] = 0; // also mark * as invalid index
            }
        }

        // Build answer: 
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(flagged[i] == 1) {
                ans += s[i];
            }
        }

        return ans;
    }
};
/*

//  2516. Take K of Each Character From Left and Right


//  Problem Statement: 
    * You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. 
    * Each minute, you may take either the leftmost character of s, or the rightmost character of s.

    * Return the minimum number of minutes needed for you to take at least k of each character, 
    * or return -1 if it is not possible to take k of each character.


// Example: 


    Example 1:
        Input: s = "aabaaaacaabc", k = 2
        Output: 8
        Explanation: 
        Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
        Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
        A total of 3 + 5 = 8 minutes is needed.
        It can be proven that 8 is the minimum number of minutes needed.

    Example 2:
        Input: s = "a", k = 1
        Output: -1
        Explanation: It is not possible to take one 'b' or 'c' so return -1.



// Visualization:
    -> According to the question we need to delete atleast k time 'a', 'b', 'c', from the leftmost or rightmost of string.
    -> We need to follow this: (cntA >= k && cntB >= k && cntC >= k) -> Then only return the answer, else return -1
    -> Approach:
        -> We need to select a window in which this above condition satisfy.
        -> We can use sliding window, technique, but first let's think this question in opposite manner:
            
        -> Let's assume we have deleted all the element form the string: 
        -> By deleting, mean store all the element frequency somewhere.
            -> if we delete all the element form string, & the above condition not satisfy, then return '-1'
                -> if(cntA < k || cntB < k || cntC < k) -> if any count is less than k, we can't generate answer.
            
            -> Else, if condition satisfy: if(cntA >= k && cntB >= k && cntC >= k):
                -> now we have frequency count of every element {a:x-times, b:y-times, c:z-times}
                -> Now, we will start removing element from the frequency count one by one, until (cntA >= k && cntB >= k && cntC >= k) this condition satisfied..
                -> By doing this, we can create a window, which represent {minuteAsked = (n - deletedElement)}
                -> We can use dynamic size sliding window, which will maximize it's size until this (cntA >= k && cntB >= k && cntC >= k) condition is satisfied, and we will find the maximum size window.
                    -> In sliding window, we keep deleting the element till our condition is valid.
                    -> At any-time if condition is violated, we can move our second 'i' pointer forward, in order to 


    -> Let's dry run this: 
            Input: s = "aabaaaacaabc", k = 2
                
                -> We atleast need 2 element of 'a', b','c'

                Initially:
                    i = 0
                    j = 0 
                    windowSize = 0
                    freq = {a:8, b:2, c:2}
                while(j < n):

                j = 0:
                    0 1 2 3 4 5 6 7 8 9 10 11
                    a a b a a a a c a a b  c
                    ij

                        s[j] == 'a'
                        freq = {a:7, b:2, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> NO
                        windowSize = max(windowSize, (j - i + 1)) => 0  // Store answer
                        j++

                j = 1:
                    0 1 2 3 4 5 6 7 8 9 10 11
                    a a b a a a a c a a b  c
                    i j

                        s[j] == 'a'
                        freq = {a:6, b:2, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> NO
                        windowSize = max(windowSize, (j - i + 1)) => 2  // Store answer
                        j++
                        
                j = 2:
                    0 1 2 3 4 5 6 7 8 9 10 11
                    a a b a a a a c a a b  c
                    i   j

                        s[j] == 'b'
                        freq = {a:6, b:1, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k))-> YES
                            // move i pointer forward, and keep adding element in frequency count.
                            i = 0:
                                        0 1 2 3 4 5 6 7 8 9 10 11
                                        a a b a a a a c a a b  c
                                        i   j
                                        
                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'a') => cntA++;
                                    i++;
                                Updated frequency: freq{a:7, b:1, c:2}

                            i = 1:
                                        0 1 2 3 4 5 6 7 8 9 10 11
                                        a a b a a a a c a a b  c
                                          i j

                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'a') => cntA++;
                                    i++;
                                Updated frequency: freq{a:8, b:1, c:2}
                            
                            i = 2:
                                        0 1 2 3 4 5 6 7 8 9 10 11
                                        a a b a a a a c a a b  c
                                            ij

                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'b') => cntB++;
                                    i++;    // this makes i pointing to index '3'
                                Updated frequency: freq{a:8, b:2, c:2}
                            
                            Break, because i > j && all frequency condition satisfies as well.

                        windowSize = max(windowSize, (j - i + 1)) => 2  // Store answer
                        j++


                    j = 3:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                              ij
                        s[j] == 'a'
                        freq = {a:7, b:2, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> NO
                        windowSize = max(windowSize, (j - i + 1)) => 2  // Store answer
                        j++

                    j = 4:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                              i j
                        s[j] == 'a'
                        freq = {a:6, b:2, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> NO
                        windowSize = max(windowSize, (j - i + 1)) => 2  // Store answer
                        j++

                    j = 5:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                              i   j
                        s[j] == 'a'
                        freq = {a:5, b:2, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> NO
                        windowSize = max(windowSize, (j - i + 1)) => 3  // Store answer
                        j++

                    j = 6:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                              i     j
                        s[j] == 'a'
                        freq = {a:4, b:2, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> NO
                        windowSize = max(windowSize, (j - i + 1)) => 4  // Store answer
                        j++

                    j = 7:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                              i       j
                        s[j] == 'c'
                        freq = {a:4, b:2, c:1} // subtract 'c' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> YES:
                            // move i pointer forward, and keep adding element in frequency count.
                            i = 3:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                          i       j
                                          
                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'a') => cntA++;
                                    i++;
                                Updated frequency: freq{a:5, b:2, c:1}

                            i = 4:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                            i     j
                                          
                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'a') => cntA++;
                                    i++;
                                Updated frequency: freq{a:6, b:2, c:1}

                            i = 5:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                              i   j
                                          
                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'a') => cntA++;
                                    i++;
                                Updated frequency: freq{a:7, b:2, c:1}

                            i = 6:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                                i j
                                          
                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'a') => cntA++;
                                    i++;
                                Updated frequency: freq{a:8, b:2, c:1}

                            i = 7:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                                  ij
                                          
                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'c') => cntC++;
                                    i++;
                                Updated frequency: freq{a:8, b:2, c:2}

                            Break, because i > j && all frequency condition satisfies as well.

                        windowSize = max(windowSize, (j - i + 1)) => 4  // Store answer
                        j++
                    
                    j = 8:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                                        ij
                        s[j] == 'a'
                        freq = {a:7, b:2, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> NO
                        windowSize = max(windowSize, (j - i + 1)) => 4  // Store answer
                        j++          
                        
                    j = 9:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                                        i j
                        s[j] == 'a'
                        freq = {a:6, b:2, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> NO
                        windowSize = max(windowSize, (j - i + 1)) => 4  // Store answer
                        j++          
                        
                    j = 10:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                                        i   j
                        s[j] == 'b'
                        freq = {a:6, b:1, c:2} // subtract 'a' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> YES:
                            // move i pointer forward, and keep adding element in frequency count.
                            i = 8:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                                    i   j

                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'a') => cntA++;
                                    i++;
                                Updated frequency: freq{a:7, b:1, c:2}

                            i = 9:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                                      i j

                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'a') => cntA++;
                                    i++;
                                Updated frequency: freq{a:8, b:1, c:2}

                            i = 10:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                                        ij

                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'b') => cntB++;
                                    i++;
                                Updated frequency: freq{a:8, b:2, c:2}

                            Break, because i > j && all frequency condition satisfies as well.
                          
                        windowSize = max(windowSize, (j - i + 1)) => 4  // Store answer
                        j++          


                    j = 11:
                        0 1 2 3 4 5 6 7 8 9 10 11
                        a a b a a a a c a a b  c
                                              ij
                        s[j] == 'c'
                        freq = {a:8, b:2, c:1} // subtract 'c' from freqCnt
                        if(i <= j && (cntA < k || cntB < k || cntC < k)) -> YES:
                            i = 11:
                                    0 1 2 3 4 5 6 7 8 9 10 11
                                    a a b a a a a c a a b  c
                                                          ij

                                while(i <= j && (cntA < k || cntB < k || cntC < k)):
                                    (s[i] == 'c') => cntC++;
                                    i++;
                                Updated frequency: freq{a:8, b:2, c:2}

                            Break because i > j && frequency condition is satisfied.

                        windowSize = max(windowSize, (j - i + 1)) => 4  // Store answer
                        j++       
                    
                    j = 12:
                        j is out of bound, (j < n) not satisfied.
                        -> Result of maximum window size is: 4:
                    
            -> So, if we exclude 4 size window from the string, we can follow the condition (cntA >= k && cntB >= k && cntC >= k).
            -> Now, how do we find the minute asked in question, 
                -> Simple, as we have assumed let's remove all the element, means 'n' element, n = s.size()
                -> So, Final answer:" minutes = (n - windowSize)"

// Intrusion: 
    -> First find the frequency of 'a', 'b', 'c' from the string.
    -> Second find the dynamic size sliding window, in which we have (cntA >= k && cntB >= k && cntC >= k) this condition satisfied.
    -> Last subtract that window from the string size, so that we can get our answer. 



// Complexity: 
    -> TC: O(n)
        -> we only iterate iterate string twice, one for 'j' & one for 'i'.

    -> AS: O(1)
        -> No extra space is used to compute result.
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;    // if k = 0, means we don't need to select any element.
        int n = s.size();
        
        // STEP 1: Count the frequency of all the element from the string, (Assumed: let's remove all the element form the string.)
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;

        // Storing frequency:
        for(auto i: s){ 
            if(i == 'a') cntA++;
            else if(i == 'b') cntB++;
            else cntC++;
        }

        if(cntA < k || cntB < k || cntC < k) return -1; // case when frequency is not enough to make result.


        // STEP 2: Find the window size whose satisfied (cntA >= k && cntB >= k && cntC >= k) this condition by elementing element from the frequency count.
        // start deleting elements from  string, until the given conditions satisfy:
        int i = 0;  // first pointer, iterate till <= j
        int j = 0;  // second pointer, iterate till <= n

        int windowSize = 0;  // Initially window size is '0'

        while(j < n){   // iterate j till string size bound.
            // Delete current element form the jth pointer
            if(s[j] == 'a') cntA--;
            else if(s[j] == 'b') cntB--;
            else cntC--;


            // If deletion count of any character becomes less than k, then shrink the window and bring element back to the frequency count.
            while(i <= j && (cntA < k || cntB < k || cntC < k)){    // i is less than j bound, && (any count is less than 'k'):
                // Move ith pointer forward & update frequency while iterating i pointer.
                if(s[i] == 'a') cntA++;
                else if(s[i] == 'b') cntB++;
                else cntC++;
                i++;
            }

            // Last update the maximum size window, throughout the iteration of 'j'
            windowSize = max(windowSize, j - i + 1);  // storing maximum from all the jth iterations.

            j++;
        }
       
        // last subtracting windowSize form string size, will give us the minute required, as per the question condition.
        return n - windowSize;
    }
};
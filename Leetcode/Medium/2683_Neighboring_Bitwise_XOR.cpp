/*

//  2683. Neighboring Bitwise XOR


//  Problem Statement: 
    -> A 0-indexed array derived with length n is derived by computing the bitwise XOR (⊕) of adjacent values in a binary array original of length n.
    -> Specifically, for each index i in the range [0, n - 1]:
        -> If i = n - 1, then derived[i] = original[i] ⊕ original[0].
        -> Otherwise, derived[i] = original[i] ⊕ original[i + 1].

    -> Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.
    -> Return true if such an array exists or false otherwise.
        -> A binary array is an array containing only 0's and 1's

    
// Example:

    Example 1:
        Input: derived = [1,1,0]
        Output: true
        Explanation: A valid original array that gives derived is [0,1,0].
        derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
        derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
        derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0

    Example 2:
        Input: derived = [1,1]
        Output: true
        Explanation: A valid original array that gives derived is [0,1].
        derived[0] = original[0] ⊕ original[1] = 1
        derived[1] = original[1] ⊕ original[0] = 1

    Example 3:
        Input: derived = [1,0]
        Output: false
        Explanation: There is no valid original array that gives derived.


// Observations: 


        Input: derived = [1,1,0]
        Output: true
        Explanation: A valid original array that gives derived is [0,1,0].
            derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
            derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
            derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0



                    1 1 0   -> derived
                    0 1 0   -> Possible originals   
                    1 0 1   -> Possible originals



        XOR Property:
            a ^ b = c
            (a ^ b) ^ b = (c ^ b)
            a = (c ^ b)

            If we take xor of two number, if we again take xor both side with nay number we will get another number.


        XOR Property:
            a ^ b = c
            (a ^ b) ^ b = (c ^ b)
            a = (c ^ b)

            If we take xor of two number, if we again take xor both side with nay number we will get another number.
            We will use simillar approach to generate the original array.


                derived[]  = [0, 1, 0, 0, 1, 0]
                original[] = [a, b, c, d, e, f]

                    take original[0] = derived[0], because:
                            derived[0] = 0, means xor of (a ^ b) is same, this is why we got '0'
                            Two possible cases:
                                1 ^ 1 = 0
                                0 ^ 0 = 0
                            Now we can take either '1' or '0', let's take same as we have in original:

                derived[]  = [0, 1, 0, 0, 1, 0]
                original[] = [0, b, c, d, e, f]

                    original[1] = derived[0] ^ original[0]
                    original[1] = 0


                derived[]  = [0, 1, 0, 0, 1, 0]
                original[] = [0, 0, c, d, e, f]
                    
                    original[2] = derived[1] ^ original[1]
                    original[2] = 1

                derived[]  = [0, 1, 0, 0, 1, 0]
                original[] = [0, 0, 1, d, e, f]


                Similarly we will do the rest of operation & generate the original array.
                original[] = [0, 0, 1, 1, 1, 0]



// Brute Solution:
    -> Generate original array with the above property of XOR
    -> Generate derivedTemp with original array.
    -> If derived & derivedTemp is same, return true, else return false.


// Better Solution:
    -> we can only check last value of derived[n-1] is original[0] ^ original[n-1]:
        -> Because we have created whole original so all the values are correct, at their places.
        -> so instead of generating the whole temp, we can simply check the last value of derived from original that we have created:
            -> if(derived[n-1] != original[0] ^ original[n-1]) return false
            -> else return true;


// Efficient Solution:
    -> Let's observe more:

                original[] = [ a,   b,   c,   d,   e,   f]
                original[] = [ 0,   0,   1,   1,   1,   0]
                derived[]  = [ 0,   1,   0,   0,   1,   0]
                derived[]  = [a^b, b^c, c^d, d^e, e^f, f^a]


                In derived array, every element occur twice..
                -> XOR Property: if we take xor of two same element resultant will be '0'
                -> Same if we take XOR of all the element the xor should be '0' for valid derived array.

    -> In simple if XOR of derived aray is '0' return true: else return false.



// Extra Observations: 
    -> In XOR type of question, always look for number of occurrence of every element, & try to think you approach..



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: 
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for(auto i: derived){   // taking xor of all derived array:
            ans ^= i;
        }

        return ans == 0;    // if xor is 0, return true: return false.
    }
};


// Better Solution:


class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n == 1){
            if(derived[0] == 0) return 1;
            else return 0;
        }

        // Generate Original:
        vector<int> org(n, 0);
        org[0] = derived[0];    // initialize org[0] as derived[0]
        for(int i=0;i<n-1;i++){
            org[i+1] = derived[i] ^ org[i];  // now compute rest of the values with the help of XOR Property.
        }

        // Checking only last element:
        if(derived[n-1] != (org[0] ^ org[n-1])) return false;
        else return true;
    }
};



// Brute Solution:
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n == 1){ // if we have single derived element:
            if(derived[0] == 0) return 1;   // if it's '0', it's following the given condition.
            else return 0;  // else if it's '1', it's not following the given condition.
        }

        // Generate Original:
        vector<int> org(n, 0);
        org[0] = derived[0];    // initialize org[0] as derived[0]
        for(int i=0;i<n-1;i++){ 
            org[i+1] = derived[i] ^ org[i]; // now compute rest of the values with the help of XOR Property.
        }

        // Now generate derived:
        vector<int> temp(n, 0);
        temp[n-1] = org[0] ^ org[n-1];
        for(int i=0;i<n-1;i++){
            temp[i] = org[i] ^ org[i+1];
        }

        return temp == derived; // check if it's same as derived, then return true: else return false
    }
};




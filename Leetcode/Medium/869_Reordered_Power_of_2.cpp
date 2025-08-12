/*

//  869. Reordered Power of 2


//  Problem Statement: 
    -> You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
    -> Return true if and only if we can do this so that the resulting number is a power of two.

 
// Example:
    Example 1:
        Input: n = 1
        Output: true

    Example 2:
        Input: n = 10
        Output: false


// Observations: 
    -> From the given number, we can change the order of digit, in such a way so that any of the possible arrangement is power of 2, if it's power of 2, => return true : else return false
    -> Note: Leading '0' numbers should not be considered.
    
        
// BruteForce Solution: 
    -> Generate all the possible permutations from given number, and check wether that number is power of '2' or not?
        -> Example:
                n = 281
                    Permutations: 
                        281, 218, 821, 812, 128, 182
                                             |
                                        power of '2'
                                    2^7 = 128

    
    // Complexity: 
        -> TC: O(n!) => because of computing every possible permutations
        -> SC: O(n!)



// Efficient Solution: 
    -> We need to find any power of 2 which can be form from the given number right?
    -> precompute all power of '2' upto 1e9(since n fits in int)
    -> For each compute the sorted string of digit.
    -> Example: 
            n = 251
                    -> Sort: "125" 

            -> Now, Generate all the power of 2, from 2^0 to 2^30 -> Since all 1e9 number will fits in.
            
             Power            Values              Sorted
                2^0     =        1        =>        1
                2^1     =        2        =>        2
                2^2     =        4        =>        4
                2^3     =        8        =>        8
                2^4     =        16       =>        16
                2^5     =        32       =>        23
                2^6     =        64       =>        46
                2^7     =        128      =>        128
                2^8     =        256      =>        256
                2^9     =        512      =>       [125]   ----------> Matched
                2^10    =        1028     =>        0128
                2^11    =        2048     =>        0248
                ...
                ...

            -> For Every 2^x we will get the value & sort it & try to match with it with sorted value.
            -> This way we can find wether, number is power of 2 or not?

            // Complexity: 
                -> TC: O(1)
                -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: 
class Solution {
public:
    bool reorderedPowerOf2(int n) {

        string num = to_string(n);
        sort(begin(num), end(num));
        
        for(int i = 0; i < 31; i++) {   // 2^30 covers all the values within range 1e9
            string temp = to_string(1 << i);    // Generate power of '2', like 1 bit is leftshift at ith position on every iterations..
            sort(begin(temp), end(temp));
            if(temp == num) return true;
        }

        return false;
    }
};


// BruteForce Solution: 
class Solution {
private: 
    bool isPowerOf2(int n) {    // find power of '2'
        return n > 0 && (n & (n - 1)) == 0;
    }
    void permutation(string& s, int i, vector<string>& ans) {
        if(i == s.size()) {
            ans.push_back(s);
            return;
        }

        for(int idx = i; idx < s.size(); idx++) {
            swap(s[i], s[idx]);
            permutation(s, i + 1, ans);
            swap(s[i], s[idx]);
        }
    }
    vector<string> generatePermutations(string &s) {
        vector<string> ans;
        permutation(s, 0, ans);
        sort(begin(ans), end(ans));

        return ans;
    }
public:
    bool reorderedPowerOf2(int n) {
        
        if(isPowerOf2(n)) return true;

        // Generate all permutations of given num 'n'
        string num = to_string(n);
        vector<string> res = generatePermutations(num);

        // Find if any permutations is power of '2':
        for(auto& s: res) {
            if(s[0] == '0') continue;   // skip leading '0' numbers
            if(isPowerOf2(stoi(s))) return true;    // return true if any permutations is power of '2'
        }

        return false;   // no such permutations is power of '2'
    }
};
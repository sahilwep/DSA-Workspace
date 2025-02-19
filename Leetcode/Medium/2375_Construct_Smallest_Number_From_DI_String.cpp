/*

//  2375. Construct Smallest Number From DI String


//  Problem Statement:
    -> You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.
    -> A 0-indexed string num of length n + 1 is created using the following conditions:
        -> num consists of the digits '1' to '9', where each digit is used at most once.
        -> If pattern[i] == 'I', then num[i] < num[i + 1].
        -> If pattern[i] == 'D', then num[i] > num[i + 1].
    -> Return the lexicographically smallest possible string num that meets the conditions.


// Example:

    Example 1:

        Input: pattern = "IIIDIDDD"
        Output: "123549876"
        Explanation:
        At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
        At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
        Some possible values of num are "245639871", "135749862", and "123849765".
        It can be proven that "123549876" is the smallest possible num that meets the conditions.
        Note that "123414321" is not possible because the digit '1' is used more than once.

    Example 2:

        Input: pattern = "DDD"
        Output: "4321"
        Explanation:
        Some possible values of num are "9876", "7321", and "8742".
        It can be proven that "4321" is the smallest possible num that meets the conditions.


// BruteForce Solution:
    -> we are asked to generate smallest possible string num that meets conditions.
        -> If pattern[i] == 'I', then num[i] < num[i + 1].
        -> If pattern[i] == 'D', then num[i] > num[i + 1].
    -> first store the numbers from 1 to n + 1 in a string from the given size of pattern
    -> Then generate next permutations until we not get the match.




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    bool matchesPattern(string &nums, string &pattern) {
        for(int i = 0; i < pattern.size(); i++) {
            if(pattern[i] == 'I' && nums[i] > nums[i+1] 
            || pattern[i] == 'D' && nums[i] < nums[i+1])  {
                return false;
            }
        }

        return true;
    }
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num = "";

        for(int i = 1; i <= n + 1; i++) {
            num.push_back(i + '0');     // i = 1 => '1'
        }

        while(!matchesPattern(num, pattern)) {
            next_permutation(begin(num), end(num));
        }

        return num;
    }
};
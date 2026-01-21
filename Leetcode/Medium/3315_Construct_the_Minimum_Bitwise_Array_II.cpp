/*

//  3315. Construct the Minimum Bitwise Array II


//  Problem Statement: 
    - You are given an array nums consisting of n integers.
    - You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].
    - Additionally, you must minimize each value of ans[i] in the resulting array.
    - If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

 
// Example:
    Example 1:
        Input: nums = [2,3,5,7]
        Output: [-1,1,4,3]
        Explanation:
            For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0] + 1) = 2, so ans[0] = -1.
            For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is 1, because 1 OR (1 + 1) = 3.
            For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is 4, because 4 OR (4 + 1) = 5.
            For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is 3, because 3 OR (3 + 1) = 7.

    Example 2:
        Input: nums = [11,13,31]
        Output: [9,12,15]
        Explanation:
            For i = 0, the smallest ans[0] that satisfies ans[0] OR (ans[0] + 1) = 11 is 9, because 9 OR (9 + 1) = 11.
            For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 13 is 12, because 12 OR (12 + 1) = 13.
            For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 31 is 15, because 15 OR (15 + 1) = 31.



// Observations:
    - We have to find the smallest number "num" whose follows: 
        (num OR (num + 1)) == nums[i]


    // Approach 1: 
        - for every i:
            - for j from 1 to that nums[i] compute OR:
                - j OR j + 1
                - the minimum j we found is our ans[i]

                7  = 111
                    
                    11    -> 3
                    100    -> 4

            // Complexity:
                - TC: O(n * maxElement)
                - SC: O(1)

    - Approach 2:
        - NOTE: Given nums are prime:
            2, 3, 5, 7, 11, 13....

            11 = 1 0 [1] 1
                 
                 1 0 0 1    -> 9
                 1 0 1 0    -> 10

        - If we flip the last bit of trailing 1's and the number we got is our valid lowest value.
        - because we can take that num OR num + 1 as our resultant nums[i]

            7 = [1] 1 1

                 0  1 1 -> 3
                 1  0 0 -> 4
                -----------
             OR  1  0 1 -> 5

            - we have to convert that into the Binary:
            - we will flip the last 1's of trailing bit:
            - and that will be our answer:


        - Edge case:
            1 0 = 2
                -> if last bit is '0':
                    "-1"

        Decimal to Binary:
            num = 11 => 1 0 1 1

            - Every time take rem from num & after that divide that num by 2 until that number not become 0

            11 % 2 = 1
            5  % 2 = 1
            2  % 2 = 0
            1  % 2 = 1

                1 0 1 1 -> 11


        Binary to Decimal:
            s = 1 0 1 1 => 11

            2^0 * 1 = 1
            2^1 * 1 = 2
            2^2 * 0 = 0
            2^3 * 1 = 8 +
        -------------------
                     11

    // Complexity:
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 2:
class Solution {
private:
    string toBinary(int num) {  // function to convert int to binary: O(log(num)) => O(1), because we are processing only 32 bits..
        string s = "";
        while(num > 0) {
            s += to_string(num % 2);
            num = num / 2;
        }

        reverse(begin(s), end(s));  // reverse to get in order:
        return s;
    }
    int toInteger(string& s) {  // Function to to convert binary to int: TC: O(1), as only 32 bit to process
        int num = 0;
        for(int i = 0; i < s.size(); i++) {
            num += pow(2, i) * (s[s.size() - 1 - i] - '0');
        }

        return num;
    }
    string solve(string &s) {   // TC: O(1), as only 32 bit to precess
        int n = s.size();

        if(s[n - 1] == '0') return "-1";
        int pos = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] == '0') {
                pos = i + 1;
                break;
            }
        }
        
        string res = "";
        int i = 0;
        if(pos == -1) {
            string res = "0";
            i = 1;  // start from '1'
        }

        for(; i < n; i++) {
            if(i == pos) {
                res += '0';
            } else {
                res += s[i];
            }
        }

        return res;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int> ans;

        for(auto &num: nums) {  // O(N)
            string s = toBinary(num);   // convert that num into binary string:
            string validNum = solve(s); // get the smallest num:
            if(validNum == "-1") {
                ans.push_back(-1);
            } else {
                ans.push_back(toInteger(validNum));
            }
        }

        return ans;
    }
};



// Approach 1: 
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int> ans;

        for(auto &num: nums) {
            bool found = false;
            for(int j = 1; j <= num; j++) {
                if((j | (j + 1)) == num) {
                    ans.push_back(j);
                    found = true;
                    break;
                }
            }
            if(!found) ans.push_back(-1);
        }

        return ans;
    }
};
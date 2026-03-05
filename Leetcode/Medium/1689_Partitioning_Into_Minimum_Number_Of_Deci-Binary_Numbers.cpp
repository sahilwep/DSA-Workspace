/*

//  1689. Partitioning Into Minimum Number Of Deci-Binary Numbers


//  Problem Statement: 
    - A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
    - Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

 
// Example:
    Example 1:
        Input: n = "32"
        Output: 3
        Explanation: 10 + 11 + 11 = 32

    Example 2:
        Input: n = "82734"
        Output: 8

    Example 3:
        Input: n = "27346209830709182346"
        Output: 9

        


// Observations:
    - Given string n
    - we need to find the deci-binary number (number that contains only 1 or 0 digits) to make sum 'n'
    - return the minimum count of deci-binary numbers to create number 'n'
    - Example:
        n = string

            32: 100000
            32 = 10 + 11 + 11
            here, 10, 11 are deci-binary numbers that sums up value 32.

    - If we carefully observe, we have to make sum of deci-binary number so that we can form sum 'n'
    - let say we have number 
        n = 121
                first get all the 3 size deci-binary number:
                    100 101 110 111 
                    we will get the number "111" & subtract =>  121 - 111 = 10

                Now we have n = 10
                    All possible deci-binary with 2 digits
                        10  11
                    we will pick 10, so that we can make our result '0'
                It consist only 2-step to reach '0'
        

        n = 1004
            All deci-binary with 4 size:
                1000    1001    1010    ...
                we will pick "1001" & subtract  =>  1004 - 1001 = 3

            Now we have n = 3
                All possible deci-binary with single digit
                    0   1
                we will pick 1, & subtract => n = 2

            n = 2
                again we subtract with '1'
            
            n = 1
                again we subtract with '1'
            
                    n = 0
            
                Total 4 steps/deci-binary

        // Key Observations
            - for any number we directly subtract with the deci-number with that size.
            - means, for any larger number like "7190182382" => we subtract and make the size shrinkable..
            - Every-time we reducing the digits to '0'
            - Or we can say the maximum digit in number is what we are trying to reduce to '0'
            - in simple, the largest digit in number is what we are shrinking to '0'..
                - if we observe it carefully, everytime whatever number we take, it's the maximum digit which is being reducing to '0'
                - and in-between all the digits are automatically reducing to '0'
            - So we can say, the largest digit in our number is exactly the number of times we need any deci-binary numbers in order to reduce our number to '0'
            - we can take any example & simulate, we will take exactly that much amount of deci-binary number to reduce whole value n to '0'


    // Approach:
        - Find the maximum digit in number, and return that..
    
        // Complexity:
            - TC: O(n)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        
        int ans = 0;
        for(auto &ch: n) {
            ans = max(ans, (ch - '0'));
        }

        return ans;
    }
};
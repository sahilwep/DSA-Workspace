/*

//  401. Binary Watch


//  Problem Statement: 
    - A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
        - For example, the below binary watch reads "4:51".
    - Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
    - The hour must not contain a leading zero.
        - For example, "01:00" is not valid. It should be "1:00".
    - The minute must consist of two digits and may contain a leading zero.
        - For example, "10:2" is not valid. It should be "10:02".

 
// Example:
    Example 1:
        Input: turnedOn = 1
        Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

    Example 2:
        Input: turnedOn = 9
        Output: []



// Observations:
    - We are given total number of bits.
    - We we have to generate all the possible time from the exact given number of bits.
    - Example:

        turnedOn 1 => possible binary:

                        1           =      1
                        10          =      2
                        100         =      4
                ------- 1000        =      8 -----------    till hours we can take
                        10000       =      16 
                        100000      =      32 ----------    till minutes we can take
                        1000000     =      64   

                    For hours, we only need till 12 , so we can't make up with 16
                    For Minutes, we only need till 59, so we can't make up with 64


            2 => possible binary:
                        11
                        101
                        110
                        1001
                        1010
                        1100
                        ..
                        with ony two set bits.

            - We need to get the set bits from minutes.
            - we also need to get the set bits from the hours.
            - If given turnedOn set bits is equal to (min + hours) set bits
                - we will store that time.

            - Possible Hours:
                    0 - 11
            
            - Possible Minutes:
                    1 - 59
                
            - If Hours_bits + minutes_bits == turnedOn
                    => Store that time.



    // Complexity:
        - TC: O(1)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int getSetBits(int n) { // TC: O(1)
        int cnt = 0;
        for(int i = 1; i <= 32; i++) {  // O(32)
            int bit = n & 1;    // get the last set bits from the number n
            cnt += bit;         // add that bit into count, if set bit is 1, it will add 1 else add '0'
            n >>= 1;            // right shift n by 1, so that we count next bit.
        }

        return cnt;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string> ans;

        // TC: O(12 * 60) => O(720) => O(1)
        for(int h = 0; h < 12; h++) {   // from 0 to < 12
            for(int m = 0; m < 60; m++) {   // from 0 to < 60
                if(getSetBits(h) + getSetBits(m) == turnedOn) { // if set bit from min & hours is equal to turnedOn
                    // store that time as our possible answer.
                    string s = "";
                    s += to_string(h);          // push hour first
                    s += ":";                   // then colon :
                    s += (m < 10) ? "0" : "";   // add starting minute value, if less than 10 => add 0 in front else nothing.
                    s += to_string(m);          // last, add minute value.

                    ans.push_back(s);           // include s into answer.
                }
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        // Normal reverse number logic:
        long range = 0;
        while(x){
            int ld = x % 10;    // getting last digit:
            range = (range * 10) + ld;
            x = x / 10;
        }


        // Now, Checking overFlow & underflow range:
        if(range > INT_MAX || range < INT_MIN) return 0;
        return int(range);  // else return reversed value.

    }
};
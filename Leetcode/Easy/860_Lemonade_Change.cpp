/*

//  860. Lemonade Change


//  Problem Statement: 
    - At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
    - Note that you do not have any change in hand at first.
    - Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

 
// Example:
    Example 1:
        Input: bills = [5,5,5,10,20]
        Output: true
        Explanation: 
        From the first 3 customers, we collect three $5 bills in order.
        From the fourth customer, we collect a $10 bill and give back a $5.
        From the fifth customer, we give a $10 bill and a $5 bill.
        Since all customers got correct change, we output true.

    Example 2:
        Input: bills = [5,5,10,10,20]
        Output: false
        Explanation: 
        From the first two customers in order, we collect two $5 bills.
        For the next two customers in order, we collect a $10 bill and give back a $5 bill.
        For the last customer, we can not give the change of $15 back because we only have two $10 bills.
        Since not every customer received the correct change, the answer is false.

//  Observations:
    - at a lemonade stand.
    - each lemonade cost 5
    - we only have 5, 10 20
    - initially we don't have anything
    - for each bills, we will have to cost 5, and return remaining.
    - check if we complete all the transaction, if not return false.

    // Complexity:
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int _5 = 0, _10 = 0, _20 = 0;

        for(auto &i: bills) {
            if(i == 5) {
                _5++;
            } else if(i == 10) {
                // transaction falis:
                _10++;  // add 10 bill
                if(_5 == 0) return false;
                _5--;
            } else {    // 20_bills:
                _20++;
                if(_5 == 0) return false;   // not enough
                if(_10 == 0) {
                    if(_5 < 3) return false;
                    // else:
                    _5 -= 3;
                    continue;
                }
                // have 10 & 5:
                _10--;
                _5--;
            }
        }

        return true;
    }
};
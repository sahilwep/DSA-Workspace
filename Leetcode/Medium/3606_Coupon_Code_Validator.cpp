/*

//  3606. Coupon Code Validator


//  Problem Statement: 
    - You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:
        - code[i]: a string representing the coupon identifier.
        - businessLine[i]: a string denoting the business category of the coupon.
        - isActive[i]: a boolean indicating whether the coupon is currently active.
    - A coupon is considered valid if all of the following conditions hold:
        - code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
        - businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
        - isActive[i] is true.
    - Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

 

// Example:
    Example 1:
        Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]
        Output: ["PHARMA5","SAVE20"]
        Explanation:
            First coupon is valid.
            Second coupon has empty code (invalid).
            Third coupon is valid.
            Fourth coupon has special character @ (invalid).

    Example 2:
        Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]
        Output: ["ELECTRONICS_50"]
        Explanation:
            First coupon is inactive (invalid).
            Second coupon is valid.
            Third coupon has invalid business line (invalid).


// Observations: 
    - given code, business, & isActive
    - coupon is only valid if it has (a-z, A-Z, 0-9) or "_" underscore.
    - return the valid coupon.
    - This problem is more of implementations type.

    // Complexity:
        - TC: O(n * max_size(code[i])) = O(n)
        - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        vector<string> electronics, grocery, pharmacy, restaurant;
        for(int i = 0; i < n; i++) {
            if(isActive[i] == 1 && !code[i].empty()) {

                // check valid code:
                string coupon = code[i];
                bool isValid = true;
                for(auto &ch: coupon) {
                    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch == '_' ) {
                        continue;
                    } else {
                        isValid = false;
                    }
                }

                if(!isValid) continue;  // if coupon is not valid, skip 
                
                // Now push coupons according to their business line:
                string business = businessLine[i];
                if(business[0] == 'e') {
                    electronics.push_back(coupon);
                } else if(business[0] == 'g') {
                    grocery.push_back(coupon);
                } else if(business[0] == 'p') {
                    pharmacy.push_back(coupon);
                } else if(business[0] == 'r') {
                    restaurant.push_back(coupon);
                }
            }
        }

        // Now build answer according to the business line, sorted way:
        sort(begin(electronics), end(electronics));
        sort(begin(grocery), end(grocery));
        sort(begin(pharmacy), end(pharmacy));
        sort(begin(restaurant), end(restaurant));

        vector<string> ans;
        for(auto &it: electronics) ans.push_back(it);
        for(auto &it: grocery) ans.push_back(it);
        for(auto &it: pharmacy) ans.push_back(it);
        for(auto &it: restaurant) ans.push_back(it);

        return ans;
    }
};
/*

//  2064. Minimized Maximum of Products Distributed to Any Store



// Problem Statement:
    * You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.
    * You need to distribute all products to the retail stores following these rules:
        * A store can only be given at most one product type but can be given any amount of it.
        * After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.

    * Return the minimum possible x


// Example:

    Example 1:

        Input: n = 6, quantities = [11,6]
        Output: 3
        Explanation: One optimal way is:
        - The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
        - The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
        The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

    Example 2:

        Input: n = 7, quantities = [15,10,10]
        Output: 5
        Explanation: One optimal way is:
        - The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
        - The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
        - The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
        The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.

    Example 3:

        Input: n = 1, quantities = [100000]
        Output: 100000
        Explanation: The only optimal way is:
        - The 100000 products of type 0 are distributed to the only store.
        The maximum number of products given to any store is max(100000) = 100000.




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    // This function will distribute "mid" value, in all the shops, Note: we can distribute at max mid items
    bool possibleDistribute(int x, vector<int> &q, int shops){
        for(int &product: q){
            // instead of subtract x from quantities[i], we directly divide it by 'x' -> this will give us number of shop needed to distribute that item.
            // we have taken ceil() which will gives decimal upper value, because if division result is in decimal, we get the incremented value.
            shops -= (product + x - 1) / x; // or we can use -> ceil(product/x);

            if(shops < 0){
                return false;
            }
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int m = q.size();

        // Apply Binary Search:
        int l = 1;
        int r = *max_element(begin(q), end(q));  // this function will find the maximum element from the quantity.
        
        int res = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(possibleDistribute(mid, q, n)){
                res = mid;  // this can be a possible answer, so store this into our answer.
                r = mid - 1;    // making r lesser, because we may found smaller value.
            }else{  // if this is not possible, means we need to go right, means we are increasing our left value.
                l = mid + 1;
            }
        }

        return res;
    }
};
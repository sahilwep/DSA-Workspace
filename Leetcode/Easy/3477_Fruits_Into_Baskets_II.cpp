/*

//  3477. Fruits Into Baskets II


//  Problem Statement: 
    -> You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
    -> From left to right, place the fruits according to these rules:
        -> Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
        -> Each basket can hold only one type of fruit.
        -> If a fruit type cannot be placed in any basket, it remains unplaced.
    -> Return the number of fruit types that remain unplaced after all possible allocations are made.

 
// Example: 
    Example 1:
        Input: fruits = [4,2,5], baskets = [3,5,4]
        Output: 1
        Explanation:
            fruits[0] = 4 is placed in baskets[1] = 5.
            fruits[1] = 2 is placed in baskets[0] = 3.
            fruits[2] = 5 cannot be placed in baskets[2] = 4.
        Since one fruit type remains unplaced, we return 1.

    Example 2:
        Input: fruits = [3,6,1], baskets = [6,4,7]
        Output: 0
        Explanation:
            fruits[0] = 3 is placed in baskets[0] = 6.
            fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
            fruits[2] = 1 is placed in baskets[1] = 4.
        Since all fruits are successfully placed, we return 0.

    
// Observations: 
    -> Given fruit & basket
    -> We can place each basket only single type of fruit
    -> For every fruit we will have to start filling with **leftmost** basket, if the given constrains follows
    -> We need to count the total number of remaining baskets.


    // Approach: 
        -> For each fruit, we will start filling the basket from leftmost side, validating constrains.
        -> We can't fill the same basket again.
        -> we need to count the total number of unfilled fruit.


    // Complexity: 
        -> TC: O(n^2)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        int unplaced = 0;
        for(auto& fruit: fruits) {
            for(auto& bs: baskets) {
                if(bs == -1) continue;
                if(bs >= fruit) {
                    bs = -1;
                    fruit = -1;
                    break;
                }
            }
        }

        // Count the unplaced fruit:
        for(auto& fruit: fruits) {
            if(fruit != -1) unplaced++;
        }

        return unplaced;
    }
};
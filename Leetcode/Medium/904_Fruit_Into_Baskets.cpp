/*

//  904. Fruit Into Baskets


//  Problem Statement: 
    -> You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
    -> You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
        -> You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
        -> Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
        -> Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
    -> Given the integer array fruits, return the maximum number of fruits you can pick.

//  Example: 

    Example 1:
        Input: fruits = [1,2,1]
        Output: 3
        Explanation: We can pick from all 3 trees.

    Example 2:
        Input: fruits = [0,1,2,2]
        Output: 3
        Explanation: We can pick from trees [1,2,2].
        If we had started at the first tree, we would only pick from trees [0,1].

    Example 3:
        Input: fruits = [1,2,3,2,2]
        Output: 4
        Explanation: We can pick from trees [2,3,2,2].
        If we had started at the first tree, we would only pick from trees [1,2].



// Observations: 
    -> we have two baskets.
    -> we can take at max two type of fruits.
    -> we want to collect as much as we can collect.
    -> fruits[i] is the type of fruit, in every 'i' tree.
    -> We need to select maximum range so that we can have maximum fruit in our basket.


    // Key observation: 
        -> We need to select in range, looks like a window -> sliding window.
        -> Window size can be minimize or maximize according to our needs..
        -> We will use map to store the type of element occurring at every index.



// Complexity: 
    -> TC: O(n)
    -> AS: O(n)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();
        int maxFruit = 0;
        unordered_map<int, int> mp;

        int left = 0;
        int right = 0;

        while(right < n){
            mp[f[right]]++; // Hash the fruit frequency occurring at every index:


            // Check wether we have more than two element in map or not, if we have more than two element, then move left pointer forward, until size is not satisfied.
            while(mp.size() > 2){
                mp[f[left]]--;  // remove that left pointer element.
                if(mp[f[left]] == 0){ // note: if frequency count become '0', remove that element itself from the map.
                    mp.erase(f[left]);  // remove that element from map.
                }
                left++; // increment the left pointer forward.
            }

            // Now at last store the range: 
            maxFruit = max(maxFruit, right - left + 1);

            right++;
        }
        
        return maxFruit;
    }
};
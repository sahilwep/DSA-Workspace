/*

//  1011. Capacity To Ship Packages Within D Days


//  Problem Statement: 
    -> A conveyor belt has packages that must be shipped from one port to another within days days.
    -> The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
    -> Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 
// Example: 
    Example 1:
        Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
        Output: 15
        Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
        1st day: 1, 2, 3, 4, 5
        2nd day: 6, 7
        3rd day: 8
        4th day: 9
        5th day: 10
        Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

    Example 2:
        Input: weights = [3,2,2,4,1,4], days = 3
        Output: 6
        Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
        1st day: 3, 2
        2nd day: 2, 4
        3rd day: 1, 4


// Observations:
    -> we have items on conveyer belt with weights[i] given
    -> We are given D days on which we have to ship all the items from the conveyer belt

    weights = [1,2,3,4,5,6,7,8,9,10], days = 5
        -> max capacity which we can take sum of all the wights: 55
        -> we can ship all the items in 1 day
        -> But we are given 5 days to ship
        -> So, we need to find the minimum weight of ship on which we can ship all the items on given D days

        -> minimum capacity is max_element() = 10, because we are sure we can ship all the package if ship has this much minimum capacity, doesn't consedering the fact we have D days to ship
        -> If we take minimum capcity lesser than the max_element, few items wor left, and not be shipped.

        -> which will ship items every day in worse case

        Range: start = max_element
                End = sumOfAllElement
        
        -> Now, we only need to write a functions which we pass the capacity & that will return the required days to finish all the items.
      

    // Complexity: 
        -> TC: O(n * log(S))
            -> S = total Sum
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Binary Search Impl.
class Solution {
private: 
    int reqDays(vector<int>& weights, int cap) {
        int load = 0;
        int days = 1;   //  1 because, On day 1 ship is not yet loaded, Now loading is starting..
        for(auto& item: weights) {
            // While loading the item on ship, if it's crossing capicity of ship:
            if(load + item > cap) {
                days++;         // increment the days count
                load = item;    // now include this current item into load for processing it into next day
            } else {
                load += item;   // else include that item.
            }
        }

        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(begin(weights), end(weights));
        int high = accumulate(begin(weights), end(weights), 0);

        // Find the minimum Capcity Using Binary Search:
        int minCap = INT_MAX;
        while(low <= high) {
            int mid = (low + high) / 2;

            int reqDay = reqDays(weights, mid);

            // If reqDays is true for given Days: capcity is larger & adjust all the items, now minimize capacity by moving left:
            if(reqDay <= days) {
                high = mid - 1;
                minCap = mid;   // store minimum Capacity
            } 
            else {  // reqDay is grater, we have to go for more capacity: move right
                low = mid + 1;
            }
        }

        return minCap;
    }
};



// Linear Search Impl.
class Solution {
private: 
    int reqDays(vector<int>& weights, int cap) {
        int load = 0;
        int days = 1;   //  1 because, On day 1 ship is not yet loaded, Now loading is starting..
        for(auto& item: weights) {
            // While loading the item on ship, if it's crossing capicity of ship:
            if(load + item > cap) {
                days++;         // increment the days count
                load = item;    // now include this current item into load for processing it into next day
            } else {
                load += item;   // else include that item.
            }
        }

        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(begin(weights), end(weights));
        int high = accumulate(begin(weights), end(weights), 0);

        int minCap = INT_MAX;
        for(int i = low; i <= high; i++) {
            int reqDay = reqDays(weights, i);
            if(reqDay <= days) {
                minCap = i;
                break;
            }
        }

        return minCap;
    }
};
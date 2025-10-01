/*

//  1518. Water Bottles


//  Problem Statement: 
    - There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
    - The operation of drinking a full water bottle turns it into an empty bottle.
    - Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

 
// Example:
    Example 1:

        Input: numBottles = 9, numExchange = 3
        Output: 13
        Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
        Number of water bottles you can drink: 9 + 3 + 1 = 13.

    Example 2:
        Input: numBottles = 15, numExchange = 4
        Output: 19
        Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
        Number of water bottles you can drink: 15 + 3 + 1 = 19.

// Observations:
    -> there are "numBottles" water bottle that are initially full of water.
    -> you can exchange "numExchange" empty water bottles from the market with one full water bottle.
    -> The operation of drinking a full water bottle turn it into an empty bottle.
    -> Given the two integer, "numBottle" and "numExchange", return the maximum number of water bottle you can drink.

    Input: numBottles = 9, numExchange = 3
    Output: 13
    Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
    Number of water bottles you can drink: 9 + 3 + 1 = 13.

        - Initially 9 full bottle -> drink 9 bottle

        - 9 empty bottle -> 3 bottle we can use to exchange on full water bottle
            - from 9 empty bottle we can get 3 full water bottle
        
        - drink 3 bottle => 12 total bottle we can drink

        - 3 bottle remains, we can use again it to get one full water bottle

        - again drink one bottle => 13 total bottle we can drink..
            - Now, this time we don't have enough bottle to get exchange..
        
        - Total drink = 13

    // Complexity:
        -> TC: O(n)
        -> SC: O(1)


// Optimization:
    - as we are drinking one bottle at every iterations, we can directly drink the given number of Exchange
    - This will improve our code significantly, because we directly exchange all the empty bottle into single iterations.
    - Then, we can directly add all the drink bottle, & empty bottle in single iterations...


    // Complexity: 
        -> TC: O(logn)
        -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient: TC: O(logn)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrink = numBottles;    // Initially we can drink all the full water bottles
        int emptyBottle = numBottles;   // we will have this much bottle empty bottle.

        while(numExchange <= emptyBottle) {
            // Get new full bottle by exchanging empty bottle:
            int newBottle = emptyBottle / numExchange;
            
            // add into total Drink so far:
            totalDrink += newBottle;

            // Now, add empty bottle into emptyBottle:
            emptyBottle = emptyBottle % numExchange + newBottle;
        }

        return totalDrink;
    }
};

// BruteForce: TC: O(n), as we iterating one by one
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrink = numBottles;    // Initially we can drink all the full water bottles
        int emptyBottle = numBottles;   // we will have this much bottle empty bottle.

        while(numExchange <= emptyBottle) {
            // Get exchange:
            emptyBottle -= numExchange;

            // add one bottle into empty list, as we drink
            emptyBottle += 1;

            // increment total bottle, as we already drink that...
            totalDrink++;
        }

        return totalDrink;
    }
};
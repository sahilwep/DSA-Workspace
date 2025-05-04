/*

// 0 - 1 Knapsack problem

// Types & Variations of 0-1 Knapsack Problems:
    1. Subset Sum
    2. Equal Sum Partitions
    3. Count of Subset Sum
    4. Minimum Subset Sum Difference
    5. Target Sum
    6. No of subset & give difference


// Knapsack: 
    * Knapsack meaning a bag or shoulder bag.
    * Knapsack: Three Types
        * Fractional Knapsack -> Greedy
        * 0 - 1 Knapsack    -> either include or not
        * Unbounded Knapsack -> allow to pick item infinite times

// Knapsack Example:
    * Example: 
        Let's assume we are given some items, & these items has some weight, & we are given some
            Items:      I1  I2  I3  I4 
            value[] =   1   4   5   7
            weight[] =  1   3   4   5

            W(Capacity) = 7 (bag that can hold some value)

            Let Suppose:
                We are given some item that has some value associated with it and it has some weight, we need to pick items in such a way so that our profit will be maximum..
                let say Bag has Capacity of 7kg
                Constrains: Bag has fixed weight    ->  Example: Maximum we can put 7 kg item in bag
                Let say there is some items: 
                        I1 = {7Kg, 5$}
                        I2 = {7Kg, 1000$}
                        So, it's better that we should put I2 that is of 7Kg & vale is 1000$ so that we will be having the maximum profit.
                
            In Conclusion: 
                We need to pick those item from the given Items & put it into bag, so that the profit will be maximum -> we have to maximize the profit.


// 0 -1 Knapsack


// Fractional Knapsack: 
    * Let say our bag has Capacity of 10kg & we have filled our bag with 9kg, Now 1kg is left.
    * Let say we have one item that has weight 2kg & the price of that item is 20$
        * So, we can split our item into 1-1kg & the price will also be splitted, & we are allowed to fill our bag with 1kg.
        * So, In fractional knapsack we are allowed to split our items into fractions, & we can fill our bag.
        * So, here we can use Greedy approach, & there is no need of DP


// 0 - 1 Knapsack:
    * Let's assume same case with the 0-1 knapsack, No if there is some space left, & we have some item..
    * Either we can put item into bag or we can't put it into bag if space is left we can insert item, else we can remove the previous stored item & then put it into bag..
    * Example:
        * If Bag is size of 10kg & 9kg is filled, & there is one item of 2kg
        * Either we can put 2 kg item by removing previous inserted items, or we can't put 2kg items.
    * 0 - 1: means 1(either consider it) or 0(or left it)

// Unbounded Knapsack:
    * Unbounded item is same like 0-1 knapsack, by here we have infinite supply of items, we can put as many item as we want of same value..
    * But in 0-1 knapsack we are limited with item supply once we have put some item in bag, we are not able to put same item in bag again.
    * In unbounded knapsack we have unlimited supply of items, we can fill the bag with as many item as we want.


// O - 1 Knapsack Identify:
        * Example: 
        I/p:
            Items:      I1  I2  I3  I4 
            value[] =   1   4   5   7
            weight[] =  1   3   4   5
            W(Capacity) = 7 (bag that can hold some value)

        O/p: we need to find the maximum profit.

        * Identify:
            * Choice: we are given some choice that we are choose it or not.
            * Optimal: we need to find the maximum profit.

        * If these two conditions are are fulfilled, then we can say this problem is of DP.

        * Now we have identify that this problem is of DP, we need to solve it by using;
            Recursion -> Memoize -> Top-Down
        
        * DP: [recursion + storage]



*/
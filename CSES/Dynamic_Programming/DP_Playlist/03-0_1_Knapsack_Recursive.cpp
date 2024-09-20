/*

//  3 01 Knapsack Recursive 


// Identification of Knapsack: 
    * Choice is given, Then
    * Use DP -> First apply Recursion -> Then apply Topdown


// Example:
    Input: 
        wt[]  = {1, 3, 4, 5}
        val[] = {1, 4, 5, 7}
        W = 7
    O/p: Find the maximum profit.


// How to write the code:
    * Write recursive code for given problem.
    * Before writing the recursive code for the given problem, write the choice diagram.
    
    // Choice Diagram:
        * Let's say we have item 1 & we have to put this into bag, what are the choices that we have for item 1.
        * Let, Bag capacity = W = 10 kg
        * Let, item weight =  w1

                                    [w1]
                                      |
                [w1 <= W]-------------------------[w1 > W] 
                    |                                 |
       [Include]---------[reject]                  [reject]

       * If item weight is less or equal to the Bag Capacity, either we can put this into bag or not it's our choice.
       * If item weight is strictly grater than the Bag Capacity, we cannot place item into bag.

    
    // Writing the knapsack function
        * return type is integer
        * we are given two array, size of array, & capacity of bag.
        * Write recursive Function: 

            int knapsack(int val[], int weight, int n, int W){
                // Base Condition: 
                ....
                // Choice Diagram:
                ...
            }

        // For any Recursive Function: method to write it
            * Check what's the return type first.
            * Then Check for the input parameter that goes in recursive function.
            * Then write for the base condition:
            * Then write choice diagram.
            
            // Base Condition: technique use to write base condition.
                * Think of the smallest "valid" input.
                * Example: 
                    Input:
                        n = size of both the array.
                        wt[] =  {.......}       -> 0
                        val[] = {.......}       -> 0
                        W = Capacity of bag     -> 0
                    * We can decrease size of array as much as we want, So we can say:
                    * base condition:  if(n == 0 || w == 0)
                    * for both the condition n = 0 & w = 0, the output will be:
                        * we have to get the maximum profit, so if there is no item we will get 0, & also if there is no space in bag, we will have 0 profit.
                    
                    if(n == 0 || w == 0) return 0;
            
            * NOTE: For any recursive function whenever it calls again, it should call itself for smaller input.
                * fib(n) -> fib(n-1)..


            // Choice diagram code:
                * Input:
                        n = size of both the array.
                        wt[] =  [ | | | | | ]
                        val[] = [ | | | | | ]
                                          n-1
                        W = Capacity of bag
                * If we select items from backwards, & think for including or not & then at the last we will remove it from the array so that our next call will be smaller.
                * Also, while including items from the array, our weight should also decreased.
                          
                                    [Item 1, wt 1]
                                            |
                            [wt <= W]---------------[wt > W]
                                |                  can't include
                    [Include]------[Reject]

                * Code:
                    // If item weight is less or equal to Capacity:
                    if(wt[n-1] <= W){
                        // Choice 1: Include
                        // If we include the value, then the price of item will be added, & the storage from bag W capacity will be decreased.
                        // then after we have to choose from the remaining element from the array
                        // at last we have to check for remaining items, in parent call we have seen for total n items, & now we have to look for n-1 items.
                        return val[n-1] + knapsack(wt, val, (W - wt[n-1]), n-1)

                        // Choice 2: Reject
                        // for reject we need to return:
                        return knapsack(wt, val, W, n-1);   // we are rejecting the item..

                        
                        // Merging both Include & Reject: We need max profit, so we need to check for which choice we are having maximum profit, so we can use max() function in this case..
                        return max( (val[n-1] + knapsack(wt, val, (W - wt[n-1]), n-1))   ,    knapsack(wt, val, W, n-1));
                        //              Include                                                     reject the item

                    }
                    // If item weight is grater than the Capacity:
                    else{
                        // if(wt[n-1] > W): So we don't include, so we will return same thing. that is:
                        // We have to Reject, so we need to remove the element that we are seeing, so we decrease the size of array from n to n-1
                        return knapsack(wt, val, W, n-1);

                    }


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Knapsack function: 
int knapsack(int wt[], int val[], int W, int n){
    // base Condition:
    if(n == 0 || W == 0){
        return 0;   // return 0 as maximum profit, because we didn't include item, or we don't have any capacity left..
    }

    // Choice Diagram:
    // When element is less or equal to the Capacity:
    if(wt[n-1] <= W){
        // Include: Including the item, & removing the item from range & calling for left items..
        // Reject: reject the current, item..
        // Max Profit: we need to get for which we are getting maximum profit.
        return max( (val[n-1] + knapsack(wt, val, (W - wt[n-1]), n-1)), (knapsack(wt, val, W, n-1)));
        //   max of ((Included: current + remaining item)            ), (Reject                   )
    }
    // When element is grater than the Capacity:
    else{
        // we have to remove the item, as it's exceed the capacity size.
        return knapsack(wt, val, W, n-1);
    }
}

void solve(){
    int n;
    cin >> n;
    int value[n];
    int weight[n];
    for(int i=0;i<n;i++) cin >> value[i];
    for(int i=0;i<n;i++) cin >> weight[i];

    int W;
    cin >> W;

    cout << knapsack(weight, value, W, n) << endl;

}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
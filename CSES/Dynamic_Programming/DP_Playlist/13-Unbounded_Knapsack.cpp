/*

//  Unbounded Knapsack:


// Difference b/w 0-1 Knapsack & unbounded knapsack:

    * In 0-1 knapsack:

            Item = [ x | x | x | x | x ]
                            /       \
                        [value]   [weight]   -> given
                    
        * We were taking decision
            Item = [ x | x | x | x | x ]
                                    / \
                            [Include] [Reject]  -> For any item we can take decision that we will take it or reject...
    
                        * Once we take decision that item is removed, means we can't take decision on that item again..
    
            Item = [ x | x | x | x ]    -> our array become smaller,


    * Unbounded Knapsack:
        * But in unbounded knapsack, even after taking decision that item is never removed, means we can take decision again..
    
            Item = [ x | x | x | x | x ]
                                    / \
                            [Include] [Reject]  -> For any item we can take decision that we will take it or reject...
            
            Item = [ x | x | x | x | x ]
                                / \
                        [Include] [Reject]  -> For any item we can take decision that we will take it or reject...
    
                * but again we can go on the last one & take decision..
                * because, multiple occurrence of same item is allowed in unbounded knapsack.



// Difference between 0-1 Knapsack & Unbounded Knapsack:

    * In 0-1 Knapsack:

            Item = [ x | x | x | x | x ]
                            /       \
                        [value]   [weight]   -> given
                    
        * We make decisions as follows:
            Item = [ x | x | x | x | x ]
                                    / \
                            [Include] [Reject]  -> For any item, we can decide whether to include it or reject it.
    
                        * Once we make the decision, that item is removed, meaning we can't consider it again.
    
            Item = [ x | x | x | x ]    -> The size of the array becomes smaller.


    * Unbounded Knapsack:
        * In the Unbounded Knapsack, even after making a decision, the item is never removed, meaning we can reconsider the item.

            Item = [ x | x | x | x | x ]
                                    / \
                            [Include] [Reject]  -> For any item, we can decide whether to include it or reject it.
            
            Item = [ x | x | x | x | x ]
                                / \
                        [Include] [Reject]  -> For any item, we can decide whether to include it or reject it.

                * However, we can return to the same item and make the decision again.
                * This is because multiple occurrences of the same item are allowed in the Unbounded Knapsack.



        * Key Observation:

            * In 0-1 Knapsack:
                    Item = [ x | x | x | x | x ]
                                            / \
                                    [include] [reject] -> Taking Decisions
                                        |        |
                                  [processed] [processed] -> Both decisions lead to the item being processed, meaning we can't include this item again in the 0-1 knapsack.
                                    
                                * For both decisions, the item is processed, meaning we can't include this particular item again.

            
            * But in Unbounded Knapsack:

                    Item = [ x | x | x | x | x ]
                                            / \
                                    [include] [reject] -> Taking Decisions
                                        |         |
                            [Not processed]   [Processed]

                                    * Even after including the item, we can include it again because it is not considered fully processed.
                                    * However, if we reject the item, it is processed, meaning we won't consider it again.
                    
                    * Concluding: For the included item -> the item remains in an unprocessed state, and for the rejected item -> the item is considered processed.


                * Example:

                    Item = [1, 2, 5]
                    Knapsack capacity = 5
                    -> We have to fill the knapsack with the maximum frequency of elements that can fit.
                        * If we include 5 -> knapsack {5} -> we can fit only 1 element because there is no space left in the knapsack.
                        * If we include only 2 -> {2, 2} -> we can fit a maximum of 2 elements.
                        * If we include 2 and 1 ->  {2, 2, 1} -> we can fit a maximum of 3 elements.
                        * If we include 2 and 1 ->  {2, 1, 1, 1} -> we can fit a maximum of 4 elements.
                        * If we include only 1 -> {1, 1, 1, 1, 1} -> we can fit a maximum of 5 elements.

                    * From this example, we understand that once we reject an element, we don't process it again.
                    * However, the element that we include in our knapsack can be reconsidered again.



// Problem Description:
    * Given a set of n items, each with a weight and a value, determine the number of each item to include in a collection 
    * so that the total weight is less than or equal to a given capacity 'W',and the total value is maximized. 
    * You can include an item multiple times (unlike 0-1 Knapsack where each item can only be included once).
    * We have to find the maximum profit, meaning maximum value we can store in knapsack.
            


// Intrusion:
    * Code is same as 0-1 knapsack, we just need to change include condition, 
    * when we include any item, that item is not processed, so we will not minimizing the size for include condition..
    * Code logic is same for recursive, memoization, tabulation
    

// TC: 
    * Recursive: O(2^n)
    * memoization: O(n*W)
    * tabulation: O(n*W)


*/



#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Recursive Solution:
int knapsack_rec(int wt[], int val[], int W, int n){
    if(n == 0 || W == 0){
        return 0;
    }
    // If item weight is less or equal to capacity:
    if(wt[n-1] <= W){
        // Include(Not-processed) or Reject(Processed)
        return max(val[n-1] + knapsack_rec(wt, val, W - (wt[n-1]), n), knapsack_rec(wt, val, W, n-1));
    }
    else{
        // reject
        return knapsack_rec(wt, val, W, n-1);
    }
}




// Dp Solution: Memoization
int knapsack(int wt[], int val[], int W, int n, vector<vector<int> > &t){
    if(n == 0 || W == 0){
        return 0;
    }
    // If value is already present in memo array: return 
    if(t[n][W] != -1){
        return t[n][W];
    }

    // If item weight is less or equal to capacity:
    if(wt[n-1] <= W){
        // Include(Not-processed) or Reject(Processed)
        return t[n][W] = max(val[n-1] + knapsack(wt, val, W - (wt[n-1]), n, t), knapsack(wt, val, W, n-1, t));
    }
    else{
        // reject
        return t[n][W] = knapsack(wt, val, W, n-1, t);
    }
}

// Control code:
int knapsack_d_m(int wt[], int val[], int W, int n){
    vector<vector<int> >  t(n+1, vector<int> (W+1, -1));

    return knapsack(wt, val, W, n, t);
}





// Dp Solution: Tabulation
int knapsack_dp_t(int wt[], int val[], int W, int n){

    // initialization:
    // Declaring matrix of size n, & w, also filling with 0, because When (W == 0 || n == 0)
    vector<vector<int> > t(n+1, vector<int> (W+1, 0));

    // Choice Diagram Code:
    // Changing (n -> i & W -> j)
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            // when wt[n-1] <= W : Two choices -> accept(Not-Processed) or reject(Processed)
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]],  t[i-1][j]);
            }
            // when wt[n-1] > W : reject
            else{
                t[i][j] = t[i-1][j];
            }
        }

    }

    return t[n][W]; // returning maxProfit:
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

    // Recursive Solution Call:
    cout << knapsack_rec(weight, value, W, n) << endl;


    // Dp Solution Call: memoization
    cout << knapsack_d_m(weight, value, W, n) << endl;

    // Dp Solution Call: memoization
    cout << knapsack_dp_t(weight, value, W, n) << endl;

}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
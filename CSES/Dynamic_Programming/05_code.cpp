/*

//  
//  Coin Combinations II -> Unbounded knapsack


// Problem Statement: 
    * Consider a money system consisting of n coins. Each coin has a positive integer value. 
    * Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.

    * For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
        2+2+5
        3+3+3
        2+2+2+3

    * Constraints
        1 <= n <= 100
        1 <= x <= 10^6
        1 <= c[i] <= 10^6


Example

// Visualization: 
    -> This question is similar to the previous one. In the previous question, we were finding all the possible ways by checking all possible arrangements.
    -> In this question, however, we need to find only the unique solutions, where the order of arrangements does not matter.


    // Let's solve this question using the Unbounded Knapsack approach:
        -> We are allowed to choose any coin an unlimited number of times.
        -> We are given 'x', which represents the target sum of money that we need to make using the given coins.
        -> We need to count the number of unique combinations that sum up to 'x'.
        -> NOTE: Here, the order of arrangements does not matter.

    
        // Relate this question using "subset count with given sum"
            -> In subset count, we were given sum value, & we will have to count the number of unique subset that will for the 'sum'

            coins: {2,3,5}, sum = 9


            // Unbounded knapsack Decision tree: 

                                                            [Item]
                                                              |
                                [item <= sum]----------------------------------------------[item > sum]
                                      |                                                         |
                         [Accept]------------[Reject]                                        [Reject]


                    -> In Unbounded knapsack, we are allowed to choose any item unlimited number of times:

                            [Accept Case] -> Not-Processed, because we can choose this item again & again until we decided not to choose.
                            [Reject Case] -> Processed State, Item is processed means we never want this item again.


                    -> For every branch if we were getting our answer, we will include that in our total count, by using '+' operator.
                    
            // Base case: 

                        coin[n] = {c1,c2,c3...c[n]}, n = size,  sum = x
                    
                    when (x == 0 && n == 0) => we will have one subset that is {} empty subset
                    
                    When we have (x = 0), Sum = 0, & (n > 0), we don't know how many subset we can form..

                    There is one base case, 
                                if(n == 0 && sum == 0) return 1;    // empty subset {}
                                if(n == 0) return 0;    // empty subset
                                if(sum == 0) return 0;  // "sum = 0"
                    
                
                    When we were writing Tabulations solution, we need to fill table: 

                        
                    Example:
                        
                            coins: {2,3,5}, sum = 9, n = 3

                        -> Create dp table of size t[n+1][sum+1]
                                                   t[3+1][9+1]



                                   0   1   2   3   4   5   6   7   8   9        => Sum
                            0    | 1 |   |   |   |   |   |   |   |   |   |
                            1    |   |   |   |   |   |   |   |   |   |   |
                            2    |   |   |   |   |   |   |   |   |   |   |
                            3    |   |   |   |   |   |   |   |   |   |   |
                           "n"
                        
                        -> For this table we are sure that t[0][0] = 1, as it's has one {} empty set, also we can think like this
                        -> No of ways to form sum = 0, with 0 coins, is 1 -> we don't choose any coins.

                        -> Default rest of the table filled with '0', because we can compute these later...


            // Filling the rest of the table: 

                        -> We can the rest of the table on the above decision tree logic:

                                for(i = 1 to n + 1){
                                    // we need to iterate from 0, because we are not sure that with given '0' value how may subset we can from with different n values, example: n = {0, 0}, & sum = 0, we can can have 4 possibility for this..
                                    for(j = 0 to sum + 1){
                                        if(itemsize[i-1] <= sum->j){
                                            // Two choices: accept / reject
                                            //          Not processed               Processed
                                            t[i][j] = t[i][j-itemsize[i-1]]  + t[i-1][j]    // from the above branch, if we got our answer, we will Add all those branch by '+' operator..
                                        }
                                        else{
                                            t[i][j] = t[i-1][j];    // reject(processed)
                                        }
                                    }
                                
                                }

                                last we will return t[n][sum]  -> last value of table



// Complexity: Accepted in CSES.
    * TC: O(n*sum)
    * AS: O(n*sum)

// NOTE: 
    * We can use int, instead of long long

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 1000000007


// Function to return the count of subset with given sum:
int coinCombination_2(vector<int> &coins, int sum, int n){

    vector<vector<int> > t(n+1, vector<int> (sum+1, 0));

    t[0][0] = 1;    // base case, for {} empty set

    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(coins[i-1] <= j){
                t[i][j] = (t[i][j-coins[i-1]] + t[i-1][j]) % mod;
            }
            else{
                t[i][j] = t[i-1][j]  % mod;
            }
        }
    }

    return t[n][sum];
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for(int i=0;i<n;i++) cin >> coins[i];

    cout << coinCombination_2(coins, x, n) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    // cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
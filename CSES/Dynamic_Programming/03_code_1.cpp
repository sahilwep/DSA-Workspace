/*

//  CSES: Minimizing Coins

//  Problem Statement:
    * Consider a money system consisting of n coins. 
    * Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
    
    * For example, 
        if the coins are {1,5,7} and the desired sum is 11, 
        an optimal solution is 5+5+1 which requires 3 coins.
    
    * Constrains:

            1 <= n <= 100
            1 <= x <= 10^6
            1 <= coins[i] <= 10^6


// Visualization:
    -> We will be solving this problem with same mindset, given a big problem, & We will try to reduce it down in smaller problem, & solve these smaller problem & somehow get the relations b/w these smaller problem to get the answer for the bigger subproblem.

    -> We want to construct sum X, & we have these coins c1, c2, c3... up till c(n)
    -> we want to construct X, & let suppose we will use coins c1, now what will happened to X

                            X
                            |
                ------------------------------
                |       |       |            |
                X-c1    x-c2    ...          x-c[n]    -> If we would use the coin c[i], & x - c[i] to be constructed.

    
            The problem x-c1, x-c2,..x-c[n] these are smaller subproblem that we have to solve in order to get the answer for X

            Let suppose we want to construct the sum of 11, & we had this coins {1, 5, 7}

                    -> How we can construct the sum of 11
                    -> Let suppose we use coins 1 by 1..


                                       11
                                ----------------
                                |1     |5      |7   -> if we would have use this coins[i], 
                               [10]     [6]    [4]    -> we would have to construct this coins


                    -> If we would have use coin '1', we would have to construct coin '10'
                    -> If we would have use coin '5', we would have to construct coin '6'
                    -> If we would have use coin '7', we would have to construct coin '4'

                Now, similary these problems that we are coming now {10, 6, 4}, these are the smaller subproblem that we have to solve in order to get the answer for 11.

                    -> Now look at [10], how we can get '10'
                    -> Similary, we can choose any coins that we want, let suppose we will choose coins 1 by 1..

                                       10
                                ----------------
                                |1     |5      |7   -> if we would have use this coins[i], 
                               [9]     [5]    [3]    -> we would have to construct this coins
                            
                    -> If we would have use coin '1', we would have to construct coin '9'
                    -> If we would have use coin '5', we would have to construct coin '5'
                    -> If we would have use coin '7', we would have to construct coin '4'


                Let's look for another branch [6]:
                                       6
                                ----------------
                                |1     |5      |7   
                               [5]     [1]    Not-possible
                            
                    -> If we would have use coin '1', we would have to construct coin '5'
                    -> If we would have use coin '5', we would have to construct coin '1'
                    -> If we would have use coin '7', which is not possible, because coins is grater than the subproblem itself.

            NOTE: If we want to construct the sum of X, We cannot be using a coin which has a value higher than 'X' -> Logical right

            We are breaking the problems into smaller sub-problems going down, & eventually we will hit a point where we don't need to divide subproblem, Now what would that point be?
            Can we say when we hit a point '0', Are we required any coins to construct '0' -> Answer is NO, So i know the answer for '0'
            When i construct the sum of 0, the answer is 0, i don't need anymore coins -> First observations
            Second Observations: Concept of overlapping sub-problem, a big problem is being divide into smaller problem, & then smaller problems repeating again & again..
            So, we should be storing the answer for the subproblem & return it when it's begin called to computed again...

            Now, let's see we have n smaller problem, which one should be choose, Here in this question we need the best possible ways to construct the combinations, so out of all we will get one which is taking minimum number of coins.
            whichever of them requires the minimum number of coins that is the one we will choose.

    
    -> So we can define our DP State like: 

                    dp[k] = minimum number of coins required to construct a sum of 'k'
                
                Now,  in order to construct 'k', what are the possible choices that we have, what are the smallest subproblem in which we can bring it.
                If we want to construct 'k', k can be broken down into:

                                    k
                                    |
                        ------------------------------
                        |       |       |            |
                        k-c1    k-c2    ...          k-c[n]

                
                There are n possible ways in which we can reduce this 'k' into smaller values, So, which one them are we going to choose, 
                Each of them requires 1 coins, (k-c1 -> 1 coin), (k-c2 -> 1 coin), (k-c3 -> 1 coin),..., (k-cn -> 1 coin)
                all of them requires 1 coins, So, which one are we going to choose, we are going to choose the one which gives us the minimal number of coins.

                                    k
                                    |
                        ------------------------------
                        |       |       |            |
                        k-c1    k-c2    ...          k-c[n]
                        5       3       20  11      100         -> Let's suppose this will take this much coins.

                Out of these we will choose (k-c2), because this will take minimum coins 3, 
                
                If we have to write a transition, what will this transition be?
                we will consider all these n possibility, & we will choose minimum of them.

                            dp[k] = min(dp[k-c[i]])
                                    i goes from 1 to n
                
                We will consider the best possibility that we have

                Now, If "k-c2" is required 4 coins, how many coins requires to construct 'k' -> 4 + 1,      { 4(k-c2), 1(this is for k)}

                For all of this problems the number of coins that are required we will add 1 coin to it to actually get the value 'k'
                So, we can say: 

                                d[k] = min(dp[k-c[i]]) + 1
                                        i goes from 1 to n
    
    -> Now think the minimal case for which we doesn't need to be divided, & for which we know the answer ? 

                That is dp[0], because in order to construct the sum of 0, how many coins we required ? -> answer is '0'

                    dp[0] = 0   -> base case
    
    -> Summing up: 

                // DP State: 
                        dp[k] = minimum number of coins required to construct the sum of 'k'

                // DP Transition: 
                        dp[k] = min(dp[k - c[i]]) + 1
                                i goes from 1 to n
                
                // Base case: 
                        dp[0] = 0


    -> Now what is the final subproblem that we are constructing?
        we want to construct this integer 'x', we want to find out the minimum number of coins required to construct this integer 'x'
        So, clearly the final subproblem is going to be: 
                    final subproblem -> dp[x]


// Complexity: 
    * Time complexity: 
        * Time complexity = state * avg transistion time per state
                            O(x)  * O(n)
        * TC: O(n*x)
    
    * Space complexity: 
        * Space is determined by the number of states: 
            * States: O(x)


*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int minCoins(vector<int> coins, int x, int n){

    vector<int> dp(x + 1, 1e9);    // construct an array of size x + 1, & with default value 10^9, which is very big number because we need minimum number, & we will never react to that default big number..

    dp[0] = 0;  // base case

    // dp[x] = dp[x - c[i]], in order to calculate dp[x], it's depends on previous value, this is why we are starting from 1 & go up till x
    for(int i=1;i<x+1;i++){
        // we are iterating into coins, from index 0 to 'n'
        for(int j=0;j<n;j++){
            // if coins value is less or equal to the 'x' we can use it else we can't
            if(coins[j] <= i){
                // transitions:
                dp[i] = min(dp[i], (dp[i - coins[j]] + 1)); // getting the minimum value, & we will have simple transitions.
            }
        }
    }

    return (dp[x] < 1e9) ? dp[x] : -1;
}

void solve(){
    int n, sum;
    cin >> n >> sum;
    vector<int> val(n);
    for(int i=0;i<n;i++) cin >> val[i];

    cout << minCoins(val, sum, n) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
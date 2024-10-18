/*

// Coin change problem: Minimum number of coins

// Problem Statement:
    * We are given an array of coins, & an integer sum, We have to find the minimum number of ways for we we get the sum.
    * In simple term we have to find the minimum number of coins for which we can make sum.
    * Example:
        
        arr[] = {1, 2, 3}, sum = 5

        * No of ways:
            {1, 1, 1, 1, 1}  = 5
            {1, 1, 3} = 5
            {1, 1, 1, 2} = 5
            {1, 2, 2} = 5
            {2, 3} = 5
        
        * from the number of ways, what will be the minimum number of coins needed to make sum = 5

            {2, 3} = 5      ->      minimum number of coins to make sum = 5
             
            ->  2 Coins are needed to make sum = 5

// Observations: 
    * This question is of unbounded knapsack type, because we are allowed to choose same coins again & again in order to make sum.
    // Initialization: 
        * In knapsack we have: 
            t[n+1][W+1] -> table
        * And we were given:
                W = capacity
                wt[] = weight array
                val[] = value array
        
        * Here in this problem, we have coin[] & Sum, So, val[] array from knapsack will be eliminated.
            * Matching:
                W = Sum
                wt[] = coin[]

            * So, initialization will be:

                t[n+1][Sum+1]       
                                => n = size of coins[] array.
                                => Sum = given
        
            * Matrix Creation: 
                Example:
                    coin[] = {1, 2, 3}, sum = 5,   n = 3

                                      <-----sum+1------------->
                                         0   1   2   3   4   5
                                   0   |   |   |   |   |   |   |
                            ^      1   |   |   |   |   |   |   |
                            |      2   |   |   |   |   |   |   |
                           n+1     3   |   |   |   |   |   |   | matrix = t
           
                
                    * NOTE: During the initialization, we will fill the 0th row & 0th column.
                    
                    * For the first row: 0 -> sum+1
                        
                            n = 0, coin[] = {}, & sum {0-5}
                        
                        * Logically there is no way we can make our sum with 0 coins..

                                    -----------------------------
                                    // Extra: 
                                            * Why we don't fill the first (sum = 0 & n = 0) with 0:
                                                * Their are INFINITE(Unbounded) number of Null Sets(null subsets) to contribute to sum 0. 
                                    -----------------------------
                        

                        * But, mathematically if we see:
                            n = 0, coin[] = {} , sum = 1
                            * We need infinite coin to make sum = 1, if we don't have any coin..
                        
                        * So, infinite can be represent as "INT_MAX"
                            * We will take "INT_MAX - 1" so that this should not round to "INT_MIN", when it's increased.

                        * So, we will fill the first row with "INT_MAX - 1"
                                       <-----------------------------------sum+1------------------------------------------->
                                              0             1             2            3               4           5
                                   0   | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 |
                            ^      1   |      0      |             |             |             |             |             |
                            |      2   |      0      |             |             |             |             |             |
                           n+1     3   |      0      |             |             |             |             |             | matrix = t
           
                    * For the first column: 1 -> n+1
                           n = 1, arr[] {1}, sum = 0       -> we need 0 coin to makes sum = 0
                           n = 2, arr[] {1, 2}, sum = 0    -> again, we need 0 coin to make sum = 0
                           ...
                           ...

                        * So, for sum = 0, & (n > 0), we need 0 coins to make our knapsack equal to sum               

                        * NOTE: Given the constrains, (1 >= cons[i]) coins is always grater than 0, this is why we don't fill it with 1, in earlier question that we were doing...


                    * For Second Row, Yes for this question we also need to fill the 2nd row, this one is unique question.
                        
                        * Example:
                                    arr[] = {3, 5, 2}, sum = 5

                                                <-----------------------------------sum+1------------------------------------------->
                                                       0             1             2            3               4           5
                                            0   | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 |
                                     ^      1   |      0      |             |             |  yyyyyyyyy  |  xxxxxxxx   |             |
                                     |      2   |      0      |             |             |             |             |             |
                                    n+1     3   |      0      |             |             |             |             |             |  matrix = t


                                * Let's look for the case when we have n = 1, & sum = 4:

                                    * For arr[] = {3, 5, 2}, sum = 5
                                                   |
                                            for this choice     -> Here, from the array, we are looking on '3', because we need to take decision for for arr[0] = '3', i.e our first element of an array.

                                * Now for filling here "xxxxxxx", n = 1 & sum = 3, How we can fill this in a way so that we can make our sum = 4

                                        3 + 3 + 3 + .. + 3 = 4  -> Not possible to make our sum = 4

                                            * because, for 3, it can be placed only on the place of: 3, 6, 9,...multiple of 3's

                                    * So, we will fill infinity here, in order to make sum = 4, mathematically
                                    * So, we will fill "INT_MAX - 1"
                                
                                * Now for filing here "yyyyyyyy", n = 1, & sum = 3, How we can fill this in a way so that we can make our sum = 3

                                        3 = 3(sum)
                                            
                                            3/3 = 1

                                            * We need single coin 1..
                                
                                * So, our matrix will look like this:

                                                <-----------------------------------sum+1------------------------------------------->
                                                       0             1             2            3               4           5
                                            0   | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 | INT_MAX - 1 |
                                     ^      1   |      0      |             |             |       1     | INT_MAX - 1 |             |
                                     |      2   |      0      |             |             |             |             |             |
                                    n+1     3   |      0      |             |             |             |             |             |  matrix = t


                                * So, from this point we can conclude that:
                                    * While filing the second row: (1 to sum+1):
                                        * if the arr[] element is divisible by sum value, we can fill " i / coin[0]", else we will fill "INT_MAX - 1" 


                                * Initialization Code:
                                        // First row:
                                            for(int i=0;i<sum+1;i++){
                                                t[0][i] = INT_MAX - 1;
                                            }
                                        // First Column:
                                            for(int i=1;i<n+1;i++){
                                                t[i][0] = 0
                                            }
                                        
                                        // Second row:
                                            for(int i=1;i<sum+1;i++){
                                                // we are checking for arr[0], because for (n = 1), we are checking arr[0], i.e our first element, so we can explicitly assign arr[0]
                                                if(i % arr[0] == 0){
                                                    t[1][i] = i / coin[0];    // if it's divisible, fill it with that divisible number...           -> because we can have divisible 1, 2, 3,.. (eg. 9/3 = 3, 9/9 = 1) -> both both number is divisible by 9, but 9 divides by single time by 9, & 3 divides thrice time with 9
                                                }
                                                else{
                                                    t[1][i] = INT_MAX - 1;  // if it's not divide, then we can fill it with infinity.
                                                }
                                            }


            * Filling the rest of the table:

                * Comparing it with knapsack:
                        if(wt[i-1] <= j){
                            t[i][j] = max(
                                val[i-1] + t[i-1][j-wt[i-1]],   // include case
                                t[i-1][j];  // exclude case:
                            );
                        }
                        else{
                            t[i][j] = t[i-1][j];    // exclude case:
                        }

                * Comparing it for unbounded knapsack with Code Variation:
                
                    * Note, we have to filled our table for remaining empty place: (i.e i = 2, & j = 1)

                        // if coin is less or equal to sum:
                        if(coin[i-1] <= j){
                            // two choice: Include(Not-Processed) / Exclude(Processed)
                            t[i][j] = min(  // taking minimum because we need to get the minimum number of possible coins.
                                1 + t[i][j - coin[i-1]],    // adding 1, so that we can count the number of coins, & this is for Include Case, (this is why t[i] not t[i-1])
                                t[i-1][j]       // exclude case (Processed), this is why we remove the element from our comparision choice.
                            );
                        }
                        else{
                            // exclude case, when we have {coin[i-1](element) > j(sum)} coin is grater than the sum capacity.
                            t[i][j] = t[i-1][j]
                        }

// NOTE:
    * Small Improvement:
        * At the last stage when returning the t[n][sum], we need to check the value, whether it's possible to get the sum from the coin[] array.

            if(t[n][sum] == INT_MAX - 1){
                return -1;  // there is no chance we can get the sum with the coin[] array.
            }
            else{
                return t[n][sum];   // we can get the sum with the coin[] array.
            }


    * Also, we have used "INT_MAX - 1" everywhere instead of "INT_MAX":
        * Because when this value sum up with include case, this will make ((INT_MAX - 1) + 1) = INT_MAX,
                    1 + t[i][j - coin[i-1]],

        * If we have taken "INT_MAX" only, then the sum up become (INT_MAX + 1) = INT_MIN -> this is why we were using (INT_MAX - 1)



// TC: O(n * sum)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


int coinChangeMaxNoOfWays(vector<int> coin, int sum){
    int n = coin.size();

    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (sum+1));

    // Filling first Row: 0 -> sum+1
    for(int i=0;i<sum+1;i++) t[0][i] = INT_MAX - 1;

    // Filling first Column: 1 -> n+1
    for(int i=1;i<n+1;i++) t[i][0] = 0;

    // Filling the second Row: 1 -> sum+1
    for(int i=1;i<sum+1;i++){
        // because for every sum, we are checking it with first element.
        if(i % coin[0] == 0){
            t[1][i] = i / coin[0];    // if it's divisible, fill it with that divisible number
        }else{
            t[1][i] = INT_MAX - 1;  // filling it with infinite number if it's not possible to make sum.
        }
    }

    // Filling the rest of Matrix: as we have filled all the 
    for(int i=2;i<n+1;i++){     // first two row is filled
        for(int j=1;j<sum+1;j++){   // first column is filled, so, we will skip that
            // if given coins is less or equal to the current sum:
            if(coin[i-1] <= j){
                // Two choices: Include(Not-processed) / Reject(Processed)
                t[i][j] = min(  // taking minimum, because we need to find the minimum coins for which we can make our sum. 
                    1 + t[i][j - coin[i-1]],    // 1 + because we are adding all the coins that makes our sum, & "t[i]" because it's still in unprocessed state -> Include Case
                    t[i-1][j]     // Reject case, Processed => t[i-1]
                );
            }
            else{
                // if coins is grater than the sum itself.
                t[i][j] = t[i-1][j];    // Exclude case
            }
        }
    }

    if(t[n][sum] == INT_MAX - 1){
        return -1;  // not Possible
    }
    return t[n][sum];   // else return the minimum number of coin
}

void solve(){
    int n, sum;
    cin >> n >> sum;

    vector<int> coin(n);
    for(int i=0;i<n;i++) cin >> coin[i];

    cout << coinChangeMaxNoOfWays(coin, sum) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
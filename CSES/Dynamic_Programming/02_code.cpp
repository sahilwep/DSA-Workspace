/*

//  CSES: Dice Combinations

//  Problem Statement: 
    * Your task is to count the number of ways to construct sum n by throwing a dice one or more times. 
    * Each throw produces an outcome between 1 and  6.
    * Print the number of ways modulo 10^9+7.
    * Constraints:  (1 <= n <= 10^6)


// Example:

    For example, if n=3, there are 4 ways:

        1+1+1
        1+2
        2+1
        3


// Visualization:

        -> n can go up to 10^6
        -> We can throw dice as many times as we want..
        -> Dice value can range b/w 1 to 6


        -> We have big problem, & We will try to break it into smaller sub-problem which are relatively easier to solve..
        -> and we can come up with the relations for the smaller sub-problem so that we can get the answer for the bigger sub-problem..
        -> Let's say we want to construct 'k', now what are the different ways in which we can actually get the sum of 'k', in just one roll let's suppose:
        -> What we can do, we can divide this subproblem into 6 parts:

                we can get the sum of 'k' from:

                                                        k
                                                        |
                                    ----------------------------------------
                                    1      2       3       4       5       6    -> These are the throws
                                    |      |       |       |       |       | 
                                   k-1    k-2     k-3     k-4     k-5     k-6   -> We can get the value of 'k' from k-i, i = 1 to 6

                
                    We can get the sum of 'k' from k-1, by making a throw of 1
                    We can get the sum of 'k' from k-2, by making a throw of 2
                    We can get the sum of 'k' from k-3, by making a throw of 3
                    ...
                    We can get the sum of 'k' from k-6, by making a throw of 6

                You might we wondering what we are essentially doing here, 
                'K' is very big problem to solve, in order to solve 'k', we are just saying that we can get this value of 'k' from so many cases..
                k-1, k-2, k-3, ... k-6


                                                    k
                                                    |
                                ----------------------------------------
                                1      2       3       4       5       6    -> These are the throws
                                |      |       |       |       |       | 
                                k-1    k-2     k-3     k-4     k-5     k-6   -> We can get the value of 'k' from k-i, i = 1 to 6
                                a1     a2      a3      a4      a5      a6

                Now, let's think this like: 
                    The number of ways to get 'k-1' is a1
                    The number of ways to get 'k-2' is a2
                    The number of ways to get 'k-3' is a3
                    ..
                    The number of ways to get 'k-6' is a6
                
                Now, if i will tell you that you have value of 'k-1', & you want to get the value of 'k' in just 1 throw, how many ways are that ?
                -> There are just a1 ways.

                Because the number of ways which we can get 'k-1' is a1, & then we can make a throw of 1, which will give us the sum of 'k'
                similarly, for k-2, k-3.., k-6

                So, k is bigger problem, & we have broken this into k-1, k-2,..k-6, can we think a state here?
                    What is state: State is sub-problem, in this entire problem.
                So, we can define our state like this:

                        dp[k] = number of ways to get a sum of k        -> This is our sate.
                
                Now, what is going to be the total number of ways, it's nothing but addition of all the ways, k-1, k-2,.. so on up till k-6

                So, transition would look something like this:

                                      6
                            dp[k]  =  ∑ dp[k-i]
                                     i=1

                Now, what is the smallest sub-problem for which we don't have to further divide, for which we already know the answer?

                    dp[k] = number of ways to get a sum of k, So where do we actually start from?
                    So, we start from sum of 0 right, & the number of ways to get sum of 0 is just 1, because we are not going to roll dice.
                    So, 
                            dp[0] = 1   -> This is going to our base case..



// Example Visualization: 

    Example: n = 4

    Initialization: dp[0] = 1: There is exactly 1 way to achieve a sum of 0 (by not rolling the dice).

    Step-by-Step Calculation:
    For i=1:
        Inner loop for dice outcomes (1 to 6):
            j = 1: Since j is less than or equal to i, we update dp[1]:
            dp[1]=dp[1]+dp[1−1]=dp[1]+dp[0]=0+1=1

            j = 2, 3, 4, 5, 6: Since these values are greater than i, the loop breaks.

        Result after iteration: dp[1]=1dp[1]=1
            There is 1 way to achieve a sum of 1:
                1

    For i=2:
        Inner loop for dice outcomes (1 to 6):
            j = 1: Since j is less than or equal to i, we update dp[2]:
            dp[2]=dp[2]+dp[2−1]=dp[2]+dp[1]=0+1=1

            j = 2: Since j is still less than or equal to i, we update dp[2]:
            dp[2]=dp[2]+dp[2−2]=dp[2]+dp[0]=1+1=2

            j = 3, 4, 5, 6: Since these values are greater than i, the loop breaks.

        Result after iteration: dp[2]=2dp[2]=2
            There are 2 ways to achieve a sum of 2:
                1 + 1
                2

    For i=3:
        Inner loop for dice outcomes (1 to 6):
            j = 1: Since j is less than or equal to i, we update dp[3]:
            dp[3]=dp[3]+dp[3−1]=dp[3]+dp[2]=0+2=2

            j = 2: Since j is still less than or equal to i, we update dp[3]:
            dp[3]=dp[3]+dp[3−2]=dp[3]+dp[1]=2+1=3

            j = 3: Since j is still less than or equal to i, we update dp[3]:
            dp[3]=dp[3]+dp[3−3]=dp[3]+dp[0]=3+1=4

            j = 4, 5, 6: Since these values are greater than i, the loop breaks.

        Result after iteration: dp[3]=4dp[3]=4
            There are 4 ways to achieve a sum of 3:
                1 + 1 + 1
                1 + 2
                2 + 1
                3

    For i=4:
        Inner loop for dice outcomes (1 to 6):
            j = 1: Since j is less than or equal to i, we update dp[4]:
            dp[4]=dp[4]+dp[4−1]=dp[4]+dp[3]=0+4=4

            j = 2: Since j is still less than or equal to i, we update dp[4]:
            dp[4]=dp[4]+dp[4−2]=dp[4]+dp[2]=4+2=6

            j = 3: Since j is still less than or equal to i, we update dp[4]:
            dp[4]=dp[4]+dp[4−3]=dp[4]+dp[1]=6+1=7

            j = 4: Since j is still less than or equal to i, we update dp[4]:
            dp[4]=dp[4]+dp[4−4]=dp[4]+dp[0]=7+1=8

            j = 5, 6: Since these values are greater than i, the loop breaks.

        Result after iteration: dp[4]=8dp[4]=8
            There are 8 ways to achieve a sum of 4:
                1 + 1 + 1 + 1
                1 + 1 + 2
                1 + 2 + 1
                1 + 3
                2 + 1 + 1
                2 + 2
                3 + 1
                4

        Summary:
            dp[4]=8: There are 8 ways to achieve the sum of 4 using dice rolls. 
            The computation uses previous values of dp and efficiently builds up solutions using dynamic programming.




// Complexity:
    * TC: O(n)
    * AS: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll countWays(int n) {
    vector<ll> dp(n + 1);  // Create a vector 'dp' of size (n + 1) initialized to 0. This vector will store the number of ways to achieve each sum from 0 to n.

    dp[0] = 1;  // Base case: There is 1 way to achieve a sum of 0 (by not rolling the dice at all).

    for (int i = 1; i <= n; i++) { // Iterate over every possible sum from 1 to n.
        for (int j = 1; j <= 6; j++) {  // For each sum 'i', consider the possible dice rolls (from 1 to 6).
            if (j > i) break;   // If the dice roll value 'j' is greater than the current sum 'i', stop considering further values (since it won't contribute).

            dp[i] = (dp[i] + dp[i - j]) % mod; // Update dp[i] by adding the number of ways to achieve the sum (i - j).
        }
    }

    return dp[n];   // Return the number of ways to achieve the sum 'n'.
}


void solve(){
    int n;
    cin >> n;

    cout << countWays(n) << endl;

}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
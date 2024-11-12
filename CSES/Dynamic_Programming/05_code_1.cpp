/*

//  CSES: Coin Combinations II -> Tabulations Solution

// Problem Statement: 
    * Consider a money system consisting of n coins. Each coin has a positive integer value. 
    * Your task is to calculate the number of distinct "ordered" ways you can produce a money sum x using the available coins.

    * For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
        2+2+5
        3+3+3
        2+2+2+3

    * Constraints
        1 <= n <= 100
        1 <= x <= 10^6
        1 <= c[i] <= 10^6



// Visualization: 
        -> Let's visualize this problem:
            
            Let say we have coins: c1, c2, c3, c4, c5 & we were trying to make our value X

                    c1 c1 c2 c2 c5 = X      let's assume this possible coins make x
                    c1 c2 c1 c2 c5 = x      This one also makes 'x'

                Even the coins combinations are same, but when the ordered is change, & we ended up counting it twice.
                So, how do we make sure we don't count them twice.

                    For this what we can do, we can say something like this: 
                        We will make sure all the c1's comes together, all the c2 comes together, all the c3 comes together up till cn.
                        and this will fix the problem of counting them twice..
                
                    But we can have one edge case: 
                        what if: 
                                c2 c2 c1 c1 c5 = x      Now this time c2 are come together, c1 are comes together, & c5, But this is still turning out to be a different ways.
                    
                    Solution to that edge case: 

                            if we make sure that (c[i] < c[i+1]), 
                            All the c[i] they are first of all coming together, & they have to come before c[i+1]
                            Then we can say our final order in which we will be getting all these coins are ordered.
                            So, this gives us a unique permutations, we cannot permute the coins anymore if we make sure that this condition holds

                Let's see how we can make sure this: c[i] < c[i+1]
                    assume we have coins c1, c2, c3, c4.... up till cn
                    and let say if we are picking up 'c2', we will pick all this c2 "together".
                    So, we are saying all the c[i] should be picked up before c[i+1]
                    So, what this is also means, if we skip c2 & we have landed at c3, we are only allowed to pick c3 & coins higher to that.

                                      | -->
                                c1 c2 | c3 c4 c5....cn
                    
                    So, when we are concern to make sum 'X', we are also concern about which coins we actually pick up.
            

            So, Initially if we look a the problem:

                        [              ]            X
                        c1 c2 ....... cn
                        
                We have c1, c2,.. cn, & for constructing x, we can say we are allowed to pick up all the coins from c1 up till cn
                So, the first thing we can do is to we can actually pick up coin c1 & in that case we will have to make (X - c1)

                                    X
                                   / 
                                  /  
                                 /   
                             (X-c1) -> we have picked c1, but we are still allowed to pick this coin c1 again.
                             So we can say we are not just concern about (X - c1), But we are also concern about this integer c1, that now we are still allowed to pick coin c1
                    
                But what if we have decided to skip this coin c1:
                            
                                     X
                                   /  |
                                  /   |
                                 /    |
                             (X-c1)  (X)
                                      |
                                    In that case we still have to make this integer 'X', because if we have skipped C1, we haven't subtracted anything from that.
                                    and now we are not allowed to pick c1 again.
                                                X
                                              /  |
                                             /   |
                                            /    |
                                        (X-c1)  (X-[c2..cn]) -> We are only allowed to pick coins c2 & beyond.


                So, when we are looking this problem there are two things which are important:            
                    1. What is the integer that we want to construct as a sum
                    2. What are the coins that we can actually pick up.

                Now, to denote this thing what we can do, we can say:
                    When we pick up this integer "i"   
                                                  |
                                                and all the coins from c[i] up till c[n] are pickable
                    
                    So, we need two informations from here
                        1. The sum that we want to construct
                        2. The coins from which we actually start picking up.

            // DP state:
                We can say our dp state like: 
                    'i' there is an integer i, from which all the coins from c[i] up till c[n] are pickable.
                    and we want to construct this integer 'k'

                                    (i, k)

                    There are two things we can that we can actually do at this point, we can either pickup coins i, or we can either skip coins i.
                
                                    (i, k)
                                      |
                        [Picked--------
                          |                      
                        (i, k - c[i])      

                    If we pick up coins i, what happens, in this case we are still pick up this coins again, 
                    & the what is the integer that we want to construct, i.e (k - c[i]), we have decided to subtracted coins from our 'k' 

                    The other case where we skip coin c[i]:
                    If We skip coin c[i], we can't pickup coin c[i] again,
                
                                    (i, k)
                                      |
                        [Picked--------------[Skipped]
                          |                        |
                        (i, k - c[i])        (i + 1, )
                                            In that case we can only start picking up coins from (i+1), 
                                            and the sum that we want to construct, we still want to construct the sum 'k', because we haven't subtracted anything from that.
                    
                    Let say this bigger problem 'p'

                                    (i, k)
                                      |
                        [Picked--------------[Skipped]
                          |                        |
                        (i, k - c[i])        (i + 1, )
                           "p1"                  "p2"
                        
                        -> This smaller subproblem is "p1" & "p2"
                        -> "p1": In p1, we are constructing smaller sum "k-c[i]", with the same set of coins that we had initially in problem 'p'
                        -> "p2": In p2, we are constructing same sum "k", with a smaller set of coins, that we had initially in problem 'p'.
                        -> So, both 'p1' & 'p2' are smaller than 'p' in terms of size of 'p'
                    
                                        (i, k)
                                        |
                            [Picked--------------[Skipped]
                            |                        |
                            (i, k - c[i])        (i + 1, )
                            "p1"                  "p2"
                            (a1)         +          (a2)

                        -> Let's suppose there are a1 ways to construct problem p1 -> This means there are a1 ways to construct this sum 'k-c[i]' from the coins c[i] up till c[n]
                        -> let's suppose there are a2 ways to construct problem p2 -> This means we can construct the sum 'k' from the coins c[i+1] up till c[n].
                        -> And if we want to solve this bigger subproblem, this bigger subproblem can be solve using this two ways, & if we want to find out all the number of ways, we can simply add up A1 & A2
                            -> Total number of ways = A1 + A2
                        
                        DP State:
                                dp[i, k] = no of ways to get a sum of k, such that all coins from c[i] to c[n] are pickable,
                                           & all coins before c[i] are skipped

            // Transitions: 
                    Transitions like: 
                                dp[i, k] can be retrievd using two ways: 

                                            dp[i, k]
                                          /         \
                                         /           \
                                    [ Skip ]        [pick]
                                dp[i+1][k]          dp[i][k-c[i]]

                            -> When we skip the value, we will go with "i+1" coins, & we still have for sum 'k', because we haven't subtracted for anything from 'k'
                            -> when we pick the , we can have sill have options to go with same coins, but we have  subtracted c[i] from 'k', which will reduce the value of 'k'


                    -> Relations b/w these two subproblem:
                        We can simply add these both the problem to get the answer for the bigger subproblems.

            // Base case:
                    Smallest subproblem for which we want to solve, for which we further don't divide.
                    If sum becomes 0, it' doesn't matter how many coins we have left,
                    It's just one possible ways to construct '0' -> Don't pick up any of the coins.
                    So that is the one way for which we don't further divide:
                                dp(i, 0)
                                -> i can go from 1 to n, any value...

                                "dp[i][0] = 1"
                
            // Final State:
                    
                    Final subproblem  => dp[1][x]

                    -> this means that all the coins from c1 up til cn are pickable & we want to construct the sum of 'x'
                    -> we are traversing backward, this is why we are denoting first dimensions with least value.


// Complexity:
    * Time Complexity: States & T.T
            * State:
                dp[i][k]
                i = 1 to n
                k = 0 to x
            * Transition Time per state: 
                -> Simply order of 1, O(1), because state is depending upon two other states, & we are getting their values & adding them up.
                -> TT: O(1)

            * Time Complexity: O(n*x) * O(1) => O(n * x)
    
    * Space Complexity:
            * Space complexity is just defined from number of states: O(n * x)



// Extra: 
        * How Do we define loops: 
            
            How do we figure out the, from where loop starts, & from where it goes.

            let's see: 
                dp[i][k] -> depends upon dp[i][k - some_value] & dp[i+1][k]

                If we are looking at this second parameter 'k':
                    -> In order to get the value of k, we need smaller value, because [k - some_value]
                    -> That for loop, for the second dimension of loop start from '0'  to up till 'n'

                If we are looking at this first parameter 'i':
                    -> In order to get the value of i, we need larger value, because we are getting [i+1]
                    -> That for loop, for the first dimension it will have to come from larger value to smaller value, it will have to go from 'n' to '0'.

                Dimension          Depends upon                          loop definations flow
                    k        ->    'k' & (k - some value)                 0 -----> n
                    i        ->    'i' & (i + 1)                          n -----> 0


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007

int coinCombination_2(vector<int> &coins, int x, int n){
    
    vector<vector<int> > t(n+1, vector<int> (x+1, 0));

    // filling the first column: for sum = 0, we atleast have 1 choice, that we can pick no coins.
    for(int i=0;i<n+1;i++){
        t[i][0] = 1;
    }

    // iteration start from n-1 last, because, t[i][k] = t[i][k - some value], t[i+1][k], & here i depends on one forward value, which is [i+1], this is why it's start from n-1 & goes up till 0
    for(int i=n-1;i>=0;i--){    // for i, we are going from higher value to a smaller value.
        for(int sum=1;sum<=x;sum++){    // But, for sum, we are going from lower value to a higher value.
            // we are finding dp[i][sum]
            
            // First Skip the coins 'i':
            int skipping = t[i+1][sum];     // Skipping -> Processed = t[i+1][sum], if we skip the coin i, we only left picking up from (i+1) up till 'n'

            // Second pick the coin 'i':    
            int picking = 0;
            // if item is less or equal to sum: 
            if(coins[i] <= sum){    // if we are picking the coins, we need to check whether the coins size is less or equal to sum or not, if it's higher, we can't pick it up.
                picking = t[i][sum - coins[i]]; // picking -> Not-processed = t[i][sum-coins[i]],   if we pick the coin i, we still have to options to pick coin i, but the sum is subtracted by the current coin 'i'
            }

            // Transition:
            t[i][sum] = (skipping + picking) % mod;     // last adding all the item which are skipped & picked
        }
    }


    return t[0][x];  // returning the final subproblem, it will found in t[0][x], as we are iterating from backward.
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
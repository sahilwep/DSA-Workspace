/*

//  Egg Dropping Problem Memoization binary Search Optimizations:


//  Problem Statement:
    * We are given N identical eggs, and we have access to K-floored building from 1 to K.
    * There exist a floor 'f' where 0 <= f <= k, such that any egg dropped from a floor higher than 'f' will break, 
    * and any egg dropped from or below floor f will not break.
        * An egg that survives a fall can be used again.
        * A broken egg must be discarded.
        * The effect of a fall is the same for all eggs.
        * If the egg doesn't break at a certain floor, it will not break at any floor below.
        * If the egg break at a certain floor, it will break at any floor above.
        
    * Return the minimum number of moves you need to determine with certainly what the value of 'f' is.



// Visualization: 

        * We are given N eggs & K floors, & From these we need find minimum number of attempts to find the floor, which will (critical floor/ Threshold floor).


                                |---| |
                                |   | | Egg breaks 
                                |   | |
                    Critical -> | k |   |       
                    floor       |   |   |   
                                |   |   |   Egg not breaks
                                |___|   |


                                    k -> first floor, where egg will not break, is our critical floor / threshold floor.


        * To find this critical floor, how much minimum number of attempts we needed, that we have to find according to the question.

        // We are given eggs, & floor, from this egg we need to find the critical floor.
            * General Evaluations: 
                         ___   
                        |   |   
                        |   |   
                        |   |   
                        |-k-|  -> let say from this floor, the eggs are broken:
                        |   |   
                        |   |   
                        |   |   
                        |___|   
                        Building

                    * If eggs are broken from 'k' floor, we need to go down, (k-1) floor, we have to try..
                    
                         ___   
                        |   |   
                        |   |   
                        |   |   
                        |-k-|  -> let say from this floor, the eggs Not-broken:
                        |   |   
                        |   |   
                        |   |   
                        |___|   
                        Building

                    * If eggs are Not-broken from 'k' floor, we can try for above floors, (k+1) floor, we have to try..

            * From this we can say: 
                If egg is broken from 'K' floor we will have to try for "k-1" floors
                If egg is not broken from 'K' floor we will have to try for "k+1" floors



        // Worse case Evaluations:

                * If we are given only one egg, we need to use it very wisely. Dropping it from a random floor risks breaking the egg, and if it breaks, we won’t be able to determine the "critical floor."
                * In the worst case, with only one egg, we would drop it starting from the first floor, then the second, then the third, and so on, until we find the "critical floor."
                * If the egg does not break, we can continue using it to test the next floors. This way, we will eventually identify the "critical floor."
                * Therefore, if we have only one egg, we would drop it sequentially from the 1st floor up to the 'f' floor to find the critical threshold.
                

                        egg = 1
                         ___    
                        |   | 'F' floor
                        |   |   
                        |   |   
                        |   |  
                        |   |   
                        |   |   
                        |   |   
                        |___|  '1st' floor
                        Building

                * So, in worse case when we have only 1 egg, "critical floor" found on top i.e 'F'
                        
                        1 egg => F attempts needed
        

                * So, we can say we have to find:
                    * In Worse case, by using best technique & minimize the number of attempts, we have to find the "Critical floor".
                    * & We have to return the number of attempts.


        // MCM Identification: 
            * We are trying to drop egg from every floor, means we are trying to perform partition for every 'k' range (i -- j)
            * This is why we will use MCM technique to solve this question.
        

        // MCM Format:

            // Find i & j

                We are not given any array or string, but we are given floor 'f', which represent an array, if we carefully watch: 

                    f = 7
                         ___    
                        |   | 7 
                        |   | 6 
                        |   | 5
                        |   | 4 
                        |   | 3 
                        |   | 2 
                        |___| 1

                        Building: 

                            [ 1 | 2 | 3 | 4 | 5 | 6 | 7 ]    -> 1 index based array

                        If we choose i = 1 & j = 7, there is no problem, because here we can try dropping eggs from (i = 1 to j = 7)

                            [ 1 | 2 | 3 | 4 | 5 | 6 | 7 ]  
                              i                       j 
                    
                Generalization:

                            [ 1 | 2 | 3 | 4 |........| F ]  
                              i                        j

                        i = 1
                        j = f


            // Find base Cases:

                Think of the smallest valid input:

                    Inputs: 
                        e = egg 
                        f = floor
                    
                Smallest input:

                    If egg = 0  -> if there is no egg, we won't able to find, so egg = 0 condition is not valid.
                    If egg = 1 -> In worse case we will drop it from 1 to F floor, and we will have minimum f attempts in worse case.

                        if(egg == 1) return F

                    If floor = 0 -> If there is no floor, we will have 0 attempts
                    If floor = 1 -> if there is 1 floor, in worse case will have 1 attempt needed.

                        if(f == 0 || f == 1) return f;

            // find K loops:

                We don't know for which floor egg will break, so we will try dropping from (1 to f), floor

                         ___    
                    j   |   | f     -> k
                        |   | .     -> k
                        |   | .     -> k
                        |   | 4     -> k
                        |   | 3     -> k
                        |   | 2     -> k
                    i   |___| 1     -> k


                        for(int k = i; k <= j; k++){
                            logic...
                        }

            // find partition scheme:

                         ___
                        |   | 'F' floor
                        |   |   
                        |   |   
                        | k |   -> Kth floor:
                        |   |  
                        |   |   
                        |   |   
                        |   |   
                        |___|  '1st' floor
                        Building

                    IF we have 'F' floors, & we will drop eggs from 'Kth' floor, what are the possible cases:
                    given (e = eggs, & f = floor)


                                            (e, f)  -> Dropped from 'kth' floor
                                            /     \
                                           /       \
                                     [Break]       [Not-Break]
                                      |                     |
                                check(e-1, k-1)      check(e, F-k)
                        
                        * If egg Breaks:
                            * Threshold floor will be found below 'Kth' floor.
                            * We will have to check at max: (k-1) floors only
                            * and we have loss of one egg, so (e-1)
                        
                        * If egg Not Breaks:
                            * We are sure that threshold floor found above "kth" floor
                            * So, we will have to check (f-k) floor only.
                            * and we don't have any loss of egg, so (e)
 
                        
                            Example:
                                f = 9, e = 3
                                     ___
                                    |   | 9
                                    |   | 8 
                                    |   | 7  
                                    |   | 6 
                                    | k | 5  -> Kth floor:
                                    |   | 4  
                                    |   | 3 
                                    |   | 2  
                                    |___| 1
                                    Building

                                            // breaks: 
                                                checks(3-1, 5-1) => checks(2, 4) -> called

                                            // Not breaks:
                                                checks(3, 9-5) => checks(3, 4) -> called

                        // From this we will have decision: 
                                // Breaks:
                                    check(e-1, k-1)
                                // Not breaks:
                                    check(e, f-k)

                    FOR, BOTH DECISIONS WE ARE TAKING FROM WORSE CASE: According to the question, we need to find minimum number of attempts in worse case:
                    Because we are finding these decision from worse case: this is why we will take max() from both the decisions.

                        tempAns = max(Breaks, Not-Breaks)

                        tempAns = max(solve(e-1, k-1), solve(e, f-k))

                    WE HAVE ONLY COMPUTED FOR (EGGS & FLOORS), WE HAVEN't COMPUTED FOR ATTEMPTS 
                        
                        tempAns = max(solve(e-1, k-1), solve(e, f-k))
                                             |    |          |    |
                                            egg floor       egg floor
                        
                        So for every attempts, we will add 1 to both the decisions.

                        tempAns = 1 + max(solve(e-1, k-1), solve(e, f-k))

            // find answer from temporary answer:

                At last we need minimum number of attempts, from above the temporary answer:

                    ans = min(ans, tempAns)



// Recursive Complexity:
    * TC: O(2^f)
    * AS: O(f)  -> f calls in recursive stack.


// Problem with Recursive Solution: 
    * From given recursive solution, we will have subproblem, called & Computes multiple times.
    * TC: O(2^n)


// Intrusion: 
    * Solution for that we will use DP solution: 
        * We will use memoization solution
        * We will have to maintain memo table of variable size (changing size parameters): (e & f)
        * Create a 2D table of size (ExF)
    * Whenever recursive function calls for solution of subproblem, we will apply check that if the value exist, return directly from memo table without going into the recursive calls.
    * If solution is not exist in table, compute the solution, & store result in table & then return the values.



// Memoization Complexity:
    * TC: O(e*f^2)
    * AS: O(f)



// Optimized Using Binary Search:
    * We can implement a binary Search on the k-partition instead of a linear search.
    * This is based on the observation that, as k (the floor from which we drop the egg) increases, 
    * the break and not-break cases exhibit a predictable pattern that allows for a binary search approach.
    
    // Reasoning Behind Binary Search:
        * When we partition at floor k, we have two scenarios:
            * The egg breaks: This means we need to search below k, specifically k-1 floors with e-1 eggs.
            * The egg does not break: We can continue the search above k, which is f-k floors with e eggs.
        * This split leads to a "valley" pattern in the number of attempts:
            * When we start at lower values of k, the break case is likely to be larger.
            * As k increases, the not-break case tends to dominate.
        * Using binary search over the range of floors can help us converge more quickly to the optimal k where the worst-case attempt count is minimized. 
        * This approach reduces the time complexity from O(f^2) to O(f log f) for each egg-floor pair



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Memoization Solution: 
int eggDrop(int e, int f, vector<vector<int> > &t){

    // If floor is 0 || 1 -> In worse case we will have f attempts.
    if(f == 0 || f == 1) return f;
    
    // If we have single egg -> In worse case will have to go for f attempts, because we will try from 1st -> 2nd -> 3rd -> so-on till 'F' floor.
    if(e == 1) return f;

    // Checking subproblem solutions from memo-table:
    if(t[e][f] != -1) return t[e][f];


    // Perform Binary Search: 
    int ans = INT_MAX;
    int low, high;

    int left = 1, right = f;
    while(left <= right){
        int k = (left + right) / 2;

        // If we don't have to precomputed values, compute and store them.
        if(t[e-1][k-1] == -1){
            t[e-1][k-1] = eggDrop(e-1, k-1, t);
        }
        low = t[e-1][k-1];

        if(t[e][f-k] == -1){
            t[e][f-k] = eggDrop(e, f-k, t);
        }
        high = t[e][f-k];

        int tempAns = 1 + max(low, high);  // Take the worst case
        ans = min(ans, tempAns);    // Take the minimum over all worst cases

        // Narrow down the search range based on comparisons:
        if(low < high){
            left = k + 1;  // Need to increase k
        }
        else{
            right = k - 1;  // Need to decrease k
        }
    }
    
    return t[e][f] = ans; // Storing the answer in memo table, before returning
}


void solve(){
    int e, f;
    cin >> e >> f;
    
    vector<vector<int> > t(e+1, vector<int> (f+1, -1));

    cout << eggDrop(e, f, t) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
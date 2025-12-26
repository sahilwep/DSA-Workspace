/*

//  2483. Minimum Penalty for a Shop



//  Problem Statement: 
    - You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':
        - if the ith character is 'Y', it means that customers come at the ith hour
        - whereas 'N' indicates that no customers come at the ith hour.
    - If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:
        - For every hour when the shop is open and no customers come, the penalty increases by 1.
        - For every hour when the shop is closed and customers come, the penalty increases by 1.
    - Return the earliest hour at which the shop must be closed to incur a minimum penalty.
    - Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

 

// Example:
    Example 1:
        Input: customers = "YYNY"
        Output: 2
        Explanation: 
        - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
        - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
        - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
        - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
        - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
        Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.

    Example 2:
        Input: customers = "NNNNN"
        Output: 0
        Explanation: It is best to close the shop at the 0th hour as no customers arrive.

    Example 3:
        Input: customers = "YYYY"
        Output: 4
        Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.



// Observations: 
    - given customer comes at ith hour..
        - Y -> come
        - N -> don't come
    - If shop is closed at jth hour (0 <= j <= n) the penalty is calculated:
        - for every hour when shop Open, no customer come -> penalty Increase
        - for every hor when shop is closed & customer come -> penalty Increase.
    - Return the earliest hour, at which shop must be closed with a minimum penalty.

    // Explanation:

            customer: [Y, Y, N, Y]
                -> size = 4

                    0th hour:
                                Open | closed
                                    [|Y, Y, N, Y]
                                     |
                        penalty       +  +     +    => 3


                    1st hour:
                                   Open | closed
                                    [ Y,| Y, N, Y]
                                        |
                        penalty           +     +    => 2



                    2nd hour:
                                      Open | closed
                                    [ Y, Y,| N, Y]
                                           |
                        penalty              +      => 1


                    3rd hour:
                                         Open | closed
                                    [ Y, Y, N,| Y]
                                              |
                        penalty             +   +    => 2


                    4th hour:
                                           Open   | closed
                                    [ Y, Y, N, Y ]|
                                                  |
                        penalty             +       => 1
                
            => At 2nd & 4th hour, customer penalty is minimum, so answer is '2nd' earliest one..


    // Bruteforce Solution:
        - For every hour 'j' (0 <= j <= n)
            - Compute the left side Open time at which total customer not come.
            - Compute the right side Closed time at which customer come.
            - Calculate penalty.
        - Store the minimum penalty we can get, & for that earliest hour return..

        // Complexity: 
            - TC: O(n^2)
            - SC: O(1)

    // Optimization: 
        - At every jth hour, we are calculating the left & right side open & closed, 
        - if we store these results in some prefix array & directly get these results, then our jobs is quite easy to process.
        - we will maintain prefix & suffix sum:
            - Prefix sum: this will calculate the customer that not come at open hours.
            - Suffix sum: this will calculate the customer that will come at closed hour..
        - at every jth hour, we can calculate & compute the min penalty.
        
        // Complexity: 
            - TC: O(n)
            - SC: O(n)

    // Space Optimization:
        - Instead of maintaining prefix & suffix sum we can do this in O(1) space
        - while iterating forward we will calculate the prefix.
        - We will precalculate the suffix & while iterating we will decrement..

        // Complexity:
            - TC: O(n)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Space Optimized
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        // precompute closed sum:
        int closed = 0;
        for(auto &c: customers) {
            if(c == 'Y') closed++;
        }

        // Now Calculate the Early Hour:
        int earlyHour = n;  // at worse we will close at nth hour
        int minPenalty = INT_MAX;
        int open = 0;

        for(int j = 0; j <= n; j++) {
            int penalty = 0;
            // Calculate Open Hours penalty (left side):
            penalty += open;

            // Calculate Closed Hour penalty (right side):
            penalty += closed;

            // Calculate the minimum penalty:
            if(penalty < minPenalty) {
                minPenalty = penalty;
                earlyHour = j;
            }

            // As we move forward, Compute Closed & open:
            if(j < n) {
                if(customers[j] == 'N') {    // if shope was open, & customer not came => penalty
                    open++;
                }
                if(customers[j] == 'Y') {    // if shop was closed, & customer came => penalty
                    closed--;
                }
            }
        }

        return earlyHour;
    }
};


// Optimal Solution:
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // Compute Prefix sum: customer that will not come in open hours:
        vector<int> open(n, 0);
        open[0] = (customers[0] == 'N') ? 1 : 0;
        for(int i = 1; i < n; i++) {
            open[i] = (customers[i] == 'N') ? open[i - 1] + 1 : open[i - 1];
        }

        // Compute Suffix: customer that will come in closed hours:
        vector<int> closed(n, 0);
        closed[n-1] = (customers[n-1] == 'Y')  ?  1 : 0;
        for(int i = n - 2; i >= 0; i--) {
            closed[i] = (customers[i] == 'Y') ? closed[i + 1] + 1 : closed[i + 1];
        }


        // Now Calculate the Early Hour:
        int earlyHour = n;  // at worse we will close at nth hour
        int minPenalty = INT_MAX;

        for(int j = 0; j <= n; j++) {
            int penalty = 0;
            // Calculate Open Hours penalty (left side):
            if(j > 0) {
                penalty += open[j - 1];
            }

            // Calculate Closed Hour penalty (right side):
            if(j < n) {
                penalty += closed[j];
            }

            // Calculate the minimum penalty:
            if(penalty < minPenalty) {
                minPenalty = penalty;
                earlyHour = j;
            }
        }

        return earlyHour;
    }
};


// BruteForce Solution:
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int earlyHour = n;  // at worse we will close at nth hour
        int minPenalty = INT_MAX;

        for(int j = 0; j <= n; j++) {
            int penalty = 0;
            // Calculate Open Hours penalty (left side):
            for(int i = j - 1; i >= 0; i--) {
                // Count how many customer not come at open hours:
                if(customers[i] == 'N') penalty++;
            }

            // Calculate Closed Hour penalty (right side):
            for(int i = j; i < n; i++) {
                if(customers[i] == 'Y') penalty++;
            }

            // Calculate the minimum penalty:
            if(penalty < minPenalty) {
                minPenalty = penalty;
                earlyHour = j;
            }
        }

        return earlyHour;
    }
};


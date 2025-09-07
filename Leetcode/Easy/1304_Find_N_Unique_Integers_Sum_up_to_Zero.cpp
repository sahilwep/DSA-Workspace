/*

//  1304. Find N Unique Integers Sum up to Zero


//  Problem Statement: 
    -> Given an integer n, return any array containing n unique integers such that they add up to 0.

 
// Example:
    Example 1:
        Input: n = 5
        Output: [-7,-1,1,3,4]
        Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

    Example 2:
        Input: n = 3
        Output: [-1,0,1]

    Example 3:
        Input: n = 1
        Output: [0]


// Observations: 
    -> n = 6    -> Even
        n / 2   => (3 sets of -ve) & (3 sets of +ve) numbers

        {-3, -2, -1, 1, 2, 3}

    -> n = 7    -> Odd
        n / 2    => (3 sets of -ve number), (0), (3 sets of +ve) number
        
            {-3, -2, -1, 0, 1, 2, 3}

            => All we required is one extra '0'
        
    // Complexity: 
        -> TC: O(n / 2)
        -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> sumZero(int n) {
        
        if(n == 1) return {0};

        vector<int> ans;
        int half = n / 2;

        for(int i = 1; i <= half; i++) {
            ans.push_back(i);
            ans.push_back(i * -1);
        }
        
        if(n % 2 != 0) ans.push_back(0);
        
        return ans;
    }
};
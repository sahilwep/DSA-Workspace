/*

//  1431. Kids With the Greatest Number of Candies

//  Observations: 
    * There are n kids candies, and we are given integer array candies, where each candies[i] represent the number of candies the ith kid has.
    * and integer extraCandies denoting the number of extra candies we have..
    * Return boolean array result true if the ith kid is given all the extraCandies that we have..

// Example:

    Input: candies = [2,3,5,1,3], extraCandies = 3
    Output: [true,true,true,false,true] 
    Explanation: If you give all extraCandies to:
    - Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
    - Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
    - Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
    - Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
    - Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.


    Input: candies = [4,2,1,1,2], extraCandies = 1
    Output: [true,false,false,false,false] 
    Explanation: There is only 1 extra candy.
    Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.


    Input: candies = [12,1,12], extraCandies = 10
    Output: [true,false,true]

// Intrusion:
    * first we will get the maximum value among all the array.
    * Then we will add given candies to every value & compare the sum up with maxFinding value, if it grater or equal then return true, else return false.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = -1;
        int n = candies.size();
        for(int i=0;i<n;i++){
            if(candies[i] > max){
                max = candies[i];
            }
        }

        vector<bool> res(n);
        for(int i=0;i<n;i++){
            int val = candies[i] + extraCandies;
            if(val >= max){
                res[i] = 1;
            }else{
                res[i] = 0;
            }
        }

        return res;
    }
};
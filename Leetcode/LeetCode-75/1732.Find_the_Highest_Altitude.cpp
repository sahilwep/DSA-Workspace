/*

//  1732. Find the Highest Altitude


//  Observations: 
    * A rider is riding bike on mountain, & initially he starts at the altitude of 0, Now, he is going on hills, so he is traveling on different different altitude.
    * We are given an array that consist of altitude.
    * We need to find the maximum altitude on which the rider went.

// Intrusion: 
    * We can iterate throughout the array & find the prefix sum, also at every iteration we will store the max value by comparing it with all the previous max values.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxh = 0;
        int sum = maxh;
        for(int i=0;i<gain.size();i++){
            sum += gain[i];
            maxh = max(sum, maxh);
        }

        return maxh;
    }
};
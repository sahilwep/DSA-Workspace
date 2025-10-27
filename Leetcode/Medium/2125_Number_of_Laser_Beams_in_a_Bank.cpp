/*

//  2125. Number of Laser Beams in a Bank


//  Problem Statement: 
    -> Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.
    -> There is one laser beam between any two security devices if both conditions are met:
        -> The two devices are located on two different rows: r1 and r2, where r1 < r2.
        -> For each row i where r1 < i < r2, there are no security devices in the ith row.
    -> Laser beams are independent, i.e., one beam does not interfere nor join with another.
    -> Return the total number of laser beams in the bank.

 
// Example: 
    Example 1:

        Input: bank = ["011001","000000","010100","001000"]
        Output: 8
        Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
        * bank[0][1] -- bank[2][1]
        * bank[0][1] -- bank[2][3]
        * bank[0][2] -- bank[2][1]
        * bank[0][2] -- bank[2][3]
        * bank[0][5] -- bank[2][1]
        * bank[0][5] -- bank[2][3]
        * bank[2][1] -- bank[3][2]
        * bank[2][3] -- bank[3][2]
        Note that there is no beam between any device on the 0th row with any on the 3rd row.
        This is because the 2nd row contains security devices, which breaks the second condition.

    Example 2:

        Input: bank = ["000","111","000"]
        Output: 0
        Explanation: There does not exist two devices located on two different rows.

// Observations: 
    - we need to find the total number of laser beams in given grid.
    
    // Approach: 
        - for every row, count the devices
        - store in some other device list.
        - start iteration from 1 till device.size()
        - compute beam at every level & last sums up..

        // Complexity: 
            -> TC: O(n * m)
            -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();

        vector<int> devices(n, 0);
        for(int i = 0; i < n; i++) {
            int dCnt = 0;
            for(int j = 0; j < m; j++) {
                if(bank[i][j] == '1') {
                    dCnt++;
                }
            }
            if(dCnt > 0) {
                devices.push_back(dCnt);
            }
        }
        
        // Compute answer from devices:
        int k = devices.size();
        int totalBeam = 0;
        for(int i = 1; i < k; i++) { 
            totalBeam += devices[i-1] * devices[i];
        }

        return totalBeam;
    }
};
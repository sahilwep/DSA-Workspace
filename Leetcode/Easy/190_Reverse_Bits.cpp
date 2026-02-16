/*

//  190. Reverse Bits


//  Problem Statement:
    - Reverse bits of a given 32 bits signed integer.

 
// Example:
    Example 1:

        Input: n = 43261596
        Output: 964176192

        Explanation:

            Integer	    Binary
            43261596	00000010100101000001111010011100
            964176192	00111001011110000010100101000000


    Example 2:
        Input: n = 2147483644
        Output: 1073741822
        Explanation:
        
            Integer	    Binary
            2147483644	01111111111111111111111111111100
            1073741822	00111111111111111111111111111110



// Observations:
    - We are given integer
    - we need to reverse their binary bits.
    - Example:
            n = 10      => 5

                Integer Binary 
                10      1010
                5       0101


    // BruteForce Approach:
        - we can convert the decimal to binary string & reverse it & then convert it back to decimal.
        - This take huge complexity, as (1 <= n <= 2^31-2)
            

    // Better Approach:
        - For any number we can get the last significant bit "lsb" by: (n & 1)

            n = 10
                        1 0 1 0
                        0 0 0 1 &
                    ---------------
                        0 0 0 0 => 0

            - using (n & 1) will gives us the lsb
                - because if last value is '1' it will give 1, else it will give 0, because we are doing & with '1'

        - Now we know that we can get the significant bit by (n & 1), we just have to build our answer with lsb.

                let say n = 10
                let say ans = '0'

                Initially:

                    n       1 0 1 0
                    ans     0 0 0 0
                    
                    1st time:

                        n       1 0 1 0
                                        lsb = (n & 1) = 0

                        Now we have to place this bit into our ans.

                        ans     0 0 0 0
                        lsb     0 0 0 0  OR
                            --------------
                                0 0 0 0 

                        n >>= 1, right sift by 1 so that last significant bit is removed
                        n = 0101

                    2nd time:

                        n       0 1 0 1
                                        lsb = (n & 1) = 1

                        Now we have to place this bit into our ans.

                        ans     0 0 0 0
                        lsb     0 0 0 1  OR
                            -------------
                                0 0 0 1
                        
                        n >>= 1
                        n = 0010

                    3rd time:
                        .. same process as above..

            - Now till when we will process this whole operations.
            - well, we will process only 32 bit.
                            

    // Complexity:
        - TC: O(1)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int reverseBits(int n) {
        
        if(n == 0) return 0;
        
        int res = 0;
        for(int i = 1; i <= 32; i++) {  // process 32 bits,      TC: O(32)
            res <<= 1;  // left shift res by 1 position, so that we can have last space to insert our lsb from 'n'.     O(1)

            int bit = n & 1;        // O(1)

            // Now we will have to place this into lsb of res.  O(1)
            res = res | bit;

            n >>= 1;    // remove the lsb from the 'n'      O(1)
        }

        return res;
    }
};
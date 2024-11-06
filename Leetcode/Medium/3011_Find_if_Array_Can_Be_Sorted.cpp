
/*

// 3011. Find if Array Can Be Sorted            


// Question Observations: 
    -> We can swap two numbers if they ave same number of set bits:
    -> We are allowed to do this Operations any number of times:

    // Example: 
        nums = [8,4,2,30,15]
            binary Representation: 

                8 = 1000
                4 = 100
                2 = 10
                30 = 11110
                15 = 1111
    
        
            8 4 2 30 15 -> numbers
            1 1 1 4  4  -> set bits

            We can swap those values which has same number of bits, & then compare if they were in sorte order or not?

    // Visualizations: 

        * One thing we are sure about if the values are having same bits we can swap & adjust their positions..
        * If we carefully observe, for a range, if bits are same, only minimum & maximum values are useful, else everyting in middle has no use...
        
        // Example: 

            nums = [8, 4, 2, 30, 15, 121, 247, 127]

                     |       |     |            => These are the ranges
                8 4 2| 30 15 | 121 | 247 127    => Values
                1 1 1| 4  4  |  5  | 7  7       => set bits

                // We can swap the values if they have same bits:

                    2 4 8 | 15 30 |  121  | 127 247 => Sorted order
                    1 1 1 | 4  4  |   5   | 7  7    => Bits

                // If we observe carefully, we only need starting & ending values of every range:

                    2 4 8 | 15 30 |  121  | 127 247
                    1 1 1 | 4  4  |   5   | 7  7
                    mi mx | mn mx | mn mx | mn max

                // And using those values (minimum & maximum) -> we can comapre every ranges

                         
                    2    8   | 15   30  |    121   |  127  247
                    min  max   min  max    min max    min  max
                         |______|   |_______|   |______|
                        
                    These values we have to compare => after sotring minimum & maximum values somewhere

                // Finally, we have to compare two adjecent values, & based on that we will return our answer.
                    while(i < arr.size()) -> if(arr[i] < arr[i-1]) return false:
                    else return true



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;    // Single element is already sorted, return true
        if(isSorted(nums)) return 1;    // Function that will check if given nums are already sorted or not?

        // Storing bits:
        vector<int> bits(n);
        for(int i=0;i<n;i++){
            bits[i] = __builtin_popcount(nums[i]);  // __builtin_popcount() -> function return number of set bits in O(1)
        }

        // Storing minimum & maximum value of every range:
        vector<int> range;
        int min = nums[0], max = nums[0]; 
        for(int i=1;i<n;i++){
            // When bits are matched: means when we are in a range where all values of same number of bits:
            if(bits[i] == bits[i-1]){
                // We need to get, minimum & maximum from that range:
                if(nums[i] < min){
                    min = nums[i];
                }
                if(nums[i] > max){
                    max = nums[i];
                }
            }
            // When we fall into another range: means when we encounter at some position where we have new bit range starts
            else{
                // first push minimum & maximum values into range vector
                range.push_back(min);
                range.push_back(max);

                // setting new maximum & minimum as our current nums[i]
                min = nums[i];
                max = nums[i];
            }
        }

        // At last pushing leftOver min & max values:
        range.push_back(min);
        range.push_back(max);
        
        // Final Check in range vector, if values are sorted or not?
        for(int i=1;i<range.size();i++){
            if(range[i] < range[i-1]) return 0;
        }

        return 1;    // return true, means it's can be sorted..
    }
    bool isSorted(vector<int> &nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1]) return 0;
        }
        return 1;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    Solution obj;
    (obj.canSortArray(nums)) ? cout << "True" : cout << "False";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}
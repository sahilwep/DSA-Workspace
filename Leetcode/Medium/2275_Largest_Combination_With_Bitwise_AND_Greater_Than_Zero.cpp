/* 

// 2275. Largest Combination With Bitwise AND Greater Than Zero

// Problem Statement:
    -> The bitwise AND of an array 'nums' is the bitwise AND of all integer in nums.
    -> For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
    -> Also, for nums = [7], the bitwise AND is 7.
    -> You are given an array of positive integers "candidate". Evaluate the bitwise AND of every combinations of number of candidates. Each number in "candidate"may be used once in each combinations.
    -> Return the size of the largest Combinations of "candidate" with a bitwise AND {{{{{grater than '0}}}}}'.
    -> NOTE: after computations our AND result if grater than 1, we will return the maximum value.
    

// Problem Visualization: 

        Input: candidates = [16,17,71,62,12,24,14]
        Output: 4


                    Binary Representation of every numbers:
                        16 -> 0 0 1 0 0 0 0
                        17 -> 0 0 1 0 0 0 1
                        71 -> 1 0 0 0 1 1 1
                        62 -> 0 1 1 1 1 1 0
                        12 -> 0 0 0 1 1 0 0
                        24 -> 0 0 1 1 0 0 0
                        14 -> 0 0 0 1 1 1 0     

                    Possible Combinations:

                            [16,17,62,24]

                            16 -> 0 0 1 0 0 0 0
                            17 -> 0 0 1 0 0 0 1
                            62 -> 0 1 1 1 1 1 0
                            24 -> 0 0 1 1 0 0 0  AND
                            ---------------------
                                  0 0 1 0 0 0 0  => 16  -> total 4 numbers that has same bits on certain index.
                    
                    One thing we can observe, at every index we have either '1' or '0', 
                    and the index that has all '1', will given '1' in AND operations.
                    and we are returning the count of that numbers.

                    Or We can say if we have all numbers & we are doing AND operations, the index on which we have maximum 1's, we will count that
                    and we will return that index values. because it has maximum set bits.
                    More Visualization:


                            16 -> 0 0 1 0 0 0 0
                            17 -> 0 0 1 0 0 0 1
                            71 -> 1 0 0 0 1 1 1
                            62 -> 0 1 1 1 1 1 0
                            12 -> 0 0 0 1 1 0 0
                            24 -> 0 0 1 1 0 0 0
                            14 -> 0 0 0 1 1 1 0     
                        ----------------------------
                                  1 1 3 4 4 3 1        ->  writing the count of set bits on every index.

                    
                    maximum count we have 4, so we will return 4, because there are 4 number that has set bits on same index.

                
                // Implementations Part:
                        1. Convert every numbers from decimal to binary(we will use size of 32-bits)
                            -> We can make a function that will return string of size 32, which represent binary number of any decimal number.
                        2. After that, we will store the count of set bits of that binary number in an array.
                        3. then we can simply count the higher frequency from the array, & return that frequency, because in total we have that much number which is making maximum result.
    
// Complexity:
    * TC: O(n)
        -> decToBinary() takes O(1), because it's runs only for 32 times
        -> computeRes() takes O(1), because it's runs only for 32 times
        -> largestCombination() takes O(n), iteration in nums.
    * AS: O(1)
        -> Size of vector 32, which will take constant size



*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // function to compute decimal to binary: O(1)
    string decToBinary(int n){
        string res = "";
        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1){
                res += '1';
            }else{
                res += '0';
            }
        }
        return res;
    }
    // Function that will store the frequency of every binary number set bits: O(1)
    void computeRes(vector<int> &res, string s){
        for(int i=0;i<32;i++){
            char ch = s[i];
            if(ch == '1'){
                res[i] += 1;
            }else{
                res[i] += 0;
            }
        }
    }
    int largestCombination(vector<int>& c) {    // takes: O(n)
        int n = c.size();
        
        vector<int> res(32);    // creating vector of 32 size to store frequency of set bits of every number at every index.
        for(int i=0;i<n;i++){
            string temp = decToBinary(c[i]);    // getting decimal to binary: O(1) 
            computeRes(res, temp);  // writing frequency
        }

        // Finally getting the maximum frequency from 'res' vector.
        int solu = INT_MIN;
        for(auto i: res){
            if(i > solu) solu = i;
        }

        return solu;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    Solution obj;
    cout << obj.largestCombination(nums) << endl;

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}
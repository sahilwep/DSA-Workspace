/*

//  1679. Max Number of K-Sum Pairs

//  Observations: 
    * We are given an array, & a integer k.
    * We need to find such pair, or two element from an array that is equal to k, & then count that pair, & also remove that pair form array, so that next time it will not be considered.


// Intrusion: 
    // Bruteforce Solutions:
        * We need to find such pair that can be sum up and equal to k.
        * Once we found & counted those pairs, we need to remove them from array so that next time they are not considered. 
            * One thing we can do is we will overwrite it with "-1", & use a condition that whenever we have "-1", we should not considered it..
            * We can use any value that is out of the constrains of arr[i], 
            * NOTE: We should explicitly use condition that whenever we saw (arr[i] == -1) we should not considered it, because it may effect the sum if we only overwrite the value & don't use this conditions..

        * TC: O(n^2) -> TLE

    // Sorting & Two-Pointer Approach :
        * We will sort the values in increasing order..
        * Once the values are sorted we will use two pointer:
            * first pointer at start, & second pointer at end..
            * if Pointer the value is equal to sum we increment the size & move first pointer forward, & second pointer backward.
            * if Pointer sum value is grater than the sum, we will move second pointer backward.
                * because the end pointer value is grater, & if we move it backward, the pointer sum will decreased, because array is sorted..
            * if Pointer sum value is lesser than the sum, we will move start pointer forward.
                * because the start pointer value is smaller, when we move it forward the sum will not increased significantly as it increase when we move end pointer backward.
        * NOTE: This logic only work when the values are sorted:
        * Example:
                    k = 10:  
                    nums = [3, 5, 4, 6, 2]   

                    sorted => [2, 3, 4, 5, 6]
                               |           |
                               S           E

                    while(S < E):
                        sum = nums[S] + nums[E] => 2 + 6 => 8
                        sum < K:
                            S++
                                            [2, 3, 4, 5, 6]
                                                |        |
                                                S        E

                        
                        sum = nums[S] = nums[E] => 3 + 6 => 9
                        sum < K:
                            S++

                                            [2, 3, 4, 5, 6]
                                                   |     |
                                                   S     E
                    
                        sum = nums[S] = nums[E] => 3 + 6 => 9
                        sum == k:
                            cnt++;
                            S++
                            E--

                                            [2, 3, 4, 5, 6]
                                                      ||
                                                      SE
                        Break -> cnt = 1
        
        * TC: O(nlogn)


    // Hashing Approach:
        * This problem is simillar like 2 sum, we have used hashing approach to find those two index which are needed for sum, but here we need to remove the values that are being evaluated.
        * We can use hashmap, & we will try to get the sum value needed from the hashmap & once we get that we will remove those values from the map.
        * Note: We can have duplicate values, so we need to take care of that, instead of removing the element itself, we will minimize the frequency..
        * Exapmle:
                nums = [2,2,2,3,1,1,4,1]
                cnt = 0
                k = 4

                i = 0
                    need = k - arr[i] = 4 - 2 => 2
                    Not in map:
                        Hash values in map[arr[i]]++ => mp{(2,1)}
                
                i = 1
                    need = k - arr[i] = 4 - 2 => 2
                    There in map:
                        cnt++ => 1
                        decrement frequency from map[need]-- => map{}

                i = 2
                    need = k - arr[i] = 4 - 2 => 2
                    Not in map:
                        Hash values in map[arr[i]]++ => mp{(2,1)}
                
                i = 3
                    need = k - arr[i] = 4 - 3 => 1
                    Not in map:
                        Hash values in map[arr[i]]++ => mp{(2,1), (3, 1)}
                
                i = 4
                    need = k - arr[i] = 4 - 1 => 3
                    There in map:
                        cnt++ => 2
                        decrement frequency from map[need]-- => mp{(2,1)}
                
                i = 5
                    need = k - arr[i] = 4 - 1 => 3
                    Not in map:
                        Hash values in map[arr[i]]++ => mp{(2,1), (1, 1)}
                
                i = 6
                    need = k - arr[i] = 4 - 4 => 0
                    Not in map:
                        Hash values in map[arr[i]]++ => mp{(2,1), (1, 1), (4, 1)}
                
                i = 7
                    need = k - arr[i] = 4 - 1 => 3
                    Not in map:
                        Hash values in map[arr[i]]++ => mp{(2,1), (1, 2), (4, 1)}
                

                        => cnt = 2

        * TC: O(n)


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


class Solution{
public:
    // BruteForce Solution:
    int maxOperations_M1(vector<int>& nums, int k) {
        int maxOpr = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == k && (nums[i] != -1 && nums[j] != -1)){
                    // When we find we can remove those value, as we don't want to change the size of vector, we can overwrite these values with some other values.
                    // nums[i] = INT_MIN;   // there is no need to make (nums[i] = INT_MIN), because this value will not considered again in future.
                    nums[j] = -1;   // making this value -1, so that it will not be considered in sum.
                    maxOpr++;   // increment the counter
                    break;
                    
                }
            }
        }

        return maxOpr;
    }

    // Using Sorting & two pointers: O(nlogn)
    int maxOperations_M2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // sorting all the values:

        int n = nums.size();
        
        int start = 0;
        int end = n-1;
        int cnt = 0;

        // When both pointer position are at same position, it will break out from the iterations.
        while(start < end){
            int sum = nums[start] + nums[end];  // getting sum with two pointers

            if(sum == k){
                cnt++;  // increasing counter
                start++;    // moving start pointer forward
                end--;  // moving end pointer backward
            }

            // If sum is grater, we will move end pointer, as it's effecting more on sum. 
            else if(sum > k){
                end--;  // moving end pointer backward
            }
            // when sum is lesser, we will increase start pointer as it effect lesser in compare to end pointer.
            else{
                start++;    // increasing start pointer forward
            }
        }

        return cnt;
    }

    // Using Hashing: O(n)
    int maxOperations(vector<int>& nums, int k){
        unordered_map<int, int> mp;

        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int need = k - nums[i];     // nums[i] is first element of pair, & need is second element of the pair.

            // When needed element is already present in map, we will increment the counter, and decrement the need count.
            if(mp[need] > 0){
                cnt++;
                mp[need]--; // minimizing the frequency if it has occurred multiple times, else if has occurred only once this will remove elements from map
            }
            // else when the element is not found, we will hash that element into map. => {(arr[i], 1)}
            else{
                mp[nums[i]]++;
            }
        }

        return cnt;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    int k;
    cin >> k;

    Solution obj;
    cout << obj.maxOperations(nums, k) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
/*

//  Subarrays with equal 1s and 0s

//  Observations: 
    * Given an array counting 0's & 1's, Find the number of subarray having equal numbers of 0s and 1s.


// Example: 

    Input:
        n = 7
        A[] = {1,0,0,1,0,1,1}
    Output: 8
    Explanation: The index range for the 8 
        sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
        (4, 5) ,(2, 5), (0, 5), (1, 6)

    Example 2:

    Input:
        n = 5
        A[] = {1,1,1,1,0}
    Output: 1
    Explanation: The index range for the subarray is (3,4).


// Intrusion: 
    // Bruteforce Approach: 
        * Iterate through all possible subarrays.
        * Count the number of 0s and 1s in each subarray.
        * If the count of 0s and 1s is equal, increment the counter.
        * TC: O(n^2)
    
    // Hashing Approach:
        *  Key Idea:
            * Replace each 0 in the array with -1. 
            * This transforms the problem into finding subarrays with a sum of 0.
        
        * In simple terms:
            * We need to count subarrays that have an equal number of 0s and 1s.
            * To do this, we can treat 0s as -1 and keep track of the cumulative sum of the array elements.
                * If the element is 0, we subtract 1 from the sum, and if it's 1, we add 1 to the sum. 
                * We then store this cumulative sum in a hashmap.
            * As we traverse the array, we check if the current cumulative sum has already been seen in the map.
                * If the sum has appeared before, it means the subarray between the previous occurrence and the current index has an equal number of 0s and 1s.
                * We increment the count by the frequency of that cumulative sum from the hashmap.

        * Let's understand with an example:

                0 0 1 0 1 0 1 1 0 0 1 1 1
                <-------------> 
                      X (If the sum is X here)         
                <--------------------->
                            X (If the sum is X again here)
                                <----->
                                    X (Then, this section is also X)

                                
                * As you traverse the array, the cumulative sum at different points can repeat.
                * For example, if you encounter the same cumulative sum X at different indices, it means the subarray between these indices has an equal number of 1s and 0s.
                * This is because the difference between two equal cumulative sums represents a subarray where the net effect is zero (i.e., an equal count of 1s and 0s).


                * Example Observations: 
                                    
                    Num:                  0    0   1   0   1   0   1   1   0   0   1   1   1

                    sum: 0(initially)    -1   -2  -1  -2  -1  -2  -1   0  -1  -2  -1   0   1
                    occurred                       *   *   *   *   *   *   *   *   *   *
                    Freq:                 1    1   2   2   3   3   4   2   5   4   6   3   1

                        * -> Explanation: Whenever we encounter the same cumulative sum again, we add its frequency to the counter and increment that frequency.

                        cnt = 1 + 1 + 2 + 2 + 3 + 1 + 4 + 3 + 5 + 2 => 24


                    * Here, whenever we encounter a cumulative sum that has previously occurred, we add the frequency of that sum to our total count because it indicates that there are that many subarrays found between the indices where that sum was recorded.

                    * Example: 

                        Num:                  0    0   1   0   1   0   1   1   0   0   1   1   1

                        sum: 0(initially)    -1   -2  -1  -2  -1
                        occurred                       *   *   *
                        Freq:                 1    1   2   2   $ Here when we encounter -1 again, 
                                * We have previous frequency 2, so in total we have new 2 subarray found,
                                * That is:
                                                        0    0   1   0   1   0   1   1   0   0   1   1   1
                                                                _____
                                                                     _____

        TC: O(n)
        AS: O(n)


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
    // Optimized approach using hashing to count subarrays with equal 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        // Map to store the frequency of cumulative sums.
        unordered_map<int, int> mp;
        // Initializing with mp[0] = 1 to handle cases where the subarray starts from index 0.
        mp[0] = 1;
        
        int sum = 0;  // Cumulative sum.
        long long cnt = 0;  // Counter for valid subarrays.

        for (int i = 0; i < n; i++) {
            // Replace 0 with -1.
            if (arr[i] == 0) sum--;
            else sum++;

            // If the cumulative sum has been seen before, increment the counter.
            if (mp.find(sum) != mp.end()) {
                cnt += mp[sum];  // Add the frequency of the current sum to the counter.
                mp[sum]++;  // Increment the frequency of the sum.
            } else {
                // If it's the first time encountering this sum, insert it into the map.
                mp[sum] = 1;
            }
        }

        return cnt;
    }

    // Bruteforce Solution:  
    long long int countSubarrWithEqualZeroAndOne_Brute(int arr[], int n){
        long long int cnt = 0;
        for(int i=0;i<n;i++){
            int Zcnt = 0;
            int Ocnt = 0;
            for(int j=i;j<n;j++){
                if(arr[j] == 1) Ocnt++;
                else if(arr[j] == 0) Zcnt++;
                
                if(Ocnt == Zcnt) cnt++;
            }
        }
        
        return cnt;
        
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
        int n,i;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++) cin>>arr[i];
        Solution obj;
        cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
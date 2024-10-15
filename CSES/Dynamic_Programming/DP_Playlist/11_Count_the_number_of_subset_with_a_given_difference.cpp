/*

// Count the number of subset with a given difference

// Problem Statement:
    * Given an array partition into two subsets(possibly empty) such that each element must belong to only one subset.
    * Let the sum of element of these two subsets be S1 and S2.
    * Given a difference d, count the number of partition in which S1 is grater than or equal to S2
    * and the difference b/w S1 & S2 is equal to d. Since the answer may be large return it modulo 10e9+7


// Example:

    Input:
    n = 4
    d = 3
    arr[] =  { 5, 2, 6, 4}
    Output: 1
    Explanation:
    There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

    Input:
    n = 4
    d = 0 
    arr[] = {1, 1, 1, 1} 
    Output: 6 
    Explanation:
    we can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in S1 and remaning two 1's in S2.
    Thus there are total 6 ways for partition the array arr. 


// Observations: 
    * We are given an array, & We are given the difference of their subset sum

                        [array items]
                        /           \
                   {subset1}       {subset2}
            sum:       S1              S2


              
            abs(s1 - s2) = diff(given)     -> s1 >= s2
 
            s1 = (diff + s2) -> we can get subset 1 sum value.


            s1 + s2 = range(sum of array)
            
            s2 = range - s1


            s1 = (diff + s2)
            s1 = diff + range - s1

            2*s1 = (diff + range)
            s1 = (diff + range) / 2

            So, we have got s1 value..



// Iterating from 0 to sum: in inner loop while building dp table.

    * As you build the DP table, you're calculating how many ways you can form subsets with each possible sum j, 
    * where j ranges from 0 to the target sum. This means you need to check every possible sum from 0 (smallest) to sum (the target).

    * If we only start from j = 1, we'd skip over the case where the subset sum is 0, 
    * which is necessary for correct propagation of the DP values. 
    * It ensures that the DP table is built correctly by considering the full range of possible subset sums.


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


// Function to count the number of subsets with a given difference
int countTheNumberOfSubsetWithGivenDifference(vector<int> &nums, int diff) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array

    // Edge cases:
    if (diff > totalSum) return 0; // If the difference is greater than the total sum, no subsets can form
    if ((diff + totalSum) % 2 != 0) return 0; // If (diff + totalSum) is odd, it can't be split into two equal integers

    // Find the target sum for one of the subsets (S1)
    int targetSum = (diff + totalSum) / 2;

    // Create a DP table to count subset sums
    vector<vector<long long int> > t(n + 1, vector<long long int>(targetSum + 1, 0)); // Initialize DP table of size (n+1) x (targetSum+1)

    // Initialize the t table:
    // If sum is 0, there's always one subset (the empty subset)
    for (int i = 0; i <= n; i++) {
        t[i][0] = 1;
    }

    // DP transition: 
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < targetSum + 1; j++) {
            // If the current element is smaller or equal to the current sum, include/exclude it
            if (nums[i - 1] <= j) {
                t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j] % mod;
            } 
            // If the current element is greater than the current sum, exclude it
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][targetSum] % mod; // Return the result modulo 10^9+7
}




void solve(){
    int n, diff;
    cin >> n >> diff;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];

    // Subset Sum: 
    cout << countTheNumberOfSubsetWithGivenDifference(nums, diff) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
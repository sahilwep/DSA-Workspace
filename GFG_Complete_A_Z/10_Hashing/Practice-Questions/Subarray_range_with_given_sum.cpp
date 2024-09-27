/*

//  Subarray range with given sum

//  Observations: 
    * We are given an array of size n, & we are given target, 
    * determine the subarray that element whose sum up to the target.


// Example:
    Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
    Output: 3
    Explanation: Subarray with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].


    Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
    Output: 1
    Explanation: Subarray with sum 33 is: [20,3,10].


// Intrusion: 
    // Bruteforce Solutions
        * Select each element one by one & try to find the subarray size, & once we get the sum we will increment the sum.
        * TC: O(n^2)

    
    // Hashing Approach:
        * IF same element occur again, that means we have '0's in b/w the subarray or the sum of subarray is 0...
        * According to the same observations if the value is just incremented by the sum, we would say that we get the sum.
        * Example:
            arr[] = 10 2 -2 -20 10
            tar = -10


            Edge case: mp[0] = 1


            prefix sum:     sum - tar       Found
               0,  1 ---------------BASE---------
               10, 1        (10 - 10)  =>    x
               12, 1        (12 - 10)  =>    x
               10, 2        (10 - 10)  =>    Y
               -10, 1       (10 - 10)  =>    Y
               0, 2         (0 - 10)   =>    Y


        * TC: O(n)
        * AS: O(n)



*/

#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_set>
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

class Solution {
public:
    // Hashing Approach: 
    int subArraySum(vector<int>& arr, int tar) {
        int sum = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        
        // Handel the case where a subarray starting from beginning matches the target:
        mp[0] = 1;

        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(mp.find(sum - tar) != mp.end()){
                // cout << sum << " " << sum - tar << " " << mp[sum - tar] << endl;
                cnt += mp[sum - tar];
            }
            mp[sum]++;
        }

        return cnt;
    }   

    // Bruteforce Approach: O(n^2)
    int subArraySum_Brute(vector<int>& arr, int tar) {
        int cnt = 0;

        for(int i=0;i<arr.size();i++){
            int sum = 0;
            for(int j=i;j<arr.size();j++){
                sum += arr[j];
                if(sum == tar){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
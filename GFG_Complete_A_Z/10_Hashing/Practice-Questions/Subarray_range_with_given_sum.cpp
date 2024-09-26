/*

//  Subarray range with given sum

//  Observations: 
    * We are given an array of size n, & we are given target, determine the subarray that element whose sum up to the target.


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

class Solution {
public:
    // Bruteforce Approach: O(n^2)
    int subArraySum(vector<int>& arr, int tar) {
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
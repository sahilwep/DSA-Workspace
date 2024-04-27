/*
//  1512. Number of Good Pairs            https://leetcode.com/problems/number-of-good-pairs/description/


// Efficient Solution: 
* For each key-value pair in the map, where the key is the unique integer and the value is its frequency:
* Calculate the value k, which represents the frequency of the current integer.
* Check if k is greater than 1, which means there are at least two occurrences of that integer in the input vector.
* If k is greater than 1, it implies that there are identical pairs of that integer.
* Calculate the number of identical pairs for the current integer using the formula ((k - 1) * k) / 2.
* This formula calculates the number of pairs that can be formed from n occurrences of the same integer. 
* It works because for each occurrence beyond the first (k-1 occurrences), it forms a pair with all the previous occurrences.
* Example: 
      Number     Frequency 
        3           2
        2           1
        1           3

    * Formula: 
        k = mp.second() // means we want to compute the frequency
        ans = ans + ((k-1)*k)/2
        k = 2 -> ans = ((2-1)*2)/2 => 1, here number 2 comes two times...

 */ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a)

// Naive solution: O(n^2)
int numIdenticalPairs_(vector<int>& nums) {
    int n = nums.size();
    int pair=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i] == nums[j]){
                pair++;
            }
        }
    }
    return pair;
}

// Efficient Solution: O(n)
int numIdenticalPairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++)  mp[nums[i]]++;
    int ans = 0;

    // for(auto i : mp) cout << i.first << " " << i.second << endl; // for debugging..

    for(auto i : mp){
        int k = i.second;
        if(k > 1){
            ans = ans + ((k-1)*k) / 2;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        nums[i] = k;
    }
    cout << numIdenticalPairs(nums) << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}
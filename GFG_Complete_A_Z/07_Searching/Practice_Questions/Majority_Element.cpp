/*

//  Majority Element

//  Observations: 
    * We are given an array, find the majority element if it's exist, else return -1.


// Intrusion:
    // Bruteforce Approach:
        * selecting each element again and again & iterating throughout the array, & try to find if it's exist more than n/2 times or not?
        * TC: O(n^2)    -> TLE
        * AS: O(1)

    // Sorting: 
        * We can sort the values of array:
        * If there is any majority it will definitely fall at (n/2 + 1) position.
        * Then we can count that (n/2 + 1) position element, if it's grater than n/2 we return that found element, else return -1
        * TC: O(nlogn)
        * AS: O(1)

    // Hashing Approach:
        * Hash each element frequency, if the frequency of any element is n/2 return that element, else return -1
        * TC: O(n)
        * AS: O(n)

    // Moore Voting Algorithm Approach:
        * First finding the most occurring candidate
        * Second counting the number of occurrence of candidate
        * Return if that candidate occur more than n/2 times, else return -1
        * TC: O(n)
        * AS: O(1)


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
    // BruteForce Solution: O(n^2) -> TLE
    int majorityElement_Brute(vector<int>& arr) {
        int n = arr.size();
        int res = -1;
        for(int i=0;i<arr.size();i++){
            int cnt = 1;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i] == arr[j]) cnt++;
            }
            if(cnt > n/2){
                res = arr[i];
            }
        }

        return res;
    }
    // Sorting: O(nlogn)
    int majorityElement_Sorting(vector<int>& arr) {
        // Edge case:
        if(arr.size() == 1){
            return arr[0];
        }

        int n = arr.size();
        sort(arr.begin(), arr.end());

        // Finding majority
        int maj = arr[n/2]; // getting the middle element
        // Now we are counting the middle element, if it's majority, it will be more than n/2, else return -1
        int cnt = 0;
        for(auto i: arr){
            if(i == maj) cnt++;
            if(cnt > n/2) return maj;
        }

        return -1;
    }
    // Hashing: O(n)
    int majorityElement_Hash(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(auto i: arr) mp[i]++;
        
        for(auto i: mp){
            if(i.second > n/2){
                return i.first;
            }
        }

        return -1;
    }
    // Moore Voting Algorithm: O(n)
    int majorityElement(vector<int>& arr) {
        // Step 1: finding the most occurring element:
        int n = arr.size();
        int cnt = 1;
        int x = 0;
        for(int i=1;i<n;i++){
            if(arr[i] == arr[x]){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt == 0){
                x = i;
                cnt = 1;
            }
        }

        // Step 2: Count the element of occurrence:
        cnt = 0;
        for(auto i: arr){
            if(i == arr[x]){
                cnt++;
            }
            if(cnt > n/2){
                return arr[x];
            }
        }

        return -1;
    }
};

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}
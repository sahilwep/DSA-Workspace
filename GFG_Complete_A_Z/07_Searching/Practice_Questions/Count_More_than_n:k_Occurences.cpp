/*
//  Count More than n/k Occurences

// Observations:
    * We are given an array arr of size n, & element k, we have to find the count of element in the array that appear more than n/k times.

// Example: 
    Input:
        N = 8
        arr = [3,1,2,2,1,2,3,3]
        k = 4
    Output: 2
    Explanation: 
    In the given array, 3 and 2 are the only elements that appears more than n/k times.

    Input:
        N = 4
        arr = [2,3,3,2]
        k = 3
    Output: 2
    Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.

// Intrusion: 
    * We can use hashing, & compare the frequency with n/k, if it's grater then we count & return the count.

*/

#include<bits/stdc++.h>
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

class Solution{
public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int cnt = 0;
        for(auto i : mp){
            if(i.second > (n/k)) cnt++;
        }

        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

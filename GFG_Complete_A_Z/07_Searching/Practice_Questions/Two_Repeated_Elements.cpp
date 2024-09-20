/*

//  Two Repeated Elements

//  Observations: 
    * we are given an array of size n+2, all elements of array are in the range 1 to n.
    * All element occur once except two elements occur twice.
    * We need to find those two element & return it.
    * NOTE: we need to maintain the order of occurrence also.

// Intrusion: 
    // Bruteforce: 
        * Select each element, & count the number of occurrence,
        * once we got the repeated element we will break out..  
        * TC: O(n^2)
        * AS: O(1)
    
    // Hashing: 
        * we will use hashing approach to find the number of element that occur twice..
        * Hash values int the hashmap, & specify the condition that when it's find that element again, it will store the element into the vector, 
        * At the end we can return that element.
        * TC: O(n)
        * AS: O(n)


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
    // Using Hashing: 
    vector<int> Func(int n, int arr[]) {
        n = n + 2;
        unordered_map<int, int> mp;
        vector<int> v;
        for(int i=0;i<n;i++){
            // If the values are already in the map, we will 
            if(mp.find(arr[i]) != mp.end()){
                v.push_back(arr[i]);
            }
            mp[arr[i]]++;
        }   

        return v;
    }
};

int main() {
    int t, n;
    cin >> t;

    while (t--){
        cin >> n;

        int arr[n + 2];

        for (int i = 0; i < n + 2; i++) cin >> arr[i];

        Solution obj;
        vector<int> res;
        res = obj.Func(n, arr);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}
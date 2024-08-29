/*
// Hashing in Unordered map : 
    
    Unordered map :
        Storing & fetching : -> O(1) in avg & best case. 

        Storing & fetching : -> O(N) in worst case.

    * worst case, will happen once in a blue moon...

// NOTE : first preference is Unordered map, because if we look
    * Most of the time we need to do Unordered map, if it's failed, 
    * or giving us TLE(Time limit exceed), Then we can use map.
    * because worst case relay happens...
    * Worst case happen : because of internal collision.

// Concept : 
    * Whatever hash they using internally, we cannot say what they are using 
        * it can be :
            * division method -> linear chaining.
            * Folding method
            * mod Square method
        * Suppose if the hashing algorithm, using division method, & hash the values with
        * chaining : (arr[i] % 10) for large numbers.
        * Whatever hash they are using, all your keys, end up at the same hash index, then there will be the chance of collision.

NOTE : In map, any DS can be a key, but in Unordered-map key can be limited to int, float....

*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        unordered_map <int, int> mpp;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            // precomputation : 
            mpp[arr[i]]++;
        }
        // print the hash unordered-map :
        for(auto it : mpp) cout << it.first << "->" << it.second << endl;

        // fetching : 
        int times;
        cin >> times;
        while(times--){
            int num;
            cin >> num;
            cout << mpp[num] << endl;
        }
    }
    return 0;
}
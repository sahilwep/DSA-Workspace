/*

//  605. Can Place Flowers

//  Observations: 
    * We are given longbed of flowerbed where some plot are planted, and some are not.
    * We have an array consisting the plots where plants are plotted.
        * 0 denotes empty plot, whereas 1 denotes plot with plant.
    * We are also given integer n, denoting the plant need to be plotted.
    * We need to check whether given array is satisfied to plant n extra plant, 
    * Condition each flower adjacent plot should be empty, means (0 1 0) -> 1 flower with both neighbour value is 0


//  Intrusion:
    * Simple Observations, for flower need to be planed, we need adjacent empty plot..
    * So, whenever we 3 consecutive have empty plot, we can plant one flower..


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    /*
        Simple Observations, for flower need to be planed, we need adjacent empty plot..
        So, whenever we 3 consecutive have empty plot, we can plant one flower..
    */
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(n == 0) return 1;

        int cnt = 1;
        for(int i=0;i<f.size();i++){
            
            if(f[i] == 0) cnt++;    // where there is 0, we will increment the counter
            else cnt = 0;           // whenever we encounter with 1, means flower, we will make counter = 0
            
            // When counter become 3, we can plant 1 flower.
            if(cnt == 3){
                n--;         // planting one flower:
                cnt = 1;    // making cnt as 1, means we have one empty space after planting...
            }

            // Edge case:
            /*
                Case when we are at last position, & we have already counter = 2
                [0, 0, 1] -> this is the case, we can plant 1 flower at starting index, so increment counter.
            */
            else if(cnt == 2 && i == f.size()-1){
                n--;
            }

            // when n == 0, means there is no flower left to plant, we return 1 -> all flower planted successfully.
            if(n == 0) return 1;
        }

        // After iterating throughout the array, it might be possible few of the flower are left to plant.
        if(n == 0) return 1;
        else return 0;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int k;
    cin >> k;

    Solution obj;
    cout << obj.canPlaceFlowers(v, k) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
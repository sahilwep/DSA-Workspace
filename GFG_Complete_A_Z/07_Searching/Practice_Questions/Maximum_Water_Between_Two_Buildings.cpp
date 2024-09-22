/*

//  Maximum Water Between Two Buildings

//  Observations: 
    * We are given an array representing the height of N building, 
    * the task is to delete N-2 building such that water can be trapped between the remaining two building is maximum.
    * NOTE: The total water trapped b/w two building is the gap between them(number of building remove) multiplied by the height of smaller building.


// Example:

    Input:
        N = 6
        height[] = {2,1,3,4,6,5}
    Output: 8
    Explanation: The heights are 2 1 3 4 6 5. So we choose the following buildings
    2,5  and remove others. Now gap between two buildings is equal to 4, and the
    height of smaller one is 2. So answer is 2 * gap = 2*4 = 8. There is no answer greater than this.

    Input:
        N = 2
        height[] = {2,1}
    Output: 0
    Explanation: The heights are 2 1. But there is no other buildings to be removed so total removed= 0.  
    Now the height of smaller one is 1. So answer is 1 * removed buildings = 1*0 = 0.



// Intrusion:
    // Bruteforce Solution: -> TLE
        * we will select every building one by one & try to find the maximum water b/w two buildings.
        * TC: O(n^2)

    
    


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{
public:
    // Bruteforce Solution: O(n^2) -> TLE
    int maxWater(int arr[], int n){
        int maxCap = 0;
        for(int i=0;i<n;i++){
            int currCap = 0;
            for(int j=i+1;j<n;j++){
                int minVal = min(arr[i], arr[j]);
                int gap = j - i - 1;
                currCap = minVal * gap;
                maxCap = max(currCap, maxCap);
            }
        }

        return maxCap;
    } 
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)  cin>>height[i];
        Solution ob;
        cout<<(ob.maxWater(height, n))<<endl;
    }
}
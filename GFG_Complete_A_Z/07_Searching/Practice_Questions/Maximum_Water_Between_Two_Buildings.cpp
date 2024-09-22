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

    // Using Two pointer Approach:
        * Take two pointer i and j pointing to the first & the last building respectively and calculate the water that can be stored between these two buildings.
        * Now increment i if(height[i] < height[j]), else decrement j. This is because the water that can be trapped is depended on the
        * height of small building and moving from the greater height building will just reduce the amount of water instead of maximizing it.
        * In the end, print the maximum amount of water calculated so far.

        * Example:
            arr [] = 2 1 3 4 6 5    -> n = 6
            maxWater = 0

                while(i < j):

                    i = 0, j = 5
                        (2 < 5):
                            maxWater = max((j-i-1) * height[i], maxWater)
                            maxWater = max(4*2, 0) = 8
                            i++

                    i = 1, j = 5
                        (1 < 5):
                            maxWater = max((j-i-1) * height[i], maxWater)
                            maxWater = max(3*1, 8) = 8
                            i++

                    i = 2, j = 5
                        (3 < 5):
                            maxWater = max((j-i-1) * height[i], maxWater)
                            maxWater = max(2 * 3, 8) = 8
                            i++

                    i = 3, j = 5
                        (4 < 5):
                            maxWater = max((j-i-1) * height[i], maxWater)
                            maxWater = max(1 * 4, 8) = 8
                            i++

                    i = 4, j = 5
                        (6 > 5):
                            maxWater = max((j-i-1) * height[i], maxWater)
                            maxWater = max(0 * 5, 8) = 8
                            j--;
                    
                    -> Break out from loop:
                            maxWater = 8 so far.


        * TC: O(n)
        * AS: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{
public:
    // Two-Pointers Approach: O(n)
    int maxWater(int height[], int n){
        int i = 0;  // starting index
        int j = n-1;    // ending index
        
        int maxCap = 0;

        // While water can be stored b/w the currently choosen building.
        while(i < j){
            
            // if height[i] is lesser than the height[j] we will increment i.
            if(height[i] < height[j]){
                // getting the distance b/w these two given building & multiply it with smaller number.
                int currCap = (j-i-1) * height[i];
                // storing the maximum water capacity so far:
                maxCap = max(maxCap, currCap);
                i++;    // increment i
            }
            // when height[i] is greater or equal to height [j], we will decrement the j
            else{
                // getting the distance b/w these two given building & multiply it with smaller number if there, otherwise if it's equal we will multiply with it.
                int currCap = (j-i-1) * height[j];
                // storing the maximum water capacity so far:
                maxCap = max(maxCap, currCap);
                j--;    // decrement i
            }
        }

        return maxCap;
    }

    // Bruteforce Solution: O(n^2) -> TLE
    int maxWater_brute(int arr[], int n){
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
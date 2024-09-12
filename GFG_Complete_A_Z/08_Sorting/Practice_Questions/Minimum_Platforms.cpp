/*

// Minimum Platforms


// Observations: 
    * We are given departure & arrival time of all the train that reaches to stations.
    * We need to find the minimum number of platform required to that station so that no train is waiting on station.
    * Consider all train arrive on same day & leave on same day.
    * arrival & departure can never be the same for train but arrival of one train can be equal to departure of other train.
    * At any instance same platform can not be used for both arrival & departure of train.
    * NOTE: Time interval in (HHMM), where first two character represent hour 24 hour format, (0-23) & third, fourth represent minute, from (0-59)


// Example: 
    Input:  arr[] = [0900, 0940, 0950, 1100, 1500, 1800], 
            dep[] = [0910, 1200, 1120, 1130, 1900, 2000]
    Output: 3
    Explanation: There are three trains during the time 0940 to 1200. So we need minimum 3 platforms.
    // Example Observations: 
        arr[] = [0900, 0940, 0950, 1100, 1500, 1800]
        dep[] = [0910, 1120, 1130, 1200, 1900, 2000]



    Input:  arr[] = [0900, 1235, 1100]
            dep[] = [1000, 1240, 1200]
    Output: 1
    Explanation: All train times are mutually exlusive. So we need only one platform
    // Example Observations: 
        arr[] = [0900, 1100, 1235]
        dep[] = [1000, 1200, 1240]


    Input:  arr[] = [1000, 0935, 1100]
            dep[] = [1200, 1240, 1130]
    Output: 3
    Explanation: All 3 trains have to be their from 11:00 to 11:30
    // Example Observations: 
        arr[] = [0935, 1000, 1100]
        dep[] = [1130, 1200, 1240]

    * In conclusion, we can say that there should be one platform which we needed atleast,
    * Once, we sort them all the array, we can compare the departure of first train & arrival of second train..
        * if arrival is lesser than the departure, means we need one extra platform, means we can increase counter. 

// Intrusion: 
    // Using two pointer method: 
        * Start by pointing both pointer on starting of arrival & departure array.
        * if current arrival time is less or equal to current departure time, it means new platform is needed.
            * so we have to increment the platform needed, & arrival pointer.
        * If current arrival time is grater than the current departure time. 
            * it means train is left, freeing the platform.
            * So we need to decrement the platform need & increment the departure pointer.
        * The maximum value will be stored in result, because we need atleast 1 platform.
        * TC: O(nlogn)


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

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Sorting both the times: departure & arrival
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        // Comparing the arrival & departure:
        int platformNeed = 0;
        int result = 1;         // we atleast need 1 platform.
        int i = 0, j = 0;
        int n = arr.size();
        
        // Iterate from both the array:
        while(i < n && j < n){
            // if arrival time of current time is less than or equal to departure time of current train
            // we need extra platform
            if(arr[i] <= dep[j]){
                platformNeed++;     // increment the platform
                i++;    // increment the arrival time pointer
            }
            // if arrival time of current train is grater than departure of current train time:
            // we will have one free platform
            else if(arr[i] > dep[j]){
                platformNeed--;      // decrement the platform
                j++;    // increment the departure time pointer
            }
            result = max(platformNeed, result); // at last we store the maximum needed platform at every iterations.
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;
    }
    return 0;
}


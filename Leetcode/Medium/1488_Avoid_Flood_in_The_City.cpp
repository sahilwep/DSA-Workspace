/*

//  1488. Avoid Flood in The City


//  Problem Statement: 
    -> Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake that is full of water, there will be a flood. Your goal is to avoid floods in any lake.
    -> Given an integer array rains where:
        -> rains[i] > 0 means there will be rains over the rains[i] lake.
        -> rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
    -> Return an array ans where:
        -> ans.length == rains.length
        -> ans[i] == -1 if rains[i] > 0.
        -> ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
    -> If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.
    -> Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes.

 
// Example:

    Example 1:
        Input: rains = [1,2,3,4]
        Output: [-1,-1,-1,-1]
        Explanation: After the first day full lakes are [1]
        After the second day full lakes are [1,2]
        After the third day full lakes are [1,2,3]
        After the fourth day full lakes are [1,2,3,4]
        There's no day to dry any lake and there is no flood in any lake.

    Example 2:
        Input: rains = [1,2,0,0,2,1]
        Output: [-1,-1,2,1,-1,-1]
        Explanation: After the first day full lakes are [1]
        After the second day full lakes are [1,2]
        After the third day, we dry lake 2. Full lakes are [1]
        After the fourth day, we dry lake 1. There is no full lakes.
        After the fifth day, full lakes are [2].
        After the sixth day, full lakes are [1,2].
        It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another acceptable scenario.

    Example 3:
        Input: rains = [1,2,0,1,2]
        Output: []
        Explanation: After the second day, full lakes are  [1,2]. We have to dry one lake in the third day.
        After that, it will rain over lakes [1,2]. It's easy to prove that no matter which lake you choose to dry in the 3rd day, the other one will flood.


// Observations:
    - we are given a list of rains happens on lakes where rain happens on the lake at rains[i] day.
    - we are given rains[i], which represent rain on ith lake
    - We need to build an answer:
        - rains[i] > 0 => ans[i] = -1
        - ans[i] is the lake we choose to dry in ith day, if rains[i] = 0
        - If it's impossible to avoid flood => return {} empty list.

    // Approach 1: Hashmap + Binary Search:
        - Store first day of rain for every lake into map.
        - If same lake has rain again => Find the nearest right side of day on which we can dry that lake.
        - We can use map to store the rain happen on lake at i'th day for the first time
        - we can set to find the first nearest day on which we can dry lake if rain happens on the same lake again.


    // Complexity:
        -> TC: O(n * logn)
        -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        unordered_map<int, int> mp; // store the first day on which we have rain
        set<int> st;                // store Dry days in sorted fashion
        vector<int> ans(n, 1);      // answer list, 1, because this will be our smallest lake to fill if we have multiple Dry days..

        for(int i = 0; i < n; i++) {    // TC: O(n * logn)
            int lake = rains[i];

            if(lake == 0) {
                st.insert(i);       // store Dry day into set.
            } else {
                ans[i] = -1;        // we can fill our answer as -1 on "rains[i] > 0"

                // Check if this lake already contains water:
                if(mp.count(lake)) {

                    // Check If we can dry this lake:
                    auto it = st.lower_bound(mp[lake]); // get the first day on which we can free after rain happens in this same lake.     => TC: O(log(n))
                    if(it == st.end()) {    // not found -> can't dry
                        return {};  // flood happened
                    }

                    // Day on which we rains happen, we can empty this lake...
                    int firstDryDay = *it;
                    ans[firstDryDay] = lake;    // we can empty this lake on that Dry day

                    st.erase(it);   // clear this dry day from set, as it used..
                }

                // Last hash the first day on rain happens on lake:
                mp[lake] = i;
            }
        }

        return ans;
    }
};

/*

//  2138. Divide a String Into Groups of Size k


//  Problem Statement: 
    -> A string s can be partitioned into groups of size k using the following procedure:
        -> The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
        -> For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
    -> Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.
    -> Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.

 
// Example: 

    Example 1:
        Input: s = "abcdefghi", k = 3, fill = "x"
        Output: ["abc","def","ghi"]
        Explanation:
        The first 3 characters "abc" form the first group.
        The next 3 characters "def" form the second group.
        The last 3 characters "ghi" form the third group.
        Since all groups can be completely filled by characters from the string, we do not need to use fill.
        Thus, the groups formed are "abc", "def", and "ghi".

    Example 2:
        Input: s = "abcdefghij", k = 3, fill = "x"
        Output: ["abc","def","ghi","jxx"]
        Explanation:
        Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
        For the last group, we can only use the character 'j' from the string. To complete this group, we add 'x' twice.
        Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".

// Observation: 
    -> Implement the given statement: 
    

// Complexity: 
    -> TC: O(n)
    -> SC: O(n)
        -> AS: O(k)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        // Edge case: If group size is grater than the given string.
        if(k > n) {
            string ans = s;
            int times = k - n;
            for(int i = 0; i < times; i++) {
                ans += fill;
            }
            return {ans};   // return vector of string
        }


        vector<string> ans;
        int i = 0;
        while(i < n) {
            string temp = "";
            int j = 0;
            int idx = i;
            while(j < k && idx < n) {   // include k character, & make sure to check the outbound index
                temp += s[idx++];
                j++;
            }

            ans.push_back(temp);
            i += k;
        }

        // if we have uneven k given to form groups:
        if(n % k != 0) {
            string temp = ans.back();
            int times = k - (n % k);
            for(int i = 0; i < times; i++) {
                temp += fill;
            }
            
            ans.pop_back();
            ans.push_back(temp);
        }

        return ans;
    }
};
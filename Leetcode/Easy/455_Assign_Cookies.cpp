/*

//  455. Assign Cookies


//  Problem Statement: 
    - Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
    - Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

 
// Example:

    Example 1:
        Input: g = [1,2,3], s = [1,1]
        Output: 1
        Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
        And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
        You need to output 1.

    Example 2:
        Input: g = [1,2], s = [1,2,3]
        Output: 2
        Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
        You have 3 cookies and their sizes are big enough to gratify all of the children, 
        You need to output 2.

 

// Constraints:
    1 <= g.length <= 3 * 1e4
    0 <= s.length <= 3 * 1e4
    1 <= g[i], s[j] <= 2^31 - 1



// Observations:
    - each child get almost one cookie
    - each child i is a greed factor g[i], which is the minimum size of cookie that the child will be content with;
    - each cooke j has size s[j], if s[j] >= g[i], we can assign the cooke j to the child i, and the child i will be content.
    - your goal is to maximize the number of content child and output the maximum number.

    // Example 1:
        i/p:
            g = [1, 2, 3]
            s = [1, 1]
        o/p: 1

            3 child, and 2 cookie.
            greed factor of 3 childrens are 1, 2, 3
            and even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content
            you need to output 1.

        i/p: 
            g = [1, 2]
            s = [1, 2, 3]
        o/p: 2
                2 children:
                greed factor of 2 children are 1, 2
                you have 3 cooke and their size are big enough to gratify all the children.
                you need to output 2.

        // Approach:
            - we need to assign the cookie to the children.
            - our goal is to maximize the children count.
            - first we sort the given list
            - and then check the valid conditions:
            - and find total number of children we can assign..

            // complexity:
                - TC: O(n * logn + n) => O(n * logn)
                - SC: O(n)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int i = 0, j = 0;
        while(i < n && j < m) {
            // We will have to explore cookie size:
            if(s[j] >= g[i]) {
                i++;
                j++;
            } else { // cookie size is smaller, move forward
                j++; 
            }
        }

        return i;
    }
};

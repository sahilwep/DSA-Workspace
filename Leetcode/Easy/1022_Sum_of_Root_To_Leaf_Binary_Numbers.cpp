/*

// 1022. Sum of Root To Leaf Binary Numbers



// Problem Statement: 
    - You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.
        - For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
    - For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
    - The test cases are generated so that the answer fits in a 32-bits integer.


// Example:

    Example 1:
        Input: root = [1,0,1,0,1,0,1]
        Output: 22
        Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

    Example 2:
        Input: root = [0]
        Output: 0



// Observations:
    - given root of binary tree
    - we need to find all the possible path & from them we need to sums up the path forming binary string.

    // Approach:
        - first find all the path & store in some vector, we can use dfs for that.
        - then add them up by binary addition of binary number
        - last convert it back to the decimal number.

    // Complexity:
        - TC: O(n)
        - SC: O(n)
        

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<string> path;
    void dfs(TreeNode* root, string& s) {
        if(root == NULL) return;

        s.push_back(char((root->val) + '0'));   // insert value from string s.
        
        // Explore:
        if(root->left == NULL && root->right == NULL)  path.push_back(s);   // NOTE: we can't store the path when root == null, because the path will be store twice, once for left & one for right, so we store the path only when left & right both are null, this way we only store the path only once.
        else {
            dfs(root->left, s);
            dfs(root->right, s);
        }

        s.pop_back();
        
    }
    string sumOfTwoBinary(string& s1, string& s2) {
        
        string res = "";
        
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {
            
            int sum = carry;
            if(i >= 0) sum += s1[i] - '0';
            if(j >= 0) sum += s2[j] - '0';

            i--;
            j--;

            res += (sum % 2) + '0';     // store the right most bit
            carry = sum / 2;            // store the left most bit
        }

        reverse(begin(res), end(res));

        return res;
    }
    int toDecimal(string s) {
        int n = s.size();
        
        int res = 0;
        int k = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                res += pow(2, n - i - 1);
            }
        }

        return res;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        
        // Get all the path:
        string s = "";
        dfs(root, s);

        // Sums Up all the found binary string path:
        string res = "";
        for(auto &val: path) {
            res = sumOfTwoBinary(val, res);
        }
        int sum = toDecimal(res);
        
        return sum;
    }
};
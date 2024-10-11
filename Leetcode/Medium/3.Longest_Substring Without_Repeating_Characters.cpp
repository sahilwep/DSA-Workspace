/*

//  3. Longest Substring Without Repeating Characters 

//  Observations: 
    * We are given a string, find the longest substring without repeating character.
    * A substring is a contiguous non-empty sequence of characters within a string.


// Example:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.


    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.


    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.




// Intrusion: 
    // Bruteforce Solution:
        * Use nested loop to find the subarray without repeating characters.
        * Iterate in outer loop string: Select element one by one
            * create a temp string that will store the subarray with unique elements only.
            * using custom function that will check whether the string contains that character or not?
            * If the function return, then only iterate further, else break..
            * In every iteration check the maximum size of string.
        * TC: O(n^2) -> Accepted
        * AS: O(1)


    
    // Using Unordered_set:
        * We need a substring with unique characters, so an unordered_set is ideal. 
        * This data structure provides average O(1) time complexity for insertions and lookups (find operations).
            * We'll apply a two-pointer (sliding window) approach to maintain a window of unique characters:
                * Left pointer (left) starts at 0.
                * Right pointer (right) iterates through the string (from 0 to n).
            * As we iterate through the string:
                1. If the character `s[right]` is not in the set:
                    * Insert `s[right]` into the set.
                    * Calculate the current window size as `(right - left + 1)` and update the maximum length if needed.
                2. If `s[right]` is already in the set (i.e., a duplicate is found):
                    * Start removing elements from the set, beginning from `s[left]`, until the duplicate character is removed.
                    * Move the left pointer forward to shrink the window and maintain only unique characters.
                
            Explanation of Key Methods:
            - `set.count()`: Similar to `set.find()`, this checks if the element exists in the set. It returns 1 if the element is found, and 0 otherwise.
            
        * TC: O(n)
        * AS: O(min(n, m)) -> n is string & m is characters ASCII(128/256)



    // Using Unordered_map:
        * Approach:
            * We can solve this problem using a sliding window technique and an unordered set.
            * The unordered set will help us keep track of the characters in the current window (substring) and ensure all characters are unique.
            * We use two pointers (`left` and `right`) to define the boundaries of the window, and we adjust these pointers based on the presence of duplicate characters.

        * Steps:
            1. Initialize the `left` pointer at the start of the string and iterate `right` through the string.
            2. If `s[right]` (current character) is not in the set, insert it into the set and update the maximum window size (`maxLength`).
            3. If `s[right]` is already in the set, remove characters from the set starting from `s[left]` and move the `left` pointer to the right until the duplicate character is removed from the set.
            4. After the duplicate is removed, insert `s[right]` into the set to maintain a window of unique characters.
            5. Continue this process until the end of the string is reached, and return the maximum length of the substring without repeating characters.
        
        * TC: O(n)
        * AS: O(min(n, m)) -> n is string & m is characters ASCII(128/256)



    // Using Auxilary array:
        * Approach:
            * This problem is solved using a sliding window technique with an auxiliary array to track the last seen index of each character.
            * Instead of using a map or hash map, we use a fixed-size array (since we know the total number of possible characters is limited, typically 128 for ASCII).
            * The array allows for constant-time lookups to check if a character has been seen before and update its position.

        * Steps:
            1. Initialize the `left` pointer at the start of the string and iterate through the string using the `right` pointer.
            2. Create an auxiliary array `v` of size 128 (for ASCII characters) initialized to `-1`. This will store the most recent index of each character in the string.
            3. For each character `s[right]`, check if it has been visited before (i.e., `v[s[right]]` is greater than or equal to `left`). If it has, update `left` to `v[s[right]] + 1` to move past the duplicate and ensure the current substring is unique.
            4. Update the auxiliary array `v` with the current index of the character `s[right]`.
            5. Calculate the length of the current window (`right - left + 1`) and update `maxLength` if the window is the largest seen so far.
            6. Continue this process until the entire string is processed.

        * TC: O(n)
        * AS: O(1)



    // Using Deque:
        * Using deque to find the size of longest subarray without duplicate:
        * We will keep iterating in string & try to find that character is present in deque or not?
        * if it's present in deque, we will remove element from deque until we will not remove that element.
        * if element in not present in deque, we will insert it into deque.
        * Example:
                Initially:
                    s = p w w k e w
                    deque:      -> insert[] -> exit
                        i = 0
                                []
                                p w w k e w
                                |
                                not in deque, insert it 
                        i = 1   
                                [p]
                                p w w k e w
                                  |
                                not in deque, inset it
                        i = 2   
                                [w p]
                                p w w k e w
                                    |
                                inside deque, remove till p
                                        []
                                    insert w inside queue
                                        [w]
                        i = 3
                                [w]
                                p w w k e w
                                      |
                                not in deque, insert it
                                    
                        i = 4
                                [k w]
                                p w w k e w
                                        |
                                not in deque, insert it
                                    
                        i = 5
                                [e k w]
                                p w w k e w
                                          |
                                inside deque, remove till w
                                        []
                                    insert w in queue
                                        [w]
                        
                        * At max we will have deque of size 3 thought the iterations..

        * TC: O(n)
        * AS: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_set>
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
    // Bruteforce Solution:
    // function to check if there is any duplicate character in string or not?
    bool isThere(string s, char ch){
        for(auto i: s){
            if(i == ch) return 0;   // if character is in the string return false
        }

        return 1;   // if character is not in string return true
    }
    int lengthOfLongestSubstring_Brute(string s) {
        int n = s.size();

        int len = 0;
        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=i;j<n;j++){
                if(isThere(temp, s[j])){
                    temp += s[j];
                    int size = temp.size();
                    len = max(size, len);
                }else{
                    break;  // if character is not unique break the loop
                }
            }
        }

        return len;
    }

    // Using Unordered Set:
    int lengthOfLongestSubstring_Set(string s) {    
        int n = s.size();
    
        // Unordered set to store characters in the current window.
        unordered_set<char> st;

        int left = 0;    // Left pointer for the sliding window.
        int maxLength = 0; // To store the length of the longest substring without repeating characters.

        // Iterate through the string using the right pointer.
        for (int right = 0; right < n; right++) {
            // If the character is not in the set, add it to the set and update the maximum length.
            if (st.count(s[right]) == 0) {
                st.insert(s[right]);
                maxLength = std::max(maxLength, right - left + 1);  // Calculate the window size.
            } 
            else {
                // If the character is already in the set, we need to remove elements from the set until the duplicate is removed.
                while (st.count(s[right])) {
                    st.erase(s[left]);  // Remove the character at s[left] from the set.
                    left++;  // Move the left pointer forward.
                }
                // After the duplicate is removed, insert the current character (s[right]) into the set.
                st.insert(s[right]);
            }
        }

        return maxLength;
    }

    // Using map to store character & their corrsponding index:
    int lengthOfLongestSubstring_Map(string s){
        int n = s.size();
        
        // Hash map to store the characters and their latest indices in the string.
        unordered_map<char, int> mp;
        
        int left = 0;    // Left pointer to mark the start of the sliding window.
        int maxLength = 0; // Stores the maximum length of the substring without repeating characters.

        // Iterate through the string using the right pointer.
        for (int right = 0; right < n; right++) {
            // Check if the character at s[right] is already in the map and within the current window.
            /*
                The condition mp[s[right]] < left ensures that the character s[right] is not part of the current sliding window 
                Why mp[s[right]] < left?
                    mp[s[right]] gives the last index where s[right] was seen.
                    If mp[s[right]] < left, it means that the last occurrence of s[right] was outside the current window, i.e., before the left pointer.
                    Therefore, this character doesn't affect the current window, and we can safely include it in the current substring without needing to adjust the left pointer.
            */
            if (mp.count(s[right]) == 0 || mp[s[right]] < left) {
                // If it's not in the current window, add/update it in the map.
                mp[s[right]] = right;

                // Calculate the window size and update maxLength if it's the largest seen so far.
                maxLength = std::max(maxLength, right - left + 1);
            } 
            else {
                // If the character is already in the window, move the left pointer to avoid the duplicate.
                left = mp[s[right]] + 1;

                // Update the character's index to the current position.
                mp[s[right]] = right;
            }
        }

        return maxLength;
    }
    // Using Auxilary Array:
    int lengthOfLongestSubstring_Aux(string& s) {
        int n = s.size();  // Get the size of the input string
        
        int maxLength = 0;  // Store the length of the longest substring found
        int left = 0;       // Left pointer for the sliding window
        
        // Auxiliary array of size 128 (for ASCII characters) to store the last seen index of each character.
        // Initialize with -1 because -1 is an invalid index and signifies that the character hasn't been visited.
        vector<int> v(128, -1);

        // Iterate through the string with the right pointer
        for (int right = 0; right < n; ++right) {
            // If the current character has been seen before and is within the current window,
            // because if it's seen means, left is smaller & right is already there
            if (v[s[right]] >= left) {
                // Move the left pointer to one position after the previous occurrence of the current character
                left = v[s[right]] + 1;
            }

            // Update the auxiliary array with the current index of the character
            v[s[right]] = right;

            // Calculate the size of the current window and update maxLength if necessary
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    // Using deque:
    int lengthOfLongestSubstring(const std::string& s) {
        deque<char> dq;  // Deque to store the current window of characters
        int maxLength = 0;    // Variable to track the length of the longest substring

        // Iterate through the characters in the string
        for (char c : s) {
            // Find the current character in the deque
            auto it = find(dq.begin(), dq.end(), c);

            // If the character is not in the deque (i.e., no repetition in the current window)
            if (it == dq.end()) {
                dq.push_back(c);  // Add the character to the deque
                maxLength = max(maxLength, (int)dq.size());  // Update maxLength
            } 
            else {
                // If the character is already in the deque, remove all characters before it
                // until we remove the repeating character itself.
                while (dq.front() != c) {
                    dq.pop_front();  // Remove characters from the front
                }
                dq.pop_front();  // Remove the current repeating character itself
                dq.push_back(c);  // Push the current character back to the deque
            }
        }

        return maxLength;  // Return the maximum length of the substring without repeating characters
    }
};

void solve(){
    string s;
    cin >> s;

    Solution obj;
    cout << obj.lengthOfLongestSubstring(s) << endl; 
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
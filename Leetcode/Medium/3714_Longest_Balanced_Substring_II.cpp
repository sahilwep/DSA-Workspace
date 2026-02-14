/*

//  3714. Longest Balanced Substring II



//  Problem Statement: 
    - You are given a string s consisting only of the characters 'a', 'b', and 'c'.
    - A of s is called balanced if all distinct characters in the substring appear the same number of times.
    - Return the length of the longest balanced substring of s.

 
// Example:
    Example 1:
        Input: s = "abbac"
        Output: 4
        Explanation: The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

    Example 2:
        Input: s = "aabcc"
        Output: 3
        Explanation: The longest balanced substring is "abc" because all distinct characters 'a', 'b' and 'c' each appear exactly 1 time.

    Example 3:
        Input: s = "aba"
        Output: 2
        Explanation: One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".


// Observations:
    - We are given string s
    - string s consist of only 3 characters 'a', 'b' & 'c'
    - we need to find the longest balanced string.
        - a string is said to balanced if all the distinct characters in the string appears the same number of times.

    // BruteForce Solution:
        - Try finding all the substring.
        - For every substring: 
            - try finding the balanced conditions.
            - as we are limited with only 3 characters, we can use use counter for every characters.
            - Then we can check if they appears same number of times.

    // Key Observations:
        - If we have any character let say 'a' the longest substring, among all the others substrings, then we can say it's balanced.
            - example:
                    "cabaaaaac"     => "aaaaa" is longest balanced substring.
        
        - If we have any two characters forming the longest balanced substring, then also we can say it's balanced.
            - example:
                    "abcaaaababbbbc"    => "aaaababbbb" is the longest balanced substring.

        - If we have all three characters appearing with maimum number of times, then we will also consider that case..



        // Efficient Approach:
            - From the above observations we can say we have 3 cases:
            - Case 1: we can have largest in with single characters
                - We can find the longest occurring characters from the string in O(n) times.
                - it's just we have to find the longest repeating characters from the string.

            - Case 2: we can have largest with two characters:
                - Possible cases: "ab", "bc", "ac"
                - a, b: we can fetch the largest length by storing the difference.
                - a, c: we can fetch the largest length by storing the difference.
                - b, c: we can fetch the largest length by storing the difference.
                
                - let say we have a & b, for which we are finding:

                    - We need counter for a & b
                        aCnt = 0
                        bCnt = 0

                    - Now we have to iterate:
                        s = "a a b b a a c b b"
                             |

                        we will iterate and count aCnt & bCnt
                        and when we have aCnt == bCnt:
                            we will store the length by: 
                                length = aCnt + bCnt

                            s = "a a b b a a c b b"
                                       |

                                       aCnt = 2
                                       bCnt = 2
                                            length = aCnt + bCnt = 4

                        Whenever we have 'c'
            
                            s = "a a b b a a c b b"
                                             |

                                Reset aCnt & bCnt = 0, so that we can start for another possible substring counting.

                                
                    - Another Example: still we are finding a & b

                            s = "b b a b a c"   => longest = "b a b a" from idx 1 to 4
                            But with previous observation we will never store the longest answer.

                             s = "b b a b a c" 
                                  |             aCnt = 0, bCnt = 1

                             s = "b b a b a c" 
                                    |           aCnt = 0, bCnt = 2

                             s = "b b a b a c" 
                                      |         aCnt = 1, bCnt = 2

                             s = "b b a b a c" 
                                        |       aCnt = 1, bCnt = 3

                             s = "b b a b a c" 
                                          |     aCnt = 2, bCnt = 3

                             s = "b b a b a c" 
                                            |  aCnt = 2, bCnt = 3

                            We never get the longest, 
                                - because aCnt & bCnt never equal at same time, 
                                - but still we have longest exist.
                                - because it's start from index '1'
                            
                                        s = "b [b a b a] c"         
                                                |     |     our substring is from this range.
                                                1     2


                                // If we Observe carefully: 
                                    The difference b/w aCnt & bCnt is same with these range:

                                             P1        P2       => points
                                            "[b] b a b [a] c"
                                              |         |
                                        aCnt-bCnt  ==  aCnt-bCnt  

                                    If diff of aCnt & bCnt at P1 is -1, then diff of aCnt & bCnt at P2 is also -1

                                        If we are saying:

                                            aCnt - bCnt = -1

                                            at index 0:
                                                aCnt = 0
                                                bCnt = 1
                                                    aCnt - bCnt = 0 - 1 = -1

                                            at index 4:
                                                aCnt = 2
                                                bCnt = 3
                                                    aCnt - bCnt = 2 - 3 = -1

                                            So, if we add some x value to aCnt & y value to bCnt on index '0'.
                                            and their difference is same for some another index 'k'
                                            then x == y, 
                                                because we just add some value x value on aCnt & some y value on bCnt.
                                                    and both x & y is same number of value.
                                                    x == y

                                        // Mathematically Proven:
                                            
                                            We are saying: at index 4:
                                                aCnt = 0 + x
                                                bCnt = 1 + y

                                                    aCnt - bCnt = -1
                                                    0 + x - 1 - y = -1
                                                    0 + x - y = - 1 + 1
                                                    x -y = 0
                                                    {x = y}

                                            In layman terms:
                                                if diff b/w two value is 'r'
                                                doesn't matter, if we add some value to both the value.
                                                the diff will be still same..
                                    

                            // Solution:
                                - we can store the difference of aCnt & bCnt and their index.
                                - so that if anytime, the difference is same we get to know the starting point of our subarray, with same frequency.
                                - We can use something like map:
                                    <diff, index>
                                - we will store their diff into map, and anytime if difference is already found then we can know the starting point.
                                - Example:

                                     s = "b b a b a c"
                                          |                 
                                                aCnt = 0, bCnt = 1
                                                diff = aCnt - bCnt = -1
                                                mp[diff] = 0th index
                                                mp{-1: 0}
                                    
                                     s = "b b a b a c"
                                            |                 
                                                aCnt = 0, bCnt = 2
                                                mp[diff] = -2
                                                mp{
                                                    -1: 0,
                                                    -2: 1,
                                                }
                                    
                                     s = "b b a b a c"
                                              |                 
                                                aCnt = 1, bCnt = 2
                                                mp[diff] = -1

                                                    => here we can found the mp.count(diff)
                                                        mp[diff] = 0
                                                            "b [b a] b a c"
                                                             0  1 2 3 4 5

                                                             length = i - mp[diff]
                                                             length = 2 - 0 => 2
                                                             we have substring with same frequency with size '2'

                                                mp{
                                                    -1: 0,
                                                    -2: 1,
                                                }
                                    

                                     s = "b b a b a c"
                                                |                 
                                                aCnt = 1, bCnt = 3
                                                mp[diff] = -2

                                                    => here we can found the mp.count(diff)
                                                        mp[diff] = 1
                                                            "b b [a b] a c"
                                                             0 1  2 3 4 5

                                                             length = i - mp[diff]
                                                             length = 3 - 1 => 2
                                                             we have substring with same frequency with size '2'

                                                mp{
                                                    -1: 0,
                                                    -2: 1,
                                                }

                                     s = "b b a b a c"
                                                  |                 
                                                aCnt = 2, bCnt = 3
                                                mp[diff] = -1

                                                    => here we can found the mp.count(diff)
                                                        mp[diff] = 0
                                                            "b [b a b a] c"
                                                             0  1 2 3 4  5

                                                             length = i - mp[diff]
                                                             length = 4 - 0 => 4
                                                             we have substring with same frequency with size '4'

                                                mp{
                                                    -1: 0,
                                                    -2: 1,
                                                }

                                     s = "b b a b a c"
                                                    |   
                                                    
                                            We hit with 'c', so reset everything.
                                                aCnt = 0, bCnt = 0
                                                mp.clear()
                                                    NOTE: it's important to clear map for the next sequence of 'a' & 'b'
                                                    

            - Case 3: we can have largest with three characters:
                - Same as above, we will store the difference, value & fetch the largest length.

                - This time we will maintain aCnt, bCnt & cCnt

                    - When aCnt == bCnt && bCnt == cCnt
                            - Store: longest = max(longest, aCnt + bCnt + cCnt)

                - And also we will store the diff:

                        aCnt - bCnt = d1
                        aCnt - cCnt = d2

                        Now we will store in map by something like:
                                map<string, int> {d1_d2 = index}
                        - and process with same logic..
                      
                        
            // Complexity:
                - TC: O(n * logn)
                - SC: O(n)
                

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BruteForce Solution:
class Solution {
private:
    bool isValid(int aCnt, int bCnt, int cCnt) {
        // Case 1: If all equals:
        if(aCnt == bCnt && bCnt == cCnt) return true;
        
        // Case 2: if one characters count are 0
        if(aCnt == 0 && bCnt == cCnt) return true;
        if(bCnt == 0 && aCnt == cCnt) return true;
        if(cCnt == 0 && aCnt == bCnt) return true;

        // Case 3: if two characters counts are 0
        if(aCnt == 0 && bCnt == 0) return true;
        if(bCnt == 0 && cCnt == 0) return true;
        if(cCnt == 0 && aCnt == 0) return true;

        return false;
    }
public:
    int longestBalanced(string s) {
        int n = s.size();

        int longest = 0;
        for(int i = 0; i < n; i++) {
            int aCnt = 0, bCnt = 0, cCnt = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == 'a') aCnt++;
                else if(s[j] == 'b') bCnt++;
                else cCnt++;

                // Check Longest:
                if(isValid(aCnt, bCnt, cCnt)) {
                    longest = max(longest, j - i + 1);
                }
            }
        }

        return longest;
    }
};


// Efficient Solution:
class Solution {
private:
    int n;
    int largestWithOne(string &s) { // TC: O(n)

        int largest = 1;
        int cnt = 1;
        
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {  // if same substrings characters
                cnt++;  // increment the counter.
            } else {
                largest = max(largest, cnt);    // store maximum
                cnt = 1;    // reset the counter.
            }
        }
        largest = max(largest, cnt);

        return largest;
    }
    int largestWithTwo(string &s, char ch1, char ch2) { // TC: O(n)

        int largest = 0;

        // using map to store the difference.
        unordered_map<int, int> mp; // diff, idx
        int ch1Cnt = 0, ch2Cnt = 0;
        for(int i = 0; i < n; i++) {    // TC: O(n)
            if(s[i] != ch1 && s[i] != ch2) {    // we got third character
                mp.clear(); // clear map;
                ch1Cnt = 0;
                ch2Cnt = 0;
                continue;
            }

            // count the characters:
            if(s[i] == ch1) ch1Cnt++;
            else ch2Cnt++;

            // if we got same count for both the characters:
            if(ch1Cnt == ch2Cnt) {
                largest = max(largest, ch1Cnt + ch2Cnt);    // store the largest length, by adding their count.
            }

            // else find diff & try finding the largest one.
            int diff = ch1Cnt - ch2Cnt;     // get the difference:
            if(mp.count(diff)) {    // Check in map, if found store largest, else store the diff.
                largest = max(largest, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }

        return largest;
    }
    int largestAmongThree(string &s) {  // TC: O(n*logn)
    
        int largest = 0;
        int aCnt = 0, bCnt = 0, cCnt = 0;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {    // TC:O(n)
            if(s[i] == 'a') aCnt++;
            else if(s[i] == 'b') bCnt++;
            else cCnt++;

            // Check equal case:
            if(aCnt == bCnt && bCnt == cCnt) {
                largest = max(largest, aCnt + bCnt + cCnt);
            }

            // Check diff & store in map:
            string diff = to_string(aCnt - bCnt) + '_' + to_string(aCnt - cCnt);    // TC: O(logn) to convert any digit into string.
            if(mp.count(diff)) {
                largest = max(largest, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }

        return largest;
    }
public:
    int longestBalanced(string s) {
        n = s.size();

        int longest = 1;
        // Case 1: largest with single characters:
        longest = max(longest, largestWithOne(s));  // TC: O(n)

        // Case 2: largest with two characters: // TC: O(n)
        longest = max(longest, largestWithTwo(s, 'a', 'b'));
        longest = max(longest, largestWithTwo(s, 'a', 'c'));
        longest = max(longest, largestWithTwo(s, 'b', 'c'));

        // Case 3: largest with three characters: TC: O(n * logn)
        longest = max(longest, largestAmongThree(s));

        return longest;
    }
};
/*

//  2559. Count Vowel Strings in Ranges


// Problem Statement:
    -> You are given a 0-indexed array of strings words and a 2D array of integers queries.
    -> Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
    -> Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
    -> Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.


// Example:
    Example 1:
        Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
        Output: [2,3,0]
        Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
        The answer to the query [0,2] is 2 (strings "aba" and "ece").
        to query [1,4] is 3 (strings "ece", "aa", "e").
        to query [1,1] is 0.
        We return [2,3,0].

    Example 2:
        Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
        Output: [3,2,1]
        Explanation: Every string satisfies the conditions, so we return [3,2,1].



// BruteForce Solution:
    -> Process the vowel array:
    -> For every word, store weather they satisfies the condition or not?
    -> Check for every queries & count the number of vowels for the given queries range.
    // Complexity:
        -> TC: O(n * m)
        -> AS: O(m)


// Optimization:
    -> Somehow if we improve the query thing then we can have better time complexity.

        Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1],[3,4]]
        Output: [2,3,0,2]

                vow[] = {1, 1, 2, 3, 4}     -> Commutative Sum / Prefix Sum
                         0  1  2  3  4

                queries: [3, 4]
                    l = 3
                    r = 4

                    we know how may vowel till index '4' -> r
                    we also know how many vowel till index '3' -> l
                    if we subtract the number of vowel till index '2', i.e "l-1" from 'r', then we will know how many vowel contains till 3 to 4
            
            -> From this observations, First get the vowel count from 'r'
            -> Then we can get the vowel count just before 'l', i.e from 'l-1'
            -> And, we can subtract the part to get the vowel count.


    // Implementation Steps:
        1. Precompute `cumSum` for all words based on whether they start and end with vowels.
        2. Use `cumSum` to efficiently calculate results for each query.
    

    // Complexity: 
        -> TC: O(n)
        -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: 
class Solution {
private:
    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;; // return true for these characters
        return 0;   // else return false
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q = queries.size();
        int w = words.size();

        // Computing Commutative Sum:
        vector<int> cumSum(w);
        int sum = 0;
        for(int i=0;i<w;i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back())){
                sum++;
            }
            cumSum[i] = sum;
        }

        // Searching in query:
        vector<int> res(q);
        for(int i=0;i<q;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = cumSum[r] - ((l > 0) ? cumSum[l-1] : 0);
        }

        return res;
    }
};


// Bruteforce Solution:
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        // Process the Vowel array:
        int m = words.size();
        vector<int> vow(m, 0);;   // 1-> Vowel, 0-> not-Vowel
        vector<char> vowel = {'a','e','i','o','u'};
        for(int i=0;i<m;i++){
            string temp = words[i];
            bool start = false, end = false;
            for(auto it: vowel){
                if(temp[0] == it){
                    start = true;
                }
                if(temp[temp.size()-1] == it){
                    end = true;
                }
            }
            if(start && end){
                vow[i] = 1;
            }
        }

        // Check for every query:
        int n = queries.size();
        vector<int> res(n);

        for(int i=0;i<n;i++){
            int start = queries[i][0];
            int end = queries[i][1];

            int cnt = 0;
            for(int j=start;j<=end;j++){
                if(vow[j] == 1) cnt++;
            }

            res[i] = cnt;
        }

        return res;
    }
};
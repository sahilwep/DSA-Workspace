/*

//  2390. Removing Stars From a String 

//  Observations: 
    * We are given a string s that contains '*' stars
    * In one operations: 
        * choose a star in s
        * remove the closest non-star character to its left, as well as remove the star itself.
    * Return the string once all the star have been removed.



// Intrusion: 
    // Using Stack:
        * We will use stack to remove all the stars & closest left characters from the string..
        * We will iterate from 0 to s.siz():
            * in every iteration, we will push characters into stack.
            * If the element in stack is "*", pop() two element from stack, '*' & element before it.
        * This will remove all the '*' stars & closest left element form the string.
        * Now, characters are in stack, so we need to transfer it into string..
        * Note: we will have to reverse the string, as stack store element into LIFO order..
        * TC: O(n)
        * AS: O(n)


    // Using Counter & remove the * & closest left element
        * As we have to remove left element, we will start iterating from left to right, s[n-1] -> 0
        * whenever we will use encounter with "*", we will count that.
        * Whenever we will encounter with non-stars, we will check whether the starCounter has some value or not:
            * if they have some values we will decrement it, & do nothing.
            * if Counter is 0 or less than that, we will add that part of string into our result.
        * At the end we will reverse that string & return it.    
        * TC: O(n)
        * AS: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    // Using stack:
    string removeStars_Stack(string s) {
        stack<char> st; // using stack to perform all the actions..

        for(int i=0;i<s.size();i++){
            st.push(s[i]);  // push element into stack

            // whenever we encounter with '*', we need to remove two element * & element before it.
            if(st.top() == '*'){
                st.pop();   // removing *
                st.pop();   // removing adjecent left element.
            }

        }

        // if stack is empty means there is equal number of * as in comapre to characters..
        if(st.empty()){
            return "";
        }

        // Now moving charcters from stack to string.
        string res = "";
        while(!st.empty()){
            // res = st.top() + res;   // store string in reverse order.     -> This leads to memory limit exceeded.
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res; // return that string..
    }
    // Using Counter & remove the * & closest left element
    string removeStars(string s) {
        int n = s.size();
        int starCnt = 0;
        
        string res = "";
        for(int i=n-1;i>=0;i--){
            // Whenever we encounter with '*'
            if(s[i] == '*'){
                starCnt++;  // increment '*' star count.
            }

            // Whenever we encounter with non-star element:
            else{
                // if we have starCnt grater than 0, we will skip '*' stars & the element near to them.
                if(starCnt > 0){
                    // do nothing, just skip those characters:
                    starCnt--;
                }
                // when starCnt is less 0, means we need to insert those string[i] into our result.
                else{
                    res += s[i];
                }
            }
        }

        // Now at the end we will reverse the string:
        reverse(res.begin(), res.end());

        return res;
    }

};

void solve(){
    string s;
    cin >> s;

    Solution obj;
    string k = obj.removeStars(s);
    (k == "") ? cout << "Empty String" : cout << k;
    cout << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
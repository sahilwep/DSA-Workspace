/*

//  Removing consecutive duplicates


// Observations: 
    * We have to remove the consecutive duplicates form the string using stack.


// Example: 
    Input: aaaaaabaabccccccc
    Output: ababc

    Explanation: 
    The order is in the following way 6->a, 1->b, 2->a, 1->b, 7->c. 
    So, only one element from each group will remain and rest all are removed.
    Therefore, final string will be:- ababc.

// Example: 
    Input: abbccbcd
          
    Output: abcbcd

    Explanation: 
    The order is in the following way 1->a, 2->b, 2->c, 1->b, 1->c, 1->d.
    So, only one element from each group will remain and rest all are removed.
    Therefore, final string will be:- abcbcd. 

// Intrusion: 
    // Normal Comparing consecutive element: 
        * we can create an empty string "res" that stores s[0] character
        * Start iteration from (1 to s.size()-1), while iterating we will compare the consecutive elements..
        * If they are distinct to each other, we will store that character into string "res"
        * At end we return the string "res"


    // Using two pointer:
        * We will use two pointer approach: 
            * first pinter will use to iterate over the array
            * Second pointer will shift the pointer of unique elements.
        * Approach: 
            * when we have same element we increment first pointer..
            * when we have different element we will change the second pointer to first pointer locations, & store that element..
        
        * Example:
            Input: abbccbcd
                Initially:
                    p1 = 0, p2 = 0, res = "a"

                while(p1 < s.size())
                    p1 = 0, p2 = 0, res = "a" : same case hit
                            a     b     b     c     c     b     c     d
                          p1 p2


                    p1 = 1, p2 = 0, res = "a" : distinct case hit
                            a     b     b     c     c     b     c     d
                            p2    p1
                        p1 = 2, p2 = 1, res = "ab" : inside the distinct case we have change the values.


                    p1 = 2, p2 = 1, res = "ab"  : same case hit
                            a     b     b     c     c     b     c     d
                                  p2    p1


                    p1 = 3, p2 = 1, res = "ab"  : Distinct case hit
                            a     b     b     c     c     b     c     d
                                  p2          p1
                        p1 = 4, p2 = 3, res = "abc"  : inside the distinct case we have change the values.


                    p1 = 4, p2 = 3, res = "abc"  : same case hit
                            a     b     b     c     c     b     c     d
                                              p2    p1


                    p1 = 5, p2 = 3, res = "abc"  : Distinct case hit
                            a     b     b     c     c     b     c     d
                                              p2          p1
                        p1 = 6, p2 = 5, res = "abcb"  : inside the distinct case we have change the values.


                    p1 = 6, p2 = 5, res = "abcb"  : Distinct case hit
                            a     b     b     c     c     b     c     d
                                                          p2    p1
                        p1 = 7, p2 = 6, res = "abcbc"  : inside the distinct case we have change the values.


                    p1 = 6, p2 = 5, res = "abcb"  : Distinct case hit
                            a     b     b     c     c     b     c     d
                                                                p2    p1
                        p1 = 8, p2 = 7, res = "abcbcd"  : inside the distinct case we have change the values.

                We will break out as p1 is exceed s.size()

    // Using stack:
        * We can insert only unique elements to stack..
        * Using stack.top() we will compare the unique element..

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Using stacks:
    string removeConsecutiveDuplicates(string s){
        stack<char> stk;
        stk.push(s[0]); // inserting first element on stack..

        for(int i=1;i<s.size();i++){
            if(stk.top() != s[i]){
                stk.push(s[i]);
            }
        }
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }

    // Normal method:
    string removeConsecutiveDuplicates_NormalMethod(string s){
        string res = "";    // making empty string res
        res += s[0];    // assigning first character of original string.
        for(int i=1;i<s.size();i++){
            // comparing two consecutive element, if they are not same, we will store that character in result
            if(s[i] != s[i-1]){
                res += s[i];    // store it in string res
            }
        }
        return res; // returning string
    }

    // Two Pointer method:
    string removeConsecutiveDuplicates_UsingTwoPointer(string s){
        int ptr1 = 0;   // this pointer iterate over the string
        int ptr2 = 0;   // this pointer will store the unique element
        
        string res = "";    // string that will store result.
        res += s[0];    // storing the first element into the string res.

        // we will iterate first pointer till the size of string.
        while(ptr1 < s.size()){
            // if we have same element, increment the pointer..
            if(s[ptr1] == s[ptr2]){
                ptr1++; 
            }
            // else we will change the reference of second pointer to pointer 1, & increment the value.
            else{
                res += s[ptr1];
                ptr2 = ptr1;    // changing the reference o second pointer is important.
                ptr1++;
            }
        }
        return res;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}
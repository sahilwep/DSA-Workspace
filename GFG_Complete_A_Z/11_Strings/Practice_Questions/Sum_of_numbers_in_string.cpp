/*

// Sum of numbers in string


// Observations: 
    * We are given a string s, which we have some numbers given, we have to return the sum of it..

// Examples:

    Input:  str = 1abc23
    Output: 24
        Explanation: 1 and 23 are numbers in the
        string which is added to get the sum as
        24.

    Input:  str = geeks4geeks
    Output: 4
        Explanation: 4 is the only number, so the
        sum is 4.


// Intrusion:
    * we will iterate throughout the string, & find the contigious number..
    * If we got any contigious number we will sum up..


// TC: O(N)
    * Because, we are skipping the found number portions from the string..
    * In total we are iterating O(n) times.



*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int findSum(string s){

        int sum = 0;    // sum variable that will sum up the string numbers
        for(int i=0;i<s.size();i++){
            // if we get any numbers:
            if(s[i] >= 48 &&  s[i] <= 57){
                int ptr = i;    // making pointer to check the contigious numbers.
                // iterations from ptr to end, to find the contigious numbers
                for(int j=ptr;j<s.size();j++){
                    // if we get number, increment the ptr pointer
                    if(s[j] >= 48 && s[j] <= 57){
                        ptr++;
                        continue;   // skip rest of iterations..
                    }
                    // if we got any character, we break the iteration..
                    else  break;
                }

                // last we store the number that we got..
                string temp = "";
                // iterations start from current ith pointer to ptr pointer, so that we can get the portions of string that contains numbers.
                for(int j=i;j<=ptr;j++){
                    temp += s[j];   // storing the string portions into the string..
                }
                i = ptr;    // last making i to ptr, so that we can skip the number that we have got so far
                int num = stoi(temp);   // converting string numbers into int numbers
                sum += num;  // last sum up the numbers..

            }
        }

        return sum; // returning the sum
    }
};

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution obj;
        cout << obj.findSum(str);
        cout<<endl;
    }
    return 0;
}
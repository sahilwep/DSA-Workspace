/*
//  Stock span problem

Span Definition: The span of the stock's price on a given day is the maximum number of consecutive days (including the current day) the price has been less than or equal to the current day's price.

// Example: 
    Input: N = 7, price[] = [100 80 60 70 60 75 85]
    Output: 1 1 1 2 1 4 6
    
    Explanation:
        Traversing the given input span 
        100 is greater than equal to 100 and there are no more elements behind it so the span is 1,
        80 is greater than equal to 80 and smaller than 100 so the span is 1,
        60 is greater than equal to 60 and smaller than 80 so the span is 1,
        70 is greater than equal to 60,70 and smaller than 80 so the span is 2,
        60 is greater than equal to 60 and smaller than 70 so the span is 1,
        75 is greater than equal to 60,70,60,75 and smaller than 100 so the span is 4,
        85 is greater than equal to 80,60,70,60,75,85 and smaller than 100 so the span is 6. 
        Hence the output will be 1 1 1 2 1 4 6.

    Input: N = 6, price[] = [10 4 5 90 120 80]
    Output:1 1 2 4 5 1
    Explanation:
        Traversing the given input span 
        10 is greater than equal to 10 and there are no more elements behind it so the span is 1,
        4 is greater than equal to 4 and smaller than 10 so the span is 1,
        5 is greater than equal to 4,5 and smaller than 10 so the span is 2,
        90 is greater than equal to all previous elements so the span is 4,
        120 is greater than equal to all previous elements so the span is 5,
        80 is greater than equal to 80 and smaller than 120 so the span is 1,
        Hence the output will be 1 1 2 4 5 1.


// Observations:
    * If we observe carefully we need to print the span of stock price for all n days:
        * For every day we have given some values..
        * We need to check whether it has lesser than previous or not...
            * if it's smallest among all the previous once, we will print 1
        * If it's grater than previous values, we need to print how many values that are grater than the previous than the current value...


// Intrusion: 
    // Bruteforce: 
        * Simple implementation will take, O(n^2) complexity, we are using checking every number & their previously smallest element...

    // Efficient Solution:
        * We will use Stack data structure...
        * Traverse the Price Array:
            * For each day's price (let's call it price[i]):
                * Pop from Stack:
                    * While the stack is not empty and the price at the top index of the stack (price[st.top()]) is less than or equal to the current price (price[i]), pop the top element from the stack. This is because these prices are not useful for calculating the span as they are less than or equal to the current price.
                * Calculate Span:
                    * If the stack is empty after popping, it means there are no previous days with a higher price, so the span is the entire range from the first day to the current day, which is i + 1.
                    * If the stack is not empty, the span is the difference between the current day index i and the index at the top of the stack (st.top()), which represents the most recent day with a higher price. Thus, res[i] = i - st.top().
                * Push Current Index:
                    * Push the current index i onto the stack. This represents that the current day's price might be useful for calculating the span of future days.

        * In Simple words, we are using index of every element to observe whether the current element is grater than how many previous values..
        * at every iteration we are inserting the index of an array into stack.
        * also at every iterations, we will check if the current value is lesser than the previous stored index value from stack, if it's then we pop the element out until it become maximum..
        * at end we can compare if there is no element present in stack, the we store the currIndex + 1
        * else if there is still some element is left over in stack, then we can subtract current index to stack top element index, so that we can get the range...


*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    // Bruteforce Solution: 
        // function to check how many previous value are grater..
        int checkPrev(int price[], int start, int x){
            int cnt = 1;    // as we are given if there is no value, value itself will count, this is why 1
            // starting from start-1 to 0, because we have to count the element before it..
            for(int i=start-1;i>=0;i--){
                // if element is grater or equal to previous all the values...
                if(x >= price[i]){
                    cnt++;  // increment the counter...
                }else{
                    break;  // else break out from loop...
                }
            }
            return cnt;
        }
        //Function to calculate the span of stockâ€™s price for all n days.
        vector <int> calculateSpan_(int price[], int n){
            vector<int> res(n);
            int k = 0;
            for(int i=0;i<n;i++){
                    res[k++] = checkPrev(price, i, price[i]);   // for every value of i, we are checking their previous smallest element & count it, and store it into vector res..
                    // we are sending array, index of that value, & the value it'self
            }
            return res;
        }

        // Efficient Solution: 
        vector<int> calculateSpan(int price[], int n){
            vector<int> res(n);
            stack<int>  s;

            for(int i=0;i<n;i++){
                // when stack is not empty & price[s.top()] index element is less than the price[i] or current element..
                while(!s.empty() && price[s.top()] <= price[i]){
                    s.pop();    // pop it till we can get the max value in stack top()...
                }
                if(s.empty()){
                    res[i] = i+1;   // if all the values are removed from stack, means we have just encounter the max value which is grater than all the previous value...
                    // that's why we are storing the index itself, with +1, because it's 0 based index...
                }
                // if there is some values inside the stack
                else{
                    res[i] = i-s.top(); /// subtract it from i, so that we can get the number of values that are
                }
                s.push(i);      // at every iteration we will insert the index of the element or price[i];
            }
            return res; // at last we return the res...
        }

};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i,a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }

        Solution obj;
        vector <int> s = obj.calculateSpan(a, n);

        for(i=0;i<n;i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

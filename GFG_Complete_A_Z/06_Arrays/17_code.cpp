/*
// Stock buy and sell (Naive solution)
    * We assume that we known prices of upcoming n days.
    * We can buy the stock in any day & we can sell the stock in any day.

// Examples:

    Input: arr[] = {100, 180, 260, 310, 40, 535, 695}
    Output: 865
    Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210
                        Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655
                        Maximum Profit  = 210 + 655 = 865

    Input: arr[] = {4, 2, 2, 2, 4}
    Output: 2
    Explanation: Buy the stock on day 1 and sell it on day 4 => 4 – 2 = 2
                        Maximum Profit  = 2



    I/p arr[] = {1, 5, 3, 8, 12}
    O/p 13
        * explanation : buy at day 0 & sell at day 1: profit 4, then buy at day 2 & sell at day 4: profit 9 :=> total profit 13

    I/p arr[] = {30, 20, 10}
    O/p 0

    I/p arr[] = {10, 20, 30}
    O/p 20

    I/p arr[] = {1, 5, 3, 1, 2, 8}
    O/p 11

// Example:
    I/p : {1 5 3 8 12}
    O/p : 13

    1   5   3   8   12
    |               |
    Start           end

    i=0
    j=1 
        curr_profit = (5 - 1) + 
            max_profit(arr, 0, -1)
            max_profit(arr, 2, 4)
            = 4 + 0 + 9
            = 13

    i=0
    j=2 
        curr_profit = (3 - 1) + 
            max_profit(arr, 0, -1)
            max_profit(arr, 3, 4)
            = 2 + 0 + 4
            = 6, So this will not store in profit, because from previous computation we got max(profit, curr_profit)=13

    * TC : O(n^2)
    * AS : O(1)
*/

#include<bits/stdc++.h>
using namespace std;


// Naive Solution:
int maxProfit(int price[], int start, int end){
    if(end <= start) return 0;  // case when there is only one element or less than one element we return 0.
    int profit = 0;
    for(int i=start;i<end;i++){
        for(int j=i+1;j<=end;j++){
            if(price[j] > price[i]){
                int curr_profit = price[j] - price[i] +
                maxProfit(price, start, i-1) + 
                maxProfit(price, j+1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit; 
}

int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout <<  maxProfit(arr, 0, n);

    return 0;
}


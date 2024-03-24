/*
// Stock buy and sell (Efficient Solution)


    I/p arr[] = {1, 5, 3, 8, 12}
    O/p 13
        * explanation : buy at day 0 & sell at day 1: profit 4, then buy at day 2 & sell at day 4: profit 9 :=> total profit 13

    I/p arr[] = {30, 20, 10}
    O/p 0

    I/p arr[] = {10, 20, 30}
    O/p 20

    I/p arr[] = {1, 5, 3, 1, 2, 8}
    O/p 11


// The Solution is based on the fact, we know the prices of stock in advance.
    * When we will buy the stock:
        * When the prices is going down, we let them go down, & once it's reaches bottom, we buy the stock.
    * When we will sell the stock:
        * at every peak point we will sell the stock. 

// Implementation: 
    * We compare two adjacent elements: 
    * if current element is grater than the previous element, i.e: arr[i] > arr[i-1]
    * we computer the difference, & add them, at the end we will have our profit amount.
    
// Example:
        1 5 3 8 12

        profit = 0
    i = 1 : profit = 0 + (5-1) = 4
    i = 2 : 
    i = 3 : profit = 4 + (8 - 3) = 9
    i = 4 : profit = 9 + (12 - 8) = 13

// Complexity: 
    * TC : O(n)
    * AS : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int n){
    int profit = 0;
    for(int i=1;i<n;i++){
        if(price[i] > price[i-1]){
            profit = profit + (price[i] - price[i-1]);
        }
    }
    return profit;
}

int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << maxProfit(arr, n);

    return 0;
}

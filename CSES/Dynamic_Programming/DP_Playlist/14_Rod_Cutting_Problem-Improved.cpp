/*


// Rod Cutting Problem: Improved for better visualization -> recursion + Memoization + tabulation



//  Problem Statement:
    * We are given a rod or rodSize, & also we are given what's the price of each length of the rod in an array of size n.
    * We need to cut this rod in a way that we can maximize the profit.
    * We are allowed to cut a rod with same length..

        I/p:
            n = 8
            len[n] = {1, 2, 3, 4,  5,  6,  7,  8}
            price[] = {1, 5, 8, 9, 10, 17, 17, 20}
            RodSize = 8
        
        O/p: 22


        I/p:
            n = 4
            len[n] = {1, 2, 3, 4};
            price[n] = {2, 5, 7, 8};
            rodLength = 5;

        O/p: 12


// Observations: 

    * Example: But this Example let's understand the flow of recursive calls:

            n = 4
            len[n] = {1, 2, 3, 4};
            price[n] = {2, 5, 7, 8};
            rodLength = 20;


                    <----rodLength = 20---------->
                    |----------------------------|

     price[] /  len[n] = {1, 2, 3, 4};
                                   |
                                /-----\
                        (Include)     (Reject)      ->  We have Two Options
                            |            |
                     {1, 2, 3, 4}       ...      |-----rodLength = 16------|
                               |
                            /-----\
                     (include)   (reject)
                         |          |
                   {1, 2, 3, 4}    ...           |-----rodLength = 12------|
                             |
                        /--------\
                (include)     (reject)
                    |           |
              {1, 2, 3, 4}     ...               |-----rodLength = 18------|
                        |
                    /--------\
            (include)     (reject)
                |            |
              ....          ...

                                    -> NOTE: This will not fall for infinite recursive call, when (rodLength = 0 || n == 0) -> recursive calls stops.


        * By this example we can understand the fact that we have two options: 
            * Include / reject
            * When we include any item in our knapsack, the rodLength get's decreased, we can again reconsider that same item to include..
            * Now, when we reject any item:


                        <----rodLength = 20---------->
                        |----------------------------|


         price[] /  len[n] = {1, 2, 3, 4};                              |-----rodLength = 20------|
                                       |    
                                    /-----\
                            (Include)     (Reject)      ->  We have Two Options
                                |            |
                               ...      {1, 2, 3}                       |-----rodLength = 20------|
                                               |
                                            /------\
                                     (include)    (reject)
                                        |             |
                                       ...        {1, 2}                |-----rodLength = 20------|
                                                      |
                                                  /--------\
                                            (include)   (reject)
                                               |            |
                                              ...          ...

            * Rod length still the same, it's just the size of price[] & len[] is gets decreased
            * So, modifying in our unbounded knapsack code:

                -----------------
                // Base Case: when rodLength is become out of capacity, or all items are excluded.
                    if(rodLength == 0 || n == 0) return 0
                -----------------
                // decision Tree:

                    if(len[n-1] <= rodLength){
                        // two options: include / reject
                        return max(
                            // include case: only rod length decreased
                            price[n-1] + solve(len, price, n, (rodLength - len[n-1])), 
                            // reject case: item is excluded, rod length still the same
                            solve(len, price, n-1, rodLength)
                        );
                    }
                    else{
                        // reject
                        solve(len, price, n-1, rodLength)
                    }

                -----------------


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Recursive Solution
int rodCutting_rec(int len[], int price[], int n, int rodLength){
    // base case: when knapsack is full, means rodLength become 0, & all the items are rejected, means n = 0
    if(n == 0 || rodLength == 0) return 0;

    // if given length is less or equal to rod length:
    if(len[n-1] <= rodLength){
        // include(Not-Processed state) / reject(Processed state)
        return max(
            // Include case: only the rodLength will decreased
            price[n-1] + rodCutting_rec(len, price, n, (rodLength-len[n-1])),
            // Reject case: item size decreased, as we have excluded, but rodLength still the same.
            rodCutting_rec(len, price, n-1, rodLength)
        );
    }
    else{
        // reject the piece, but rodLength still same.
        return rodCutting_rec(len, price, n-1, rodLength);
    }
}





// Top-Down: memoization
int memo(int len[], int price[], int n, int rodLength, vector<vector<int> > &t){

    // base case: when knapsack is full, means rodLength become 0, & all the items are rejected, means n = 0
    if(n == 0 || rodLength == 0) return 0;

    // If same subproblem call's again:
    if(t[n][rodLength] != -1){
        return t[n][rodLength];
    }

    // if given length is less or equal to rod length:
    if(len[n-1] <= rodLength){
        // include(Not-Processed state) / reject(Processed state)
        return t[n][rodLength] =  max(
            // Include case: only the rodLength will decreased
            price[n-1] + memo(len, price, n, (rodLength-len[n-1]), t),
            // Reject case: item size decreased, as we have excluded, but rodLength still the same.
            memo(len, price, n-1, rodLength, t)
        );
    }
    else{
        // reject the piece, but rodLength still same.
        return t[n][rodLength] = memo(len, price, n-1, rodLength, t);
    }
}

int rodCutting_mem(int len[], int price[], int n, int rodLength){
    
    // Creating memo array:
    vector<vector<int> > t(n+1, vector<int> (rodLength+1, -1));

    return memo(len, price, n, rodLength, t);
}




// Bottom-up: Tabulation
int rodCutting_tab(int len[], int price[], int n, int rodLength){
    // Initialization:
    // create matrix with filling '0' -> this will handel all the base case when (n == 0 || rodLength == 0)
    vector<vector<int> > t(n+1, vector<int> (rodLength+1, 0));  

    // Start filling up matrix:
    // replace n -> i & rodLength -> j
    // iteration in item:
    for(int i=1;i<n+1;i++){
        // iteration in length:
        for(int j=1;j<rodLength+1;j++){
            // when item length[] is less or equal to given rodLength:
            if(len[i-1] <= j){
                // include(Not-Processed State) / reject(Processed State)
                t[i][j] = max(
                    // include: here item length will not decreased, only rodLength will decreased:
                    price[i-1] + t[i][j-len[i-1]],
                    // here item length will decreased, rodLength remains same, because we didn't include value in our knapsack.
                    t[i-1][j]
                );
            }
            else{
                // reject
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][rodLength];   // returning the result
}

void solve(){
    // size of both the array: len[] & rod[]
    int n;
    cin >> n;

    // input in both the array len[] & price
    int len[n];
    int price[n];
    for(int i=0;i<n;i++) cin >> len[i];
    for(int i=0;i<n;i++) cin >> price[i];
    
    // input of rod size:
    int rodLength;
    cin >> rodLength;


    // Calling Recursive Solution:
    cout << rodCutting_rec(len, price, n, rodLength) << endl;


    // Calling Top-Down:
    cout << rodCutting_mem(len, price, n, rodLength) << endl;



    // Calling Bottom-Up:
    cout << rodCutting_tab(len, price, n, rodLength) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
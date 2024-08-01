/*
//  Stock span problem


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



*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n){

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

#include <iostream>
using namespace std;

int main(void){

    int num;
    cin >> num;
    for(int i = 1; i<=num; i++){
        if(num%i==0){
            cout << i << " ";
        }
    }

    return 0;
}

/*
    Time complexity : O(n), because loop runs from 1 to n, & for condition, it is a unit step.
*/
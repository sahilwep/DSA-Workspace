// Print from n to 1, without using (i-1,n), by passing value (n,n)

#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    // base condition 
    if(i>=2*n) return;
    print(i+1,n);
    // printing the i in when base condition hit.
    cout << i-n+1 << " ";

}

int main(void){
    int n;
    cin >> n;
    // passing value (n,n)
    print(n,n);

    return 0;
}
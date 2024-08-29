//  Taking input from user in vector and printing the vector. 

#include <bits/stdc++.h>
using namespace std;

// input in vector from user
void input_vector(vector<int> &vec, int n){
    int a;  // making variable to take input from user & then store the value into the vector.
    for(int i = 1; i<=n; i++){
        cout << "Enter the " << i << " value : ";
        cin >> a;
        vec.push_back(a);
    }
}


// print the vector 
void print_vector(vector<int> &vec){
    cout << "\nPrinting vector : ";
    for(auto it : vec) cout << it << " ";
}

int main(void){
    vector<int> vec;
    // size 
    int n; 
    cout << "Enter the size of vector : ";
    cin >> n;
    // input
    input_vector(vec, n);
    // print
    print_vector(vec);

    return 0;
}

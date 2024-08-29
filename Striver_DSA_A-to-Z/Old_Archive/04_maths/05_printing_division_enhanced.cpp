
/*
        Solution : 
//  now we have to find the factors of any number, let say n = 36
            factors will be : 1, 2, 3, 4, 6, 9, 12, 18, 36
            so, 
                for 1 to be a factors, it's need to multiply by something & then it divide to n, & if condition is satisfied then it become the factor.
                same for 2, it need to multiply by something..

                n = 36

                    1      X      36        n/1
                    2      X      18        n/2
                    3      X      12        n/3     or we can say       n/i
                    4      X      9
            --------6------X------6---------- mid value ie nothing but square root, because sqrt(36) = 6
                    9      X      4
                    12     X      3
                    18     X      2
                    36     X      1
                factors         need to multiply with

        Conclusion : 
            * we can say we need to iterate the loop till sqrt(n),
            * & inside the loop we need to check for condition : for n to become factor 
                    * i.e  (n % i == 0), it this satisfied, then we can print (i) & (n/i)
        
        Solution : 
            * First : is simple where we are using this conclusion.
            * Second : is where we are using a certain condition i.e when (i != n/i) to not print the repeated value.
            * Third :   is when we use the vector to store the values, & Sorting them
            * Fourth :  is when we can replace the "i<=sqrt(n)" condition with "i*i<=n", i.e same.
*/

#include <bits/stdc++.h>
using namespace std;

// Fourth : using (i*i<=n) instead of i<=sqrt(n)
int main(void){
    int n;
    cin >> n;
    vector<int> v;  // using vector to store the the elements, also we don't know the size, that's why we use vector. 
    // TC : O(sqrt(n))     -> 1st
    for(int i = 1; i*i<=n; i++){
        if(n % i == 0){
            v.push_back(i); // push_back() will insert the value into back.
            if(i != (n/i)){
                v.push_back(n/i);
            }
        }
    }
    // TC : O(no of factors * log(no of factors))     -> 2nd
    sort(v.begin(),v.end());
    // TC : O(no of factors)      -> 3rd
    for(auto i : v) cout << i << " ";
    
    // so for TC : 1st + 2nd + 3rd

    return 0;
}

/*
// Third : This will print in ordered way
int main(void){
    int n;
    cin >> n;
    vector<int> v;  // using vector to store the the elements, also we don't know the size, that's why we use vector. 
    for(int i = 1; i<=sqrt(n); i++){
        if(n % i == 0){
            v.push_back(i); // push_back() will insert the value into back.
            if(i != (n/i)){
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(),v.end());
    for(auto i : v) cout << i << " ";

    return 0;
}
*/


/*
// Second : This will print not print the repeated value, but it is in unordered.
int main(void){
    int n;
    cin >> n;
    for(int i = 1; i<=sqrt(n); i++){
        if(n % i == 0){
            cout << i <<" ";
            if(i != (n/i)){
                cout << (n/i) << " ";
            }
        }
    }    
    return 0;
}
*/

/*
// first : this will print the repeated value, when (i = n/i), also it is not in ordered.
int main(void){
    int n;
    cin >> n;
    for(int i = 1; i<=sqrt(n); i++){
        if(n % i == 0){
            cout << i <<" " << (n/i) << " ";
            
        }
    }    
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;


class Array{
public:
    template <class T>
    static void input(vector<T> &A,int n){
        for (int i = 0; i < n; i++){
            scanf("%lf ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A){
        cout<<setprecision(3)<<fixed;
        for (int i = 0; i < A.size(); i++){
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        double ans;
        
        switch (choice){
            case 1: {
                double rd = (arr[0]);
                ans = M_PI * rd * rd;
                break;
            }
            case 2: {
                double l = (arr[0]);
                double R = (arr[1]);
                ans = l * R;
                break;
            }
            default: {
                return -1;
                break;
            }
        }
        
        return ans;
    }
};

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int choice;
        scanf("%d",&choice);
        
        
        vector<double> arr(choice);
        Array::input(arr,choice);
        
        Solution obj;
        double res = obj.switchCase(choice, arr);
        // cout<<fixed<<endl;
        if(res == int(res)){
            cout<<int(res)<<endl;
            continue;
        }
        cout<<setprecision(2)<<fixed;
        // 
        // }else{
            cout<<res<<endl;
        // }
        
    }
}
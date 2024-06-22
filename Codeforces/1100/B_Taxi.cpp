/*
//  B. Taxi


// Observations: 
    * n groups went outside to celebrate birthday..
    * ith group consist of si friends, & they want to go on event together. They decided to go there by taxi
    * each car can carry at-most 4 passenger, 
    * what minimum number of cars will the children need if each group should ride in the same taxi.
    * But one taxi can take more than one group.


// Intrusion: 
    * we can use hashing..
        * First we can store hash value of 4,
        * Then we can store all the values in car, at max 4 person can sit..
            * group with 4 people will take 1 car.
            * group with 3 people have two case: 
                * 3 and 1: Group with 3 people and group with 1 people
                * 3 only: when there will be no group with 1 people available
            * group with 2 people have two case:  
                * 2 only: pairs of group of two people can sit together.
                * 2 and 1: group with 2 people & group with one people can sit together.
            * group with 1 people: 
                * we will check it at last, when all the group have seated.
                * if 1 is not adjust with 2 & 3, we have to provide them extra taxi.
// Approach:    
    * Create taxi = 0
        * add all the hash value of 4 directly into taxi.
              taxi += hash[4] 
        * Second add the hash value of 3 with 1:
              if(hash[3] < hash[1]){
                taxi += hash[1];
                hash[1] -= hash[3]; // as all the hash[3] store with hash[1], so we subtract to get the remaining values of hash[1]
              }
              else if(hash[3] >= hash[1]){
                taxi += hash[3];    // all the hash[1] value exhaust with hash[3] & remaining hash[3] will will store in separate taxi.
              }
        * third we will store all the 2 & 1(if remaining)
            if(hash[2] > 0){
                taxi += hash[2]/2;  // if all the hash[2] are in even then next line will be 0.
                hash[2] = hash[2] % 2;  // storing remaining if it's in odd in number, this will remaining 1->2's
            }
        * Fourth we have only 1's or if remaining, then one 2's
            * create a left variable & store all the values in that.
            left = hash[1] + (2 * hash[1]);
            * now we can simply divide by 4, as all the elements can directly fit into the taxi..
            * if it's able to completely divide by 4, we can simply store (left/4), else if it's not divisible by 4, then we can add one to (left/4).

    * TC: O(n)

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);


void solve(){
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    int group1=0, group2=0, group3=0, group4=0; // as constrains is not grater than 4, so we have taken this 4 variable, else we could have use map to store frequency.
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] == 1) group1++;
        else if(arr[i] == 2) group2++;
        else if(arr[i] == 3) group3++;
        else if(arr[i] == 4) group4++;
    }
    int taxi = 0;
    // checking for group4:
    taxi += group4; // each group need 1 taxi.


    // checking for group3:
    // storing (3, 1) pairs:
    if(group3 < group1){    // if group 3 is lesser than group 1
        taxi += group3; // adding group 3 to taxi.
        group1 = group1 - group3;   // as group 1 has added with group3, & it's is grater in number, so we subtract..
    }
    else{   // when group3 is grater or equal than group 1, i.e (group3 >= group1)
        taxi += group3; // adding all the group 3 members to taxi, note as group1 is small or equal, all the group1 members fit in this taxi.
        group1 = 0; // making group 1 zero, because all the group 1 members fit in taxi.
    }

    // checking for group2:
    if(group2 > 0){ 
        // first we will store (2,2) pair in taxi.
        /*
            here when storing in paris, when the number of 2 is in even, we can simply split in half & fit.
            But, when they are in odd in number, we have one left.
            example: 
                    {2 2 2 2} -> 2 taxi needed
                    n/2 = 2
                    
                    {2 2 2 2 2} -> 3 taxi needed
                    n/2 = 2, & one left, so we can do ((n = n % 2), gives 1)
        
        */
        taxi += group2/2; // in one taxi group2 can add in pairs.
        group2 = group2 % 2;    // then is give the left groups of group2, i.e 1

    }
    // now we only have 1 group of 2, & remaining all 1's
    // we can store all the value some variable left;
    int left = group1 + (group2*2); // one left group2(we are multiplying it by 2 because it will take 2 space in taxi) & all the group 1 members are store in left
    // now we simply divide it by 4 & store result in taxi:
    if(left % 4 != 0){
        taxi += ((left / 4) + 1);
    }
    else if(left % 4 == 0){
        taxi += (left / 4);
    }
    cout << taxi << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
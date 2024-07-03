/*
//  A. Catch the Coin

// Observations: 
    * We are given coordinates: 
        * x => x coordinates from left to right
        * y => y coordinates from bottom to top
        * The center of screen has coordinates (0, 0)
    * At beginning character is located at center & n coin is appears on the screen.
    * The ith coin is the coordinates (xi, yi), coordinates of all the coins are different & not (0, 0)
    * In One second character can move one of the possible eight directions...
        * (x, y+1), (x+1, y+1), (x+1, y), (x+1, y+1), (x, y-1), (x-1, y-1), (x-1, y), (x-1, y+1)
    * if the character ends up at the coordinates with coin, then he can collect the coin..
    * after character move, all coin fell down by 1, that is they move from (x,y) to (x, y-1), we can assume the game field is of infinite in all directions..
    * monocorp want to collect atleast 1 coin, but not certain which coin to go for, we need to find for each coin wether he can collect it..
    * the (xi, yi), are the coordinates of coin given..

// Key Observations: 
    * Initially we are at (0,0)
    * We can move in any directions(diagonally also)..
    * if Coin is at any axis, above the x-axis, we can collect it easily...

                                            |
                                            |
                        *(-2, 3)Collect     |       *(1, 1) Collect
                                            |
                                            |
                                            |
                                            |(0,0)
                       <--------------------|------------------->   (x-axis)
                                            |-1
                                            |-2
                                            |-3
                                            |-4
                                            |..
                                            |.. 
    * As we are allowed to move diagonal, we can collect coin no matter wherever it is above the x-axis
    * Even in the case when coin is below the x-axis, if it's y-axis is -1, we can collect
                                            |
                                            |
                                            |
                                            |
                                            |
                                            |
                                            |(0,0)
                       <--------------------|------------------->   (x-axis)
                                *(-2, -1)   |-1
                                            |-2
                                            |-3
                                            |-4
                                            |..
                                            |.. 
    * After we move diagonally from (0, 0) to (-1,-1) coin fell down by (-2, -2) from (-2,-1).
        * again, after one more move diagonally, we move to (-2, -2), & coin fell down by (-2, -3).
        * Then we can move from (-2, -2) to (-2, -3) & collect the coin..
    * So, we can say if the y-axis of coin is (-1), in that case we can collect the coin..
    * If it's less than -1, we can't collect...
    * Example: (-1,-2)
        * when we move from (0, 0) to (-1, -1), coin fell down & new position will be (-1, -3).
        * When we move from (-1, -1) to (-1, -2), coin fell down & new position will be (-1, -4).
        * same again..
        * So, we have difference of 1 always...
    * In Conclusion, we can say if coin is below (-1) of y-axis, we can't collect the coin...
    * else if it's above (-1) or at (-1), we can collect...


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
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
    int x, y;
    cin >> x >> y;
    if(y < -1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
/*
// Betting game

// Observations: 
    * we are playing betting game,
    * if we win current round, betting amount will be added to our total sum
    * If we loose current round, amount will be reduces & next bet will be twice the previous bet..
    * game ends either when all rounds are over or we don't have sufficient funds..
    * Initially we are given inital sum = 4,
    * W = Wins
    * L = Loose

    * We need to find & print the amount at the end of game, or if we don't have enough funds we need to return -1

 W W L W L L L

b = 1 2 4 8

5 6 5 6 5 3 -1

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int betBalance(string s){
        int res = 4;    // initial 
        int bet = 1;    // bet amount
        for(int i=0;i<s.size();i++){
            if(res < bet) return -1;    // if we don't have enough money to bet

            if(s[i] == 'W'){
                res += bet;
                bet = 1;    // when we win we reset the bet
            }
            else if(s[i] == 'L'){
                res = res - bet;    // subtract bet from the result
                bet = bet * 2;  // we double the bet, this will double only if we have consecutive losses
            }
        }
        return res;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string result;
        cin>>result;
        
        Solution ob;
        cout<<ob.betBalance(result)<<endl;
    }
    return 0;
}
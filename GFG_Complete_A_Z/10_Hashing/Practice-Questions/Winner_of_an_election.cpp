/*

// Winner of an election

// Observations: 
    * We are given list of candidates who's perform in an election, & we need to find the candidate who's got maximum votes.
    * Else if the voting is drawn, then we need to return the lexigraphically smaller name.


// Intrusion: 
    // Approach 1: Bruteforce approach
        * We can use nested loop to compare the value by picking one by one.
        * If the match is drawn then we can sort the array & return the lexigraphically smaller values.
        * This will take O(n^2) complexity.
        * TC: O(N^2) -> TLE
    
    // Approach 2: Using hashing
        * We can hash all the values in hashmap & from there we can fetch the value & return the winner if it's there.
        * else we will return the lexigraphically first value.
        * we will use map data structure that store the element in sorted fashion, which maintain the lexigraphically order.
        * TC: O(nlogn)
        * AS: O(n)

*/

#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    // Bruteforce Approach: 
    vector<string> winner_Brute(string arr[],int n){
        // sorting the value that will maintain the lexigraphically order if we don't have any winners
        sort(arr, arr + n);

        vector<string> res;
        int solu = 0;
        string winner = "";
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(arr[i] == arr[j]){
                    cnt++;
                }
            }
            // this will make sure if there is no winner the first value lexigraphically will be considered as winner.
            if(cnt > solu){
                solu = cnt;
                winner = arr[i];
            }
        }

        res.push_back(winner);
        res.push_back(to_string(solu));

        return res;
    }
    // Approach 2: Using hashing
    vector<string> winner(string arr[],int n){
        // hashing all the candidate result in the hashmap.
        map<string, int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;

        // finding the winner: 
        int votes = 0;
        string winner = "";
        for(auto i=mp.begin();i!=mp.end();i++){
            // condition to check the winner from the hashmap
            if(i->second > votes){
                votes = i->second;
                winner = i->first;
            }
        }

        // storing the winner
        vector<string> res;
        res.push_back(winner);
        res.push_back(to_string(votes));

        return res;
    }

};

int main(){
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
/*

//  3433. Count Mentions Per User


//  Problem Statement: 
- You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.
- Each events[i] can be either of the following two types:
    - Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
        - This event indicates that a set of users was mentioned in a message at timestampi.
        - The mentions_stringi string can contain one of the following tokens:
            id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
            ALL: mentions all users.
            HERE: mentions all online users.
    - Offline Event: ["OFFLINE", "timestampi", "idi"]
        - This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
- Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.
- All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.
- Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.

 
// Example:
    Example 1:
        Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]
        Output: [2,2]
        Explanation:
            Initially, all users are online.
            At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]
            At timestamp 11, id0 goes offline.
            At timestamp 71, id0 comes back online and "HERE" is mentioned. mentions = [2,2]

    Example 2:
        Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]
        Output: [2,2]
        Explanation:
            Initially, all users are online.
            At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]
            At timestamp 11, id0 goes offline.
            At timestamp 12, "ALL" is mentioned. This includes offline users, so both id0 and id1 are mentioned. mentions = [2,2]

    Example 3:
        Input: numberOfUsers = 2, events = [["OFFLINE","10","0"],["MESSAGE","12","HERE"]]
        Output: [0,1]
        Explanation:
            Initially, all users are online.
            At timestamp 10, id0 goes offline.
            At timestamp 12, "HERE" is mentioned. Because id0 is still offline, they will not be mentioned. mentions = [0,1]


// Observations:
    - given 'numberOfUsers'
    - given 'events' of size n * 3.
    - event[i] can be either of two type:
        - message event:
        - offline event
    - This is typical simulations type problem.

    // Approach: 
        - first sort the given data based on timestamp, so that we can process all the event in organized manners.
        - if user goes offline & comes back online at same timestamp for two event, first we will process offline & then online..
        - sort(begin(events), end(events), lambda)
        - we will have to write lambda:
            auto lambda = [] (auto &vec1, auto &vec2) { // sorting on the basis of timestamp:
                // get the timestamp:
                int t1 = stoi(vec1[1]);
                int t2 = stoi(vec2[1]);

                if(t1 == t2) {
                    // now we will have to process offline first:
                    return vec1[0][1] > vec2[0][1]; // compare "MESSAGE" & "OFFLINE" -> "M" & "O" lexographacially
                } else {
                    t1 < t2
                }
            }

        - after sorting we can compare & process...



// Complexity:  
    - TC: O(ElogE + E * N)
    - SC: O(N)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    void applyMessageEvent(vector<string> event, vector<int> &mentionCnt, vector<int> &offlineTime) {
        int timeStamp = stoi(event[1]); // get the current timestamp.


        // Tokenize the message (mentions_string)
        vector<string> ids;
        stringstream ss(event[2]);
        string token;
        while(ss >> token) {    // Bydefault: it break tokens on the basis of whitespace
            ids.push_back(token);
        }


        // process all IDs:
        for(string id: ids) {
            if(id == "ALL") {   // mention  all the users..
                for(int i = 0; i< mentionCnt.size(); i++) {
                    mentionCnt[i]++;
                }
            } else if(id == "HERE") {   // mentions only online users:
                for(int i = 0; i < mentionCnt.size(); i++) {
                    if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timeStamp) {
                        mentionCnt[i]++;
                    }
                }
            } else {
                mentionCnt[stoi(id.substr(2))]++;   // fetch id value i.e x from idx (id0, id1, etc) -> "0, 1, 2" it will fetch & then mentions cnt will 
            }
        }
    }
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        vector<int> mentionsCnt(numberOfUsers); // SC: O(N)
        vector<int> offlineTime(numberOfUsers);

        auto lambda = [] (auto &vec1, auto &vec2) {
            // Get the timestamps:
            int t1 = stoi(vec1[1]);
            int t2 = stoi(vec2[1]);

            if(t1 == t2) { // Offline should come first.
                return vec1[0][1] > vec2[0][1]; // comparing 'O' of "OFFLINE" with 'M' of "MESSAGE"
            } 

            return t1 < t2;    // return the lesser timestamp
        };

        // Sort the given events based on timestamps:
        sort(begin(events), end(events), lambda);   // TC: O(ElogE)

        // Process Every events:
        for(auto &event: events) {  // TC: O(E * N)
            if(event[0] == "MESSAGE") {
                applyMessageEvent(event, mentionsCnt, offlineTime);
            } else if(event[0] == "OFFLINE") {
                int timeStamp = stoi(event[1]);
                int id = stoi(event[2]);
                offlineTime[id] = timeStamp;
            }
        }

        return mentionsCnt;
    }
};  
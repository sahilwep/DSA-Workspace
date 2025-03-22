/*

//  2115. Find All Possible Recipes from Given Supplies


//  Problem Statement:
    -> You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
    -> You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
    -> Return a list of all the recipes that you can create. You may return the answer in any order.
    -> Note that two recipes may contain each other in their ingredients.

 
// Example: 
    Example 1:
        Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
        Output: ["bread"]
        Explanation:
        We can create "bread" since we have the ingredients "yeast" and "flour".

    Example 2:
        Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
        Output: ["bread","sandwich"]
        Explanation:
        We can create "bread" since we have the ingredients "yeast" and "flour".
        We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".

    Example 3:
        Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
        Output: ["bread","sandwich","burger"]
        Explanation:
        We can create "bread" since we have the ingredients "yeast" and "flour".
        We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
        We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".

// BruteForce Solution: 
    -> For every recipes: 
        -> check if all the needed ingredients are available or not?
    -> NOTE: Make sure to check all possible case where we cook certain recipes first & then we proceed with other recipes..
    // Complexity:
        -> TC: O(n ^ 2 * m)
            -> n = recipes
            -> m = ingredients 
        -> SC: O(n + m)


// Topo-Sort Solution: 
    -> Because there is a dependent relations b/w the recipes & their ingredients & the supplies..
    -> Means, bread can only be cooked once we have floor & yeast, simillar like Topo-sort where edge have dependent relations, like node 3 comes before 2, etc..
    -> this can be solved using Topo-Sort, with slightly modifications:
    -> Store all the adj list into the map
    -> Also, parallel process the indegree.
    -> insert all the supply int queue.
    -> Process BFS & decrement the indegree[recipes] items
    -> Once the recipes is cooked push it inot queue & store it in our answer.
    // TC: O(V + E)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Topo-Sort Approach:
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string, vector<string>> adj;  // adj list
        unordered_map<string, int> indegree;    // indegree
        
        // Process recipes & ingredients & Build Adj list:
        for(int i = 0; i < recipes.size(); i++) {   // for every recipes:
            for(auto &item: ingredients[i]) {       // get the ingredients items:

                // Edge from j ---> i,  because recipes depends on ingredients, or to go on recipes we must start with ingredients & then move to recipes.
                adj[item].push_back(recipes[i]);    // directed edges: There is a path from every items of current recipes[i].
            }

            // all the ingredients[i] have directed edge to recipes[i], so, we can store the indegree of every recipes.
            indegree[recipes[i]] = ingredients[i].size(); // indegree of every recipes are their inringredinets size.
        }

        // Now, push all the available supplies into queue, so that we can process it into queue:
        queue<string> q;
        for(auto &sup: supplies) {
            q.push(sup);
        }

        
        // Process BFS:
        vector<string> ans;
        while(!q.empty()) {
            auto items = q.front();
            q.pop();

            // check the required item to are available to cook that recipe or not?
            for(auto &recipe: adj[items]) { 

                indegree[recipe]--; // while every items found, we are putting that items into recipes this is why we are subtracting the indegree of recipes.
                if(indegree[recipe] == 0) { // once the food is cooked:
                    ans.push_back(recipe);  // store it into answer
                    
                    q.push(recipe);   // push that item into queue also.
                }
            }
        }

        return ans;
    }
};


// BruteForce Solution:
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        unordered_set<string> items(begin(supplies), end(supplies));    // using unordered set to O(1) query operations.

        set<string> res;    // set to hold only unique values.

        // Try all possible case to cook recipes:
        for(int k = 0; k < n; k++) {        // TC: O(n * n * m)
            for(int i = 0; i < n; i++) {
                string dish = recipes[i];
                bool itemAvl = true;
                for(int j = 0; j < ingredients[i].size(); j++) {
                    if(items.find(ingredients[i][j]) == items.end()) {  // if ingredients is available to cook recipes:
                        itemAvl = false;    // mark this flag as false
                        break;
                    }
                }
                if(itemAvl) {   // check if all the item available to cook recipes, then only store in our answer:
                    items.insert(dish);
                    res.insert(dish);
                }
            }
        }

        vector<string> ans(begin(res), end(res));

        return ans;
    }
};
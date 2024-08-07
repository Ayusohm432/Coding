/*
Problem Link :- https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2024-07-27
*/

/*2976. Minimum Cost to Convert String I

You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.
 

Constraints:

1 <= source.length == target.length <= 105
source, target consist of lowercase English letters.
1 <= cost.length == original.length == changed.length <= 2000
original[i], changed[i] are lowercase English letters.
1 <= cost[i] <= 106
original[i] != changed[i]


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

//Approach-1 ---> Dijkstra Algorithm
class Solution {
private:
    vector<long long> dijkstra(int startChar , vector<vector<pair<int,int>>>& adj){
        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;

        pq.push({0 , startChar});

        vector<long long> minCosts(26 , -1);
        while(!pq.empty()){
            auto [currentCost , currentChar] = pq.top();
            pq.pop();

            if(minCosts[currentChar] != -1 && minCosts[currentChar] < currentCost){
                continue;
            }

            for(auto& [targetChar , cost] : adj[currentChar]){
                long long newCost = currentCost + cost;

                if(minCosts[targetChar] == -1 || newCost < minCosts[targetChar]){
                    minCosts[targetChar] = newCost;
                    pq.push({newCost , targetChar});
                } 
            }
        }
        return minCosts;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        int n = original.size();

        for(int i=0 ; i<n ; i++){
            adj[original[i] - 'a'].push_back({changed[i] - 'a' , cost[i]});
        }

        vector<vector<long long>> minCost(26 , vector<long long>(26));
        for(int i=0 ; i<26 ; i++){
            minCost[i] = dijkstra(i , adj);
        }

        long long totalCost = 0;
        int stringLength = source.size();
        for(int i=0 ; i<stringLength ; i++){
            if(source[i] != target[i]){
                long long charConversionCost = minCost[source[i] - 'a'][target[i] - 'a'];
                if(charConversionCost == -1){
                    return -1;
                }
                totalCost += charConversionCost;
            }
        }
        return totalCost;
    }
};

//Approach-2
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> minCost(26,vector<long long>(26 , INT_MAX));

        for(int i=0 ; i<original.size() ; i++){
            int startChar = original[i] - 'a';
            int endChar   = changed[i] - 'a';
            minCost[startChar][endChar] = min(minCost[startChar][endChar] , (long long)cost[i]);
        }

        for(int k=0 ; k<26 ; k++){
            for(int i=0 ;i<26 ; i++){
                for(int j=0 ; j<26 ; j++){
                    minCost[i][j] = min(minCost[i][j] , minCost[i][k] + minCost[k][j]);
                }
            }
        }
        long long totalCost = 0;
        for(int i=0 ; i<source.size() ; i++){
            if(source[i] == target[i]){
                continue;
            }

            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            if(minCost[sourceChar][targetChar] >= INT_MAX){
                return -1;
            }
            totalCost += minCost[sourceChar][targetChar];
        }
        return totalCost;
    }
};


//Main Function
int main(){
    Solution solution;
    string source = "abc";
    string target = "bca";
    vector<char> original = {'a','b','c'};
    vector<char> changed = {'b','c','a' };
    vector<int> cost = {1,2,3};
    cout<<solution.minimumCost(source,target,original,changed,cost)<<endl;
    return 0;

}
/*
Problem Link: https://www.geeksforgeeks.org/problems/count-the-paths4332/1
*/

/*Count the paths


Given a Directed Acyclic Graph (DAG) with V nodes labeled from 0 to V-1, and a list of directed edges, count the total number of distinct paths from a given start node to a destination node. Each edge is represented as edges[i] = [u, v], indicating a directed edge from u to v.

Examples :

Input: edges[][] = [[0,1], [0,3], [2,0], [2,1], [1,3]], V = 4, src = 2, dest = 3
Output: 3
Explanation: There are three ways to reach at 3 from 2. These are: 2 -> 1 -> 3, 2 -> 0 -> 3 and 2 -> 0 -> 1 -> 3.
Print-all-paths-1
Input: edges[][] = [[0,1], [1,2], [1,3], [2,3]], V = 4, src = 0, dest = 3
Output: 2
Explanation: There is two way to reach at 3 from 0 that is : 0 -> 1 -> 2 -> 3 and 0 -> 1 -> 3.
Print-all-paths-2
Constraints:
2  ≤  V  ≤  103
1  ≤   E = edges.size()  ≤  (V * (V - 1)) / 2

*/

class Solution {
  public:
    int solve(int u, int v, vector<int> adj[], vector<int>& dp){
        if(u == v){
            return 1;
        }
        if(dp[u] != -1){
            return dp[u];
        }
        
        int total = 0;
        for(auto& neighbour : adj[u]){
            total += solve(neighbour, v, adj, dp);
        }
        
        return dp[u] = total;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<int> adj[V];
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> dp(V, -1);
        return solve(src, dest, adj, dp);
    }
};
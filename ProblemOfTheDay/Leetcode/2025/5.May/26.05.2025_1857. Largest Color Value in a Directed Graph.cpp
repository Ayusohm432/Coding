/*
Problem Link: https://leetcode.com/problems/largest-color-value-in-a-directed-graph?envType=daily-question&envId=2025-05-26
*/

/*1857. Largest Color Value in a Directed Graph

There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 

Example 1:



Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
Example 2:



Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.
 

Constraints:

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n

*/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int, vector<int>> adj;
        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));

        vector<int> inDegree(n, 0);

        for(auto& vec : edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int result = 0;
        int nodesCount = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            nodesCount++;
            result = max(result, dp[u][colors[u] - 'a']);

            for(int &v : adj[u]){
                for(int i=0; i<26; i++){
                    dp[v][i] = max(dp[v][i], dp[u][i] + (colors[v] - 'a' == i));
                }

                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(nodesCount < n){
            return -1;
        }

        return result;
    }
};
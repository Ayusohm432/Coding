/*
Problem Link: https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1
*/

/*Minimum Weight Cycle

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents the edge between the nodes u and v having w edge weight.
Your task is to find the minimum weight cycle in this graph.

Examples:

Input: V = 5, edges[][] = [[0, 1, 2], [1, 2, 2], [1, 3, 1], [1, 4, 1], [0, 4, 3], [2, 3, 4]]

Output: 6
Explanation: 

Minimum-weighted cycle is  0 → 1 → 4 → 0 with a total weight of 6(2 + 1 + 3)
Input: V = 5, edges[][] = [[0, 1, 3], [1, 2, 2], [0, 4, 1], [1, 4, 2], [1, 3, 1], [3, 4, 2], [2, 3, 3]]

Output: 5
Explanation: 

Minimum-weighted cycle is  1 → 3 → 4 → 1 with a total weight of 5(1 + 2 + 2)
Constraints:
1 ≤ V ≤ 100
1 ≤ E = edges.size() ≤ 103 
1 ≤ edges[i][j] ≤ 100

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        int res = INT_MAX;
        
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int v = edge[0];
            int u = edge[1];
            int wt = edge[2];
            adj[v].push_back({u, wt});
            adj[u].push_back({v, wt});
        }
        
        for (auto& edge : edges) {
            int src = edge[0], des = edge[1], weight = edge[2];
            vector<int> dist(V, INT_MAX);
            dist[src] = 0;
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.push({0, src});
            
            while (!pq.empty()) {
                int curWt = pq.top().first;
                int cur = pq.top().second;
                pq.pop();
                
                for (auto x : adj[cur]) {
                    int child = x.first;
                    
                    if ((cur == src && child == des) || (cur == des && child == src)) continue;
                    
                    int wts = x.second;
                    
                    if (dist[cur] + wts < dist[child]) {
                        dist[child] = dist[cur] + wts;
                        pq.push({dist[child], child});
                    }
                }
            }
            
            if (dist[des] != INT_MAX) {
                res = min(res, weight + dist[des]);
            }
        }
        
        return (res == INT_MAX) ? -1 : res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends
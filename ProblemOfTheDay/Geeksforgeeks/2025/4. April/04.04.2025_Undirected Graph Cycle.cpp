/*
Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

/*Undirected Graph Cycle

Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105

*/

class Solution {
    bool hasCycleDfs(int node, int parent, vector<bool>& visited, unordered_map<int, list<int>>& adj){
        visited[node] = true;
        
        for(int neighbour : adj[node]){
            if(neighbour == parent){
                continue;
            }
            if(visited[neighbour] || hasCycleDfs(neighbour, node, visited, adj)){
                return true;
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, list<int>> adj;
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && hasCycleDfs(i, -1, visited, adj)){
                return true;
            }
        }
        
        return false;
    }
};
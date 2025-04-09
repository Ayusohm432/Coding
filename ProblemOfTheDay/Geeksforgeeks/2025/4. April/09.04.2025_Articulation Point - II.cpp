/*
Problem LinK: https://www.geeksforgeeks.org/problems/articulation-point2616/1
*/

/*Articulation Point - II

You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.

Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.

Examples :

Input: V = 5, edges[][] = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]

Output: [1, 4]
Explanation: Removing the vertex 1 or 4 will disconnects the graph as-
   
Input: V = 4, edges[][] = [[0, 1], [0, 2]]
Output: [0]
Explanation: Removing the vertex 0 will increase the number of disconnected components to 3.  
Constraints:
1 ≤ V, E ≤ 104

*/

class Solution {
    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap, int& time){
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent[u]) continue;

            if (!visited[v]) {
                parent[v] = u;
                ++children;
                dfs(v, adj, visited, disc, low, parent, ap, time);

                low[u] = min(low[u], low[v]);

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (parent[u] == -1 && children > 1)
            ap[u] = true;
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        vector<bool> visited(V);
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<bool> ap(V);
        int time = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, disc, low, parent, ap, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (ap[i]) result.emplace_back(i);
        }

        return result.empty() ? vector<int>{-1} : result;
    }
};
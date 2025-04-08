/*
Problem Link: https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1
*/

/*Bridge edge in a graph

Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between the vertices u and v. Determine whether a specific edge between two vertices (c, d) is a bridge.

Note:

An edge is called a bridge if removing it increases the number of connected components of the graph.
if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.
Examples :

Input:

c = 1, d = 2
Output: true
Explanation: From the graph, we can clearly see that blocking the edge 1-2 will result in disconnection of the graph.
Hence, it is a Bridge.
Input:

c = 0, d = 2
Output: false
Explanation:

Blocking the edge between nodes 0 and 2 won't affect the connectivity of the graph.
So, it's not a Bridge Edge. All the Bridge Edges in the graph are marked with a blue line in the above image.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ c, d ≤ V-1

*/

class Solution {
    public:
      void dfs(int node, const vector<vector<int>>& adj, int c, int d, vector<int>& visited){
          visited[node] = true;
          for(auto neighbour : adj[node]){
              if(!visited[neighbour] && !(node == c && neighbour == d)){
                  dfs(neighbour, adj, c, d, visited);
              }
          }
      }
      bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          // Code here
          vector<int> visited(V, 0);
          vector<vector<int>> adj(V);
          
          for(auto& edge : edges){
              int u = edge[0];
              int v = edge[1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          
          dfs(c, adj, c, d, visited);
          if(visited[d]){
              return false;
          }
          return true;
      }
  };
/*
Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

/*Directed Graph Cycle

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]



Output: true
Explanation: 3 -> 3 is a cycle
Input: V = 3, edges[][] = [[0, 1], [1, 2]]



Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105

*/
class Solution {
    public:
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // code here
          vector<vector<int>> adj(V);
          vector<int> degree(V);
          
          queue<int> que;
          int count = 0;
          
          for(auto& edge : edges){
              int u = edge[0], v = edge[1];
              if(u == v){
                  return true;
              }
              degree[v]++;
              adj[u].push_back(v);
          }
          
          for(int i=0; i<V; i++){
              if(degree[i] == 0){
                  que.push(i);
                  count++;
              }
          }
          
          while(!que.empty()){
              int curr = que.front();
              que.pop();
              
              for(auto node : adj[curr]){
                  degree[node]--;
                  if(degree[node] == 0){
                      que.push(node);
                      count++;
                  }
              }
          }
          
          return (count < V);
      }
  };
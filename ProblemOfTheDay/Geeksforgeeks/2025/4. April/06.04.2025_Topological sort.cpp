/*
Problem Link: https://www.geeksforgeeks.org/problems/topological-sort/1
*/

/*Topological sort

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes an directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  103
1  ≤  E = edges.size()  ≤  (V * (V - 1)) / 2

*/

class Solution {
    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          // code here
          vector<int> result;
          
          vector<int> degree(V+ 1, 0);
          vector<vector<int>> graph(V);
          
          for(auto edge : edges){
              graph[edge[0]].push_back(edge[1]);
              degree[edge[1]]++;
          }
          
          queue<int> que;
          for(int i=0; i<V; i++){
              if(degree[i] == 0){
                  que.push(i);
                  result.push_back(i);
                  degree[i] = -1;
              }
          }
          
          while(!que.empty()){
              int curr = que.front();
              que.pop();
              
              for(auto edge : graph[curr]){
                  degree[edge]--;
                  
                  if(degree[edge] == 0){
                      degree[edge] = -1;
                      que.push(edge);
                      result.push_back(edge);
                  }
              }
          }
          
          return result;
      }
  };
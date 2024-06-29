/*
Problem Link :- https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
*/

/*2192. All Ancestors of a Node in a Directed Acyclic Graph

You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.

 

Example 1:


Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
Example 2:


Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
 

Constraints:

1 <= n <= 1000
0 <= edges.length <= min(2000, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi <= n - 1
fromi != toi
There are no duplicate edges.
The graph is directed and acyclic.


*/


//Approach-1        S.C:- O(V+E)            T.C:-O(v*(V+E))

class Solution {
public:
    void DFS(int ancestor , unordered_map<int,vector<int>>& adj , int currnode , vector<vector<int>>& result){
        for(int& ngb : adj[currnode]){
            if(result[ngb].empty() || result[ngb].back() != ancestor){
                result[ngb].push_back(ancestor);
                DFS(ancestor,adj,ngb,result);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int,vector<int>> adj;

        for(vector<int>& vec : edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }


        for(int i=0 ; i<n ; i++){
            int ancestor = i;
            DFS(ancestor,adj,i,result);
        }
        return result;
    }
};


//Approach-2         S.C:- O(V+E)            T.C:-O(v*(V+E))

class Solution {
public:
    void DFS(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;

        for (int& v : adj[u]) {
            if (!visited[v]) {
                DFS(v, adj, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        for (vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }

        for (int u = 0; u < n; ++u) {
            vector<int> ancestors;
            vector<bool> visited(n, false);

            DFS(u, adj, visited);

            for (int i = 0; i < n; ++i) {
                if (i != u && visited[i]) {
                    ancestors.push_back(i);
                }
            }
            result[u] = ancestors;
        }
        return result;
    }
};


//Approach-3

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);

        for(vector<int>& vec : edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }

        vector<int> topOrder;
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            topOrder.push_back(curr);
            for(int& v : adj[curr]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }

        vector<unordered_set<int>> vec(n);

        for(int& node : topOrder){
            for(int& v : adj[node]){
                vec[v].insert(node);
                vec[v].insert(vec[node].begin(),vec[node].end());
            }
        }

        for(int i=0 ; i<n ; i++){
            result[i] = vector<int>(vec[i].begin() , vec[i].end());
            sort(begin(result[i]),end(result[i]));
        }

        return result;
    }
};
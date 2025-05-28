/*
Problem Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i?envType=daily-question&envId=2025-05-28
*/

/*3372. Maximize the Number of Target Nodes After Connecting Trees I

There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.

Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

 

Example 1:

Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2

Output: [9,7,9,8,8]

Explanation:

For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 0 from the second tree.
For i = 2, connect node 2 from the first tree to node 4 from the second tree.
For i = 3, connect node 3 from the first tree to node 4 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:

Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1

Output: [6,3,3,3,3]

Explanation:

For every i, connect node i of the first tree with any node of the second tree.


 

Constraints:

2 <= n, m <= 1000
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.
0 <= k <= 1000

*/

class Solution {
    int explore(int current, int parent, vector<vector<int>>& graph, int depth){
        if(depth < 0){
            return 0;
        }

        int nodesReachable = 1;
        for(int neighbour : graph[current]){
            if(neighbour == parent){
                continue;
            }
            nodesReachable += explore(neighbour, current, graph, depth - 1);
        }

        return nodesReachable;
    }

    vector<int> computeReachableNodes(vector<vector<int>>& connections, int maxDepth){
        int totalNodes = connections.size() + 1;
        vector<vector<int>> adjList(totalNodes);

        for(const auto& conn : connections){
            adjList[conn[0]].push_back(conn[1]);
            adjList[conn[1]].push_back(conn[0]);
        }

        vector<int> reachability(totalNodes);
        for(int i=0; i<totalNodes; i++){
            reachability[i] = explore(i, -1, adjList, maxDepth);
        }

        return reachability;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        vector<int> reach1 = computeReachableNodes(edges1, k);
        vector<int> reach2 = computeReachableNodes(edges2, k-1);

        int maxi = *max_element(reach2.begin(), reach2.end());
        vector<int> result(n);

        for(int i=0; i<n; i++){
            result[i] = reach1[i] + maxi;
        }

        return result;
    }
};
/*
Problem Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii?envType=daily-question&envId=2025-05-29
*/

/*3373. Maximize the Number of Target Nodes After Connecting Trees II

There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

 

Example 1:

Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]

Output: [8,7,7,8,8]

Explanation:

For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 4 from the second tree.
For i = 2, connect node 2 from the first tree to node 7 from the second tree.
For i = 3, connect node 3 from the first tree to node 0 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:

Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]

Output: [3,6,6,6,6]

Explanation:

For every i, connect node i of the first tree with any node of the second tree.


 

Constraints:

2 <= n, m <= 105
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.

*/

class Solution {
public:
    unordered_map<int, vector<int>> buildGraph(vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        for (auto& conn : connections) {
            int node1 = conn[0];
            int node2 = conn[1];

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        return graph;
    }

    // DFS traversal to alternate color nodes and count color groups
    void traverseDFS(int node, unordered_map<int, vector<int>>& graph, int parent,
                     vector<int>& colors, int& group0, int& group1) {

        if (colors[node] == 0) {
            group0++;
        } else {
            group1++;
        }

        for (auto& neighbor : graph[node]) {
            if (neighbor != parent) {
                colors[neighbor] = (colors[node] == 0) ? 1 : 0;  // alternate coloring
                traverseDFS(neighbor, graph, node, colors, group0, group1);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& tree1Edges, vector<vector<int>>& tree2Edges) {
        int sizeA = tree1Edges.size() + 1;
        int sizeB = tree2Edges.size() + 1;

        unordered_map<int, vector<int>> graphA = buildGraph(tree1Edges);
        unordered_map<int, vector<int>> graphB = buildGraph(tree2Edges);

        vector<int> colorA(sizeA, -1);
        colorA[0] = 0;
        int groupA0 = 0;
        int groupA1 = 0;
        traverseDFS(0, graphA, -1, colorA, groupA0, groupA1);

        vector<int> colorB(sizeB, -1);
        colorB[0] = 0;
        int groupB0 = 0;
        int groupB1 = 0;
        traverseDFS(0, graphB, -1, colorB, groupB0, groupB1);

        int maxGroupB = max(groupB0, groupB1);

        vector<int> output(sizeA);
        for (int i = 0; i < sizeA; i++) {
            output[i] = (colorA[i] == 0 ? groupA0 : groupA1) + maxGroupB;
        }

        return output;
    }
};

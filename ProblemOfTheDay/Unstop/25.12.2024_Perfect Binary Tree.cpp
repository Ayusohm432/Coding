/*
Problem Link: https://unstop.com/code/practice/277797
*/

/*Perfect Binary Tree

Problem Statement
You are given a Perfect Binary Tree of height N. A perfect binary tree is a binary tree in which every internal node has exactly two child nodes, and all the leaf nodes are at the same level.
The node of the tree is represented by the number 1. Each node V has two children: nodes indexed (2·V) and (2·V+1).
The edge from node I to node ⌊I / 2⌋ has W[I] weight.
Your task is to increase some edge weights so that the distance from root node 1 to all the leaf nodes is the same. Find the minimum sum of increments in the edges to make the distance from the root node to each leaf node equal.

Note: Node 1 is the root node.

Input Format
The first line contains an integer, N (height of the perfect binary tree having 2^(N+1) – 1 nodes).
The next line contains space-separated 2^(N+1) - 2 integers representing the weight of the edge between node i and node ⌊I / 2⌋.

Output Format
Print the minimum sum of increments in the edge weights as described in the problem statement.

Constraints
1 ≤ N ≤ 18
1 ≤ W[I] ≤ 10^6

Sample Testcase 0
Testcase Input
1
5 10
Testcase Output
5
Explanation
We can increase the edge weight between nodes 1 and 2 (5 to 10). By doing this, the edge weights from 1 to 2 and from 1 to 3 will become equal. Hence the answer is 5.
Sample Testcase 1
Testcase Input
2
3 6 2 1 5 4
Testcase Output
8
Explanation
We can increase the weight of the edge between node 5 and node 2 to 2: an increase of 1.
Then, we can increase the weight of the edge between node 7 and node 3 to 5: an increase of 1.
Then, we can increase the weight of the edge between node 2 and node 1 to 9: an increase of 6.
Thus, all the paths from the root node to the leaf node will have the same length of 11.
So, an increase of 1+1+6 = 8 will be required in the edge weights.

*/

//Approach - 1

#include <iostream>
#include <vector>
#include <cstring>

long long totalVertices = 0;
int edge[1 << 21][2];

long long dfs(int node, std::vector<int>& wt, long long &ans) {
    if (2 * node > totalVertices) return 0;
    long long leftEdgeLength = edge[node][0] + dfs(2 * node, wt, ans);
    long long rightEdgeLength = edge[node][1] + dfs(2 * node + 1, wt, ans);
    ans += abs(leftEdgeLength - rightEdgeLength);
    return std::max(leftEdgeLength, rightEdgeLength);
}

long long user_logic(int n, std::vector<int>& weights) {
    totalVertices = (1 << (n + 1)) - 1;
    memset(edge, 0, sizeof(edge));
    std::vector<int> currNode = {1};
    int itr = 0;

    for (int i = 1; i <= n; i++) {
        std::vector<int> temp;
        int idx = 0;
        while (idx < currNode.size()) {
            int node = currNode[idx];
            temp.push_back(2 * node);
            temp.push_back(2 * node + 1);
            edge[node][0] = weights[itr];
            edge[node][1] = weights[itr + 1];
            itr += 2;
            idx++;
        }
        currNode = temp;
    }

    long long ans = 0;
    dfs(1, weights, ans);
    return ans;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> weights((1 << (n + 1)) - 2);
    for (int i = 0; i < (1 << (n + 1)) - 2; i++) {
        std::cin >> weights[i];
    }

    long long result = user_logic(n, weights);
    std::cout << result << std::endl;

    return 0;
}
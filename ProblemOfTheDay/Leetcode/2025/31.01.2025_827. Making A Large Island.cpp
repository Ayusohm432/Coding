/*
Problem Link: https://leetcode.com/problems/making-a-large-island?envType=daily-question&envId=2025-01-31
*/

/*827. Making A Large Island

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.

*/

class DisjointSet {
public:
    vector<int> parent;
    vector<int> islandSize;

    DisjointSet(int n) {
        parent.resize(n);
        islandSize.resize(n);
        for (int node = 0; node < n; node++) {
            parent[node] = node;
            islandSize[node] = 1;
        }
    }

    int findRoot(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findRoot(parent[node]);
    }

    void unionNodes(int nodeA, int nodeB) {
        int rootA = findRoot(nodeA);
        int rootB = findRoot(nodeB);

        if (rootA == rootB) return;

        if (islandSize[rootA] < islandSize[rootB]) {
            parent[rootA] = rootB;
            islandSize[rootB] += islandSize[rootA];
        } else {
            parent[rootB] = rootA;
            islandSize[rootA] += islandSize[rootB];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        DisjointSet ds(rows * columns);

        vector<int> rowDirections = {1, -1, 0, 0};
        vector<int> columnDirections = {0, 0, 1, -1};

        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentColumn = 0; currentColumn < columns;
                 currentColumn++) {
                if (grid[currentRow][currentColumn] == 1) {
                    int currentNode = (columns * currentRow) + currentColumn;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];
                        if (neighborRow >= 0 && neighborRow < rows &&
                            neighborColumn >= 0 && neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            ds.unionNodes(currentNode, neighborNode);
                        }
                    }
                }
            }
        }

        int maxIslandSize = 0;
        bool hasZero = false;
        unordered_set<int> uniqueRoots;

        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentColumn = 0; currentColumn < columns;
                 currentColumn++) {
                if (grid[currentRow][currentColumn] == 0) {
                    hasZero = true;
                    int currentIslandSize = 1;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        if (neighborRow >= 0 && neighborRow < rows &&
                            neighborColumn >= 0 && neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            int root = ds.findRoot(neighborNode);
                            uniqueRoots.insert(root);
                        }
                    }

                    for (int root : uniqueRoots) {
                        currentIslandSize += ds.islandSize[root];
                    }
                    uniqueRoots.clear();
                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        if (!hasZero) return rows * columns;

        return maxIslandSize;
    }
};
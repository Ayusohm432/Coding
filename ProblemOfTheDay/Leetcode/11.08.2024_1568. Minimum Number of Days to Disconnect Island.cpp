/*
Problem link : https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/
*/

/*1568. Minimum Number of Days to Disconnect Island

You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 

Example 1:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:


Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.


*/
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions array for moving in 4 directions
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Function to count the number of islands in the grid
        auto countIslands = [&](vector<vector<int>>& g) -> int {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int count = 0;

            function<void(int, int)> dfs = [&](int i, int j) {
                if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] == 0 || visited[i][j])
                    return;
                visited[i][j] = true;
                for (auto& dir : directions) {
                    dfs(i + dir.first, j + dir.second);
                }
            };

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (g[i][j] == 1 && !visited[i][j]) {
                        count++;
                        if (count > 1) return count; // Early exit if more than 1 island
                        dfs(i, j);
                    }
                }
            }
            return count;
        };

        // If already disconnected
        if (countIslands(grid) != 1) return 0;

        // Check if we can disconnect the grid in one move
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Turn land into water
                    if (countIslands(grid) != 1) {
                        return 1; // Disconnected by removing this cell
                    }
                    grid[i][j] = 1; // Restore land
                }
            }
        }

        // If no single cell removal disconnects the grid, it takes at least 2 days
        return 2;
    }
};

/*
problem Link :- https://leetcode.com/problems/regions-cut-by-slashes/?envType=daily-question&envId=2024-08-10
*/

/*959. Regions Cut By Slashes

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:


Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.


*/

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 0) {
            return 0;
        }
        grid[row][col] = 1;

        // Explore all 4 directions
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);

        return 1;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int regions = 0;

        // Create a 3n x 3n grid
        vector<vector<int>> gridExpanded(n * 3, vector<int>(n * 3, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    gridExpanded[i * 3][j * 3 + 2] = 1;
                    gridExpanded[i * 3 + 1][j * 3 + 1] = 1;
                    gridExpanded[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    gridExpanded[i * 3][j * 3] = 1;
                    gridExpanded[i * 3 + 1][j * 3 + 1] = 1;
                    gridExpanded[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        // Count the number of regions
        for (int i = 0; i < n * 3; ++i) {
            for (int j = 0; j < n * 3; ++j) {
                if (dfs(gridExpanded, i, j)) {
                    regions++;
                }
            }
        }

        return regions;
    }
};

//Main Function
int main(){
    Solution solution;
    vector<string> grid = {" /","/ ","//"};
    int regions = solution.regionsBySlashes(grid);
    cout << "Number of regions: " << regions << endl;
    return 0;
    
}
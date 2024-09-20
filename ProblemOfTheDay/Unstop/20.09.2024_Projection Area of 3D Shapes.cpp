/*
Problem link : https://unstop.com/code/practice/250600
*/

/*Projection Area of 3D Shapes

Problem Statement
Marco likes projection areas a lot. His friend gave him an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned with the x, y, and z axes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j), and asked him to view the projection of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane. He is viewing the "shadow" when looking at the cubes from the top, the front, and the side.

His friend challenged him to find the total area of all the three projections.

Input Format
The first line contains the integer N, the grid size.

The next line contains N*N space integers grid[i][j], where 0 <= i < N and 0 <= j < N.

Output Format
The first line contains the integer ans, the total area.

Constraints
N == grid.length == grid[i].length

1 <= N <= 1000

0 <= grid[i][j] <= 1000

Sample Testcase 0
Testcase Input
2
1 2 3 4
Testcase Output
17
Explanation
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
 Hence, the total area is 17.
Sample Testcase 1
Testcase Input
1
2
Testcase Output
5
Explanation
For the shadows projections , the top will give 1, front will give 2 and side view will give 2.
Hence, the total area is 5.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int projectionArea(vector<vector<int>>& grid) {
    int n = grid.size();
    int xy_projection = 0;
    int xz_projection = 0;
    int yz_projection = 0;
    
    vector<int> max_in_rows(n, 0);
    vector<int> max_in_cols(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                xy_projection++;
            }
            max_in_rows[i] = max(max_in_rows[i], grid[i][j]);
            max_in_cols[j] = max(max_in_cols[j], grid[i][j]);
        }
    }
    
    xz_projection = accumulate(max_in_rows.begin(), max_in_rows.end(), 0);
    yz_projection = accumulate(max_in_cols.begin(), max_in_cols.end(), 0);
    
    return xy_projection + xz_projection + yz_projection;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << projectionArea(grid) << endl;
    return 0;
}
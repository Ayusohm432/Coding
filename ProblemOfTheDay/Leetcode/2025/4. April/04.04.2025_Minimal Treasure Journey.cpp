/*
Problem Link: https://unstop.com/code/practice/511007
*/

/*Minimal Treasure Journey

Problem Statement
Alex is a game developer designing a puzzle game for his players. In the game, there's a treasure hunt that takes place across multiple levels. Each level has a grid of treasures, and Alex wants to find the optimal path for the player to collect the treasure in the shortest possible way.

Each level consists of an N x N grid where each cell contains a certain amount of treasure. The player can start collecting treasures from any cell in the first row and, in each subsequent row, they must select one treasure while avoiding the column from which they collected treasure in the previous row (no direct vertical shifts allowed). The goal is to calculate the minimum sum of treasures collected along such a valid path.

Input Format
The first line contains an integer N, representing the size of the grid.

The next N lines each contain N integers, representing the treasures in each cell of the grid.

Output Format
Print the integer representing the minimum sum of treasures that can be collected following the valid path.

Constraints
1 <= N <= 500

-10^5 <= grid[i][j] <= 10^5

Sample Testcase 0
Testcase Input
3
2 4 6
8 1 3
5 7 9
Testcase Output
8
Explanation
Row 1: Choose any element — 2, 4, 6.


Row 2: For each choice in Row 1, avoid the same column and pick the minimum from the available options:
       From 2: choose 1 (min(1, 3)) → Sum = 2 + 1 = 3
       From 4: choose 3 (min(8, 3)) → Sum = 4 + 3 = 7
       From 6: choose 1 (min(8, 1)) → Sum = 6 + 1 = 7


Row 3: For each choice in Row 2, avoid the same column and pick the minimum from the available options:
       From 2 -> 1: choose 5 (min(5, 9)) → Sum = 3 + 5 = 8
       From 4 -> 3: choose 5 (min(5, 9)) → Sum = 7 + 5 = 12
       From 6 -> 1: choose 5 (min(5, 7)) → Sum = 7 + 5 = 12


The minimum sum of treasure: 8

Sample Testcase 1
Testcase Input
2
1 -1
1 -1
Testcase Output
0
Explanation
The possible treasure paths are: [1, -1] ; [-1, 1].
The trasure path with the smallest sum is either [-1,1] or. [1, -1], so the answer is 0.

*/

/*nclude <iostream>
#include <vector>

using namespace std;

int min_treasure(vector<vector<int>>& grid) {
    /*
    Write your logic here.
    Parameters:
        grid: 2D vector representing the grid with treasures
    Returns:
        int: Minimum sum of treasures collected following the valid path

    return 0;
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
    int result = min_treasure(grid);
    cout << result << endl;
    return 0;
} */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min_treasure(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = grid[0][j];
    }

    for (int i = 1; i < n; ++i)
    {
        int min_val = INT_MAX, second_min_val = INT_MAX;
        int min_index = -1;

        for (int j = 0; j < n; ++j)
        {
            if (dp[i - 1][j] < min_val)
            {
                second_min_val = min_val;
                min_val = dp[i - 1][j];
                min_index = j;
            }
            else if (dp[i - 1][j] < second_min_val)
            {
                second_min_val = dp[i - 1][j];
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (j != min_index)
            {
                dp[i][j] = min(dp[i][j], min_val + grid[i][j]);
            }
            else
            {
                dp[i][j] = min(dp[i][j], second_min_val + grid[i][j]);
            }
        }
    }

    int result = INT_MAX;
    for (int j = 0; j < n; ++j)
    {
        result = min(result, dp[n - 1][j]);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int result = min_treasure(grid);
    cout << result << endl;
    return 0;
}

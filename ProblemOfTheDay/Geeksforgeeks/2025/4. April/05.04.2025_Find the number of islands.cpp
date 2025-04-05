/*
Problem Link: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/

/*Find the number of islands

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'], ['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
Output: 4
Explanation:
The image below shows all the 4 islands in the grid.
 
Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
Output: 2
Expanation:
The image below shows 2 islands in the grid.
 
Constraints:
1 ≤ n, m ≤ 500
grid[i][j] = {'L', 'W'}


*/

class Solution {
    vector<pair<int, int>> directions = {
        {1, 1}, {1, 0}, {1, -1}, {-1, -1},
        {-1, 0}, {-1, 1}, {0, 1}, {0, -1}
    };
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == 'L'){
                    count++;
                    queue<pair<int, int>> que;
                    que.push({i, j});
                    visited[i][j] = true;
                    
                    while(!que.empty()){
                        auto Pair = que.front();
                        int x = Pair.first, y = Pair.second;
                        que.pop();
                        
                        for(auto dir : directions){
                            int dx = dir.first, dy = dir.second;
                            int newX = x + dx;
                            int newY = y + dy;
                            
                            if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] == 'L'){
                                que.push({newX, newY});
                                visited[newX][newY] = true;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
    
};

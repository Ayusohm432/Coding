/*
Problem Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries?envType=daily-question&envId=2025-03-28
*/

/*2503. Maximum Number of Points From Grid Queries

You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

 

Example 1:


Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.
Example 2:


Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
k == queries.length
1 <= k <= 104
1 <= grid[i][j], queries[i] <= 106

*/

class Solution {
    public:
        vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size();
            int n = grid[0].size();
    
            int q = queries.size();    
            vector<int> result(q, 0);
    
            vector<pair<int, int>> sortedQueries;
            for(int i=0; i<q; i++){
                sortedQueries.push_back({queries[i], i});
            }
    
            sort(sortedQueries.begin(), sortedQueries.end());
    
            priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int points = 0;
            pq.push({grid[0][0], 0, 0});
            visited[0][0] = true;
    
            for(int i=0; i<q; i++){
                int queryValue = sortedQueries[i].first;
                int idx = sortedQueries[i].second;
    
                while(!pq.empty() && pq.top()[0] < queryValue){
                    int i = pq.top()[1];
                    int j = pq.top()[2];
                    pq.pop();
                    points++;
    
                    for(auto& dir : directions){
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
    
                        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]){
                            pq.push({grid[i_][j_], i_, j_});
                            visited[i_][j_] = true;
                        }
                    }
                }
    
                result[idx] = points;
            }
            return result;
        }
    };
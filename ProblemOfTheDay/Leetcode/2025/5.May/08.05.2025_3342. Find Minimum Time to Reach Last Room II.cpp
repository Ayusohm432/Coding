/*
Problem Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii?envType=daily-question&envId=2025-05-08
*/

/*3342. Find Minimum Time to Reach Last Room II

There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

Example 1:

Input: moveTime = [[0,4],[4,4]]

Output: 7

Explanation:

The minimum time required is 7 seconds.

At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
Example 2:

Input: moveTime = [[0,0,0,0],[0,0,0,0]]

Output: 6

Explanation:

The minimum time required is 6 seconds.

At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
At time t == 3, move from room (1, 1) to room (1, 2) in one second.
At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
Example 3:

Input: moveTime = [[0,1],[1,2]]

Output: 4

 

Constraints:

2 <= n == moveTime.length <= 750
2 <= m == moveTime[i].length <= 750
0 <= moveTime[i][j] <= 109

*/


class Solution {
    public:
        typedef pair<int, pair<int, int>> P;
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int m = moveTime.size();
            int n = moveTime[0].size();
    
            vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
            priority_queue<P, vector<P>, greater<P>> pq;
    
            ans[0][0] = 0;
            pq.push({0, {0, 0}});
    
            while(!pq.empty()){
                int currTime = pq.top().first;
                auto cell = pq.top().second;
                pq.pop();
    
                int i = cell.first;
                int j = cell.second;
    
                if(i == m-1 && j == n-1){
                    return currTime;
                }
    
                for(auto &dir : directions){
                    int nextI = i + dir[0];
                    int nextJ = j + dir[1];
    
                    if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n){
                        int moveCost = (nextI + nextJ) % 2  == 0 ? 2 : 1;
    
                        int wait = max(moveTime[nextI][nextJ] - currTime, 0);
                        int arrivalTime = currTime + wait + moveCost;
    
                        if(ans[nextI][nextJ] > arrivalTime){
                            ans[nextI][nextJ] = arrivalTime;
                            pq.push({arrivalTime, {nextI, nextJ}});
                        }
                    }
                }
            }
            return -1;
        }
    };
/*
Problem link :- https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1
*/

/*Minimum Cost Path

Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  

Examples :

Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
Expected Time Complexity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 Constraints:
1 ≤ n ≤ 500
1 ≤ cost of cells ≤ 500

*/
#define p pair<int,pair<int,int>>
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	vector<vector<int>> neighbours{{1,0},{-1,0},{0,1},{0,-1}};
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        vector<vector<int>> result(n , vector<int>(n , INT_MAX));
        priority_queue<p,vector<p>,greater<p>> pq;
        
        pq.push({grid[0][0] , {0,0}});
        result[0][0] = grid[0][0];
        
        while(!pq.empty()){
            int distance = pq.top().first;
            auto index =  pq.top().second;
            
            int i = index.first;
            int j = index.second;
            
            pq.pop();
            
            for(auto neighbour : neighbours){
                int new_i = i + neighbour[0];
                int new_j = j + neighbour[1];
                int new_distance = distance + grid[new_i][new_j];
                    
                if(new_i >=0 && new_i <n && new_j >= 0 && new_j < n && result[new_i][new_j] > new_distance){
                    result[new_i][new_j] = new_distance;
                    pq.push({new_distance , {new_i , new_j }});
                }
            }
        }
        return result[n-1][n-1];
    }
};
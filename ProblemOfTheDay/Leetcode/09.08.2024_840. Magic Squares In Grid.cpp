/*
Problem Link ;- https://leetcode.com/problems/magic-squares-in-grid/?envType=daily-question&envId=2024-08-09
*/

/*840. Magic Squares In Grid

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15



*/


#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;



class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid , int r , int c){
        //Checking Unique value in grid
        unordered_set<int> st;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                int num = grid[r+i][c+j];
                if(num<1 || num>9 ||st.count(num)){
                    return false;
                }
                else{
                    st.insert(num);
                }
            }
        }

        //Checking Sum along row and columns
        int SUM = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for(int i=0 ; i<3 ; i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != SUM){
                return false;
            }
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != SUM){
                return false;
            }
        }

        //Checking diagonal sum
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != SUM){
            return false;
        }

        //checking Anti-Diagonal Sum
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != SUM){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        int count = 0;

        for(int i=0 ; i<=rows-3 ; i++){
            for(int j=0 ; j<=columns-3 ; j++){
                if(isMagicSquare(grid , i , j)){
                    count++;
                }
            }
        }
        return count;
    }
};

//Main Function
int main(){
    vector<vector<int>> grid = {{48, 30, 21, 36,
    15, 6, 56, 27,
    25, 50, 32, 11,
    41, 49, 35, 22,
    5, 24, 39, 48,
    18, 44, 12, 8,
    31, 14, 43, 20}};
    Solution solution;
    cout << solution.numMagicSquaresInside(grid) << endl;
    return 0;
}
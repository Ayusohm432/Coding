/*
Problem Link: https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
*/

/*Solve the Sudoku

Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.

Examples:

Input: mat[][] = 

Output:

Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
Input: mat[][] = 

Output:

Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
Constraints:
mat.size() = 9
mat[i].size() = 9
0 ≤ mat[i][j] ≤ 9

*/

class Solution {
  public:
    // Function to find a solved Sudoku.
     bool checker(int t,int r,int c,vector<vector<int>>& mat,int n){
         for(int j=0;j<n;j++){
             if(mat[r][j]==t) return 0;
         }
         for(int i=0;i<n;i++){
             if(mat[i][c]==t) return 0;
         }
         
         int temp1=r-(r%3);
         int temp2=c-(c%3);
         
         for(int i=temp1;i<temp1+3;i++){
             for(int j=temp2;j<temp2+3;j++){
                 if(mat[i][j]==t) return 0;
             }
         }
         
         return 1;
    }
    bool helper(int row,int col,vector<vector<int>>& mat,int n){
       
       if(row==9) return true; 
       if(col==n){
          return helper(row+1,0,mat,n);   
       }
       if(mat[row][col]!=0){
           return helper(row,col+1,mat,n);
       }
       
       for(int k=1;k<=9;k++){
           if(checker(k,row,col,mat,n)){
               mat[row][col]=k;
               bool ans=helper(row,col+1,mat,n);
               if(ans){
                   return true;
               }else 
               mat[row][col]=0;
           }
       }
           
        return false;   
    }
    void solveSudoku(vector<vector<int>> &mat) {
       helper(0,0,mat,mat.size());
    }
};
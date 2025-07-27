/*
Problem Link: https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1
*/

/*Set Matrix Zeros

You are given a 2D matrix mat[][] of size n x m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0.

Examples:

Input: 
    
Output: 
    
Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.
Input: 
    
Output: 
    
Explanation: mat[0][0] and mat[0][3] are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.
Constraints:
1 ≤ n, m ≤ 500
- 231 ≤ mat[i][j] ≤ 231 - 1

*/

// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        //Code here
        int n=mat.size();
        int m=mat[0].size();
        bool row_first=0;
        bool col_first=0;
        for(int i=0;i<n;i++){
            if(mat[i][0]==0){
                col_first=true;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]==0){
                row_first=true;
                break;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][0]==0 || mat[0][j]==0) mat[i][j]=0;
            }
        }
        if(row_first){
            for(int i=0;i<m;i++) mat[0][i]=0;
        }
        if(col_first){
            for(int i=0;i<n;i++) mat[i][0]=0;
        }
        
    }
};

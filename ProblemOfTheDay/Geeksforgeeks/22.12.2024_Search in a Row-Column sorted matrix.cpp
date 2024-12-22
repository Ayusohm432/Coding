/*
Problem link: https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1
*/

/*Search in a Row-Column sorted matrix

Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.

Examples:

Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
Output: false
Explanation: 62 is not present in the matrix, so output is false.
Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
Output: true
Explanation: 55 is present in the matrix.
Input: mat[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]], x = 3
Output: true
Explanation: 3 is present in the matrix.
Constraints:
1 <= n, m <=1000
1 <= mat[i][j] <= 109
1<= x <= 109

*/

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i=0; i<m; i++){
            if(mat[i][0] <= x && mat[i][n-1] >= x){
                int start = 0;
                int end = n-1;
                while(start <= end){
                    int mid = start + (end - start)/2;
                    if(mat[i][mid] == x){
                        return true;
                    }
                    else if(mat[i][mid] < x){
                        start = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};


class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int m = mat.size();      
        int n = mat[0].size();   
        
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            if (mat[row][col] == x) {
                return true;  
            } else if (mat[row][col] > x) {
                col--; 
            } else {
                row++;  
            }
        }
        
        return false; 
    }
};
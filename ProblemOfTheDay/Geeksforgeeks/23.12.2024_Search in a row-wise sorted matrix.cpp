/*
Problem Link: https://www.geeksforgeeks.org/problems/search-in-a-row-wise-sorted-matrix/1
*/

/*Search in a row-wise sorted matrix

Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].

Examples :

Input: mat[][] = [[3, 4, 9],[2, 5, 6],[9, 25, 27]], x = 9
Output: true
Explanation: 9 is present in the matrix, so the output is true.
Input: mat[][] = [[19, 22, 27, 38, 55, 67]], x = 56
Output: false
Explanation: 56 is not present in the matrix, so the output is false.
Input: mat[][] = [[1, 2, 9],[65, 69, 75]], x = 91
Output: false
Explanation: 91 is not present in the matrix.
Constraints:
1 <= n, m <= 1000
1 <= mat[i][j] <= 105
1 <= x <= 105

*/

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
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
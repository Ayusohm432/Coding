/*
Problem Link: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
*/

/*Search in a sorted Matrix

Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.

Examples:

Input: mat[][] = [[1, 5, 9], [14, 20, 21], [30, 34, 43]], x = 14
Output: true
Explanation: 14 is present in the matrix, so output is true.
Input: mat[][] = [[1, 5, 9, 11], [14, 20, 21, 26], [30, 34, 43, 50]], x = 42
Output: false
Explanation: 42 is not present in the matrix.
Input: mat[][] = [[87, 96, 99], [101, 103, 111]], x = 101
Output: true
Explanation: 101 is present in the matrix.
Constraints:
1 <= n, m <= 1000
1 <= mat[i][j] <= 109
1 <= x <= 109

*/

class Solution {
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int left = 0, right = n * m - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mat[mid / m][mid % m];
            
            if (midValue == x) {
                return true;
            } else if (midValue < x) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        
        return false; 
    }
};
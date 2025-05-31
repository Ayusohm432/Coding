/*
Problem Link: https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1
*/

/*Kth element in Matrix

Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Examples:
Input: n = 4, mat[][] = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]], k = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
Input: n = 4, mat[][] = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]], k = 7
Output: 30
Explanation: 30 is the 7th smallest element.
Constraints:
1 <= n <= 500
1 <= mat[i][j] <= 10000
1 <= k <= n*n

*/

class Solution {
  public:
    int count(vector<vector<int>>& matrix, int element){
        int n = matrix.size();
        int cnt = 0;
        int right = 0;
        int c = n-1;
        
        while(right < n && c >= 0){
            if(matrix[right][c] <= element){
                cnt += c + 1;
                right++;
            }else{
                c--;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int result = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int ele_count = count(matrix, mid);
            
            if(ele_count < k){
                low = mid + 1;
            }else{
                result = mid;
                high = mid - 1;
            }
        }
        
        return result;
    }
};
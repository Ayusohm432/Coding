/*
Problem Link: https://leetcode.com/problems/first-completely-painted-row-or-column?envType=daily-question&envId=2025-01-20
*/

/*2661. First Completely Painted Row or Column

You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

 

Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
 

Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.

*/

//Approach - 1
class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mp;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int val = mat[i][j];
                mp[val] = {i, j};
            }
        }

        vector<int> rowCountPaint(m, 0); 
        vector<int> colCountPaint(n, 0); 

        for(int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            auto [row, col] = mp[val];

            rowCountPaint[row]++;
            colCountPaint[col]++;

            if(rowCountPaint[row] == n || colCountPaint[col] == m) {
                return i;
            }
        }
        return -1;
    }
};

//Approach - 2
class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, int> mp;

        for(int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            mp[val] = i;
        }

        int minIndex = INT_MAX;

        for(int row = 0; row < m; row++) {
            int lastIndex = INT_MIN; 

            for(int col = 0; col < n; col++) {
                int val = mat[row][col];
                int idx = mp[val];
                lastIndex = max(lastIndex, idx);
            }

            minIndex = min(minIndex, lastIndex);
        }

        for(int col = 0; col < n; col++) {
            int lastIndex = INT_MIN; 
            for(int row = 0; row < m; row++) {
                int val = mat[row][col];
                int idx = mp[val];
                lastIndex = max(lastIndex, idx);
            }

            minIndex = min(minIndex, lastIndex);
        }
        

        return minIndex;

    }
};

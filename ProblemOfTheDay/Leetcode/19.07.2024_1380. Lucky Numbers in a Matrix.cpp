/*
Problem Link ;- https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19
*/

/*1380. Lucky Numbers in a Matrix

Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.


*/

//Approach-1
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        unordered_set<int> minInRow;

        for(vector<int>& vec : matrix){
            int minimum = *min_element(vec.begin() , vec.end());
            minInRow.insert(minimum);
        }

        for(int i=0 ; i<matrix[0].size() ; i++){
            int maximum = INT_MIN;
            for(int j=0 ; j<matrix.size() ; j++){
                if(matrix[j][i] > maximum){
                    maximum = matrix[j][i];
                }
            }
            if(minInRow.count(maximum)){
                result.push_back(maximum);
                minInRow.erase(maximum);
            }
        }

        return result;
    }
};

//Approach-2
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int minRowMax = INT_MIN;
        int maxColumnMin = INT_MAX;

        for(int row = 0 ; row < n ; row++){
            int minRow = INT_MAX;
            for(int col = 0 ; col < m ; col++){
                minRow = min(minRow , matrix[row][col]);
            }
            minRowMax = max(minRowMax , minRow);
        }

        for(int col = 0 ; col < m ; col++){
            int colMax = INT_MIN;
            for(int row = 0 ; row < n ; row++){
                colMax = max(colMax , matrix[row][col]);
            }
            maxColumnMin = min(maxColumnMin , colMax);
        }

        if(minRowMax == maxColumnMin){
            return {minRowMax};
        }
        return {};
    }
};
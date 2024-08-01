/*
Problem Link ;- https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
*/

/*Spirally traversing a matrix

You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12],
                  [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 <= matrix.size(), matrix[0].size() <= 100
0 <= matrix[i][j]<= 100



*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        int s = n*m;
        
        int a = 0 , b=0;
        int c = n-1;
        int d = m-1;
        
        vector<int> result;
        while(result.size() < s){
            for(int i=b ; i<=d && result.size() < s; i++){
                result.push_back(matrix[a][i]);
            }
            a++;
            for(int i=a ; i<=c && result.size() < s ; i++){
                result.push_back(matrix[i][d]);
            }
            d--;
            for(int i=d ; i>=b && result.size() < s ; i--){
                result.push_back(matrix[c][i]);
            }
            c--;
            for(int i=c ; i>=a && result.size() < s ; i--){
                result.push_back(matrix[i][b]);
            }
            b++;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
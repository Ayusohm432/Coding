/*
Problem Link :- https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1
*/

/*Left Rotate Matrix K times


You are given an integer k and matrix mat. Rotate the elements of the given matrix to the left k times and return the resulting matrix.

Examples:

Input: k=1, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
2 3 1
5 6 4
8 9 7
Explanation: Rotate the matrix by one
1 2 3       2 3 1
4 5 6  =>  5 6 4
7 8 9       8 9 7
Input: k=2, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
3 1 2
6 4 5
9 7 8
Explanation: After rotating the matrix looks like
1 2 3       2 3 1       3 1 2
4 5 6  =>   5 6 4  =>   6 4 5
7 8 9       8 9 7       9 7 8
Expected Time Complexity: O(n*m)
Expected Auxillary Space: O(n*m)

Constraints:
1<= mat.size, mat[0].size, mat[i][j] <=1000
1<=k<=10000

*/

/*Drivers Code 
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends
*/


//Approach-1

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> output(n,vector<int>(m,0));
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                output[i][j] = mat[i][(j+k)%m];
            }
        }
        
        return output;
    }
};


//Approach-2

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        
        k = k%m;
        
        for(auto& row : mat){
            reverse(row.begin() , row.end());
            reverse(row.rbegin() , row.rbegin()+k);
            reverse(row.rbegin()+k , row.rend());
        }
        
        
        return mat;
    }
};
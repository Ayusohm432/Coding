/*
Problem Link :- https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

/*Rat in a Maze Problem - I


Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1


*/


//{ Driver Code Starts
// Initial template for C++

// #include <bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>


using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void help(vector<vector<int>>& matrix , int n , int i , int j , vector<string>& ans , string temp){
         if(i<0 || j<0 || i==n || j==n || matrix[i][j]==0){
             return ;
         }
         
         if(i==n-1 && j==n-1){
             ans.push_back(temp);
             return;
         }
         
         matrix[i][j] = 0;
         help(matrix , n , i+1 , j , ans , temp+'D');
         help(matrix , n , i-1 , j , ans , temp+'U');
         help(matrix , n , i , j+1 , ans , temp+'R');
         help(matrix , n , i , j-1 , ans , temp+'L');
         matrix[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        
        help(mat , mat.size() , 0 , 0 , ans , "");
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
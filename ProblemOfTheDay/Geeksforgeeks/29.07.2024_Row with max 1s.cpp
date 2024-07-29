/*
Problem Link :- https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
*/


/*Row with max 1s

Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Examples:

Input: arr[][] = [[0, 1, 1, 1],
               [0, 0, 1, 1],
               [1, 1, 1, 1],
               [0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
Input: arr[][] = [[0, 0], 
               [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing).
Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of rows, number of columns ≤ 103
0 ≤ arr[i][j] ≤ 1 

*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;


// } Driver Code Ends
// User function template for C++
//Appoach-1
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int i=0 ;
        int j=arr[0].size()-1;
        int ans = -1;
        
        while(i < arr.size() && j >= 0){
            if(!arr[i][j]){
                i++;
            }
            else{
                ans = i;
                j--;
            }
        }
        return ans;
    }
};

//Approach-2
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int maxi = 0;
        int maxIndex = -1;
        
        for(int i=0 ; i<n ; i++){
            int j=0;
            while(j<m){
                if(arr[i][j] == 1){
                    if(maxi < m - j){
                        maxi = m-j;
                        maxIndex = i;
                        break;
                    }
                }
                j++;
            }
        }
        return maxIndex;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
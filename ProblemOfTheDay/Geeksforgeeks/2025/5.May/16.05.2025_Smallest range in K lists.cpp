/*
Problem Link: https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
*/

/*Smallest range in K lists

Given a 2d integer array arr[][] of size k*n, where each row is sorted in ascending order. Your task is to find the smallest range [l, r] that includes at least one element from each of the k lists. If more than one such ranges are found, return the first one.

Examples:

Input: n = 5, k = 3, arr[][] = [[4, 7, 9, 12, 15], [0, 8, 10, 14, 20], [6, 12, 16, 30, 50]]
Output: [6, 8]
Explanation: Smallest range is formed by  number 7 from the first list, 8 from second list and 6 from the third list.
Input: n = 5, k = 3, arr[][] = [[1, 3, 5, 7, 9], [0, 2, 4, 6, 8], [2, 3, 5, 7, 11]]
Output: [1, 2]
Explanation: Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list.
Input: n = 2, k = 3, arr[][] = [[2, 4], [1, 7], [20, 40]]
Output: [4, 20]
Explanation: Smallest range is formed by number 4 from the first list, 7 from second list and 20 from the third list.
Constraints:
1 <= k, n <= 500
0 <= arr[ i ] <= 105

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int k = arr.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int maxi = INT_MIN;
        for(int i=0; i<k; i++){
            pq.push({arr[i][0], i, 0});
            maxi = max(maxi, arr[i][0]);
        }
        
        vector<int> result = {0, 100000};
        
        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            
            int mini = curr[0];
            int listIndex = curr[1];
            int index = curr[2];
            
            if(maxi - mini < result[1] - result[0]){
                result[0] = mini;
                result[1] = maxi;
            }
            
            if(index+1 < arr[listIndex].size()){
                int nexti = arr[listIndex][index+1];
                pq.push({nexti, listIndex, index+1});
                maxi = max(maxi, nexti);
            }else{
                break;
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
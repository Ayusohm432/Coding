/*
Problem Link : https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1
*/


/*Sorted subsequence of size 3

You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.

Note:

The output will be 1 if the subsequence returned by the function is present in the array arr
If the subsequence is not present in the array then return an empty array, the driver code will print 0.
If the subsequence returned by the function is not in the format as mentioned then the output will be -1.
Examples :

Input: arr = [1, 2, 1, 1, 3]
Output: 1
Explanation: A subsequence 1 2 3 exist.
Input: arr = [1, 1, 3]
Output: 0
Explanation: No such Subsequence exist, so empty array is returned (the driver code automatically prints 0 in this case).
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106


*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        
        vector<int> leftSmall(n);
        vector<int> rightLarge(n);
        
        leftSmall[0] = arr[0];
        for(int i=1 ; i<n ; i++){
            leftSmall[i] = min(arr[i] , leftSmall[i-1]);
        }
        
        rightLarge[n-1] = arr[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            rightLarge[i] = max(arr[i] , rightLarge[i+1]);
        }
        
        for(int i=1 ; i<=n-2 ; i++){
            if(arr[i] > leftSmall[i-1] && arr[i] < rightLarge[i+1]){
                return {leftSmall[i-1] , arr[i] , rightLarge[i+1]};
            }
        }
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() && res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] && res[1] < res[2]) && isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
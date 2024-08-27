/*
Problem Link :- https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1
*/


/*Maximum Difference

Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

Examples :

Input: arr = [2, 1, 8]
Output: 1
Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
Input: arr = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= arr.size() <= 106
1<= arr[i] <=109


*/

//{ Driver Code Starts
// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        vector<int> leftSmaller(n) , rightSmaller(n);
        stack<int> st;
        
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                leftSmaller[i] = st.top();
            }
            else{
                leftSmaller[i] = 0;
            }
            st.push(arr[i]);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                rightSmaller[i] = st.top();
            }
            else{
                rightSmaller[i] = 0;
            }
            st.push(arr[i]);
        }
        
        int maxDifference = INT_MIN;
        
        for(int i=0 ; i<n ; i++){
            if(abs(leftSmaller[i] - rightSmaller[i]) > maxDifference){
                maxDifference = abs(leftSmaller[i] - rightSmaller[i]);
            }
        }
        return maxDifference;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
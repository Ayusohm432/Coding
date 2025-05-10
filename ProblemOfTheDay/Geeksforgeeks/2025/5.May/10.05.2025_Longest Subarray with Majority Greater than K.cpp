/*
Problem Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1
*/

/*Longest Subarray with Majority Greater than K

Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

Examples:

Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.
Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 106
0 <= k <= 106

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        int maxLength = 0;
        
        unordered_map<int, int> mp;
        
        int countLess = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i] <= k){
                countLess--;
            }else{
                countLess++;
            }
            
            if(countLess <= 0 && !mp.count(countLess)){
                mp[countLess] = i;
            }
            
            if(countLess <= 0 && mp.count(countLess - 1)){
                maxLength = max(maxLength, i - mp[countLess - 1]);
            }
            
            if(countLess > 0){
                maxLength = i+1;
            }
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
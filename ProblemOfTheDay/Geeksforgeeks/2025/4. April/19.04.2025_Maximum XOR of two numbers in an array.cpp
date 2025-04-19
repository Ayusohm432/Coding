/*
Problem Link: https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1
*/

/*Maximum XOR of two numbers in an array

Given an array arr[] of non-negative integers of size n. Find the maximum possible XOR between two numbers present in the array.

Examples:

Input: arr[] = [25, 10, 2, 8, 5, 3]
Output: 28
Explanation: The maximum possible XOR is 5 ^ 25 = 28.
Input: arr[] = [1, 2, 3, 4, 5, 6, 7]
Output: 7
Explanation : The maximum possible XOR is 1 ^ 6 = 7.
Constraints:
2 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 106

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
struct TrieNode{
    TrieNode* next[2] = {};
};


class Solution {
    TrieNode* root = new TrieNode();
    
    void insert(int num){
        TrieNode* node = root;
        
        for(int i=20; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node->next[bit]){
                node->next[bit] = new TrieNode();
            }
            node = node->next[bit];
        }
    }
    
    int find(int num){
        TrieNode* node = root;
        int xorVal = 0;
        
        for(int i=20; i>=0; i--){
            int bit = (num >> i) & 1;
            int want = 1 - bit;
            if(node->next[want]){
                xorVal |= (1 << i);
                node = node->next[want];
            }else{
                node = node->next[bit];
            }
        }
        return xorVal;
    }
  public:
    int maxXor(vector<int> &arr) {
        // code here
        for(int num : arr){
            insert(num);
        }
        
        int maxResult = 0;
        for(int num : arr){
            maxResult = max(maxResult, find(num));
        }
        
        return maxResult;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
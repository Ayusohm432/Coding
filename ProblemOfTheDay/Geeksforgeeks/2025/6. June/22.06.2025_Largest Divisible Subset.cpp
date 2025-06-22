/*
Problem Link: https://www.geeksforgeeks.org/problems/largest-divisible-subset--170643/1
*/

/*Largest Divisible Subset

Given an array arr[] of distinct positive integers. Your task is to find the largest subset such that for every pair of elements (x, y) in the subset, either x divides y or y divides x.
Note : If multiple subsets of the same maximum length exist, return the one that is lexicographically greatest, after sorting the subset in ascending order.

Examples:

Input: arr[] = [1, 16, 7, 8, 4]
Output: [1, 4, 8, 16]
Explanation: The largest divisible subset is [1, 4, 8, 16], where each element divides the next one. This subset is already the lexicographically greatest one.
Input: arr[] = [2, 4, 3, 8]
Output: [2, 4, 8]
Explanation: The largest divisible subset is [2, 4, 8], where each element divides the next one. This subset is already the lexicographically greatest one.
Constraint:
1 ≤ arr.size() ≤ 103
1  ≤ arr[i] ≤ 109

*/
class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.rbegin(), arr.rend());
        
        vector<int> dp(n, 1);
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        int maxLen = 1;
        int maxIndex = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j] % arr[i] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        
        vector<int> result;
        while(parent[maxIndex] != maxIndex){
            result.push_back(arr[maxIndex]);
            maxIndex = parent[maxIndex];
        }
        result.push_back(arr[maxIndex]);
        // reverse(result.begin(), result.end());
        return result;
    }
};


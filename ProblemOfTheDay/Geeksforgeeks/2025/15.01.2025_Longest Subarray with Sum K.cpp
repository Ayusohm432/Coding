/*
Problem Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
*/

/*Longest Subarray with Sum K

Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109

*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum=0,length=0;
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) length=max(length,i+1);
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            if(mp.find(sum-k)!=mp.end()) length=max(length,i-mp[sum-k]);
        }
        return length;
    }
};
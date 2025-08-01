/*
Problem Link: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
*/

/*Max Circular Subarray Sum

You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
Input: arr[] = [5, -2, 3, 4]
Output: 12
Explanation: The circular subarray [3, 4, 5] gives the maximum sum of 12.
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104

*/

class Solution {
    int maxKadane(vector<int>& arr, int n){
        int sum = arr[0];
        int maxSum = arr[0];
        
        for(int i=1; i<n; i++){
            sum = max(sum+arr[i], arr[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
    
    int minKadane(vector<int>& arr, int n){
        int sum = arr[0];
        int minSum = arr[0];
        
        for(int i=1; i<n; i++){
            sum = min(sum+arr[i], arr[i]);
            minSum = min(minSum, sum);
        }
        
        return minSum;
    }
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int maxSubarraySum = maxKadane(arr, n);
        int minSubarraySum = minKadane(arr, n);
        int circularSubarraySum = totalSum - minSubarraySum;
        
        if(maxSubarraySum > 0){
            return max(maxSubarraySum, circularSubarraySum);
        }
        return maxSubarraySum;
    }
};
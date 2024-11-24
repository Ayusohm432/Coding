/*
Problem Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
*/

/*Kadane's Algorithm

Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.
Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.
Constraints:
1 ≤ arr.size() ≤ 105
-109 ≤ arr[i] ≤ 104

*/
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        long long ans = INT_MIN; 
        long long sum = 0; 
        
        for(int i=0 ; i<arr.size() ; i++){
            sum += arr[i];
            ans = max(ans , sum);
            
            if(sum < 0){
                sum = 0;
            }
        }
        return ans;
    }
};
/*
Problem link: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
*/

/*Max Circular Subarray Sum

Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
Output: 52
Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.
Constraints:
1 <= arr.size() <= 105
-104 <= arr[i] <= 104

*/

//Approach-1
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int n = arr.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum1 = 0; 
        int sum2 = 0; 
        int total = 0;
        
        for(int i=0; i<n; i++){
            sum1 += arr[i];
            sum2 += arr[i];
            total += arr[i];
            
            if(sum2 > 0){
                sum2 = 0;
            }
            else{
                mini = min(mini, sum2);
            }
            
            if(sum1 < 0){
                sum1 = 0;
            }
            else{
                maxi = max(maxi, sum1);
            }
        }
        
        return max(maxi, total-mini);
    }
};

//Approach-2
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int n = arr.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum1 = 0; 
        int sum2 = 0; 
        int total = 0;
        
        for(int i=0; i<n; i++){
            total += arr[i];
            sum2 = min(arr[i], sum2+arr[i]);
            mini = min(mini, sum2);
            sum1 = max(arr[i], sum1+arr[i]);
            maxi = max(maxi, sum1);
        }
        
        return max(maxi, total-mini);
    }
};
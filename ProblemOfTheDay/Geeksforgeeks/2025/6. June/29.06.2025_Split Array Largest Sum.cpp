/*
Problem Link: https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
*/

/*Split Array Largest Sum

Given an array arr[] and an integer k, divide the array into k contiguous subarrays such that the maximum sum among these subarrays is minimized. Find this minimum possible maximum sum.

Examples:

Input: arr[] = [1, 2, 3, 4], k = 3
Output: 4
Exaplanation: Optimal Split is [1, 2], [3], [4]. Maximum sum of all subarrays is 4, which is minimum possible for 3 splits.
Input: arr[] = [1, 1, 2], k = 2
Output: 2
Exaplanation: Splitting the array as [1, 1] and [2] is optimal. This results in a maximum sum subarray of 2.
Constraints:
1 ≤ k ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104

*/

class Solution {
    bool track(int mid, int k, int n, vector<int>& arr){
        int count = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > mid){
                count++;
                sum = arr[i];
            }
            
            if(count > k){
                return false;
            }
        }
        return true;
    }
  public:
    int splitArray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        int result;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(track(mid, k, n, arr)){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return result;
    }
};
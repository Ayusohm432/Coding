/*
Problem Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-elements-not-part-of-lis/1
*/

/*Maximum sum of elements not part of LIS

Given an array arr[] of positive integers, your task is to find the maximum possible sum of all elements that are not part of the Longest Increasing Subsequence (LIS).

Examples:

Input: arr[] = [4, 6, 1, 2, 3, 8]
Output: 10
Explanation: The elements which are not in LIS is 4 and 6.
Input: arr[] = [5, 4, 3, 2, 1]
Output: 14
Explanation: The elements which are not in LIS is 5, 4, 3 and 2.
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 105

*/

class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> listLength(n, 0);
        vector<int> prevIndex(n, 1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j] < arr[i] && prevIndex[i] <= prevIndex[j]+1){
                    prevIndex[i] = prevIndex[j]+1;
                    listLength[i] = j;
                }
            }
        }
        
        int totalSum = 0;
        int idx = -1;
        int maxi = 0;
        int len = 0;
        
        for(int i=0; i<n; i++){
            if(maxi <= prevIndex[i]){
                maxi = prevIndex[i];
                idx = i;
            }
            totalSum += arr[i];
        }
        
        len = maxi;
        int sum = arr[idx];
        maxi--;
        
        while(maxi > 0){
            sum += arr[listLength[idx]];
            idx = listLength[idx];
            maxi--;
        }
        
        return totalSum - sum;
    }
};
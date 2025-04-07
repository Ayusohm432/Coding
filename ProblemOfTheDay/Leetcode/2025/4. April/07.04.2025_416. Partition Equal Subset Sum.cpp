/*
Problem Link: https://leetcode.com/problems/partition-equal-subset-sum?envType=daily-question&envId=2025-04-07
*/

/*416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/

class Solution {
    public:
        int dp[201][20001];
    
        bool helper(vector<int>& nums, int i, int required){
            if(required == 0){
                return true;
            }
    
            if(i >= nums.size()){
                return false;
            }
    
            if(dp[i][required] != -1){
                return dp[i][required];
            }
    
            bool taken = false;
    
            if(nums[i] <= required){
                taken = helper(nums, i+1, required - nums[i]);
            }
    
            bool notTaken = helper(nums, i+1, required);
    
            return dp[i][required] = taken || notTaken;
        }
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sumTotal = accumulate(nums.begin(), nums.end(), 0);
    
            if(sumTotal % 2 != 0){
                return false;
            }
    
            memset(dp, -1, sizeof(dp));
    
            int required = sumTotal / 2;
    
            return helper(nums, 0, required);
        }
    };
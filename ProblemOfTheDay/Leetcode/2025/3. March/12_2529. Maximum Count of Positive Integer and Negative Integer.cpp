/*
Problem Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer?envType=daily-question&envId=2025-03-12
*/

/*2529. Maximum Count of Positive Integer and Negative Integer

Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.

 

Example 1:

Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
Example 2:

Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
Example 3:

Input: nums = [5,20,66,1314]
Output: 4
Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.
 

Constraints:

1 <= nums.length <= 2000
-2000 <= nums[i] <= 2000
nums is sorted in a non-decreasing order.
 
*/

class Solution {
    public:
        int lowerBound(vector<int>& nums){
            int low = 0;
            int high = nums.size() - 1;
            int index = nums.size();
    
            while(low <= high){
                int mid = low + (high - low)/2;
    
                if(nums[mid] < 0){
                    low = mid + 1;
                }else if(nums[mid] >= 0){
                    high = mid - 1;
                    index = mid;
                }
            }
    
            return index;
        }
    
        int upperBound(vector<int>& nums){
            int low = 0;
            int high = nums.size() - 1;
            int index = nums.size();
    
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(nums[mid] <= 0){
                    low = mid + 1;
                }else if(nums[mid] > 0){
                    high = mid - 1;
                    index =  mid;
                }
            } 
            return index;
        }
        int maximumCount(vector<int>& nums) {
            int n = nums.size();
    
            int posCount = nums.size() - upperBound(nums);
            int negCount = lowerBound(nums);
    
            return max(posCount, negCount);
        }
    };
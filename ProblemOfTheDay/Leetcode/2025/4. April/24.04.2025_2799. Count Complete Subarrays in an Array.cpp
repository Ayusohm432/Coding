/*
Problem Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array?envType=daily-question&envId=2025-04-24
*/

/*2799. Count Complete Subarrays in an Array

You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

 

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2000


*/
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
    
            unordered_set<int> distinct_elements(nums.begin(), nums.end());
            int distinct_elements_count = distinct_elements.size();
    
            unordered_map<int, int> mp;
            int j = 0;
            int result = 0;
    
            for(int i=0; i<n; i++){
                if(i > 0){
                    int curr = nums[i - 1];
                    mp[curr]--;
                    if(mp[curr] == 0){
                        mp.erase(curr);
                    }
                }
                while(j < n && mp.size() < distinct_elements_count){
                    int temp = nums[j];
                    mp[temp]++;
                    j++;
                }
    
                if(mp.size() == distinct_elements_count){
                    result += (n - j + 1);
                }
            }
    
            return result;
        }
    };
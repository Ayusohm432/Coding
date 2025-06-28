/*
Problem Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum?envType=daily-question&envId=2025-06-28
*/

/*2099. Find Subsequence of Length K With the Largest Sum

You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
 

Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length

*/

class Solution {
    typedef pair<int, int> P;
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<P> temp;

        for(int i=0; i<n; i++){
            temp.emplace_back(i, nums[i]);
        }

        sort(begin(temp), end(temp), [&](auto a, auto b){
            return a.second > b.second;
        });

        sort(begin(temp), begin(temp) + k);

        vector<int> result;

        for(int i=0; i<k; i++){
            result.push_back(temp[i].second);
        }

        return result;
    }
};
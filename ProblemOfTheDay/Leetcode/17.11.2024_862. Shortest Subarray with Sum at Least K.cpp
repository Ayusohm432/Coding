/*
Problem link : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k?envType=daily-question&envId=2024-11-17
*/

/*862. Shortest Subarray with Sum at Least K

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109

*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, long long>> dq; 
        long long sum = 0;
        int shortest = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            if (sum >= k) {
                shortest = min(shortest, i + 1); 
            }

            while (!dq.empty() && (sum - dq.front().second >= k)) {
                shortest = min(shortest, i - dq.front().first);
                dq.pop_front();
            }

            while (!dq.empty() && dq.back().second >= sum) {
                dq.pop_back();
            }

            dq.push_back({i, sum});
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};
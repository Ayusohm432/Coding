/*
Problem Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs?envType=daily-question&envId=2025-06-13
*/

/*2616. Minimize the Maximum Difference of Pairs

You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

 

Example 1:

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
Example 2:

Input: nums = [4,2,1,2], p = 1
Output: 0
Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= p <= (nums.length)/2

*/

class Solution {
    bool isValid(int n, vector<int>& nums, int mid, int p){
        int i = 0;
        int pairs = 0;
        while(i < n-1){
            if(nums[i+1] - nums[i] <= mid){
                pairs++;
                i += 2;
            }else{
                i++;
            }
        }
        return pairs >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isValid(n, nums, mid, p)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
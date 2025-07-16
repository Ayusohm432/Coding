/*
Problem Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i?envType=daily-question&envId=2025-07-16
*/

/*3201. Find the Maximum Length of Valid Subsequence I

You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 4

Explanation:

The longest valid subsequence is [1, 2, 3, 4].

Example 2:

Input: nums = [1,2,1,1,2,1,2]

Output: 6

Explanation:

The longest valid subsequence is [1, 2, 1, 2, 1, 2].

Example 3:

Input: nums = [1,3]

Output: 2

Explanation:

The longest valid subsequence is [1, 3].

 

Constraints:

2 <= nums.length <= 2 * 105
1 <= nums[i] <= 107

*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int evenCount = 0;
        int oddCount = 0;

        for(int num : nums){
            if(num % 2  == 0){
                evenCount++;
            }else{
                oddCount++;
            }
        }

        int len = 1;
        int previousParity = nums[0] % 2;

        for(int i=1; i<n; i++){
            int currentParity = nums[i] % 2;
            if(currentParity != previousParity){
                len++;
                previousParity = currentParity; 
            }
        }

        return max({evenCount, oddCount, len});
    }
};
/*
Problem Link : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii?envType=daily-question&envId=2024-11-10
*/

/*3097. Shortest Subarray With OR at Least K II

You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty 
subarray
 of nums, or return -1 if no special subarray exists.

 

Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.

 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109

*/
class Solution {
    void updateFreq(vector<int>& bitFreq, int number, int val){
        for(int i=0; i<32; i++){
            if(number & (1 << i)){
                bitFreq[i] += val;
            }
        }
    }

    int getNumber(vector<int>& bitFreq){
        int number = 0;
        long long pow = 1; 
        for(int i=0; i<32; i++){
            if(bitFreq[i] > 0){
                number += pow;
            }
            pow *= 2;
        }
        return number;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k == 0){
            return 1;
        }

        int n = nums.size();
        int shortest = INT_MAX;
        int left = 0, right = 0;
        int currOr = 0;
        vector<int> bitFreq(32);

        while(right < n){
            updateFreq(bitFreq, nums[right], 1);
            currOr |= nums[right];

            while(left <= right && currOr >= k){
                shortest = min(shortest, right-left+1);
                updateFreq(bitFreq, nums[left], -1);
                currOr = getNumber(bitFreq);
                left++;
            }
            right++;
        }
        return shortest == INT_MAX ? -1 : shortest;
    }
};
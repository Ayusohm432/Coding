/*
Problem Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i?envType=daily-question&envId=2024-12-16
*/

/*3264. Final Array State After K Multiplication Operations I

You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.

 

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:

Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]
Example 2:

Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]

Explanation:

Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5

*/

//Approach-1
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0; i<k; i++){
            auto mini = min_element(nums.begin(), nums.end());
            *mini *= multiplier;
        }
        return nums;
    }
};


//Approach-2
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {nums[i], i};
        }

        make_heap(begin(arr), end(arr), greater<>());

        while(k--){
            pop_heap(begin(arr), end(arr), greater<>());
            pair<int, int> temp = arr.back();
            arr.pop_back();

            int number = temp.first;
            int idx = temp.second;

            nums[idx] = number * multiplier;

            arr.push_back({nums[idx], idx});
            push_heap(begin(arr), end(arr), greater<>());

        }
        return nums;
    }
};
/*
Problem Link: https://leetcode.com/problems/zero-array-transformation-iii?envType=daily-question&envId=2025-05-22
*/

/*3362. Zero Array Transformation III

You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

 

Example 1:

Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

Output: 1

Explanation:

After removing queries[2], nums can still be converted to a zero array.

Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Example 2:

Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

Output: 2

Explanation:

We can remove queries[2] and queries[3].

Example 3:

Input: nums = [1,2,3,4], queries = [[0,3]]

Output: -1

Explanation:

nums cannot be converted to a zero array even after using all the queries.

 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length

*/

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> queryUsing;
        priority_queue<int> queryAvailable;

        sort(queries.begin(), queries.end());

        int queryIndex = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            while(queryIndex < queries.size() && queries[queryIndex][0] == i){
                queryAvailable.push(queries[queryIndex][1]);
                queryIndex++;
            }

            nums[i] -= queryUsing.size();

            while(nums[i] > 0 && !queryAvailable.empty() && queryAvailable.top() >= i){
                queryUsing.push(queryAvailable.top());
                queryAvailable.pop();
                nums[i]--;
                count++;
            }

            if(nums[i] > 0){
                return -1;
            }

            while(!queryUsing.empty() && queryUsing.top() == i){
                queryUsing.pop();
            }
        }
        return queries.size() - count;
    }
};
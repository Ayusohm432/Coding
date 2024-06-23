/*
Problem Link :- https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
*/


/*1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109

*/

//Approach-1
class Solution {
public:
    typedef pair<int,int> p;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<p,vector<p>> maxPq;
        priority_queue<p,vector<p>,greater<p>> minPq;

        int i=0;
        int j=0;
        int maxlength = 0;

        while(j<n){
            maxPq.push({nums[j],j});
            minPq.push({nums[j],j});

            while(maxPq.top().first - minPq.top().first > limit){
                i = min(maxPq.top().second , minPq.top().second) +1;
                while(maxPq.top().second < i){
                    maxPq.pop();
                }
                while(minPq.top().second < i){
                    minPq.pop();
                }
            }
            maxlength = max(maxlength,j-i+1);
            j++;
        }

        return maxlength;
    }
};

//Approach-2
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;

        int i=0;
        int j=0;
        int maxlength = 0;

        while(j<n){
            st.insert(nums[j]);
            while(*st.rbegin()-*st.begin() > limit){
                st.erase(st.find(nums[i]));
                i++;
            }
            maxlength = max(maxlength,j-i+1);
            j++;
        }
        return maxlength;
    }
};
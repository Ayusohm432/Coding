/*
Problem Link : https://www.geeksforgeeks.org/problems/majority-vote/1
*/

/*Majority Element II

You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

Note: The answer should be returned in an increasing format.

Examples:

Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: no candidate occur more than n/3 times.
Constraint:
1 <= arr.size() <= 106
-109 <= arr[i] <= 109

*/
class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        int ele1 = nums[0], ele2 = nums[0];
        int count1 = 0, count2 = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) count1++;
            else if (nums[i] == ele2) count2++;
            else if (count1 == 0) ele1 = nums[i], count1 = 1;
            else if (count2 == 0) ele2 = nums[i], count2 = 1;
            else count1--, count2--;
        }
        
        int freq1 = 0, freq2 = 0;
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) freq1++;
            else if (nums[i] == ele2) freq2++;
        }
        
        if (freq1 > n / 3) ans.push_back(ele1);
        if (freq2 > n / 3 && ele1 != ele2) ans.push_back(ele2);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
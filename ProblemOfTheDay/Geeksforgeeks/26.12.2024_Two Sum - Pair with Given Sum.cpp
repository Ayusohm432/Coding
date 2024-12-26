/*
Problem Link: https://www.geeksforgeeks.org/problems/key-pair5616/1
*/

/*Two Sum - Pair with Given Sum

Given an array arr[] of positive integers and another integer target. Determine if there exists two distinct indices such that the sum of there elements is equals to target.

Examples:

Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
Output: true
Explanation: arr[3] + arr[4] = 6 + 10 = 16.
Input: arr[] = [1, 2, 4, 3, 6], target = 11
Output: false
Explanation: None of the pair makes a sum of 11.
Input: arr[] = [11], target = 11
Output: false
Explanation: No pair is possible as only one element is present in arr[].
Constraints:
1 ≤ arr.size ≤ 105
1 ≤ arr[i] ≤ 105
1 ≤ target ≤ 2*105


*/

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        //CodeGenius
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            int diff=target-arr[i];
            if(mp.find(diff)!=mp.end()) return true;
            mp[arr[i]]++;
        }
        return false;
    }
};
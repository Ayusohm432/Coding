/*
Problem Link: Longest subarray with Atmost two distinct integers
*/

/*Longest subarray with Atmost two distinct integers

Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.

Examples:

Input: arr[] = [2, 1, 2]
Output: 3
Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

*/

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        int result = 0;
        int i=0, j=0;
        unordered_map<int, int> mp;
        
        while(j < n){
            mp[arr[j]]++;
            while(mp.size() > 2){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                }
                i++;
            }
            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
};
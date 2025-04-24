/*
Problem Link: https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
*/

/*Unique Number III

Given an array of integers arr[] where, every element appears thrice except for one which occurs once.
Find that element which occurs once.

Examples:

Input: arr[] = [1, 10, 1, 1]
Output: 10
Explanation: 10 occurs once in the array while the other element 1 occurs thrice.
Input: arr[] = [3, 2, 1, 34, 34, 1, 2, 34, 2, 1]
Output: 3
Explanation: All elements except 3 occurs thrice in the array.
Constraints:
1 ≤ arr.size() ≤ 105
arr.size() % 3 = 1
-109 ≤ arr[i] ≤ 109


*/

class Solution {
    public:
      int getSingle(vector<int> &arr) {
          // code here
          int n = arr.size();
          unordered_map<int, int> mp;
          for(int i=0; i<n; i++){
              mp[arr[i]]++;
          }
          
          int result = 0;
          for(auto it : mp){
              if(it.second == 1){
                  result = it.first;
              }
          }
          
          return result;
      }
  };
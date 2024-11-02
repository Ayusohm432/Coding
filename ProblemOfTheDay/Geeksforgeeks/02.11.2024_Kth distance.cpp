/*
Problem Link : https://www.geeksforgeeks.org/problems/kth-distance3757/1
*/

/*Kth distance

Given an unsorted array arr and a number k which is smaller than size of the array. Find if the array contains any duplicate within k distance.

Examples:

Input: arr[] = [1, 2, 3, 4, 1, 2, 3, 4] and k = 3
Output: false
Explanation: All duplicates are more than k distance away.
Input: arr[] = [1, 2, 3, 1, 4, 5] and k = 3
Output: true
Explanation: 1 is repeated at distance 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ k < arr.size()
1 ≤ arr[i] ≤ 105

*/

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            if(mp.find(arr[i]) != mp.end()){
                if(i - mp[arr[i]] <= k){
                    return true;
                }
                else{
                    mp[arr[i]] = i;
                }
            }
            mp[arr[i]] = i;
        }
        return false;
    }
};
/*
Problme Link: https://leetcode.com/problems/three-consecutive-odds?envType=daily-question&envId=2025-05-11
*/

/*1550. Three Consecutive Odds

Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000

*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for(int i=0; i<n; i++){
            if(arr[i] % 2 == 1){
                count++;
            }else{
                count = 0;
            }

            if(count >= 3){
                return true;
            }
        }

        return (count >= 3);
    }
};